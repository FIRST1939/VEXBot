#include "constants.h"

class Drivetrain {
    public:
        Drivetrain(DriveType driveType);

        void kachow();
        void driveTo(int position, int power);
        void turnTo(int degrees, int power);
        void brake(int duration, int power);
};

class Triball {
    public:
        Triball();
        
        void shoot();
        void intake();
        void plow();
};