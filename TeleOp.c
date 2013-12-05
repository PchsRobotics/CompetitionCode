#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     br,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     fr,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     bl,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     fl,            tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     chassisLiftA,  tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     chassisLiftB,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     blockLift,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     sweeperMotor,  tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S2_C1_1,    cubeLiftServo,        tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Motor config

////////////////////////////////Current pchs teleop code 12/3/2013

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "ButtonsDefs.h"  //Buttons definitions

const float MAX_JOYSTICK = 128.0;//used to scale joystick vectors out of 1

void initializeRobot()//initialize
{
	return;
}

int scaleJoystick(int n){
	if(n < 20 && n > -20){
		return 0;
	}

	return (n / MAX_JOYSTICK)	*  100; //scale the joysticks out of 100 rather than 128
}


task main()
{
	bool driveIsAtHalfPower = false; //If true half motor power UNIMPLEMENTED
	bool sweeperIsOn = true;  //If true run sweeper motor

	int delta = 2;                        // Create int 'delta' to the be Servo Change Rate.

	initializeRobot();

	waitForStart();   // wait for start of tele-op phase

	while (true)
	{
		getJoystickSettings(joystick);

		servoChangeRate[cubeLiftServo] = delta;          // Slow the Servo Change Rate down to only 'delta' positions per update.

		//toggle sweeper power
		if(joystick.joy1_Buttons == button_a){
			sweeperIsOn = true;
		}
		else if(joystick.joy1_Buttons == button_b){
			sweeperIsOn = false;
		}

		if(sweeperIsOn){
			motor[sweeperMotor] = 100;
		}
		else{
			motor[sweeperMotor] = 0;
		}

		//rotate left
		if(joystick.joy1_Buttons == button_left_button){
			motor[fr] = 100;
			motor[fl] = -100;
			motor[br] = 100;
			motor[bl] = -100;
		}

		// rotate right
		else if(joystick.joy1_Buttons == button_right_button){
			motor[fr] = -100;
			motor[fl] = 100;
			motor[br] = -100;
			motor[bl] = 100;
		}
		//put in a way to limit max motor power -- either 25% or 100%
		if(joystick.joy1_Buttons == button_left_trigger ){
			driveIsAtHalfPower = true;

		}
		if(joystick.joy1_Buttons == button_right_trigger ){
			driveIsAtHalfPower = false;

		}
		//end  max motor power scaling

		//Lift the chassis
		if(joystick.joy1_TopHat == pov_east){
			motor[chassisLiftA] = 100;
			motor[chassisLiftB] = 100;
		}
		else if (joystick.joy1_TopHat == pov_west){
			motor[chassisLiftA] = -100;
			motor[chassisLiftB] = -100;
		}
		else{
			motor[chassisLiftA] = 0;
			motor[chassisLiftB] = 0;
		}

		//Control the block lift
		//Implement touch sensor limit
		if(joystick.joy1_TopHat == pov_north){
			motor[blockLift] = 100;
		}
		else if(joystick.joy1_TopHat == pov_south){
			motor[blockLift] = -100;
		}
		else{
			motor[blockLift] = 0;
		}

		//Servo dump block load
		if(joystick.joy1_Buttons == button_x){
			if(ServoValue[cubeLiftServo] < 128)              // If cubeLiftServo is closer to 0 (than 255):
			{
				while(ServoValue[cubeLiftServo] < 255)               // While the ServoValue of cubeLiftServo is less than 255:
				{
					servo[cubeLiftServo] = 255;                              // Move cubeLiftServo to position to 255.
				}
			}

			wait1Msec(1000);                          // Wait 1 second.

			if(ServoValue[cubeLiftServo] >= 128)             // If cubeLiftServo is closer to 255 (than 0):
			{
				while(ServoValue[cubeLiftServo] > 0)                 // While the ServoValue of cubeLiftServo is greater than 0:
				{
					servo[cubeLiftServo] = 0;                                // Move cubeLiftServo to position to 0.
				}
			}

			wait1Msec(1000);                          // Wait 1 second.
		}

		int y_vals = scaleJoystick(joystick.joy1_y1);
		int x_vals = scaleJoystick(joystick.joy1_x1);

		///////////////Start derp math
		motor[fl] = x_vals + y_vals;
		motor[br] = x_vals + y_vals;

		motor[fr] = y_vals - x_vals;
		motor[bl] = y_vals - x_vals;
		/////////////////End derp math
	}
}
