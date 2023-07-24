#include "command_base.h"

class InstantCommand : public CommandBase {

    private:
        bool isInitialized = false; 

    public:
        void run ();
        bool isFinished ();
        void onEnd (bool interrupted);

        virtual void initialize ();
        virtual void onFinish (bool interrupted);
};
