--- Marlin-2.1.2_orig/Marlin/Configuration.h	2023-01-09 20:54:03.000654597 -0800
+++ Marlin-2.1.2/Marlin/Configuration.h	2023-01-10 15:07:54.911067929 -0800
@@ -87,7 +87,7 @@
 
 // Choose the name from boards.h that matches your setup
 #ifndef MOTHERBOARD
-  #define MOTHERBOARD BOARD_RAMPS_14_EFB
+  #define MOTHERBOARD BOARD_BTT_SKR_V1_4_TURBO
 #endif
 
 /**
@@ -120,7 +120,7 @@
  * Currently Ethernet (-2) is only supported on Teensy 4.1 boards.
  * :[-2, -1, 0, 1, 2, 3, 4, 5, 6, 7]
  */
-//#define SERIAL_PORT_2 -1
+#define SERIAL_PORT_2 -1
 //#define BAUDRATE_2 250000   // :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000] Enable to override BAUDRATE
 
 /**
@@ -158,12 +158,12 @@
  *          TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE
  * :['A4988', 'A5984', 'DRV8825', 'LV8729', 'TB6560', 'TB6600', 'TMC2100', 'TMC2130', 'TMC2130_STANDALONE', 'TMC2160', 'TMC2160_STANDALONE', 'TMC2208', 'TMC2208_STANDALONE', 'TMC2209', 'TMC2209_STANDALONE', 'TMC26X', 'TMC26X_STANDALONE', 'TMC2660', 'TMC2660_STANDALONE', 'TMC5130', 'TMC5130_STANDALONE', 'TMC5160', 'TMC5160_STANDALONE']
  */
-#define X_DRIVER_TYPE  A4988
-#define Y_DRIVER_TYPE  A4988
-#define Z_DRIVER_TYPE  A4988
+#define X_DRIVER_TYPE  TMC2209
+#define Y_DRIVER_TYPE  TMC2209
+#define Z_DRIVER_TYPE  TMC2209
 //#define X2_DRIVER_TYPE A4988
 //#define Y2_DRIVER_TYPE A4988
-//#define Z2_DRIVER_TYPE A4988
+#define Z2_DRIVER_TYPE TMC2209
 //#define Z3_DRIVER_TYPE A4988
 //#define Z4_DRIVER_TYPE A4988
 //#define I_DRIVER_TYPE  A4988
@@ -172,7 +172,7 @@
 //#define U_DRIVER_TYPE  A4988
 //#define V_DRIVER_TYPE  A4988
 //#define W_DRIVER_TYPE  A4988
-#define E0_DRIVER_TYPE A4988
+#define E0_DRIVER_TYPE TMC2209
 //#define E1_DRIVER_TYPE A4988
 //#define E2_DRIVER_TYPE A4988
 //#define E3_DRIVER_TYPE A4988
@@ -536,7 +536,7 @@
  *   999 : Dummy Table that ALWAYS reads 100°C or the temperature defined below.
  *
  */
-#define TEMP_SENSOR_0 1
+#define TEMP_SENSOR_0 1047
 #define TEMP_SENSOR_1 0
 #define TEMP_SENSOR_2 0
 #define TEMP_SENSOR_3 0
@@ -544,7 +544,7 @@
 #define TEMP_SENSOR_5 0
 #define TEMP_SENSOR_6 0
 #define TEMP_SENSOR_7 0
-#define TEMP_SENSOR_BED 0
+#define TEMP_SENSOR_BED 1
 #define TEMP_SENSOR_PROBE 0
 #define TEMP_SENSOR_CHAMBER 0
 #define TEMP_SENSOR_COOLER 0
@@ -619,7 +619,7 @@
 // Above this temperature the heater will be switched off.
 // This can protect components from overheating, but NOT from shorts and failures.
 // (Use MINTEMP for thermistor short/failure protection.)
-#define HEATER_0_MAXTEMP 275
+#define HEATER_0_MAXTEMP 310
 #define HEATER_1_MAXTEMP 275
 #define HEATER_2_MAXTEMP 275
 #define HEATER_3_MAXTEMP 275
@@ -627,7 +627,7 @@
 #define HEATER_5_MAXTEMP 275
 #define HEATER_6_MAXTEMP 275
 #define HEATER_7_MAXTEMP 275
