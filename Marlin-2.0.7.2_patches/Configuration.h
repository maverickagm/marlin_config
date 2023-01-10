--- Marlin-2.0.7.2_orig/Marlin/Configuration.h	2021-01-30 13:12:38.584682406 -0800
+++ Marlin-2.0.7.2/Marlin/Configuration.h	2021-03-05 14:29:01.442476871 -0800
@@ -109,7 +109,7 @@
  * Select a secondary serial port on the board to use for communication with the host.
  * :[-1, 0, 1, 2, 3, 4, 5, 6, 7]
  */
-//#define SERIAL_PORT_2 -1
+#define SERIAL_PORT_2 -1
 
 /**
  * This setting determines the communication speed of the printer.
@@ -127,7 +127,7 @@
 
 // Choose the name from boards.h that matches your setup
 #ifndef MOTHERBOARD
-  #define MOTHERBOARD BOARD_RAMPS_14_EFB
+  #define MOTHERBOARD BOARD_BTT_SKR_V1_4_TURBO
 #endif
 
 // Name displayed in the LCD "Ready" message and Info menu
@@ -415,7 +415,7 @@
  *   998 : Dummy Table that ALWAYS reads 25°C or the temperature defined below.
  *   999 : Dummy Table that ALWAYS reads 100°C or the temperature defined below.
  */
-#define TEMP_SENSOR_0 1
+#define TEMP_SENSOR_0 1047
 #define TEMP_SENSOR_1 0
 #define TEMP_SENSOR_2 0
 #define TEMP_SENSOR_3 0
@@ -423,7 +423,7 @@
 #define TEMP_SENSOR_5 0
 #define TEMP_SENSOR_6 0
 #define TEMP_SENSOR_7 0
-#define TEMP_SENSOR_BED 0
+#define TEMP_SENSOR_BED 1
 #define TEMP_SENSOR_PROBE 0
 #define TEMP_SENSOR_CHAMBER 0
 
@@ -465,7 +465,7 @@
 // Above this temperature the heater will be switched off.
 // This can protect components from overheating, but NOT from shorts and failures.
 // (Use MINTEMP for thermistor short/failure protection.)
-#define HEATER_0_MAXTEMP 275
+#define HEATER_0_MAXTEMP 360
 #define HEATER_1_MAXTEMP 275
 #define HEATER_2_MAXTEMP 275
 #define HEATER_3_MAXTEMP 275
@@ -624,7 +624,7 @@
 #define USE_YMIN_PLUG
 #define USE_ZMIN_PLUG
 //#define USE_XMAX_PLUG
-//#define USE_YMAX_PLUG
+#define USE_YMAX_PLUG
 //#define USE_ZMAX_PLUG
 
 // Enable pullup for all endstops to prevent a floating state
@@ -654,11 +654,11 @@
 #endif
 
 // Mechanical endstop with COM to ground and NC to Signal uses "false" here (most common setup).
-#define X_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
-#define Y_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
-#define Z_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
+#define X_MIN_ENDSTOP_INVERTING true // Set to true to invert the logic of the endstop.
+#define Y_MIN_ENDSTOP_INVERTING true // Set to true to invert the logic of the endstop.
+#define Z_MIN_ENDSTOP_INVERTING true // Set to true to invert the logic of the endstop.
 #define X_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
-#define Y_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
+#define Y_MAX_ENDSTOP_INVERTING true // Used YMAX for dual Z endstop // Set to true to invert the logic of the endstop.
 #define Z_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
 #define Z_MIN_PROBE_ENDSTOP_INVERTING false // Set to true to invert the logic of the probe.
 
