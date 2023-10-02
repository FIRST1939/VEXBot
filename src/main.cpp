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

		/*
		LeftFront = -controller.get_analog(ANALOG_LEFT_Y) - controller.get_analog(ANALOG_RIGHT_X);
		LeftMiddle = -controller.get_analog(ANALOG_LEFT_Y) - controller.get_analog(ANALOG_RIGHT_X);
		LeftRear = -controller.get_analog(ANALOG_LEFT_Y) - controller.get_analog(ANALOG_RIGHT_X);
		RightFront = controller.get_analog(ANALOG_LEFT_Y) + controller.get_analog(ANALOG_RIGHT_X);
		RightMiddle = controller.get_analog(ANALOG_LEFT_Y) + controller.get_analog(ANALOG_RIGHT_X);
		RightRear = controller.get_analog(ANALOG_LEFT_Y) + controller.get_analog(ANALOG_RIGHT_X);
		*/


		LeftFront = -controller.get_analog(ANALOG_LEFT_Y);
		LeftMiddle = -controller.get_analog(ANALOG_LEFT_Y);
		LeftRear = -controller.get_analog(ANALOG_LEFT_Y);
		RightFront = controller.get_analog(ANALOG_RIGHT_Y);
		RightMiddle = controller.get_analog(ANALOG_RIGHT_Y);
		RightRear = controller.get_analog(ANALOG_RIGHT_Y);


		pros::delay(2);	
	}
}
