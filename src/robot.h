#include "constants.h"

class Drivetrain {
    private:
        DriveType driveType;

        // TODO might need to update this depending on how drivetrain is oriented
        void setDrive(int leftPower, int rightPower) {
            LeftFront = -leftPower;
            LeftMiddle = -leftPower;
            LeftRear = leftPower;
            RightFront = rightPower;
            RightMiddle = rightPower;
            RightRear = -rightPower;
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
                    (master.get_analog(ANALOG_LEFT_Y) + master.get_analog(ANALOG_RIGHT_X)),
                    (master.get_analog(ANALOG_LEFT_Y) - master.get_analog(ANALOG_RIGHT_X))
                );
            } else {
                // Tank style drive
                this->setDrive(
                    master.get_analog(ANALOG_LEFT_Y),
                    master.get_analog(ANALOG_RIGHT_Y)
                );
            }
        }

        void driveTo(int position, int power) {
            resetDriveEncoders();
            int direction = abs(position) / position;

            // TODO need to test this once gyro/intertial is installed
            // https://www.youtube.com/watch?v=6gZcQoqVOvA
            while (avgEncoderValue() < abs(position)) {
                setDrive(power * direction, power * direction);
                pros::delay(2);
            }
            brake(50, 10);
        }

        void turnTo(int degrees, int power) {
            int direction = abs(degrees) / degrees;

            inertial.reset();

            // TODO need to test this once gyro/intertial is installed
            // https://www.youtube.com/watch?v=6gZcQoqVOvA
            while (fabs(inertial.get_yaw()) < abs(degrees * 10)) {
                setDrive(power * -direction, power * direction);
                pros::delay(2);
            }
            
            // loosing momentum
            pros::delay(100);

            // TODO potential for infinite loop... need to test
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

class Triball {
    private:
        bool isPlowing;

    public:
        Triball() {
            Flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
            Intake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

            this->isPlowing = false;
        }

        void shoot() {
            if (partner.get_digital(DIGITAL_L1)) {
                Flywheel = 127;
            }  else {
                Flywheel = 0;
            }
        }

        void intake() {
            if (partner.get_digital(DIGITAL_R1)) {
                Intake = 127;
            } else if (partner.get_digital(DIGITAL_R2)) {
                Intake = -127;
            } else {
                Intake = 0;
            }
        }

        void plow() {
            if (!isPlowing && master.get_digital(DIGITAL_L2)) {
                // TODO push out wings
                piston1.set_value(false);
                isPlowing = !isPlowing;
            } else if (isPlowing && master.get_digital(DIGITAL_L2)) {
                // TODO bring in wings
                piston1.set_value(true);//for the dual acting, true is port A
                isPlowing = !isPlowing;
            }
        }

};