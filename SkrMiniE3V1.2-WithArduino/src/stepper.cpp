#include "stepper.h"
/**
 * @brief Construct a new stepper::stepper object
 * 
 * @param pinStep 
 * @param pinDir 
 */
stepper::stepper(int pinStep, int pinDir, int stepsPerRevolution)
{
    stepPin = pinStep;
    dirPin = pinDir;
    stepsPerRevo = stepsPerRevolution;
    currentPosition = 0;
    setPoint = 0;
    setSpeed = 0;
    msPerStep = 0;
}

/**
 * @brief Destroy the stepper::stepper object
 * 
 */
stepper::~stepper()
{
}

/**
 * @brief 
 * 
 */
void stepper::begin()
{
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
}

/**
 * @brief 
 * 
 * @param Position 
 * @param speed 
 */
void stepper::set(long Position, long speed)
{
    setPoint = Position;
    setSpeed = speed;
    msPerStep = 60000000/(setSpeed*stepsPerRevo);
}

/**
 * @brief 
 * 
 * @return true if position is reached else returns false
 */
bool stepper::step()
{
    if (currentPosition != setPoint)
    {
        if (currentPosition < setPoint)
        {
            digitalWrite(dirPin, HIGH);
            currentPosition++;
        }
        else
        {
            digitalWrite(dirPin, LOW);
            currentPosition--;
        }

        digitalWrite(stepPin, HIGH);
        delayMicroseconds(msPerStep/2);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(msPerStep/2);
        return false;
    }
    else{
        return true;
    }
}

/**
 * @brief 
 * 
 * @param Position 
 * @param speed 
 */
void stepper::move(long Position, long speed){

    stepper::set(Position, speed);
    while(!stepper::step());

}