#pragma once

#include "Constants.h"

#include <frc/DriverStation.h>
#include <frc/PowerDistributionPanel.h>
#include <frc/TimedRobot.h>
#include <rev/CANSparkMax.h>
#include <rev/CANEncoder.h>
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>
#include <ctre/phoenix.h>

struct RobotData;

struct DrivebaseData
{
    double currentLDBPos;
    double currentRDBPos;

    double lDriveVel;
    double rDriveVel;
};

class Drivebase
{

public:
    void RobotInit();
    void RobotPeriodic(const RobotData &robotData, DrivebaseData &drivebaseData);
    void DisabledInit();

private:

    void updateData(const RobotData &robotData, DrivebaseData &drivebaseData);
    void teleopControl(const RobotData &robotData);

    ctre::phoenix::motorcontrol::can::TalonSRX dbLM{leftFrontDeviceID};
    ctre::phoenix::motorcontrol::can::TalonSRX dbRM{rightFrontDeviceID};
    ctre::phoenix::motorcontrol::can::VictorSPX dbL1{leftMiddleDeviceID};
    ctre::phoenix::motorcontrol::can::VictorSPX dbR1{rightMiddleDeviceID};
    ctre::phoenix::motorcontrol::can::VictorSPX dbL2{leftBackDeviceID};
    ctre::phoenix::motorcontrol::can::VictorSPX dbR2{rightBackDeviceID};

    // no encoders for db motors
    // initialize PID controllers?
};