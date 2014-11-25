#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S2_C1_1,     motorF,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S2_C1_2,     motorG,        tmotorTetrix, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  	// Include joystick driver.
#include "Variables.h" 				// Include file with multi-use variable structs.
#include "Drive.h"						// Include file with relevant drive variables, functions, and tasks.
#include "Lift.h" 						// Include file with relevant elevator variables, functions, and tasks.
#include "Watchdog.h" 				// Include Watchdog file

void initializeRobot()
{
	// Place code here to initialize servos to starting positions.
	// Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

	return;
}

task main()
{
	initializeRobot(); 						// robot initialization routine
	waitForStart();								// wait for start of tele-op phase
	//StartTask(watchdog); 				// start Watchdog
	StartTask(driveController); 	// open driveController task from Drive.c
	//StartTask(liftController); 	// open liftController task from Lift.c
}
