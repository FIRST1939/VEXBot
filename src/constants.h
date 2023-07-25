/*Motor Layout
Name:            Port:
Left Front (LF)  = 20
Left Rear (LR)   = 19
Right Front (RF) = 11
Right Rear (RR)  = 12


******* possibly burned out motor ports - 7,2,12,6,3,4


*/

//Motor declarations for names
pros::Motor LF (20);
pros::Motor LR (19);
pros::Motor RF (11);
pros::Motor RR (12);
pros::Motor Intake (14);
pros::Motor Shooter (15);

//Controller declaration
pros::Controller controller(pros::E_CONTROLLER_MASTER);