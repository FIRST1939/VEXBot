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

        void arcadeDrive (int analogSpeed, int analogRotation);
        void curvatureDrive (int analogSpeed, int analogRotation);
        void tankDrive (int leftAnalogSpeed, int rightAnalogSpeed);
        void driveStraight (double inches);
        void turn (double degrees);
};

void Drivetrain::arcadeDrive (int analogSpeed, int analogRotation) {

    double speed = analogSpeed / 127.0;
    double rotation = -0.5 * analogRotation / 127.0;

    double left = rotation - speed;
	double right = rotation + speed;
			
	if (std::max(std::abs(left), std::abs(right)) > 1.0) {

		left /= std::max(std::abs(left), std::abs(right));
		right /= std::max(std::abs(left), std::abs(right));
	}

    this -> left_speed = -left;
    this -> right_speed = -right;

	this -> front_left_motor.move(-left * 127.0);
    this -> front_right_motor.move(-right * 127.0);
    this -> back_left_motor.move(-left * 127.0);
    this -> back_right_motor.move(-right * 127.0);
}

void Drivetrain::curvatureDrive (int analogSpeed, int analogRotation) {

    double speed = analogSpeed / 127.0;
    double rotation = analogRotation / 127.0;

    double leftSpeed = speed - rotation;
    double rightSpeed = speed + rotation;

    if (std::max(std::abs(leftSpeed), std::abs(rightSpeed)) > 1.0) {

        leftSpeed /= std::max(std::abs(leftSpeed), std::abs(rightSpeed));
        rightSpeed /= std::max(std::abs(leftSpeed), std::abs(rightSpeed));
    }

    this -> left_speed = leftSpeed;
    this -> right_speed = rightSpeed;

    this -> front_left_motor.move(leftSpeed * 127.0);
    this -> front_right_motor.move(rightSpeed * 127.0);
    this -> back_left_motor.move(leftSpeed * 127.0);
    this -> back_right_motor.move(rightSpeed * 127.0);
}

void Drivetrain::tankDrive (int leftAnalogSpeed, int rightAnalogSpeed) {

    double leftSpeed = leftAnalogSpeed / 127.0;
    double rightSpeed = rightAnalogSpeed / 127.0;

    this -> left_speed = leftSpeed;
    this -> right_speed = rightSpeed;

    this -> front_left_motor.move(leftSpeed * 127.0);
    this -> front_right_motor.move(rightSpeed * 127.0);
    this -> back_left_motor.move(leftSpeed * 127.0);
    this -> back_right_motor.move(rightSpeed * 127.0);
}

void Drivetrain::driveStraight (double inches) {
    
    double rotations = inches / (AutonomousConstants::wheel_diameter * std::atan(1.0) * 4.0);
    int encoderClicks = rotations * 900;

    this -> front_left_motor.move_relative(encoderClicks, AutonomousConstants::maximum_rpm);
    this -> front_right_motor.move_relative(-encoderClicks, AutonomousConstants::maximum_rpm);
    this -> back_left_motor.move_relative(encoderClicks, AutonomousConstants::maximum_rpm);
    this -> back_right_motor.move_relative(-encoderClicks, AutonomousConstants::maximum_rpm);

    while (this -> front_left_motor.get_actual_velocity() != 0.0) { pros::delay(10); }
}

void Drivetrain::turn (double degrees) {

    double arcLength = degrees / 360.0;
    double distanceTraveled = arcLength * AutonomousConstants::track_width * std::atan(1.0) * 4.0;

    double rotations = distanceTraveled / (AutonomousConstants::wheel_diameter * std::atan(1.0) * 4.0);
    int encoderClicks = rotations * 900;

    this -> front_left_motor.move_relative(encoderClicks, AutonomousConstants::maximum_rpm);
    this -> front_right_motor.move_relative(encoderClicks, AutonomousConstants::maximum_rpm);
    this -> back_left_motor.move_relative(encoderClicks, AutonomousConstants::maximum_rpm);
    this -> back_right_motor.move_relative(encoderClicks, AutonomousConstants::maximum_rpm);

    while (this -> front_left_motor.get_actual_velocity() != 0.0) { pros::delay(10); }
}
