#include "command_base.h"

void CommandBase::execute () {

    if (!this -> isFinished()) {

        if (this -> isCancelled) { this -> onEnd(true); }
        else { this -> run(); }
    } else {

        this -> onEnd(false);
    }
}

void CommandBase::cancel () { this -> isCancelled = true; }

void CommandBase::run () {}
bool CommandBase::isFinished () { return false; }
void CommandBase::onEnd (bool interrupted) {}
