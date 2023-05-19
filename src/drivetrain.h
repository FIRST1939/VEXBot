#include "main.h"
#include <string>

#include "constants.h"

class Drivetrain {

    private:
        pros::Motor front_left_motor = pros::Motor(DrivetrainConstants::front_left_motor);
        pros::Motor front_right_motor = pros::Motor(DrivetrainConstants::front_right_motor);
        pros::Motor back_left_motor = pros::Motor(DrivetrainConstants::back_left_motor);
        pros::Motor back_right_motor = pros::Motor(DrivetrainConstants::back_right_motor);
    
    public:
        double left_speed = 0.0;
        double right_speed = 0.0;

        void arcadeDrive (int analogSpeed, int analogRotation, std::string scaling_mode);
        void driveStraight (double inches);
};

void Drivetrain::arcadeDrive (int analogSpeed, int analogRotation, std::string scaling_mode) {

    double speed = analogSpeed / 127.0;
    double rotation = -0.5 * analogRotation / 127.0;

    double left = rotation - speed;
	double right = rotation + speed;

	if (scaling_mode.compare("Differential") == 0) {

		if (std::abs(left) > 1.0) {

			right = ((right > 0) - (right < 0)) * (std::abs(right) - (std::abs(left) - 1.0));
			left = ((left > 0) - (left < 0));
		} else if (std::abs(right) > 1.0) {

			left = ((left > 0) - (left < 0)) * (std::abs(left) - (std::abs(right) - 1.0));
			right = ((right > 0) - (right < 0));
		}
	} else {
			
		if (std::max(std::abs(left), std::abs(right)) > 1.0) {

		left /= std::max(std::abs(left), std::abs(right));
		right /= std::max(std::abs(left), std::abs(right));
		}
	}

    this -> left_speed = -left;
    this -> right_speed = -right;

	this -> front_left_motor.move(-left * 127.0);
    this -> front_right_motor.move(-right * 127.0);
    this -> back_left_motor.move(-left * 127.0);
    this -> back_right_motor.move(-right * 127.0);
}

void Drivetrain::driveStraight (double inches) {
    
    double rotations = inches / (16.0 * std::atan(1.0));
    int encoderClicks = rotations * 900;

    this -> front_left_motor.move_relative(encoderClicks, 110);
    this -> front_right_motor.move_relative(-encoderClicks, 110);
    this -> back_left_motor.move_relative(encoderClicks, 110);
    this -> back_right_motor.move_relative(-encoderClicks, 110);
}
