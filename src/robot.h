#include "constants.h"
#include <iostream>

using namespace std;

class Drivetrain {
    private:
        DriveType driveType;

        // Sets the speed and direction of drive motors
        void setDrive(int leftPower, int rightPower) {
            LeftFront = -leftPower;
            LeftMiddle = -leftPower;
            LeftRear = leftPower;
            RightFront = rightPower;
            RightMiddle = rightPower;
            RightRear = -rightPower;
        }

        // Resets all drive encoders
        void resetDriveEncoders() {
            LeftFront.tare_position();
            LeftMiddle.tare_position();
            LeftRear.tare_position();
            RightFront.tare_position();
            RightMiddle.tare_position();
            RightRear.tare_position();
        }

        // Gets the average encoder value of the drivetrain
        double avgEncoderValue() {
            return (
                fabs(LeftFront.get_position()) +
                fabs(LeftMiddle.get_position()) +
                fabs(LeftRear.get_position()) +
                fabs(RightFront.get_position()) +
                fabs(RightMiddle.get_position()) +
                fabs(RightRear.get_position())
            ) / 6;
        }


    public:
        Drivetrain(DriveType driveType) {
            this->driveType = driveType;

            // setting motors to coast off power
            LeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
            LeftMiddle.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
            LeftRear.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
            RightFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
            RightMiddle.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
            RightRear.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        }
        
        // Code to move the robot
        void drive() {
            if (driveType == DriveType::ARCADE) {
                // Arcade style drive
                this->setDrive(
                    (controller.get_analog(ANALOG_LEFT_Y) + controller.get_analog(ANALOG_RIGHT_X)),
                    (controller.get_analog(ANALOG_LEFT_Y) - controller.get_analog(ANALOG_RIGHT_X))
                );
            } else {
                // Tank style drive
                this->setDrive(
                    controller.get_analog(ANALOG_LEFT_Y),
                    controller.get_analog(ANALOG_RIGHT_Y)
                );
            }
        }

        // Drives forward/backward to arbitrary position (motor clicks) at a certain power
        void driveTo(int position, int power) {
            resetDriveEncoders();
            int direction = abs(position) / position;

            while (avgEncoderValue() < abs(position)) {
                setDrive(power * direction, power * direction);
                pros::delay(2);
            }
            brake(50, 10);
        }

        // Turns robot X degrees at a certain power
        void turnTo(int degrees, int power) {
            int direction = abs(degrees) / degrees;
            inertial.tare_heading();

            while (inertial.get_heading() < abs(degrees)) {
                setDrive(power * direction, power * -direction);
                pros::delay(2);
            }
            
            // loosing momentum
            pros::delay(100);

            // TODO potential for infinite loop... need to test
            if (inertial.get_heading() != abs(degrees * 10)) {
                turnTo((degrees) - inertial.get_heading(), 0.5 * power);
            }
        }

        // Brakes the robot (since motors are set to coast)
        void brake(int duration, int power) {
            setDrive(-power, -power);
            pros::delay(duration);
            setDrive(0, 0);
        }
};

class Triball {
    private:
        bool isPlowing;

    public:
        Triball() {
            Flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
            Intake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

            this->isPlowing = false;
        }

        // Run shooter
        void shoot() {
            if (controller.get_digital(DIGITAL_L1)) {
                Flywheel = 127;
            } else if (controller.get_digital(DIGITAL_L2)) {
                Flywheel = -127;
            } else {
                Flywheel = 0;
            }
        }

        // Run intake
        void intake() {
            if (controller.get_digital(DIGITAL_R1)) {
                Intake = 127;
            } else if (controller.get_digital(DIGITAL_R2)) {
                Intake = -127;
            } else {
                Intake = 0;
            }
        }

        // Run wings
        void plow() {
            if (!isPlowing && controller.get_digital(DIGITAL_X)) {
                piston1.set_value(true);
                piston2.set_value(true);

                isPlowing = !isPlowing;
            } else if (isPlowing && controller.get_digital(DIGITAL_X)) {
                piston1.set_value(false);
                piston2.set_value(false);

                isPlowing = !isPlowing;
            }
        }
};
