#include "main.h"

#include "../../lib/instant_command.h"
#include "../../subsystems/drivetrain.h"

class DriveSquare : public InstantCommand {

    private:
        Drivetrain drivetrain;

    public:
        void initialize ();
        void onFinish (bool interrupted);
};
