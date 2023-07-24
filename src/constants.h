#pragma once

enum DriveControl { Arcade, Curvature, Tank };

class DrivetrainConstants {

    public:
        static constexpr DriveControl driver_control = DriveControl::Arcade;
        static constexpr bool square_inputs = false;

        /**
         * @brief Defines the ports for the motors of the drivetrain.
         * To change the number of motors, update lines nine and ten of drivetrain.h.
         */
        static constexpr int front_left_motor = 9, front_right_motor = 10, back_left_motor = 1, back_right_motor = 2;

        /**
         * @brief Defines if the motor groups of the drivetrain are reversed.
         * No action is necessary to change the number of motors.
         */
        static constexpr bool left_motors_reversed = false, right_motors_reversed = false;
};

class AutonomousConstants {

    public:
        static constexpr double wheel_diameter = 4.0;
        static constexpr double maximum_rpm = 75.0;
        static constexpr double track_width = 8.25;
};
