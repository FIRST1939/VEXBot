#include "main.h"
#include <string>

#include "drivetrain.h"
std::string scaling_mode = "Proportional";

void toggle_scaling_mode () {

	if (scaling_mode.compare("Proportional") == 0) {

		scaling_mode = "Differential";
		pros::lcd::print(4, "1) Turn Scaling: Differential");
	} else {

		scaling_mode = "Proportional";
		pros::lcd::print(4, "1) Turn Scaling: Proportional");
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize () { 
	
	pros::lcd::initialize(); 
	pros::lcd::set_background_color(66, 191, 124);

	pros::lcd::print(0, "FRC 1939 - THE KUHNIGITS");
	pros::lcd::print(4, "1) Turn Scaling: Proportional");
	pros::lcd::print(7, "  1.           2.            3.");

	pros::lcd::register_btn0_cb(toggle_scaling_mode);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {

	Drivetrain drivetrain;
	drivetrain.driveStraight(12);
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol () {

	Drivetrain drivetrain;
	pros::Controller controller(pros::E_CONTROLLER_MASTER);

	while (true) {

		drivetrain.arcadeDrive(
			controller.get_analog(ANALOG_LEFT_Y), 
			controller.get_analog(ANALOG_RIGHT_X), 
			scaling_mode
		);

		pros::lcd::print(1, "Left Speed: %f", drivetrain.left_speed);
		pros::lcd::print(2, "Right Speed: %f", drivetrain.right_speed);
		pros::delay(20);
	}
}
