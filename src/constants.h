enum DriveControl { Arcade, Curvature, Tank };

class DrivetrainConstants {

    public:
        static constexpr DriveControl drive_control = DriveControl::Tank;
        static constexpr bool square_inputs = true;

        static constexpr int front_left_motor = 20;
        static constexpr int front_right_motor = 11;
        static constexpr int back_left_motor = 19;
        static constexpr int back_right_motor = 12;
};

class AutonomousConstants {

    public:
        static constexpr double wheel_diameter = 4.0;
        static constexpr double maximum_rpm = 75.0;
        static constexpr double track_width = 8.25;
};
