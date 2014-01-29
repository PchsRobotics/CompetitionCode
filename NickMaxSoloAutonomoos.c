#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Hubs,  S3, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S4, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     fl,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     bl,            tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S3_C1_1,     fr,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_2,     br,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_1,     liftA,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_2,     liftB,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C2_1,     sweeper,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C2_2,     spinner,       tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    cubeLiftServoA,       tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    cubeLiftServoB,       tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "HolonomicAutonomousDrives.c"

void initializeRobot()
{
	servo[cubeLiftServoA] = ServoValue[cubeLiftServoA] - 16;
	servo[cubeLiftServoB] = ServoValue[cubeLiftServoB] + 16;

	wait1Msec(50);

	return;
}


task main()
{
	initializeRobot();

	//waitForStart(); // Wait for the beginning of autonomous phase.

	PlaySound(soundBeepBeep);

	//- = up

	motor[liftA] = -100;
	motor[liftB] = -100;
	wait1Msec(2500);
	motor[liftA] = 0;
	motor[liftB] = 0;

	//driveRight(2700);
}
