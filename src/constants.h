// Declarations for drivetrain motors
pros::Motor LeftFront (20);
pros::Motor RightFront (11);
pros::Motor LeftMiddle (19);
pros::Motor RightMiddle (13);
pros::Motor LeftRear (19);
pros::Motor RightRear (18);

pros::Motor Flywheel (1);
pros::Motor Intake (2);

// Controllers
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Handy Enums
enum DriveType { ARCADE, TANK };

// Gyro
pros::IMU inertial(10);
