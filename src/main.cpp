#include "main.h"
#include <string>

#include "drivetrain.h"

/**
Screen setup and pre ran funtions
 */
void initialize () { 
	
	pros::lcd::initialize(); 
	pros::lcd::set_background_color(57, 255, 20);

	pros::lcd::print(0, "Team Astroturf");
	pros::lcd::print(7, "  1.           2.            3.");
}

/**
diabled screen.
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

	Drivetrain drivetrain;

	for (int i = 0; i < 4; i++) {

		drivetrain.driveStraight(12);
		pros::delay(2000);

		drivetrain.turn(90);
		pros::delay(2000);
	}
}

/**
Driver control
 */
void opcontrol () {

	Drivetrain drivetrain;
	pros::Controller controller(pros::E_CONTROLLER_MASTER);

	while (true) {

        drivetrain.drive(
            controller.get_analog(ANALOG_LEFT_Y), 
            controller.get_analog(ANALOG_RIGHT_X),
            controller.get_analog(ANALOG_RIGHT_Y)
        );

		pros::lcd::print(1, "Left Speed: %f", drivetrain.left_speed);
		pros::lcd::print(2, "Right Speed: %f", drivetrain.right_speed);
		pros::delay(20);
	}
}