-#define BED_MAXTEMP      150
+#define BED_MAXTEMP      120
 #define CHAMBER_MAXTEMP  60
 
 /**
@@ -1042,7 +1042,7 @@
 //#define USE_VMIN_PLUG
 //#define USE_WMIN_PLUG
 //#define USE_XMAX_PLUG
-//#define USE_YMAX_PLUG
+#define USE_YMAX_PLUG
 //#define USE_ZMAX_PLUG
 //#define USE_IMAX_PLUG
 //#define USE_JMAX_PLUG
@@ -1102,9 +1102,9 @@
 #endif
 
 // Mechanical endstop with COM to ground and NC to Signal uses "false" here (most common setup).
-#define X_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
-#define Y_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
-#define Z_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
+#define X_MIN_ENDSTOP_INVERTING true  // Set to true to invert the logic of the endstop.
+#define Y_MIN_ENDSTOP_INVERTING true  // Set to true to invert the logic of the endstop.
+#define Z_MIN_ENDSTOP_INVERTING true  // Set to true to invert the logic of the endstop.
 #define I_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
 #define J_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
 #define K_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
@@ -1112,7 +1112,7 @@
 #define V_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
 #define W_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
 #define X_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
-#define Y_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
+#define Y_MAX_ENDSTOP_INVERTING true  // Used YMAX for dual Z endstop. Set to true to invert the logic of the endstop.
 #define Z_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
 #define I_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
 #define J_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
@@ -1168,7 +1168,7 @@
  * Override with M92
  *                                      X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
  */
-#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 500 }
+#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80.4, 80.4, 400, 425 }
 
 /**
  * Default Max Feed Rate (linear=mm/s, rotational=°/s)
@@ -1640,7 +1640,7 @@
 // @section motion
 
 // Invert the stepper direction. Change (or reverse the motor connector) if an axis goes the wrong way.
-#define INVERT_X_DIR false
+#define INVERT_X_DIR true
 #define INVERT_Y_DIR true
 #define INVERT_Z_DIR false
 //#define INVERT_I_DIR false
@@ -1653,7 +1653,7 @@
 // @section extruder
 
 // For direct drive extruder v9 set to true, for geared extruder set to false.
-#define INVERT_E0_DIR false
+#define INVERT_E0_DIR true
 #define INVERT_E1_DIR false
 #define INVERT_E2_DIR false
 #define INVERT_E3_DIR false
@@ -1694,8 +1694,8 @@
 // @section geometry
 
 // The size of the printable area
-#define X_BED_SIZE 200
-#define Y_BED_SIZE 200
+#define X_BED_SIZE 325
+#define Y_BED_SIZE 325
 
 // Travel limits (linear=mm, rotational=°) after homing, corresponding to endstop positions.
 #define X_MIN_POS 0
@@ -1703,7 +1703,7 @@
 #define Z_MIN_POS 0
 #define X_MAX_POS X_BED_SIZE
 #define Y_MAX_POS Y_BED_SIZE
-#define Z_MAX_POS 200
+#define Z_MAX_POS 415
 //#define I_MIN_POS 0
 //#define I_MAX_POS 50
 //#define J_MIN_POS 0
@@ -1771,7 +1771,7 @@
  * RAMPS-based boards use SERVO3_PIN for the first runout sensor.
  * For other boards you may need to define FIL_RUNOUT_PIN, FIL_RUNOUT2_PIN, etc.
  */
-//#define FILAMENT_RUNOUT_SENSOR
+#define FILAMENT_RUNOUT_SENSOR
 #if ENABLED(FILAMENT_RUNOUT_SENSOR)
   #define FIL_RUNOUT_ENABLED_DEFAULT true // Enable the sensor on startup. Override with M412 followed by M500.
   #define NUM_RUNOUT_SENSORS   1          // Number of sensors, up to one per extruder. Define a FIL_RUNOUT#_PIN for each.
@@ -2026,13 +2026,13 @@
 #endif
 
 // Add a menu item to move between bed corners for manual bed adjustment
-//#define LCD_BED_TRAMMING
+#define LCD_BED_TRAMMING
 
 #if ENABLED(LCD_BED_TRAMMING)
   #define BED_TRAMMING_INSET_LFRB { 30, 30, 30, 30 } // (mm) Left, Front, Right, Back insets
