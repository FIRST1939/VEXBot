#include "main.h"
#include <string>

#include "constants.h"

/**
Screen setup and pre ran funtions
 */
void initialize () { 
	
	pros::lcd::initialize(); 
	pros::lcd::set_background_color(57, 255, 20);

	pros::lcd::print(0, "LIVE MAS");
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
	touchBar();
}

/**
Driver control
 */
void opcontrol () {


	pros::Controller controller(pros::E_CONTROLLER_MASTER);

	while (true) {
		// tankDrive(controller);
		arcadeDrive(controller);
		runCatapult(controller);
		
		pros::delay(2);	
	}
}



void touchBar() {
	LF = 127;
	LM = 127;
	LR = 127;
	RF = -127;
	RM = -127;
	RR = -127;

	pros::delay(2000);	

	LF = 0;
	LM = 0;
	LR = 0;
	RF = 0;
	RM = 0;
	RR = 0;
}

void arcadeDrive(pros::Controller controller) {
	LF = -(controller.get_analog(ANALOG_LEFT_Y) + controller.get_analog(ANALOG_RIGHT_X));
	LM = -(controller.get_analog(ANALOG_LEFT_Y) + controller.get_analog(ANALOG_RIGHT_X));
	LR = -(controller.get_analog(ANALOG_LEFT_Y) + controller.get_analog(ANALOG_RIGHT_X));
	RF = (controller.get_analog(ANALOG_LEFT_Y) - controller.get_analog(ANALOG_RIGHT_X));
	RM = (controller.get_analog(ANALOG_LEFT_Y) - controller.get_analog(ANALOG_RIGHT_X));
	RR = (controller.get_analog(ANALOG_LEFT_Y) - controller.get_analog(ANALOG_RIGHT_X));
}

void tankDrive(pros::Controller controller) {
	LF = controller.get_analog(ANALOG_LEFT_Y);
	LM = controller.get_analog(ANALOG_LEFT_Y);
	LR = controller.get_analog(ANALOG_LEFT_Y);
	RF = -controller.get_analog(ANALOG_RIGHT_Y);
	RM = -controller.get_analog(ANALOG_RIGHT_Y);
	RR = -controller.get_analog(ANALOG_RIGHT_Y);
}

void runCatapult(pros::Controller controller) {
	if (controller.get_digital(DIGITAL_X)) {
		CATAPULT = 100;
	} else {
		CATAPULT = 0;
	}
}
