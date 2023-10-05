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
void opcontrol () {


	pros::Controller controller(pros::E_CONTROLLER_MASTER);

	while (true) {
		
		/* my name is Zahra */

		/*
		LF = -controller.get_analog(ANALOG_LEFT_Y);
		LM = -controller.get_analog(ANALOG_LEFT_Y);
		LR = -controller.get_analog(ANALOG_LEFT_Y);
		RF = controller.get_analog(ANALOG_RIGHT_Y);
		RM = controller.get_analog(ANALOG_RIGHT_Y);
		RR = controller.get_analog(ANALOG_RIGHT_Y);
		*/

		CATAPULT =controller.get_analog(ANALOG_LEFT_Y);

		pros::delay(2);

		
		//pros::lcd::print(1, ": %f", drivetrain.right_speed);
	
	}
}