-  #define BED_TRAMMING_HEIGHT      0.0        // (mm) Z height of nozzle at leveling points
-  #define BED_TRAMMING_Z_HOP       4.0        // (mm) Z height of nozzle between leveling points
-  //#define BED_TRAMMING_INCLUDE_CENTER       // Move to the center after the last corner
+  #define BED_TRAMMING_HEIGHT      0.2        // (mm) Z height of nozzle at leveling points
+  #define BED_TRAMMING_Z_HOP       8.0        // (mm) Z height of nozzle between leveling points
+  #define BED_TRAMMING_INCLUDE_CENTER       // Move to the center after the last corner
   //#define BED_TRAMMING_USE_PROBE
   #if ENABLED(BED_TRAMMING_USE_PROBE)
     #define BED_TRAMMING_PROBE_TOLERANCE 0.1  // (mm)
@@ -2176,7 +2176,7 @@
  *   M501 - Read settings from EEPROM. (i.e., Throw away unsaved changes)
  *   M502 - Revert settings to "factory" defaults. (Follow with M500 to init the EEPROM.)
  */
-//#define EEPROM_SETTINGS     // Persistent storage with M500 and M501
+#define EEPROM_SETTINGS     // Persistent storage with M500 and M501
 //#define DISABLE_M503        // Saves ~2700 bytes of flash. Disable for release!
 #define EEPROM_CHITCHAT       // Give feedback on EEPROM commands. Disable to save PROGMEM.
 #define EEPROM_BOOT_SILENT    // Keep M503 quiet and only give errors during first load
@@ -2215,14 +2215,14 @@
 // Preheat Constants - Up to 10 are supported without changes
 //
 #define PREHEAT_1_LABEL       "PLA"
-#define PREHEAT_1_TEMP_HOTEND 180
-#define PREHEAT_1_TEMP_BED     70
+#define PREHEAT_1_TEMP_HOTEND 195
+#define PREHEAT_1_TEMP_BED     62
 #define PREHEAT_1_TEMP_CHAMBER 35
 #define PREHEAT_1_FAN_SPEED     0 // Value from 0 to 255
 
-#define PREHEAT_2_LABEL       "ABS"
-#define PREHEAT_2_TEMP_HOTEND 240
-#define PREHEAT_2_TEMP_BED    110
+#define PREHEAT_2_LABEL       "PETG"
+#define PREHEAT_2_TEMP_HOTEND 235
+#define PREHEAT_2_TEMP_BED    82
 #define PREHEAT_2_TEMP_CHAMBER 35
 #define PREHEAT_2_FAN_SPEED     0 // Value from 0 to 255
 
@@ -2239,14 +2239,14 @@
  *    P1  Raise the nozzle always to Z-park height.
  *    P2  Raise the nozzle by Z-park amount, limited to Z_MAX_POS.
  */
-//#define NOZZLE_PARK_FEATURE
+#define NOZZLE_PARK_FEATURE
 
 #if ENABLED(NOZZLE_PARK_FEATURE)
   // Specify a park position as { X, Y, Z_raise }
   #define NOZZLE_PARK_POINT { (X_MIN_POS + 10), (Y_MAX_POS - 10), 20 }
   #define NOZZLE_PARK_MOVE          0   // Park motion: 0 = XY Move, 1 = X Only, 2 = Y Only, 3 = X before Y, 4 = Y before X
   #define NOZZLE_PARK_Z_RAISE_MIN   2   // (mm) Always raise Z by at least this distance
-  #define NOZZLE_PARK_XY_FEEDRATE 100   // (mm/s) X and Y axes feedrate (also used for delta Z axis)
+  #define NOZZLE_PARK_XY_FEEDRATE  60   // (mm/s) X and Y axes feedrate (also used for delta Z axis)
   #define NOZZLE_PARK_Z_FEEDRATE    5   // (mm/s) Z axis feedrate (not used for delta printers)
 #endif
 
@@ -2461,7 +2461,7 @@
  * SD Card support is disabled by default. If your controller has an SD slot,
  * you must uncomment the following option or it won't work.
  */
-//#define SDSUPPORT
+#define SDSUPPORT
 
 /**
  * SD CARD: ENABLE CRC
@@ -2732,7 +2732,7 @@
 // RepRapDiscount FULL GRAPHIC Smart Controller
 // https://reprap.org/wiki/RepRapDiscount_Full_Graphic_Smart_Controller
 //
-//#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
+#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
 
 //
 // K.3D Full Graphic Smart Controller
