My settings are for an SKR 1.4 so not all of this may apply to some other board. My board has steppers for X, Y, Z, E0, and E1. I assigned the E1 stepper to Z2.
For endstop plugs, rather than the usual [Xmin, Xmax, Ymin, Ymax, Zmin, Zmax], the 1.4 board has [Xmin, E0 Det, Ymin, E1 Det, Zmin, PWR Det]. I assigned E1 Det to Ymax, then configured Z2 endstop to be Ymax.
I used the stock filament detector cable as the Z2 enstop cable.
Adding Y-MAX (line 3) to pins file:
Marlin/src/pins/lpc1768/pins_BTT_SKR_V1_4.h:
```
//
// TMC StallGuard DIAG pins
//
#define X_DIAG_PIN P1_29 // X-STOP
#define Y_DIAG_PIN P1_28 // Y-STOP
#define Y_MAX_PIN P1_25 // Added Y-MAX
#define Z_DIAG_PIN P1_27 // Z-STOP
#define E0_DIAG_PIN P1_26 // E0DET
#define E1_DIAG_PIN P1_25 // E1DET
```
Configuration.h:
```
// Define a stepper driver for Z2
#define Z2_DRIVER_TYPE TMC2209
// Used YMAX for dual Z endstop. Inverted it just like the rest of the endstops.
#define Y_MAX_ENDSTOP_INVERTING true
// Enable YMAX plug
#define USE_YMAX_PLUG
```
Configuration_adv.h:
```
// Set z drivers to 2 and set z2 endstop to use YMAX
//
// For Z set the number of stepper drivers
//
#define NUM_Z_STEPPER_DRIVERS 2 // (1-4) Z options change based on how many
#if NUM_Z_STEPPER_DRIVERS > 1
#define Z_MULTI_ENDSTOPS
#if ENABLED(Z_MULTI_ENDSTOPS)
#define Z2_USE_ENDSTOP _YMAX_
```
