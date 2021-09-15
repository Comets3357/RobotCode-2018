#pragma once

#include "Constants.h"

struct RobotData;

struct PincerData {};

class Pincer
{

public:
    void RobotInit();
    void DisabledInit();
    void RobotPeriodic(const RobotData &robotData, PincerData &pincerData);

private:
    void manualMode(const RobotData &robotData, PincerData &pincerData);
    void semiAutoMode(const RobotData &robotData, PincerData &pincerData);
    void updateData(const RobotData &robotData, PincerData &pincerData);

};