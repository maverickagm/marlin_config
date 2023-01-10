--- Marlin-2.0.7.2_orig/Marlin/Configuration_adv.h	2021-01-30 13:12:38.584682406 -0800
+++ Marlin-2.0.7.2/Marlin/Configuration_adv.h	2021-04-12 19:17:03.286736607 -0700
@@ -573,12 +573,12 @@
 //
 // For Z set the number of stepper drivers
 //
-#define NUM_Z_STEPPER_DRIVERS 1   // (1-4) Z options change based on how many
+#define NUM_Z_STEPPER_DRIVERS 2   // (1-4) Z options change based on how many
 
 #if NUM_Z_STEPPER_DRIVERS > 1
-  //#define Z_MULTI_ENDSTOPS
+  #define Z_MULTI_ENDSTOPS
   #if ENABLED(Z_MULTI_ENDSTOPS)
-    #define Z2_USE_ENDSTOP          _XMAX_
+    #define Z2_USE_ENDSTOP          _YMAX_
     #define Z2_ENDSTOP_ADJUSTMENT   0
     #if NUM_Z_STEPPER_DRIVERS >= 3
       #define Z3_USE_ENDSTOP        _YMAX_
@@ -1251,10 +1251,10 @@
   #endif
 
   // This allows hosts to request long names for files and folders with M33
-  //#define LONG_FILENAME_HOST_SUPPORT
+  #define LONG_FILENAME_HOST_SUPPORT
 
   // Enable this option to scroll long filenames in the SD card menu
-  //#define SCROLL_LONG_FILENAMES
+  #define SCROLL_LONG_FILENAMES
 
   // Leave the heaters on after Stop Print (not recommended!)
   //#define SD_ABORT_NO_COOLDOWN
@@ -1338,7 +1338,7 @@
    *
    * :[ 'LCD', 'ONBOARD', 'CUSTOM_CABLE' ]
    */
-  //#define SDCARD_CONNECTION LCD
+  #define SDCARD_CONNECTION LCD
 
 #endif // SDSUPPORT
 
@@ -1650,10 +1650,10 @@
  *
  * See https://marlinfw.org/docs/features/lin_advance.html for full instructions.
  */
-//#define LIN_ADVANCE
+#define LIN_ADVANCE
 #if ENABLED(LIN_ADVANCE)
   //#define EXTRA_LIN_ADVANCE_K // Enable for second linear advance constants
-  #define LIN_ADVANCE_K 0.22    // Unit: mm compression per 1mm/s extruder speed
+  #define LIN_ADVANCE_K 0       // Unit: mm compression per 1mm/s extruder speed
   //#define LA_DEBUG            // If enabled, this will generate debug information output over USB.
   //#define EXPERIMENTAL_SCURVE // Enable this option to permit S-Curve Acceleration
 #endif
@@ -1944,7 +1944,7 @@
  * Currently handles M108, M112, M410, M876
  * NOTE: Not yet implemented for all platforms.
  */
-//#define EMERGENCY_PARSER
+#define EMERGENCY_PARSER
 
 // Bad Serial-connections can miss a received command by sending an 'ok'
 // Therefore some clients abort after 30 seconds in a timeout.
@@ -2087,7 +2087,7 @@
  * Requires NOZZLE_PARK_FEATURE.
  * This feature is required for the default FILAMENT_RUNOUT_SCRIPT.
  */
-//#define ADVANCED_PAUSE_FEATURE
+#define ADVANCED_PAUSE_FEATURE
 #if ENABLED(ADVANCED_PAUSE_FEATURE)
   #define PAUSE_PARK_RETRACT_FEEDRATE         60  // (mm/s) Initial retract feedrate.
   #define PAUSE_PARK_RETRACT_LENGTH            2  // (mm) Initial retract.
@@ -2328,7 +2328,7 @@
   #endif
 
   #if AXIS_IS_TMC(E0)
-    #define E0_CURRENT      800
+    #define E0_CURRENT      900
     #define E0_MICROSTEPS    16
     #define E0_RSENSE         0.11
     #define E0_CHAIN_POS     -1
@@ -2474,7 +2474,7 @@
    * Define you own with
    * { <off_time[1..15]>, <hysteresis_end[-3..12]>, hysteresis_start[1..8] }
    */
-  #define CHOPPER_TIMING CHOPPER_DEFAULT_12V
+  #define CHOPPER_TIMING CHOPPER_DEFAULT_24V
 
   /**
    * Monitor Trinamic drivers
@@ -2487,7 +2487,7 @@
    * M912 - Clear stepper driver overtemperature pre-warn condition flag.
    * M122 - Report driver parameters (Requires TMC_DEBUG)
    */
-  //#define MONITOR_DRIVER_STATUS
+  #define MONITOR_DRIVER_STATUS
 
   #if ENABLED(MONITOR_DRIVER_STATUS)
     #define CURRENT_STEP_DOWN     50  // [mA]
