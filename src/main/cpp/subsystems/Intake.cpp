#include "subsystems/Intake.h"
#include "RobotData.h"

void Intake::RobotInit()
{

}

void Intake::DisabledInit()
{
    
}

void Intake::RobotPeriodic(const RobotData &robotData, IntakeData &intakeData)
{
    updateData(robotData, intakeData);

    if (robotData.controlData.manualMode)
    {
        manualMode(robotData, intakeData);
    }
    else
    {
        semiAutoMode(robotData, intakeData);
    }
}

void Intake::manualMode(const RobotData &robotData, IntakeData &intakeData)
{

}

void Intake::semiAutoMode(const RobotData &robotData, IntakeData &intakeData)
{

}

void Intake::updateData(const RobotData &robotData, IntakeData &intakeData)
{

}