#include "main.h"
#include "constants.h"
#include "robot.h"

using namespace std;

class Drivetrain {
    private:
        DriveType driveType;

        void setDrive(int leftPower, int rightPower) {
            LeftFront = -leftPower;
            LeftMiddle = -leftPower;
            LeftRear = -leftPower;
            RightFront = rightPower;
            RightMiddle = rightPower;
            RightRear = rightPower;
        }

        void resetDriveEncoders() {
            LeftFront.tare_position();
            LeftMiddle.tare_position();
            LeftRear.tare_position();
            RightFront.tare_position();
            RightMiddle.tare_position();
            RightRear.tare_position();
        }

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
        
        void kachow() {
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

        void driveTo(int position, int power) {
            // gyro controlled
            resetDriveEncoders();
            int direction = abs(position) / position;

            while (avgEncoderValue() < abs(position)) {
                // TODO need some tweaking here to fine tune gyro calibration
                setDrive(power * direction, power * direction);
                pros::delay(2);
            }
            brake(50, 10);
        }

        void turnTo(int degrees, int power) {
            // gyro controlled
            int direction = abs(degrees) / degrees;

            inertial.reset();

            while (fabs(inertial.get_yaw()) < abs(degrees * 10)) {
                setDrive(power * -direction, power * direction);
                pros::delay(2);
            }
            
            // loosing momentum
            pros::delay(100);

            if (inertial.get_yaw() != abs(degrees * 10)) {
                turnTo((degrees * 10) - inertial.get_yaw(), 0.5 * power);
            }
        }

        void brake(int duration, int power) {
            setDrive(-power, -power);
            pros::delay(duration);
            setDrive(0, 0);
        }
};