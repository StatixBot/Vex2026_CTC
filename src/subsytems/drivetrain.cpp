#include <iostream>
#include <drivetrain.h>
#include <math.h>
#include <algorithm>
#include "vex.h"
Drivetrain::Drivetrain(int FrontLeftMotorPort, int FrontRightMotorPort, 
                       int BackLeftMotorPort, int BackRightMotorPort, 
                       int VerticalEncoder, int HorizontalEncoder, 
                       int InertialSensorPort)  //*Initialize motors and encoders here

    //Inertial sensor Constructor, using the port number passed in the constructor to initialize the inertial sensor
    : inertialSensor(vex::PORT1 + (InertialSensorPort - 1)), //Initializer list
      FrontLeftMotor(vex::PORT1 + (FrontLeftMotorPort - 1), true),
      FrontRightMotor(vex::PORT1 + (FrontRightMotorPort - 1, false)),
      BackLeftMotor(vex::PORT1 + (BackLeftMotorPort - 1), true),
      BackRightMotor(vex::PORT1 + (BackRightMotorPort - 1), false)

     { 
        // Calibrate the inertial sensor
        inertialSensor.calibrate(); 
    
    }  

void Drivetrain::drive() {
    // Implement drive logic here

    while (true) {
        // Example: Read the inertial sensor's heading and print it to the brain screen
        double robot_heading = inertialSensor.heading();
        double theta = robot_heading * (M_PI / 180.0); // Convert heading to radians for calculations
        double joystick_x = Controller1.Axis1.position();
        double joystick_y = Controller1.Axis2.position();
        double joystick_turn = -Controller1.Axis4.position();
        double fwd = Drivetrain::dX(joystick_x, joystick_y, theta);
        double strf = Drivetrain::dY(joystick_x, joystick_y, theta);

        double FR = std::max(-100.0, std::min(fwd - strf + joystick_turn, 100.0));
        double FL = std::max(-100.0, std::min(fwd + strf - joystick_turn, 100.0));
        double BR = std::max(-100.0, std::min(fwd + strf + joystick_turn, 100.0));
        double BL = std::max(-100.0, std::min(fwd - strf - joystick_turn, 100.0));
        
        FrontRightMotor.spin(vex::directionType::fwd, FR, vex::velocityUnits::pct);
        FrontLeftMotor.spin(vex::directionType::fwd, FL, vex::velocityUnits::pct);
        BackRightMotor.spin(vex::directionType::fwd, BR, vex::velocityUnits::pct);
        BackLeftMotor.spin(vex::directionType::fwd, BL, vex::velocityUnits::pct);
    }
};