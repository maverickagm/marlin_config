--- Marlin-2.1.2_orig/Marlin/Configuration_adv.h	2023-01-09 20:54:03.000654597 -0800
+++ Marlin-2.1.2/Marlin/Configuration_adv.h	2023-01-10 14:29:26.207292233 -0800
@@ -836,9 +836,9 @@
 #ifdef Z2_DRIVER_TYPE
   //#define INVERT_Z2_VS_Z_DIR        // Z2 direction signal is the opposite of Z
 
-  //#define Z_MULTI_ENDSTOPS          // Other Z axes have their own endstops
+  #define Z_MULTI_ENDSTOPS          // Other Z axes have their own endstops
   #if ENABLED(Z_MULTI_ENDSTOPS)
-    #define Z2_USE_ENDSTOP   _XMAX_   // Z2 endstop board plug. Don't forget to enable USE_*_PLUG.
+    #define Z2_USE_ENDSTOP   _YMAX_   // Z2 endstop board plug. Don't forget to enable USE_*_PLUG.
     #define Z2_ENDSTOP_ADJUSTMENT 0   // Z2 offset relative to Y endstop
   #endif
   #ifdef Z3_DRIVER_TYPE
@@ -1630,11 +1630,11 @@
   // LCD's font must contain the characters. Check your selected LCD language.
   //#define UTF_FILENAME_SUPPORT
 
-  //#define LONG_FILENAME_HOST_SUPPORT    // Get the long filename of a file/folder with 'M33 <dosname>' and list long filenames with 'M20 L'
-  //#define LONG_FILENAME_WRITE_SUPPORT   // Create / delete files with long filenames via M28, M30, and Binary Transfer Protocol
+  #define LONG_FILENAME_HOST_SUPPORT    // Get the long filename of a file/folder with 'M33 <dosname>' and list long filenames with 'M20 L'
+  #define LONG_FILENAME_WRITE_SUPPORT   // Create / delete files with long filenames via M28, M30, and Binary Transfer Protocol
   //#define M20_TIMESTAMP_SUPPORT         // Include timestamps by adding the 'T' flag to M20 commands
 
-  //#define SCROLL_LONG_FILENAMES         // Scroll long filenames in the SD card menu
+  #define SCROLL_LONG_FILENAMES         // Scroll long filenames in the SD card menu
 
   //#define SD_ABORT_NO_COOLDOWN          // Leave the heaters on after Stop Print (not recommended!)
 
@@ -1650,7 +1650,7 @@
 
   //#define SD_REPRINT_LAST_SELECTED_FILE // On print completion open the LCD Menu and select the same file
 
-  //#define AUTO_REPORT_SD_STATUS         // Auto-report media status with 'M27 S<seconds>'
+  #define AUTO_REPORT_SD_STATUS         // Auto-report media status with 'M27 S<seconds>'
 
   /**
    * Support for USB thumb drives using an Arduino USB Host Shield or
@@ -1735,7 +1735,7 @@
    *
    * :[ 'LCD', 'ONBOARD', 'CUSTOM_CABLE' ]
    */
-  //#define SDCARD_CONNECTION LCD
+  #define SDCARD_CONNECTION ONBOARD
 
   // Enable if SD detect is rendered useless (e.g., by using an SD extender)
   //#define NO_SD_DETECT
@@ -1840,9 +1840,9 @@
   //#define BOOT_MARLIN_LOGO_ANIMATED // Animated Marlin logo. Costs ~3260 (or ~940) bytes of flash.
 
   // Frivolous Game Options
-  //#define MARLIN_BRICKOUT
-  //#define MARLIN_INVADERS
-  //#define MARLIN_SNAKE
+  #define MARLIN_BRICKOUT
+  #define MARLIN_INVADERS
+  #define MARLIN_SNAKE
   //#define GAMES_EASTER_EGG          // Add extra blank lines above the "Games" sub-menu
 
 #endif // HAS_MARLINUI_U8GLIB
@@ -2058,7 +2058,7 @@
  *
  * Warning: Does not respect endstops!
  */
-//#define BABYSTEPPING
+#define BABYSTEPPING
 #if ENABLED(BABYSTEPPING)
   //#define INTEGRATED_BABYSTEPPING         // EXPERIMENTAL integration of babystepping into the Stepper ISR
   //#define BABYSTEP_WITHOUT_HOMING
