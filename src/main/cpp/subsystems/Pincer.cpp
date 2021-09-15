#include "subsystems/Pincer.h"
#include "RobotData.h"

void Pincer::RobotInit()
{

}

void Pincer::DisabledInit()
{
    
}

void Pincer::RobotPeriodic(const RobotData &robotData, PincerData &pincerData)
{
    updateData(robotData, pincerData);

    if (robotData.controlData.manualMode)
    {
        manualMode(robotData, pincerData);
    }
    else
    {
        semiAutoMode(robotData, pincerData);
    }
}

void Pincer::manualMode(const RobotData &robotData, PincerData &intakeData)
{

}

void Pincer::semiAutoMode(const RobotData &robotData, PincerData &intakeData)
{

}

void Pincer::updateData(const RobotData &robotData, PincerData &intakeData)
{

}