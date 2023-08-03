#include "main.h"
#include <string>

#include "../constants.h"
#pragma once

class Drivetrain {

    private:
        pros::Motor back_left_motor = pros::Motor(DrivetrainConstants::back_left_motor, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
        pros::Motor back_right_motor = pros::Motor(DrivetrainConstants::back_right_motor, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);

        DriveControl driver_control = DrivetrainConstants::driver_control;
        bool square_inputs = DrivetrainConstants::square_inputs;
    
    public:
        pros::Motor front_left_motor = pros::Motor(DrivetrainConstants::front_left_motor, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
        pros::Motor front_right_motor = pros::Motor(DrivetrainConstants::front_right_motor, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
        double left_speed = 0.0;
        double right_speed = 0.0;

        Drivetrain ();
        void drive (int analogLeftY, int analogRightX, int analogRightY);
        void stop ();

        void arcadeDrive (int analogSpeed, int analogRotation);
        void curvatureDrive (int analogSpeed, int analogRotation);
        void tankDrive (int leftAnalogSpeed, int rightAnalogSpeed);

        void driveStraight (double inches);
        void turn (double degrees);
};
