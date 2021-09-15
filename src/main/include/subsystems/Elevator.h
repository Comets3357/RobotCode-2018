#pragma once

#include "Constants.h"

struct RobotData;

struct ElevatorData {};

class Elevator
{

public:
    void RobotInit();
    void DisabledInit();
    void RobotPeriodic(const RobotData &robotData, ElevatorData &elevatorData);

private:
    void manualMode(const RobotData &robotData, ElevatorData &pincerData);
    void semiAutoMode(const RobotData &robotData, ElevatorData &pincerData);
    void updateData(const RobotData &robotData, ElevatorData &pincerData);

};