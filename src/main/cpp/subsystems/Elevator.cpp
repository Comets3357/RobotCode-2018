#include "subsystems/Elevator.h"
#include "RobotData.h"

void Elevator::RobotInit()
{

}

void Elevator::DisabledInit()
{
    
}

void Elevator::RobotPeriodic(const RobotData &robotData, ElevatorData &elevatorData)
{
    updateData(robotData, elevatorData);

    if (robotData.controlData.manualMode)
    {
        manualMode(robotData, elevatorData);
    }
    else
    {
        semiAutoMode(robotData, elevatorData);
    }
}

void Elevator::manualMode(const RobotData &robotData, ElevatorData &intakeData)
{

}

void Elevator::semiAutoMode(const RobotData &robotData, ElevatorData &intakeData)
{

}

void Elevator::updateData(const RobotData &robotData, ElevatorData &intakeData)
{

}