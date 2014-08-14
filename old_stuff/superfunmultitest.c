#pragma config(Sensor, S1,     HTSMUX,              sensorI2CCustom)

#include "hitechnic-sensormux.h"
#include "hitechnic-irseeker-v2.h"
#include "lego-light.h"

#define irSensor             msensor_S1_1
#define liteSensor          msensor_S1_2

task main(){
	while(true){
		nxtDisplayTextLine(1, "%d", HTIRS2readACDir(irSensor));
		nxtDisplayTextLine(2, "%d", LSvalRaw(liteSensor));
	}
}
