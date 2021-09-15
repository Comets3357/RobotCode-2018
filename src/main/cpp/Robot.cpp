#include "Robot.h"

void Robot::RobotInit()
{
    timer.RobotInit(robotData.timerData);

    drivebase.RobotInit();
    intake.RobotInit();
    elevator.RobotInit();
    pincer.RobotInit();
}

void Robot::RobotPeriodic()
{
    timer.RobotPeriodic(robotData.timerData);

    if (IsEnabled())
    {
        otherComponents.RobotPeriodic(robotData.otherComponentsData);

        drivebase.RobotPeriodic(robotData, robotData.drivebaseData);
        intake.RobotPeriodic(robotData, robotData.intakeData);
        elevator.RobotPeriodic(robotData, robotData.elevatorData);
        pincer.RobotPeriodic(robotData, robotData.pincerData);
    }
}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}
void Robot::TeleopInit() {}

void Robot::TeleopPeriodic()
{
    controller.TeleopPeriodic(robotData, robotData.controllerData, robotData.controlData);
}

void Robot::DisabledInit()
{
    timer.DisabledInit();

    drivebase.DisabledInit();
    intake.DisabledInit();
    elevator.DisabledInit();
    pincer.DisabledInit();
}

void Robot::DisabledPeriodic() {}
void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main()
{
    return frc::StartRobot<Robot>();
}
#endif