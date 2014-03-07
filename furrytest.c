#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S2,     lightR,         sensorLightInactive)
#pragma config(Sensor, S3,     lightL,         sensorLightInactive)
#pragma config(Motor,  mtr_S1_C1_1,     fr,            tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     fl,            tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     bl,            tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     br,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     liftA,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     liftB,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C4_1,     holder,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     flagspinner,   tmotorTetrix, openLoop)
task main()
{
motor[fl]  = 100;

wait1Msec(1000);

motor[fl] = 0;
}
