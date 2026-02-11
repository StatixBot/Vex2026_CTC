#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

class Drivetrain {
public:
    Drivetrain(int FrontLeftMotorPort, int FrontRightMotorPort, int BackLeftMotorPort, int BackRightMotorPort, int VerticalEncoder, int HorizontalEncoder);
    void drive();
    void fwd_inches();
    void strf_inches();
    void stop();
};

#endif // DRIVETRAIN_H