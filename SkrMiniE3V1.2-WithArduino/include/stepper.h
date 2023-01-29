#include <Arduino.h>



class stepper
{
private:
    /* data */
    int stepPin; //step pin on stepstick driver
    int dirPin; //dir pin on stepstick driver
    int stepsPerRevo;
    long currentPosition; //current position in steps
    long setPoint;   //target position in steps
    long setSpeed; //rotation speed in rev/min
    long msPerStep; //delay to use
    


public:
    stepper(int pinStep, int pinDir, int stepsPerRevolution);
    ~stepper();
    
    void begin();
    void set(long Position, long speed);
    bool step();
    void move(long Position, long speed);
};