@@ -2105,17 +2105,17 @@
  *
  * See https://marlinfw.org/docs/features/lin_advance.html for full instructions.
  */
-//#define LIN_ADVANCE
+#define LIN_ADVANCE
 #if ENABLED(LIN_ADVANCE)
   #if ENABLED(DISTINCT_E_FACTORS)
     #define ADVANCE_K { 0.22 }    // (mm) Compression length per 1mm/s extruder speed, per extruder
   #else
-    #define ADVANCE_K 0.22        // (mm) Compression length applying to all extruders
+    #define ADVANCE_K 0.0         // (mm) Compression length applying to all extruders
   #endif
   //#define ADVANCE_K_EXTRA       // Add a second linear advance constant, configurable with M900 L.
   //#define LA_DEBUG              // Print debug information to serial during operation. Disable for production use.
   //#define EXPERIMENTAL_SCURVE   // Allow S-Curve Acceleration to be used with LA.
-  //#define ALLOW_LOW_EJERK       // Allow a DEFAULT_EJERK value of <10. Recommended for direct drive hotends.
+  #define ALLOW_LOW_EJERK       // Allow a DEFAULT_EJERK value of <10. Recommended for direct drive hotends.
   //#define EXPERIMENTAL_I2S_LA   // Allow I2S_STEPPER_STREAM to be used with LA. Performance degrades as the LA step rate reaches ~20kHz.
 #endif
 
@@ -2440,7 +2440,7 @@
  * Currently handles M108, M112, M410, M876
  * NOTE: Not yet implemented for all platforms.
  */
-//#define EMERGENCY_PARSER
+#define EMERGENCY_PARSER
 
 /**
  * Realtime Reporting (requires EMERGENCY_PARSER)
@@ -2476,7 +2476,7 @@
 #define SERIAL_OVERRUN_PROTECTION
 
 // For serial echo, the number of digits after the decimal point
-//#define SERIAL_FLOAT_PRECISION 4
+#define SERIAL_FLOAT_PRECISION 4
 
 /**
  * Set the number of proportional font spaces required to fill up a typical character space.
@@ -2633,7 +2633,7 @@
  *
  * Enable PARK_HEAD_ON_PAUSE to add the G-code M125 Pause and Park.
  */
-//#define ADVANCED_PAUSE_FEATURE
+#define ADVANCED_PAUSE_FEATURE
 #if ENABLED(ADVANCED_PAUSE_FEATURE)
   #define PAUSE_PARK_RETRACT_FEEDRATE         60  // (mm/s) Initial retract feedrate.
   #define PAUSE_PARK_RETRACT_LENGTH            2  // (mm) Initial retract.
@@ -2667,16 +2667,16 @@
   #define FILAMENT_UNLOAD_PURGE_LENGTH         8  // (mm) An unretract is done, then this length is purged.
   #define FILAMENT_UNLOAD_PURGE_FEEDRATE      25  // (mm/s) feedrate to purge before unload
 
-  #define PAUSE_PARK_NOZZLE_TIMEOUT           45  // (seconds) Time limit before the nozzle is turned off for safety.
+  #define PAUSE_PARK_NOZZLE_TIMEOUT           60  // (seconds) Time limit before the nozzle is turned off for safety.
   #define FILAMENT_CHANGE_ALERT_BEEPS         10  // Number of alert beeps to play when a response is needed.
   #define PAUSE_PARK_NO_STEPPER_TIMEOUT           // Enable for XYZ steppers to stay powered on during filament change.
   //#define FILAMENT_CHANGE_RESUME_ON_INSERT      // Automatically continue / load filament when runout sensor is triggered again.
   //#define PAUSE_REHEAT_FAST_RESUME              // Reduce number of waits by not prompting again post-timeout before continuing.
 
-  //#define PARK_HEAD_ON_PAUSE                    // Park the nozzle during pause and filament change.
+  #define PARK_HEAD_ON_PAUSE                      // Park the nozzle during pause and filament change.
   //#define HOME_BEFORE_FILAMENT_CHANGE           // If needed, home before parking for filament change
 
