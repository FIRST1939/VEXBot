#include "main.h"

#include "constants.h"
#include "robot.h"

Drivetrain drivetrain(DriveType::ARCADE);
Triball triball();


/**
Screen setup and pre ran funtions
 */
void initialize () { 
	
	pros::lcd::initialize(); 
	pros::lcd::set_background_color(57, 255, 20);

	pros::lcd::print(0, "Calibrating...");

	// TODO potential risk of infinite loop if pros::delay stops calibration...
	pros::delay(3000);
	while (inertial.is_calibrating()) {
		pros::delay(100);
	}

	pros::lcd::print(1, "LIVE MAS 🔔");

	// would be nice for autos?
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

}

/**
Driver control
 */
void opcontrol () {

	while (true) {
		drivetrain.kachow();
		triball.shoot();
		triball.intake();
		triball.plow();
		
		pros::delay(2);	
	}
}
