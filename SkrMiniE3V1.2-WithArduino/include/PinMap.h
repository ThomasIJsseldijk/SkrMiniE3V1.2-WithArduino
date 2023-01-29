#ifndef PINMAP_H
#define PINMAP_H

// Stepper Motors

// X
#define XEN PB14
#define XSTEP PB13
#define XDIR PB12
#define XUART PB15

// Y
#define YEN PB11
#define YSTEP PB10
#define YDIR PB2
#define YUART PC6

// Z
#define ZEN PB1
#define ZSTEP PB0
#define ZDIR PC5
#define ZUART PC10

// E0
#define E0EN PD2
#define E0STEP PB3
#define E0DIR PB4
#define E0UART PC11

// USB
#define USBDPLUS PA12
#define USBDMIN PA11
#define USBCONNECT PC13

// SD-card Reader
#define SDSSEL PA4
#define SDMOSI PA7
#define SDSCK PA5
#define SDMISO PA6
#define SDDET PC4

// Limit Switched
#define XSTOP PC0
#define YSTOP PC1
#define ZSTOP PC2
#define ESTOP PC15

// Heated Bed and Nozzle

#define HE0 PC8
#define TH0 PA0
#define BED PC9
#define THB PC3

// Fan
#define FAN0 PA8

// extras

#define PROBE PC14
#define SERVOS PA1
#define PTDET PC12
#define STATUS PA15

#endif