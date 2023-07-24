#include "instant_command.h"

void InstantCommand::run () { 
    
    this -> initialize(); 
    this -> isInitialized = true;
}

bool InstantCommand::isFinished () { return this -> isInitialized; }
void InstantCommand::onEnd (bool interrupted) { this -> onFinish(interrupted); }

void InstantCommand::initialize () {}
void InstantCommand::onFinish (bool interrupted) {}
