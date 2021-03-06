#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Hubs,  S3, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S4, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     irseek,         sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S3_C1_1,     fr,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_2,     br,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C2_1,     fl,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C2_2,     bl,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_1,     liftA,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S4_C1_2,     liftB,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S4_C2_1,     sweeper,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C2_2,     spinner,       tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    cubeLiftServoA,       tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    cubeLiftServoB,       tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "HolonomicAutonomousDrives.c"

int highAValue;
int highBValue;

void initializeRobot()
{
	servo[cubeLiftServoA] = ServoValue[cubeLiftServoA];
	servo[cubeLiftServoB] = ServoValue[cubeLiftServoB];

	wait1Msec(500);

	servo[cubeLiftServoA] = ServoValue[cubeLiftServoA] - 36;
	servo[cubeLiftServoB] = ServoValue[cubeLiftServoB] + 36;

	highAValue = ServoValue[cubeLiftServoA];
	highBValue = ServoValue[cubeLiftServoB];

	wait1Msec(500);

	return;
}

task playMusic(){
	while (true){
		//        100 = Tempo
		//          6 = Default octave
		//    Quarter = Default note length
		//        10% = Break between notes
		//
		PlayTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
		PlayTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
		PlayTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
		PlayTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
		PlayTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
		PlayTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
		PlayTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
		PlayTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
		PlayTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
		PlayTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
		PlayTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
		PlayTone(  988,    7); wait1Msec(  75);  // Note(E, Duration(32th))
		PlayTone( 1047,    7); wait1Msec(  75);  // Note(F, Duration(32th))
		PlayTone( 1109,    7); wait1Msec(  75);  // Note(F#, Duration(32th))
		PlayTone( 1175,    7); wait1Msec(  75);  // Note(G, Duration(32th))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
		PlayTone( 1398,   14); wait1Msec( 150);  // Note(A#, Duration(16th))
		PlayTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
		PlayTone(  784,   14); wait1Msec( 150);  // Note(C, Duration(16th))
		PlayTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
		PlayTone( 1047,   14); wait1Msec( 150);  // Note(F, Duration(16th))
		PlayTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
		PlayTone( 1109,   14); wait1Msec( 150);  // Note(F#, Duration(16th))
		PlayTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
		PlayTone( 1398,   14); wait1Msec( 150);  // Note(A#, Duration(16th))
		PlayTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
		PlayTone(  784,   14); wait1Msec( 150);  // Note(C, Duration(16th))
		PlayTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
		PlayTone( 1047,   14); wait1Msec( 150);  // Note(F, Duration(16th))
		PlayTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
		PlayTone( 1109,   14); wait1Msec( 150);  // Note(F#, Duration(16th))
		PlayTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
		PlayTone( 1398,   14); wait1Msec( 150);  // Note(A#, Duration(16th))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(  880,  108); wait1Msec(1200);  // Note(D, Duration(Half))
		PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
		PlayTone( 1398,   14); wait1Msec( 150);  // Note(A#, Duration(16th))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(  831,  108); wait1Msec(1200);  // Note(C#, Duration(Half))
		PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
		PlayTone( 1398,   14); wait1Msec( 150);  // Note(A#, Duration(16th))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(  784,  108); wait1Msec(1200);  // Note(C, Duration(Half))
		PlayTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
		PlayTone(  932,   14); wait1Msec( 150);  // Note(A#5, Duration(16th))
		PlayTone(  784,   14); wait1Msec( 150);  // Note(C, Duration(16th))
	}
}

task main()
{
	initializeRobot();

	waitForStart(); // Wait for the beginning of autonomous phase.

	//StartTask(playMusic);

	//- = up on lift

	motor[liftA] = 100;
	motor[liftB] = 100;
	wait1Msec(2800);
	motor[liftA] = 0;
	motor[liftB] = 0;

	driveForward(1100);

	servo[cubeLiftServoA] = ServoValue[cubeLiftServoA] + 86;
	servo[cubeLiftServoB] = ServoValue[cubeLiftServoB] - 86;

	wait1Msec(1000);

	//possibly lower arm se depende

	driveBackward(200);

	driveLeft(1800);

	motor[liftA] = -100;
	motor[liftB] = -100;
	wait1Msec(1700);
	motor[liftA] = 0;
	motor[liftB] = 0;

	servo[cubeLiftServoA] = highAValue;
	wait1Msec(600);
	servo[cubeLiftServoB] = highBValue;
	wait1Msec(600);

	driveForward(800);
	rotate(600, false);
	driveForward(1900);

	while(true){

	}
}
