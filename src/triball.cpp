#include "main.h"
#include "constants.h"
#include "robot.h"

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
            if (controller.get_digital(DIGITAL_L1)) {
                Flywheel = 127;
            } else if (controller.get_digital(DIGITAL_L2)) {
                Flywheel = -127;
            } else {
                Flywheel = 0;
            }
        }

        void intake() {
            if (controller.get_digital(DIGITAL_R1)) {
                Intake = 127;
            } else if (controller.get_digital(DIGITAL_R2)) {
                Intake = -127;
            } else {
                Intake = 0;
            }
        }

        void plow() {
            if (!isPlowing && controller.get_digital(DIGITAL_X)) {
                // push out wings
                isPlowing = !isPlowing;
            } else if (isPlowing && controller.get_digital(DIGITAL_X)) {
                // bring in wings
                isPlowing = !isPlowing;
            }
        }
};