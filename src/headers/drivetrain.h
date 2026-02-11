#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "vex.h"

class Drivetrain {
public:
    Drivetrain(int FrontLeftMotorPort, int FrontRightMotorPort, 
               int BackLeftMotorPort, int BackRightMotorPort, 
               int VerticalEncoder, int HorizontalEncoder, 
               int InertialSensorPort);
    void drive();
    void fwd_inches();
    void strf_inches();
    double dX(double joystick_x, double joystick_y, double theta);
    double dY(double joystick_x, double joystick_y, double theta);
    void stop();
    
private:
    vex::inertial inertialSensor;
    vex::controller Controller1;
    vex::motor FrontLeftMotor;
    vex::motor FrontRightMotor; 
    vex::motor BackLeftMotor;
    vex::motor BackRightMotor;
};

#endif // DRIVETRAIN_H