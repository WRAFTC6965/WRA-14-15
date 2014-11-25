//
//Drive Variables
//

int powerDeadband = 10;  							//set deadband value for power joystick
int turnDeadband = 10	;								//set deadband value for offset joystick
motorDrive leftDrive;									//creates motorDrive variables for left drive motors
motorDrive rightDrive;								//creates motorDrive variables for right drive motors

//
//Drive Functions
//

int skim(int thing)		//for use in motorOutputs:if abs(motorValue) is greater than 100, skim off the difference and subtract it from the opposite motor
{
	if (thing>100)
		return -((thing - 100));
	else if (thing < -100)
		return -((thing + 100));
	return 0;
}

int motorOutputs(int powerIn, int turnIn)
{
int throttleOut = (abs(powerIn) > powerDeadband) ? (100 * pow((powerIn / 100),3)) : ( 0 );
int turnOut = (abs(turnIn) > turnDeadband) ? (50 * pow((turnIn / 100),3)) : ( 0 );
	//combines power, offset, and skim function to get motor output values
	leftDrive.motorGoal = throttleOut + turnOut + skim(throttleOut - turnOut);
	rightDrive.motorGoal = throttleOut - turnOut + skim(throttleOut + turnOut);
	return leftDrive.motorGoal;
	return rightDrive.motorGoal;
}

//
//Drive tasks
//

task driveController()
{
	getJoystickSettings(joystick);
	motorOutputs(joystick.joy1_y1, joystick.joy1_x2);
	leftDrive.motorGoal = motor[motorD] = motor[motorE];
	rightDrive.motorGoal = motor[motorF] = motor[motorG];
	wait1Msec(100);
}