@@ -678,15 +678,15 @@
  *          TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE
  * :['A4988', 'A5984', 'DRV8825', 'LV8729', 'L6470', 'L6474', 'POWERSTEP01', 'TB6560', 'TB6600', 'TMC2100', 'TMC2130', 'TMC2130_STANDALONE', 'TMC2160', 'TMC2160_STANDALONE', 'TMC2208', 'TMC2208_STANDALONE', 'TMC2209', 'TMC2209_STANDALONE', 'TMC26X', 'TMC26X_STANDALONE', 'TMC2660', 'TMC2660_STANDALONE', 'TMC5130', 'TMC5130_STANDALONE', 'TMC5160', 'TMC5160_STANDALONE']
  */
-//#define X_DRIVER_TYPE  A4988
-//#define Y_DRIVER_TYPE  A4988
-//#define Z_DRIVER_TYPE  A4988
+#define X_DRIVER_TYPE  TMC2209
+#define Y_DRIVER_TYPE  TMC2209
+#define Z_DRIVER_TYPE  TMC2209
 //#define X2_DRIVER_TYPE A4988
 //#define Y2_DRIVER_TYPE A4988
-//#define Z2_DRIVER_TYPE A4988
+#define Z2_DRIVER_TYPE TMC2209
 //#define Z3_DRIVER_TYPE A4988
 //#define Z4_DRIVER_TYPE A4988
-//#define E0_DRIVER_TYPE A4988
+#define E0_DRIVER_TYPE TMC2209
 //#define E1_DRIVER_TYPE A4988
 //#define E2_DRIVER_TYPE A4988
 //#define E3_DRIVER_TYPE A4988
@@ -741,7 +741,7 @@
  * Override with M92
  *                                      X, Y, Z, E0 [, E1[, E2...]]
  */
-#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 4000, 500 }
+#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80.4, 80.4, 400, 425 }
 
 /**
  * Default Max Feed Rate (mm/s)
@@ -1086,14 +1086,14 @@
 // @section machine
 
 // Invert the stepper direction. Change (or reverse the motor connector) if an axis goes the wrong way.
-#define INVERT_X_DIR false
+#define INVERT_X_DIR true
 #define INVERT_Y_DIR true
 #define INVERT_Z_DIR false
 
 // @section extruder
 
 // For direct drive extruder v9 set to true, for geared extruder set to false.
-#define INVERT_E0_DIR false
+#define INVERT_E0_DIR true
 #define INVERT_E1_DIR false
 #define INVERT_E2_DIR false
 #define INVERT_E3_DIR false
@@ -1122,8 +1122,8 @@
 // @section machine
 
 // The size of the print bed
-#define X_BED_SIZE 200
-#define Y_BED_SIZE 200
+#define X_BED_SIZE 325
+#define Y_BED_SIZE 325
 
 // Travel limits (mm) after homing, corresponding to endstop positions.
 #define X_MIN_POS 0
@@ -1131,7 +1131,7 @@
 #define Z_MIN_POS 0
 #define X_MAX_POS X_BED_SIZE
 #define Y_MAX_POS Y_BED_SIZE
-#define Z_MAX_POS 200
+#define Z_MAX_POS 415
 
 /**
  * Software Endstops
@@ -1169,7 +1169,7 @@
  * RAMPS-based boards use SERVO3_PIN for the first runout sensor.
  * For other boards you may need to define FIL_RUNOUT_PIN, FIL_RUNOUT2_PIN, etc.
  */
-//#define FILAMENT_RUNOUT_SENSOR
+#define FILAMENT_RUNOUT_SENSOR
 #if ENABLED(FILAMENT_RUNOUT_SENSOR)
   #define FIL_RUNOUT_ENABLED_DEFAULT true // Enable the sensor on startup. Override with M412 followed by M500.
   #define NUM_RUNOUT_SENSORS   1          // Number of sensors, up to one per extruder. Define a FIL_RUNOUT#_PIN for each.
@@ -1350,13 +1350,13 @@
 #endif
 
 // Add a menu item to move between bed corners for manual bed adjustment
