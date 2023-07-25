#include "main.h"
#include <string>

#include "constants.h"

/**
Screen setup and pre ran funtions
 */
void initialize () { 
	
	pros::lcd::initialize(); 
	pros::lcd::set_background_color(57, 255, 20);

	pros::lcd::print(0, "Running better code than Carlos");
	//pros::lcd::print(7, "  1.           2.            3.");
}

/**
diabled screen output
 */
void disabled() {}

/**
Comp intialization
 */
void competition_initialize() {}

/**
Auto code runs here
 */
void autonomous() {

	// Drivetrain drivetrain;

	// for (int i = 0; i < 4; i++) {

	// 	drivetrain.driveStraight(12);
	// 	pros::delay(2000);

	// 	drivetrain.turn(90);
	// 	pros::delay(2000);
	// }
}

/**
Driver control
 */
void opcontrol () 
{

	while (true)
	 {
		//Tank drive 
		LF = -controller.get_analog(ANALOG_LEFT_Y);
		LR = -controller.get_analog(ANALOG_LEFT_Y);
		RF = controller.get_analog(ANALOG_RIGHT_Y);
		RR = controller.get_analog(ANALOG_RIGHT_Y);

		//Intake operation
		if (controller.get_digital(DIGITAL_R1))
		{
			Intake = 127;
		}
		else if(controller.get_digital(DIGITAL_R2))
		{
			Intake = -127;
		}
		else 
		{
			Intake = 0;
		}

		//Shooter operation
		if (controller.get_digital(DIGITAL_L1))
		{
			Shooter = 127;
		}
		else if(controller.get_digital(DIGITAL_L2))
		{
			Shooter = -127;
		}
		else 
		{
			Shooter = 0;
		}
		pros::delay(25);

	
	}
}
