#include <Arduino.h>
#include <USBSerial.h>
#include "C:\Users\thoma\OneDrive\Documenten\projecten\skrminie3\PinMap.h"

#include <ostream>

#include <TMCStepper.h>         // TMCstepper - https://github.com/teemuatlut/TMCStepper
#include <SoftwareSerial.h>     // Software serial for the UART to TMC2209 - https://www.arduino.cc/en/Reference/softwareSerial

#define EN_PIN           XEN      // Enable - PURPLE
#define DIR_PIN          XDIR      // Direction - WHITE
#define STEP_PIN         XSTEP      // Step - ORANGE
#define SW_SCK           0      // Software Slave Clock (SCK) - BLUE
#define SW_TX            XUART      // SoftwareSerial receive pin - BROWN
#define SW_RX            XUART      // SoftwareSerial transmit pin - YELLOW
#define DRIVER_ADDRESS   0b00   // TMC2209 Driver address according to MS1 and MS2
#define R_SENSE 0.11f           // SilentStepStick series use 0.11 ...and so does my fysetc TMC2209 (?)

using namespace std;

SoftwareSerial SoftSerial(SW_RX, SW_TX);                          // Be sure to connect RX to TX and TX to RX between both devices

TMC2209Stepper TMCdriver(&SoftSerial, R_SENSE, DRIVER_ADDRESS);   // Create TMC driver

int accel;
long maxSpeed;
int speedChangeDelay;
bool dir = false;


//== Setup ===============================================================================

void setup() {

  Serial.begin(11520);               // initialize hardware serial for debugging
  pinMode(USBCONNECT, OUTPUT);
  SoftSerial.begin(11520);           // initialize software serial for UART motor control
  TMCdriver.beginSerial(11520);      // Initialize UART
  
  pinMode(EN_PIN, OUTPUT);           // Set pinmodes
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);         // Enable TMC2209 board  

  TMCdriver.begin();                                                                                                                                                                                                                                                                                                                            // UART: Init SW UART (if selected) with default 115200 baudrate
  TMCdriver.toff(5);                 // Enables driver in software
  TMCdriver.rms_current(1000);        // Set motor RMS current
  TMCdriver.microsteps(0);         // Set microsteps

  TMCdriver.en_spreadCycle(false);
  TMCdriver.pwm_autoscale(true);     // Needed for stealthChop
  
}

//== Loop =================================================================================

void loop() {
  
  accel = 100;                                         // Speed increase/decrease amount
  maxSpeed = 1000;                                      // Maximum speed to be reached
  speedChangeDelay = 100;                                // Delay between speed changes
  
  for (long i = 0; i <= maxSpeed; i = i + accel){             // Speed up to maxSpeed
    TMCdriver.VACTUAL(i);                                     // Set motor speed
    Serial.println(TMCdriver.VACTUAL());
    delay(100);
  }
  
  for (long i = maxSpeed; i >=0; i = i - accel){              // Decrease speed to zero
    TMCdriver.VACTUAL(i);
    Serial.println(TMCdriver.VACTUAL());
    delay(100);
  }  
  
  dir = !dir; // REVERSE DIRECTION
  TMCdriver.shaft(dir); // SET DIRECTION

}