-  //#define FILAMENT_LOAD_UNLOAD_GCODES           // Add M701/M702 Load/Unload G-codes, plus Load/Unload in the LCD Prepare menu.
+  #define FILAMENT_LOAD_UNLOAD_GCODES           // Add M701/M702 Load/Unload G-codes, plus Load/Unload in the LCD Prepare menu.
   //#define FILAMENT_UNLOAD_ALL_EXTRUDERS         // Allow M702 to unload all extruders above a minimum target temp (as set by M302)
 #endif
 
@@ -2857,7 +2857,7 @@
   #endif
 
   #if AXIS_IS_TMC_CONFIG(E0)
-    #define E0_CURRENT      800
+    #define E0_CURRENT      900
     #define E0_MICROSTEPS    16
     #define E0_RSENSE         0.11
     #define E0_CHAIN_POS     -1
@@ -3048,7 +3048,7 @@
    * Define your own with:
    * { <off_time[1..15]>, <hysteresis_end[-3..12]>, hysteresis_start[1..8] }
    */
-  #define CHOPPER_TIMING CHOPPER_DEFAULT_12V        // All axes (override below)
+  #define CHOPPER_TIMING CHOPPER_DEFAULT_24V        // All axes (override below)
   //#define CHOPPER_TIMING_X  CHOPPER_TIMING        // For X Axes (override below)
   //#define CHOPPER_TIMING_X2 CHOPPER_TIMING_X
   //#define CHOPPER_TIMING_Y  CHOPPER_TIMING        // For Y Axes (override below)
@@ -3085,7 +3085,7 @@
    * M912 - Clear stepper driver overtemperature pre-warn condition flag.
    * M122 - Report driver parameters (Requires TMC_DEBUG)
    */
-  //#define MONITOR_DRIVER_STATUS
+  #define MONITOR_DRIVER_STATUS
 
   #if ENABLED(MONITOR_DRIVER_STATUS)
     #define CURRENT_STEP_DOWN     50  // [mA]
@@ -3605,14 +3605,14 @@
 /**
  * Auto-report position with M154 S<seconds>
  */
-//#define AUTO_REPORT_POSITION
+#define AUTO_REPORT_POSITION
 
 /**
  * Include capabilities in M115 output
  */
 #define EXTENDED_CAPABILITIES_REPORT
 #if ENABLED(EXTENDED_CAPABILITIES_REPORT)
-  //#define M115_GEOMETRY_REPORT
+  #define M115_GEOMETRY_REPORT
 #endif
 
 // @section security
@@ -3657,11 +3657,11 @@
 // @section reporting
 
 // Extra options for the M114 "Current Position" report
-//#define M114_DETAIL         // Use 'M114` for details to check planner calculations
+#define M114_DETAIL         // Use 'M114` for details to check planner calculations
 //#define M114_REALTIME       // Real current position based on forward kinematics
 //#define M114_LEGACY         // M114 used to synchronize on every call. Enable if needed.
 
-//#define REPORT_FAN_CHANGE   // Report the new fan speed when changed by M106 (and others)
+#define REPORT_FAN_CHANGE   // Report the new fan speed when changed by M106 (and others)
 
 // @section gcode
 
@@ -3845,12 +3845,12 @@
  * Host Prompt Support enables Marlin to use the host for user prompts so
  * filament runout and other processes can be managed from the host side.
  */
-//#define HOST_ACTION_COMMANDS
+#define HOST_ACTION_COMMANDS
 #if ENABLED(HOST_ACTION_COMMANDS)
   //#define HOST_PAUSE_M76                // Tell the host to pause in response to M76
-  //#define HOST_PROMPT_SUPPORT           // Initiate host prompts to get user feedback
+  #define HOST_PROMPT_SUPPORT             // Initiate host prompts to get user feedback
   #if ENABLED(HOST_PROMPT_SUPPORT)
-    //#define HOST_STATUS_NOTIFICATIONS   // Send some status messages to the host as notifications
+    #define HOST_STATUS_NOTIFICATIONS     // Send some status messages to the host as notifications
   #endif
   //#define HOST_START_MENU_ITEM          // Add a menu item that tells the host to start
   //#define HOST_SHUTDOWN_MENU_ITEM       // Add a menu item that tells the host to shut down
