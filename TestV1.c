#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    ExpanderBattery, sensorAnalog)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           armMotorL2,    tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           leftMotorR,    tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port3,           leftMotorF,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           intakeMotor,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           armMotorL1,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           armMotorR1,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           clawMotor,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           rightMotorF,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           rightMotorR,   tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port10,          armMotorR2,    tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)
#include "Vex_Competition_Includes.c"
//Function-variable creation begin
float dist;//distance, used by encoded movement functions
int auton = 1;//used to select automomous code with a switch-case
int ExpanderBatteryLevel = 0;//used to display battery level of power expander, always displays "replace" for some reason
bool batteryLCDBool = true;//used to select which battery level is displayed, defaults to primary
void clear(){//resets encoders
	nMotorEncoder[leftMotorR] = 0;
	nMotorEncoder[rightMotorR] = 0;
}
void halt(){//stops all movement
	motor[leftMotorF] = 0;
	motor[leftMotorR] = 0;
	motor[rightMotorF] = 0;
	motor[rightMotorR] = 0;
	motor[armMotorL1] = 0;
	motor[armMotorL2] = 0;
	motor[armMotorR1] = 0;
	motor[armMotorR2] = 0;
	motor[clawMotor] = 0;
	motor[intakeMotor] = 0;
}
void forward(int cm, int speed = 63){//forward for designated distance
	clear();
	dist = cm / 19.9580298637;
	while (nMotorEncoder[leftMotorR]>-dist && nMotorEncoder[rightMotorR]<dist){
		motor[leftMotorF] = speed;
		motor[leftMotorR] = speed;
		motor[rightMotorF] = speed;
		motor[rightMotorR] = speed;
	}
	motor[armMotorL1] = 0;
	motor[armMotorL2] = 0;
	motor[armMotorR1] = 0;
	motor[armMotorR2] = 0;
	halt();
}
void backward(int cm, int speed = 63){//see above, but moves backwards
	clear();
	dist = cm / 19.9580298637;
	while (nMotorEncoder[leftMotorR]>-dist && nMotorEncoder[rightMotorR]<dist){
		motor[leftMotorF] = -speed;
		motor[leftMotorR] = -speed;
		motor[rightMotorF] = -speed;
		motor[rightMotorR] = -speed;
	}
}
void backwardTime(int time, int speed){//moves backward for a time, not a distance
	motor[leftMotorF] = -speed;
	motor[leftMotorR] = -speed;
	motor[rightMotorF] = -speed;
	motor[rightMotorR] = -speed;
	wait1Msec(time);
}
void left(int speed = 63, int cm = 0){//moves left for a designated distance
	clear();
	if (cm == 0){
		motor[rightMotorF] = speed;
		motor[rightMotorR] = -speed;
		motor[leftMotorF] = -speed;
		motor[leftMotorR] = speed;
	}
	else{
		dist = cm / 19.9580298637;
		while(nMotorEncoder[leftMotorR]<dist && nMotorEncoder[rightMotorR]<dist){
			motor[rightMotorF] = speed;
			motor[rightMotorR] = -speed;
			motor[leftMotorF] = -speed;
			motor[leftMotorR] = speed;
		}
		halt();
	}
	clear();
}
void right(int speed = 63, float cm = 0){//see above, but moves right
	clear();
	if (cm == 0){
		motor[rightMotorF] = -speed;
		motor[rightMotorR] = speed;
		motor[leftMotorF] = speed;
		motor[leftMotorR] = -speed;
	}
	else{
		dist = cm / 19.9580298637;
		while (nMotorEncoder[leftMotorR]<dist && nMotorEncoder[rightMotorR]<dist){
			motor[rightMotorF] = -speed;
			motor[rightMotorR] = speed;
			motor[leftMotorF] = speed;
			motor[leftMotorR] = -speed;
		}
		halt();
	}
	clear();
}
void turnLeftPlace(int cm, int speed = 127){//turns left in one place
	clear();
	dist = cm / 19.9580298637;
	while (nMotorEncoder[leftMotorR]<dist && nMotorEncoder[rightMotorR]<dist){
		motor[leftMotorF] = -speed;
		motor[leftMotorR] = -speed;
		motor[rightMotorF] = speed;
		motor[rightMotorR] = speed;
	}
	motor[armMotorL1] = 0;
	motor[armMotorL2] = 0;
	motor[armMotorR1] = 0;
	motor[armMotorR2] = 0;
	halt();
}
void turnLeftPlaceDegrees(int degrees, int speed = 127){//turns left in one place
	clear();
	dist = (degrees * 8.48230016469);
	while (nMotorEncoder[leftMotorR]<dist && nMotorEncoder[rightMotorR]<dist){
		motor[leftMotorF] = -speed;
		motor[leftMotorR] = -speed;
		motor[rightMotorF] = speed;
		motor[rightMotorR] = speed;
	}
	motor[armMotorL1] = 0;
	motor[armMotorL2] = 0;
	motor[armMotorR1] = 0;
	motor[armMotorR2] = 0;
	halt();
}
void turnLeftArc(int cm, int speed = 63){//see above, but moves forward while turning
	clear();
	dist = cm / 19.9580298637;
	while (nMotorEncoder[leftMotorR]<(dist/5) && nMotorEncoder[rightMotorR]<dist){
		motor[leftMotorF] = (speed/5);
		motor[leftMotorR] = (speed/5);
		motor[rightMotorF] = speed;
		motor[rightMotorR] = speed;
	}
	motor[armMotorL1] = 0;
	motor[armMotorL2] = 0;
	motor[armMotorR1] = 0;
	motor[armMotorR2] = 0;
	halt();
}
void turnRightPlace(int cm, int speed = 63){//turns right in one place
	clear();
	dist = cm / 19.9580298637;
	while (nMotorEncoder[leftMotorR]>-dist && nMotorEncoder[rightMotorR]>-dist){
		motor[leftMotorF] = speed;
		motor[leftMotorR] = speed;
		motor[rightMotorF] = -speed;
		motor[rightMotorR] = -speed;
	}
	motor[armMotorL1] = 0;
	motor[armMotorL2] = 0;
	motor[armMotorR1] = 0;
	motor[armMotorR2] = 0;
	halt();
}
void turnRightPlaceDegrees(int degrees, int speed = 63){//turns right in one place
	clear();
	dist = (degrees * 8.48230016469);
	while (nMotorEncoder[leftMotorR]>-dist && nMotorEncoder[rightMotorR]>-dist){
		motor[leftMotorF] = speed;
		motor[leftMotorR] = speed;
		motor[rightMotorF] = -speed;
		motor[rightMotorR] = -speed;
	}
	motor[armMotorL1] = 0;
	motor[armMotorL2] = 0;
	motor[armMotorR1] = 0;
	motor[armMotorR2] = 0;
	halt();
}
void turnRightArc(int cm, int speed = 63){//see above, but movesforward while turning
	clear();
	dist = cm / 19.9580298637;
	while (nMotorEncoder[leftMotorR]>-dist && nMotorEncoder[rightMotorR]>-(dist/2)){
		motor[leftMotorF] = speed;
		motor[leftMotorR] = speed;
		motor[rightMotorF] = (speed/2);
		motor[rightMotorR] = (speed/2);
	}
	motor[armMotorL1] = 0;
	motor[armMotorL2] = 0;
	motor[armMotorR1] = 0;
	motor[armMotorR2] = 0;
	halt();
}
void raiseArm(int time, int speed = 63){//raises arm
	motor[armMotorL1] = -speed;
	motor[armMotorL2] = -speed;
	motor[armMotorR1] = -speed;
	motor[armMotorR2] = -speed;
	wait1Msec(time);
}
void lowerArm(int time, int speed = 63){//lowers arm
	motor[armMotorL1] = speed;
	motor[armMotorL2] = speed;
	motor[armMotorR1] = speed;
	motor[armMotorR2] = speed;
	wait1Msec(time);
}
void openClaw(int time, int speed = 63){//opens claw
	motor[clawMotor] = speed;
	wait1Msec(time);
}
void closeClaw(int time,int speed = 63){//closes claw
	motor[clawMotor] = -speed;
	wait1Msec(time);
}
void haltArm(){//stops arm
	motor[armMotorL1] = 0;
	motor[armMotorL2] = 0;
	motor[armMotorR1] = 0;
	motor[armMotorR2] = 0;
}
void raiseIntake(int time){
	motor[intakeMotor] = 127;
	wait1Msec(time);
}
void lowerIntake(int time){
	motor[intakeMotor] = 127;
	wait1Msec(time);
}
void batteryLCD(){//displaysbatterylevels on LCD
	if (time1[T1]%100 == 0){
		switch(batteryLCDBool){
		case true:
			clearLCDLine(0);
			displayLCDString(0, 0, "Primary: ");
			if (nAvgBatteryLevel < 5500){
				displayNextLCDString("Replace");
			}
			else if (nAvgBatteryLevel < 6500){
				displayNextLCDString("Low");
			}
			else{
				displayNextLCDString("Good");
			}
			break;
		case false:
			ExpanderBatteryLevel = SensorValue[ExpanderBattery] / 7;
			clearLCDLine(0);
			displayLCDString(0, 0, "Secondary: ");
			if (ExpanderBatteryLevel < 550){
				displayNextLCDString("Replace");
			}
			else if (ExpanderBatteryLevel < 650){
				displayNextLCDString("Low");
			}
			else{
				displayNextLCDString("Good");
			}
			break;
		}
	}
}//Function-variable creation end
void pre_auton(){//Pre-Autonomous block begin
	clear();
	while (bIfiRobotDisabled){//outputs true when robot is disabled, ends subroutine when autonomous starts
		displayLCDString(1, 0, "<<");
		displayLCDString(1, 14, ">>");
		switch(auton){
		case 1://red autoloader
			displayLCDCenteredString(0, "Red Loader");
			if (nLCDButtons == 1){
				while (nLCDButtons == 1){
				}
				auton = 7;
			}
			else{
			}
			if (nLCDButtons == 4){
				while (nLCDButtons == 4){
				}
				auton = 2;
			}
			else{
			}
			break;
		case 2://red posts
			displayLCDCenteredString(0, "Red Posts");
			if (nLCDButtons == 1){
				while (nLCDButtons == 1){
				}
				auton = 1;
			}
			else{
			}
			if (nLCDButtons == 4){
				while (nLCDButtons == 4){
				}
				auton = 3;
			}
			else{
			}
			break;
		case 3://blue autoloader
			displayLCDCenteredString(0, "Blue Loader");
			if (nLCDButtons == 1){
				while (nLCDButtons == 1){
				}
				auton = 2;
			}
			else{
			}
			if (nLCDButtons == 4){
				while (nLCDButtons == 4){
				}
				auton = 4;
			}
			else{
			}
			break;
		case 4://blue posts
			displayLCDCenteredString(0, "Blue Posts");
			if (nLCDButtons == 1){
				while (nLCDButtons == 1){
				}
				auton = 3;
			}
			else{
			}
			if (nLCDButtons == 4){
				while (nLCDButtons == 4){
				}
				auton = 5;
			}
			else{
			}
			break;
		case 5://Programming skills
			displayLCDCenteredString(0, "Pr Skills");
			if (nLCDButtons == 1){
				while (nLCDButtons == 1){
				}
				auton = 4;
			}
			else{
			}
			if (nLCDButtons == 4){
				while (nLCDButtons == 4){
				}
				auton = 6;
			}
			else{
			}
			break;
		case 6://Worst-case scenario
			displayLCDCenteredString(0, "Worst Case");
			if (nLCDButtons == 1){
				while (nLCDButtons == 1){
				}
				auton = 5;
			}
			else{
			}
			if (nLCDButtons == 4){
				while (nLCDButtons == 4){
				}
				auton = 7;
			}
			else{
			}
			break;
		case 7://testing
			displayLCDCenteredString(0, "Testing");
			if (nLCDButtons == 1){
				while (nLCDButtons == 1){
				}
				auton = 6;
			}
			else{
			}
			if (nLCDButtons == 4){
				while (nLCDButtons == 4){
				}
				auton = 1;
			}
			else{
			}
			break;
		}
	}
}//Pre-autonomous block end
task autonomous(){//Autonomous block begin
	clearLCDLine(1);
	switch(auton){
	case 1://red autoloader
		clearLCDLine(1);
		left(75,10350);   //strafe left
		halt();
		backward(600,100);
		halt();
		closeClaw(400,75);
		raiseArm(300,75);
		halt();
		motor[clawMotor] = 0; //release cube
		wait1Msec(500);
		halt();
		forward(1000,100);
		wait1Msec(200);
		backward(2000,100);
		halt();
		wait1Msec(300);
		turnRightPlace(5300,100);   //line up for section
		halt();
		wait1Msec(200);
		raiseArm(200);
		halt();
		forward(3200);
		halt();
		openClaw(900,75);
		openClaw(0,20);
		forward(4200,100);
		halt();
		closeClaw(200);   //grab skyrise section
		wait1Msec(200);
		backwardTime(0,75);
		raiseArm(200,75);
		halt();
		wait1Msec(200);
		raiseArm(500,75);
		halt();
		wait1Msec(200);
		backward(1000,100);
		halt();
		wait1Msec(200);
		backward(3000,100);
		halt();
		wait1Msec(100);
		turnLeftPlace(14000,50); //line up to base
		halt();
		wait1Msec(300);
		lowerArm(250,25);
		halt();
		wait1Msec(300);
		forward(1700,50);
		halt();
		lowerArm(100);
		halt();
		wait1Msec(500);
		openClaw(500);  //drop section
		halt();
		wait1Msec(500);
		backward(500,75);
		halt();
		break;
	case 2://red posts
		clearLCDLine(1);
		raiseArm(500,100);
		backward(16000,100);
		halt();
		wait1Msec(500);
		turnLeftPlace(6500,75);
		halt();
		wait1Msec(1000);
		lowerArm(1500,75);
		halt();
		break;
	case 3://blue autoloader
		clearLCDLine(1);
		clear();
		raiseArm(2000,100);
		halt();
		lowerArm(1100,100);
		halt();
		wait1Msec(1000);
		right(75,15350);   //strafe right
		wait1Msec(450);
		halt();
		backward(500,100);
		halt();
		lowerArm(700);//release cube
		halt();
		lowerIntake(1100);
		halt();
		wait1Msec(500);
		halt();
		backward(2500,100);
		halt();
		lowerArm(400,100);
		halt();
		wait1Msec(300);
		right(100,12000);
		halt();
		turnLeftPlace(13000,100);   //line up for section
		halt();
		wait1Msec(200);
		forward(11700);
		halt();
		lowerIntake(1300);
		halt();
		right(100,4300);
		halt();
		lowerArm(150,100);
		halt();
		openClaw(900,75);
		openClaw(0,20);
		forward(7800,100); //drive to section
		halt();
		raiseArm(75);
		halt();
		closeClaw(200);   //grab skyrise section
		wait1Msec(200);
		raiseArm(0,100);
		backward(700,100);
		halt();
		backward(8300,100);
		halt();
		raiseArm(300,100);
		halt();
		wait1Msec(200);
		turnRightPlace(16500,50); //line up to base
		halt();
		wait1Msec(300);
		backward(1000,100);
		halt();
		lowerArm(300,100);
		halt();
		lowerArm(550,25);
		halt();
		wait1Msec(300);
		backward(1700,50);
		halt();
		lowerArm(100);
		halt();
		backward(100,50);
		halt();
		forward(300,50);
		halt();
		lowerArm(150,75);
		halt();
		forward(600,65);
		halt();
		wait1Msec(500);
		openClaw(1000);  //drop section
		halt();
		wait1Msec(500);
		backward(500,75);
		halt();
		break;
	case 4://blue posts
		clearLCDLine(1);
		raiseArm(500,100);
		backward(16000,100);
		halt();
		wait1Msec(500);
		turnRightPlace(6500,75);
		halt();
		wait1Msec(1000);
		lowerArm(1500,75);
		halt();
		turnRightPlace(2000,100);
		halt();
		backward(15000,100);
		halt();
		turnRightPlace(30000,100);
		halt();
		break;
	case 5://programming skills
		clearLCDLine(1);
		forward(50000,100);
		break;
	case 6://worst-case scenario
		backward(4000,127);
		halt();
		forward(2000,127);
		halt();
		backward(4000,127);
		halt();
		break;
	case 7:
		clear();
		bLCDBacklight = true;
		motor[leftMotorF] = 75;
		motor[leftMotorR] = 75;
		motor[rightMotorF] = 75;
		motor[rightMotorR] = 75;
		while(true){
			displayLCDString(0, 0, "EncoderL: ");
			displayNextLCDNumber(nMotorEncoder[leftMotorR]);
			displayLCDString(1, 0, "EncoderR: ");
			displayNextLCDNumber(nMotorEncoder[rightMotorR]);
			//displayLCDNumber(1, 3, nMotorEncoder[leftMotorR]);
		}
		break;
	}
	while(bIfiAutonomousMode){//"catch"program while autonomous mode is active to stop auton code from looping
		halt();
	}
}//Autonomous block end
task usercontrol(){//Usercontrol block begin
	clearDebugStream();
	writeDebugStreamLine("Program start");
	clearLCDLine(0);
	bLCDBacklight = true;
	clearTimer(T1);///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*********?????????????????55555555555554Metcowwuzhere.
	while(true){
		batteryLCD();
		if(vexRT[Btn5U] == 1){
			left(127);
		}
		else if(vexRT[Btn6U] == 1){
			right(127);
		}
		else if(vexRT[Btn8U] == 1){
			if(batteryLCDBool == true){
				batteryLCDBool = false;
				wait1Msec(500);
			}
			else if(batteryLCDBool == false){
				batteryLCDBool = true;
				wait1Msec(500);
			}
		}
		else{
			motor[leftMotorF] = vexRT[Ch3];
			motor[leftMotorR] = vexRT[Ch3];
			motor[rightMotorF] = vexRT[Ch2];
			motor[rightMotorR] = vexRT[Ch2];
		}
		motor[armMotorL1] = vexRT[Ch2Xmtr2];
		motor[armMotorL2] = vexRT[Ch2Xmtr2];
		motor[armMotorR1] = vexRT[Ch2Xmtr2];
		motor[armMotorR2] = vexRT[Ch2Xmtr2];
		motor[intakeMotor] = vexRT[Ch3Xmtr2];
		if(vexRT[Btn6UXmtr2] == 1){
			motor[clawMotor] = 75;
		}
		else if(vexRT[Btn6DXmtr2] == 1){
			motor[clawMotor] = -75;
		}
		else{
			motor[clawMotor] = 0;
		}
	}
}
//usercontrol block end
