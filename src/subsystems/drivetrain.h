#include "main.h"
#include <string>

#include "../constants.h"
#pragma once

class Drivetrain {

    private:
        pros::MotorGroup left_motor_group = pros::MotorGroup({DrivetrainConstants::front_left_motor, DrivetrainConstants::back_left_motor});
        pros::MotorGroup right_motor_group = pros::MotorGroup({DrivetrainConstants::front_right_motor, DrivetrainConstants::back_right_motor});

        DriveControl driver_control = DrivetrainConstants::driver_control;
        bool square_inputs = DrivetrainConstants::square_inputs;
    
    public:
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
