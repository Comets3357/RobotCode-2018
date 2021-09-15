#pragma once

#include "Constants.h"

struct RobotData;

struct IntakeData {};

class Intake
{

public:
    void RobotInit();
    void DisabledInit();
    void RobotPeriodic(const RobotData &robotData, IntakeData &intakeData);

private:
    void manualMode(const RobotData &robotData, IntakeData &pincerData);
    void semiAutoMode(const RobotData &robotData, IntakeData &pincerData);
    void updateData(const RobotData &robotData, IntakeData &pincerData);

};