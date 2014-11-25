typedef struct{
	int motorGoal;					//goal motor setting
	int motorOld;						//last motor command
	int deltaLimit;					//limit acceleration(set to 200 to disable)
	int motorOut;						//command to output to motor
}motorDrive;
