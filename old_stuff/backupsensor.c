#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S2,     irF,            sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     lightF,         sensorLightActive)
#pragma config(Sensor, S4,     irR,            sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     fr,            tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     fl,            tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     bl,            tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     br,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     liftA,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     liftB,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C4_1,     holder,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     flagspinner,   tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "hitechnic-sensormux.h"
#include "lego-touch.h"
#include "lego-light.h"

//#define touchBack              msensor_S4_1
//#define lightL             msensor_S4_2
//#define lightR          msensor_S4_3

const int ON_TAPE = 480;
//const int OFF_TAPE = 450;


void initializeRobot(){
	bFloatDuringInactiveMotorPWM = false;
	return;
}

void takeDump(){
	motor[holder] = -100;
	wait1Msec(200);
	motor[holder] = 0;
	wait1Msec(600);
	motor[holder] = 100;
	wait1Msec(300);
	motor[holder] = 0;
}

void liftUpAndDownAndTakeDump(){
	motor[liftA] = 100;
	motor[liftB] = 100;
	wait1Msec(700);
	motor[liftA] = 0;
	motor[liftB] = 0;

	takeDump();

	motor[liftA] = -100;
	motor[liftB] = -100;
	wait1Msec(500);
	motor[liftA] = 0;
	motor[liftB] = 0;
}

task updateDisplay(){
	while(true){
		nxtDisplayTextLine(1, "%d" ,SensorRaw[lightF]);
		nxtDisplayTextLine(2, "%d" ,SensorValue[irR]);
		nxtDisplayTextLine(3, "%d" ,SensorValue[irF]);
	}
}

void irify(){

	PlaySound(soundBeepBeep);
	motor[fr] = 0;
	motor[fl] = 0;
	motor[br] = 0;
	motor[bl] = 0;
	wait1Msec(1000);

	motor[fr] = -13;
	motor[fl] = -28;
	motor[br] = -13;
	motor[bl] = -28;

	wait1Msec(300);

	while(SensorValue[irF] != 5){
		motor[fr] = -20;
		motor[fl] = 20;
		motor[br] = -20;
		motor[bl] = 20;
	}

	while(SensorRaw[lightF]  <= ON_TAPE){
		motor[fr] = 25;
		motor[fl] = 25;
		motor[br] = 25;
		motor[bl] = 25;
	}

	while(SensorRaw[lightF]  >= ON_TAPE && false){
		motor[fr] = 25;
		motor[fl] = 25;
		motor[br] = 25;
		motor[bl] = 25;
	}

	motor[fr] = 0;
	motor[fl] = 0;
	motor[br] = 0;
	motor[bl] = 0;

	while(!(SensorRaw[lightF]  >= ON_TAPE && SensorValue[irF] == 5)){
		PlaySound(soundBeepBeep);
		motor[fr] = -15;
		motor[fl] = 15;
		motor[br] = -15;
		motor[bl] = 15;
	}

	motor[fr] = 0;
	motor[fl] = 0;
	motor[br] = 0;
	motor[bl] = 0;
}

bool tapeify(){
	//while(false){
	//drive forward until left light loses tape and scan for IR beacon

	if(SensorRaw[lightF]  >= ON_TAPE){
		motor[fr] = 13;
		motor[fl] = 28;
		motor[br] = 13;
		motor[bl] = 28;
	}
	else{
		ClearTimer(T1);
		bool probablyOffTape = false;
		int timeCorrection = 0;
		while(SensorRaw[lightF]  <= ON_TAPE){
			motor[fr] = 20;
			motor[fl] = 0;
			motor[br] = 20;
			motor[bl] = 0;
			if(time1[T1] > 300){
				probablyOffTape = true;
				break;
			}
		}
		timeCorrection = time1[T1];
		ClearTimer(T1);
		while(time1[T1] < timeCorrection){
			motor[fr] = 0;
			motor[fl] = 20;
			motor[br] = 0;
			motor[bl] = 20;
		}

		if(probablyOffTape){
			return false;
		}
		else{
			return true;
		}
	}
}

task main()
{
	bool probablyOffTape = false;
	initializeRobot();
	//waitForStart();

	wait1Msec(700);

	motor[motorA] = -50;

	StartTask(updateDisplay);

	while(true){
		if(SensorValue[irR] == 5){
			irify();
			break;
		}
		else{
			probablyOffTape = tapeify();
		}

		if(probablyOffTape && false){
			break;
		}
	}

	motor[fr] = 0;
	motor[fl] = 0;
	motor[br] = 0;
	motor[bl] = 0;

	while(true){

	}

	PlaySound(soundBeepBeep);
}
