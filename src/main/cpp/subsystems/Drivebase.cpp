#include "subsystems/Drivebase.h"
#include "RobotData.h"

void Drivebase::RobotInit()
{
    dbLM.ConfigFactoryDefault();
    dbRM.ConfigFactoryDefault();
    dbL1.ConfigFactoryDefault();
    dbR1.ConfigFactoryDefault();
    dbL2.ConfigFactoryDefault();
    dbR2.ConfigFactoryDefault();

    dbLM.SetInverted(true);
    dbL1.SetInverted(true);
    dbL2.SetInverted(true);
    dbRM.SetInverted(false);
    dbR1.SetInverted(false);
    dbR2.SetInverted(false);

    //everything follows the front motors right now; might be wrong but I'm 90% sure it's right
    dbL1.Follow(dbLM);
    dbL2.Follow(dbLM);
    dbR1.Follow(dbRM);
    dbR2.Follow(dbRM);

    dbRM.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
    dbLM.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
    dbR1.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
    dbL1.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
    dbR2.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
    dbL2.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);

    // dbLM.ConfigContinuousCurrentLimit(45); //might be the wrong function but it needs to set the current limit
    // dbRM.ConfigContinuousCurrentLimit(45);
    // dbL1.ConfigContinuousCurrentLimit(45); //allegedly the VictorSPX motors don't have current limits but I'm keeping this just in case
    // dbR1.ConfigContinuousCurrentLimit(45);
    // dbL2.ConfigContinuousCurrentLimit(45);
    // dbR2.ConfigContinuousCurrentLimit(45);

    dbLM.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
    dbRM.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
}

void Drivebase::RobotPeriodic(const RobotData &robotData, DrivebaseData &drivebaseData)
{
    updateData(robotData, drivebaseData);

    if (frc::DriverStation::GetInstance().IsEnabled())
    {
        dbRM.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
        dbR1.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
        dbR2.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
        dbLM.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
        dbL1.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
        dbL2.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
    }

    teleopControl(robotData);
}

void Drivebase::DisabledInit()
{
    dbLM.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
    dbRM.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);

    dbRM.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
    dbLM.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
    dbR1.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
    dbL1.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
    dbR2.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
    dbL2.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
}

// updates encoder and gyro values
void Drivebase::updateData(const RobotData &robotData, DrivebaseData &drivebaseData)
{
    // add back wheel encoders at some point
    // drivebaseData.currentLDBPos = dbLMEncoder.GetPosition();
    // drivebaseData.currentRDBPos = dbRMEncoder.GetPosition();

    // drivebaseData.lDriveVel = dbR1Encoder.GetVelocity();
    // drivebaseData.rDriveVel = dbL1Encoder.GetVelocity();
}
// driving functions:

// adjusts for the deadzone and converts joystick input to velocity values for PID
void Drivebase::teleopControl(const RobotData &robotData)
{
    double tempLDrive = robotData.controlData.lDrive;
    double tempRDrive = robotData.controlData.rDrive;

    // converts from tank to arcade drive, limits the difference between left and right drive
    double frontBack = robotData.controlData.maxStraight * (tempLDrive + tempRDrive) / 2;
    double leftRight = robotData.controlData.maxTurn * (tempRDrive - tempLDrive) / 2;

    //deadzone NOT needed for drone controller
    if (tempLDrive <= -0.08 || tempLDrive >= 0.08)
    {
        tempLDrive = (frontBack - leftRight);
    }
    else
    {
        tempLDrive = 0;
    }

    if (tempRDrive <= -0.08 || tempRDrive >= 0.08)
    {
        tempRDrive = (frontBack + leftRight);
    }
    else
    {
        tempRDrive = 0;
    }

    //set as percent vbus
    dbL1.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, tempLDrive);
    dbR1.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, tempRDrive);
}