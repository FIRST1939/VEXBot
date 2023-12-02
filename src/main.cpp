#include "main.h"
#include "robot.h"

// TODO set controller style here
Drivetrain drivetrain = Drivetrain(DriveType::ARCADE);
Triball triball = Triball();


/**
Screen setup and pre ran funtions
 */
void initialize () { 
	
	pros::lcd::initialize(); 
	pros::lcd::set_background_color(57, 255, 20);

	pros::lcd::print(0, "Calibrating...");

	// TODO need to test this.. potential risk of infinite loop if pros::delay stops calibration
	// feel free to comment out if doesn't work or is hanging up
	pros::delay(3000);
	// while (inertial.is_calibrating()) {
	// 	pros::delay(100)
	// }

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
