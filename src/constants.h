// TODO update motor ports here

// Declarations for drivetrain motors
pros::Motor LeftFront (20);
pros::Motor RightFront (11);
pros::Motor LeftMiddle (19);
pros::Motor RightMiddle (13);
pros::Motor LeftRear (18);
pros::Motor RightRear (14);

pros::Motor Flywheel (1);
pros::Motor Intake (9);

// Controllers
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Handy Enums
enum DriveType { ARCADE, TANK };

// Gyro
pros::IMU inertial(10);

// Pneumatic controls here
pros::ADIDigitalOut piston1 (1);
pros::ADIDigitalOut piston2 (2); 
