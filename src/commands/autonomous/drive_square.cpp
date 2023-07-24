#include "drive_square.h"

void DriveSquare::initialize () {

    for (int i = 0; i < 4; i++) {

        this -> drivetrain.driveStraight(12);
        pros::delay(2000);

        this -> drivetrain.turn(90);
        pros::delay(2000);
    }
}

void DriveSquare::onFinish (bool interrupted) { if (interrupted) { this -> drivetrain.stop(); } }
