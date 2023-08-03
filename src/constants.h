#pragma once

enum DriveControl { Arcade, Curvature, Tank };

class DrivetrainConstants {

    public:
        static constexpr DriveControl driver_control = DriveControl::Arcade;
        static constexpr bool square_inputs = false;

        static constexpr int front_left_motor = 19;
        static constexpr int front_right_motor = 17;
        static constexpr int back_left_motor = 20;
        static constexpr int back_right_motor = 18;

        static constexpr bool front_left_motor_reversed = true;
        static constexpr bool front_right_motor_reversed = false;
        static constexpr bool back_left_motor_reversed = true;
        static constexpr bool back_right_motor_reversed = false;
};

class AutonomousConstants {

    public:
        static constexpr double wheel_diameter = 4.0;
        static constexpr double maximum_rpm = 75.0;
        static constexpr double track_width = 8.25;
};
