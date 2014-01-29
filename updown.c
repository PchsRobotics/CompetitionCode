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

task main()
{
	while (true){
		if(nNxtButtonPressed == 1)                        // if the current pressed button is 1 (the Right Arrow):
		{
			motor[liftA] = 100;
			motor[liftB] = 100;
		}
		else if(nNxtButtonPressed == 2)                        // if the current pressed button is 2 (the left Arrow):
		{
			motor[liftA] = -100;
			motor[liftB] = -100;
		}
		else{
			motor[liftA] = 0;
			motor[liftB] = 0;
		}
	}
}