-//#define LEVEL_BED_CORNERS
+#define LEVEL_BED_CORNERS
 
 #if ENABLED(LEVEL_BED_CORNERS)
   #define LEVEL_CORNERS_INSET_LFRB { 30, 30, 30, 30 } // (mm) Left, Front, Right, Back insets
   #define LEVEL_CORNERS_HEIGHT      0.0   // (mm) Z height of nozzle at leveling points
-  #define LEVEL_CORNERS_Z_HOP       4.0   // (mm) Z height of nozzle between leveling points
-  //#define LEVEL_CENTER_TOO              // Move to the center after the last corner
+  #define LEVEL_CORNERS_Z_HOP       6.0   // (mm) Z height of nozzle between leveling points
+  #define LEVEL_CENTER_TOO                // Move to the center after the last corner
 #endif
 
 /**
@@ -1471,7 +1471,7 @@
  *   M501 - Read settings from EEPROM. (i.e., Throw away unsaved changes)
  *   M502 - Revert settings to "factory" defaults. (Follow with M500 to init the EEPROM.)
  */
-//#define EEPROM_SETTINGS     // Persistent storage with M500 and M501
+#define EEPROM_SETTINGS     // Persistent storage with M500 and M501
 //#define DISABLE_M503        // Saves ~2700 bytes of PROGMEM. Disable for release!
 #define EEPROM_CHITCHAT       // Give feedback on EEPROM commands. Disable to save PROGMEM.
 #define EEPROM_BOOT_SILENT    // Keep M503 quiet and only give errors during first load
@@ -1503,13 +1503,13 @@
 
 // Preheat Constants
 #define PREHEAT_1_LABEL       "PLA"
-#define PREHEAT_1_TEMP_HOTEND 180
-#define PREHEAT_1_TEMP_BED     70
+#define PREHEAT_1_TEMP_HOTEND 200
+#define PREHEAT_1_TEMP_BED     62
 #define PREHEAT_1_FAN_SPEED     0 // Value from 0 to 255
 
 #define PREHEAT_2_LABEL       "ABS"
 #define PREHEAT_2_TEMP_HOTEND 240
-#define PREHEAT_2_TEMP_BED    110
+#define PREHEAT_2_TEMP_BED    80
 #define PREHEAT_2_FAN_SPEED     0 // Value from 0 to 255
 
 /**
@@ -1523,7 +1523,7 @@
  *    P1  Raise the nozzle always to Z-park height.
  *    P2  Raise the nozzle by Z-park amount, limited to Z_MAX_POS.
  */
-//#define NOZZLE_PARK_FEATURE
+#define NOZZLE_PARK_FEATURE
 
 #if ENABLED(NOZZLE_PARK_FEATURE)
   // Specify a park position as { X, Y, Z_raise }
@@ -1531,7 +1531,7 @@
   //#define NOZZLE_PARK_X_ONLY          // X move only is required to park
   //#define NOZZLE_PARK_Y_ONLY          // Y move only is required to park
   #define NOZZLE_PARK_Z_RAISE_MIN   2   // (mm) Always raise Z by at least this distance
-  #define NOZZLE_PARK_XY_FEEDRATE 100   // (mm/s) X and Y axes feedrate (also used for delta Z axis)
+  #define NOZZLE_PARK_XY_FEEDRATE  60   // (mm/s) X and Y axes feedrate (also used for delta Z axis)
   #define NOZZLE_PARK_Z_FEEDRATE    5   // (mm/s) Z axis feedrate (not used for delta printers)
 #endif
 
@@ -1724,7 +1724,7 @@
  * SD Card support is disabled by default. If your controller has an SD slot,
  * you must uncomment the following option or it won't work.
  */
-//#define SDSUPPORT
+#define SDSUPPORT
 
 /**
  * SD CARD: SPI SPEED
@@ -1985,7 +1985,7 @@
 // RepRapDiscount FULL GRAPHIC Smart Controller
 // https://reprap.org/wiki/RepRapDiscount_Full_Graphic_Smart_Controller
 //
-//#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
+#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
 
 //
 // ReprapWorld Graphical LCD
