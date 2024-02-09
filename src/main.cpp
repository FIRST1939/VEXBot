#include "main.h"
#include <string>

#include "constants.h"


void touchBar() {
	LF = 127;
	LR = 127;
	RF = -127;
	RR = -127;

	pros::delay(1800);	

	LF = 0;
	LR = 0;
	RF = 0;
	RR = 0;
}


void triball(){
	LF = 90;
	LR = 90;
	RF = -90;
	RR = -90;

	pros::delay(1000);
	INTAKE = -127; 	
	PISTON.set_value (true);

	pros::delay(500);
	LF = 0;
	LR = 0;
	RF = 0;
	RR = 0;
	INTAKE = 0;

	pros::delay(500);
	LF = 90;
	LR = 90;
	RF = 90;
	RR = 90;

	pros::delay(250);
	LF = 90;
	LR = 90;
	RF = -90;
	RR = -90; 

	pros::delay(2000);
	LF = 0;
	LR = 0;
	RF = 0;
	RR = 0;
}


void fly(){
	FLYWHEEL = 127;
}

void arcadeDrive(pros::Controller controller) {
	LF = -(controller.get_analog(ANALOG_LEFT_Y) + controller.get_analog(ANALOG_RIGHT_X));
	LR = -(controller.get_analog(ANALOG_LEFT_Y) + controller.get_analog(ANALOG_RIGHT_X));
	RF = (controller.get_analog(ANALOG_LEFT_Y) - controller.get_analog(ANALOG_RIGHT_X));
	RR = (controller.get_analog(ANALOG_LEFT_Y) - controller.get_analog(ANALOG_RIGHT_X));
}

void tankDrive(pros::Controller controller) {
	LF = controller.get_analog(ANALOG_LEFT_Y);
	LR = controller.get_analog(ANALOG_LEFT_Y);
	RF = -controller.get_analog(ANALOG_RIGHT_Y);
	RR = -controller.get_analog(ANALOG_RIGHT_Y);
}

/*
void runCatapult(pros::Controller controller) {
	if (controller.get_digital(DIGITAL_X)) {
		CATAPULT = 100;
	} else {
		CATAPULT = 0;
	}
}
*/

void runIntake(pros::Controller controller) {
	if (controller.get_digital(DIGITAL_R1)) {
		INTAKE = 127;
	} else {
		if (controller.get_digital(DIGITAL_R2)) {
			INTAKE = -127;
		} else {
			INTAKE = 0;
		}
	}
	
}

void runFlywheel(pros::Controller controller) {
	if (controller.get_digital(DIGITAL_L1)) {
		FLYWHEEL = 127;
	} else {
		if (controller.get_digital(DIGITAL_L2)) {
			FLYWHEEL = -127;
		} else {
			FLYWHEEL = 0;
		}
	}
}

void runWings(pros::Controller controller) {
	if (controller.get_digital(DIGITAL_X) ) {
		PISTON.set_value (true);
	} else { 
		PISTON.set_value (false);
	}

}
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
disabled screen output
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


	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Controller partner(pros::E_CONTROLLER_PARTNER);

	while (true) {
		// tankDrive(controller);
		arcadeDrive(master);
		runIntake(partner);
		runFlywheel(master);
		runWings (partner);
		pros::delay(2);	
	}
}

