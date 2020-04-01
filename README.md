### platformio.ini:

LPC1769 is for the skr v1.4 turbo. LPC1768 is for skr v1.4 (regular)


### Configuration_adv.h

Options needed for SD card support:

* LONG_FILENAME_HOST_SUPPORT
* SCROLL_LONG_FILENAMES
* SDCARD_CONNECTION set to either LCD on ONBOARD. This defines which SD card slot the Marlin menu looks for files to print. 

Define EMERGENCY_PARSER or else the TFT screen will have an annoying warning on boot. It's good to have

Options needed for filament runout sensor:
ADVANCED_PAUSE_FEATURE

Options used for TMC2209 stepper drivers:

* E0_CURRENT 900. Bumped up the current for Extruder 0
* CHOPPER_TIMING CHOPPER_DEFAULT_24V. We are using a 24 power supply
* MONITOR_DRIVER_STATUS. Good to have. We have spare cpu cycles on the skr 1.4

### Configuration.h

define SERIAL_PORT 0 and define SERIAL_PORT_2 -1 are required for the skr 1.4 and tft35 combination.

define MOTHERBOARD BOARD_BTT_SKR_V1_4_TURBO. We are using an skr v1.4 turbo

define DEFAULT_NOMINAL_FILAMENT_DIA 1.75. We use 1.75mm filament.

define TEMP_SENSOR_BED 1. Our Bed temperature sense (as well as our hotend temp sensor) use a 100k thermistor

define PIDTEMPBED. Use PID tuning algorithm for heating the bed. Also define the initial tune (you can do your own PID autotune afterwords):

//Adimlab Gantry Bed at 70C
#define DEFAULT_bedKp 400.00
#define DEFAULT_bedKi 74.00
#define DEFAULT_bedKd 1312.00

X_MIN_ENDSTOP_INVERTING, Y_MIN_ENDSTOP_INVERTING, Z_MIN_ENDSTOP_INVERTING set to true. Pulled this from the stock adimlab gantry configuration

This config is setup for TMC2209 stepper motor drivers which are installed in UART mode:

#define X_DRIVER_TYPE  TMC2209
#define Y_DRIVER_TYPE  TMC2209
#define Z_DRIVER_TYPE  TMC2209
#define E0_DRIVER_TYPE TMC2209

Steps per mm for {X, Y, Z, Extruder 0}. I pulled this from the stock adimlab gantry config. The original config actually had 94 for Extruder 0, but 96 works for me.
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80.4, 80.4, 400, 96 }.

Make sure your stepper motors are turning in the right direction:

#define INVERT_X_DIR true
#define INVERT_Y_DIR true
#define INVERT_Z_DIR false
#define INVERT_E0_DIR true

Set build area dimensions (pulled from the stock adimlab gantry config):

#define X_BED_SIZE 325
#define Y_BED_SIZE 325
#define Z_MAX_POS 415

Options needed for filament runout sensor (also see Configuration_adv.h for more required options):

* FILAMENT_RUNOUT_SENSOR
* NOZZLE_PARK_FEATURE
* NOZZLE_PARK_XY_FEEDRATE 60. 60 is from the stock adimlab gantry config.

Enable the classic 5 point manual bed leveling menu in Marlin:

#define LEVEL_BED_CORNER
#define LEVEL_CORNERS_Z_HOP       6.0   // (mm) Z height of nozzle between leveling points
#define LEVEL_CENTER_TOO

define EEPROM_SETTINGS. Enable Persistent storage with M500 and M501

The below are just my personal preference for preheat settings in Marlin:

 // Preheat Constants
 #define PREHEAT_1_LABEL       "PLA"
 #define PREHEAT_1_TEMP_HOTEND 180
 #define PREHEAT_1_TEMP_BED     60
 #define PREHEAT_1_FAN_SPEED     0 // Value from 0 to 255

 #define PREHEAT_2_LABEL       "ABS"
 #define PREHEAT_2_TEMP_HOTEND 240
 #define PREHEAT_2_TEMP_BED    80
 #define PREHEAT_2_FAN_SPEED     0 // Value from 0 to 255

Options needed for SD card support (also see Configuration_adv.h for more required options):

define SDSUPPORT

This is what allows us to use the emulated Marlin mode on the TFT35 v3.0 LCD controller:

define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER


The TFT35 v3.0 has firmware of its own as well. We need to tweak the bed size and disable Auto Bed leveling (or else an annoying, albiet harmless, pop up error comes up after boot). I have made a few other minor changes as well.


### Configuration.h

define BAUDRATE 250000. This needs to match what's in marlin

Marlin mode default colors (green text on black screen):

#define ST7920_BKCOLOR BLACK
#define ST7920_FNCOLOR GREEN

TFT mode preheat preferences:

 //                       PLA      PETG       ABS
 #define PREHEAT_BED      {60,      78,       80}
 #define PREHEAT_HOTEND   {200,     242,      230}

Set build are size (to match marlin):

#define X_MAX_POS 325
#define Y_MAX_POS 325
#define Z_MAX_POS 415

Disable auto bed leveling:

//#define AUTO_SAVE_LOAD_LEVELING_VALUE

Manual Bed leveling points (30mm from each edge):

#define LEVELING_POINT_1_X         (X_MIN_POS + 30)
#define LEVELING_POINT_1_Y         (Y_MIN_POS + 30)
#define LEVELING_POINT_2_X         (X_MAX_POS - 30)
#define LEVELING_POINT_2_Y         (Y_MIN_POS + 30)
#define LEVELING_POINT_3_X         (X_MAX_POS - 30)
#define LEVELING_POINT_3_Y         (Y_MAX_POS - 30)
#define LEVELING_POINT_4_X         (X_MIN_POS + 30)
#define LEVELING_POINT_4_Y         (Y_MAX_POS - 30)
