#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     LeftFront,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     LeftBack,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C1_1,     RightFront,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     RightBack,     tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"	 //Include file to "handle" the Bluetooth messages.
int powerDeadzone= 10;
int turnDeadzone = 10;
void initializeRobot()
{
	return;
}
task main()
{
	initializeRobot();
	waitForStart();
	while (true)
	{
		{
			getJoystickSettings(joystick);

		int power= (abs(joystick.joy1_y1)>powerDeadzone)?joystick.joy1_y1:0;
		int turn= (abs(joystick.joy1_x2)>turnDeadzone)?joystick.joy1_x2:0;
			int left= power - turn;
			int right= power + turn;
			motor[RightFront]= right;
			motor[RightBack]= right;
			motor[LeftFront]= left;
			motor[LeftBack]= left;
		}

	}
}
