#include "main.h"
#include <string>

#include "constants.h"

class Drivetrain {

    private:
        pros::MotorGroup left_motor_group = pros::MotorGroup({DrivetrainConstants::front_left_motor, DrivetrainConstants::back_left_motor});
        pros::MotorGroup right_motor_group = pros::MotorGroup({DrivetrainConstants::front_right_motor, DrivetrainConstants::back_right_motor});

        DriveControl drive_control = DrivetrainConstants::drive_control;
        bool square_inputs = DrivetrainConstants::square_inputs;
    
    public:
        double left_speed = 0.0;
        double right_speed = 0.0;

        void drive (int analogOne, int analogTwo);
        void arcadeDrive (int analogSpeed, int analogRotation);
        void curvatureDrive (int analogSpeed, int analogRotation);
        void tankDrive (int leftAnalogSpeed, int rightAnalogSpeed);

        void driveStraight (double inches);
        void turn (double degrees);
};

void Drivetrain::drive (int analogOne, int analogTwo) {

    double one = analogOne / 127.0;
    double two = analogTwo / 127.0;

    if (this -> square_inputs) {

        one *= std::abs(one);
        two *= std::abs(two);
    }

    int adjustedAnalogOne = one * 127.0;
    int adjustedAnalogTwo = two * 127.0;

    
}


void Drivetrain::tankDrive (int leftAnalogSpeed, int rightAnalogSpeed) {

    double leftSpeed = leftAnalogSpeed / 127.0;
    double rightSpeed = rightAnalogSpeed / 127.0;

    this -> left_speed = leftSpeed;
    this -> right_speed = rightSpeed;
    this -> left_motor_group.move(leftSpeed * 127.0);
    this -> right_motor_group.move(-rightSpeed * 127.0);
}

void Drivetrain::driveStraight (double inches) {
    
    double rotations = inches / (AutonomousConstants::wheel_diameter * std::atan(1.0) * 4.0);
    int encoderClicks = rotations * 900;

    this -> left_motor_group.move_relative(encoderClicks, AutonomousConstants::maximum_rpm);
    this -> right_motor_group.move_relative(-encoderClicks, AutonomousConstants::maximum_rpm);
    while (this -> left_motor_group.get_actual_velocities()[0] != 0.0) { pros::delay(10); }
}

void Drivetrain::turn (double degrees) {

    double arcLength = degrees / 360.0;
    double distanceTraveled = arcLength * AutonomousConstants::track_width * std::atan(1.0) * 4.0;

    double rotations = distanceTraveled / (AutonomousConstants::wheel_diameter * std::atan(1.0) * 4.0);
    int encoderClicks = rotations * 900;

    this -> left_motor_group.move_relative(encoderClicks, AutonomousConstants::maximum_rpm);
    this -> right_motor_group.move_relative(encoderClicks, AutonomousConstants::maximum_rpm);
    while (this -> left_motor_group.get_actual_velocities()[0] != 0.0) { pros::delay(10); }
}
