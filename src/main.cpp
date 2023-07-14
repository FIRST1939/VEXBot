#include "main.h"
#include <string>

#include "drivetrain.h"
std::string drive_control = "Arcade";

void switch_drive_control () {

    if (drive_control.compare("Arcade") == 0) {

        drive_control = "Curvature";
        pros::lcd::print(4, "1) Drive Control: Curvature");
    } else if (drive_control.compare("Curvature") == 0) {

        drive_control = "Tank";
        pros::lcd::print(4, "1) Drive Control: Tank");
    } else {

        drive_control = "Arcade";
        pros::lcd::print(4, "1) Drive Control: Arcade");
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
	pros::lcd::print(4, "1) Drive Control: Arcade");
	pros::lcd::print(7, "  1.           2.            3.");

	pros::lcd::register_btn0_cb(switch_drive_control);
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

	for (int i = 0; i < 4; i++) {

		drivetrain.driveStraight(12);
		pros::delay(2000);

		drivetrain.turn(90);
		pros::delay(2000);
	}
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

        if (drive_control.compare("Arcade") == 0) {

            drivetrain.arcadeDrive(
                controller.get_analog(ANALOG_LEFT_Y), 
                controller.get_analog(ANALOG_RIGHT_X)
            );
        } else if (drive_control.compare("Tank") == 0) {

            drivetrain.tankDrive(
                controller.get_analog(ANALOG_LEFT_Y), 
                controller.get_analog(ANALOG_RIGHT_Y)
            );
        } else {

            drivetrain.curvatureDrive(
                controller.get_analog(ANALOG_LEFT_Y), 
                controller.get_analog(ANALOG_RIGHT_X)
            );
        }

		pros::lcd::print(1, "Left Speed: %f", drivetrain.left_speed);
		pros::lcd::print(2, "Right Speed: %f", drivetrain.right_speed);
		pros::delay(20);
	}
}
