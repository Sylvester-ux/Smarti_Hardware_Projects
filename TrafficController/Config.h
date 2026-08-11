#ifndef CONFIG_H
#define CONFIG_H

/*************************************************
 *                GPIO PIN DEFINITIONS
 *************************************************/

// Main Road LEDs
#define MAIN_RED_PIN       2
#define MAIN_YELLOW_PIN    3
#define MAIN_GREEN_PIN     4

// Side Road LEDs
#define SIDE_RED_PIN       5
#define SIDE_YELLOW_PIN    6
#define SIDE_GREEN_PIN     7


/*************************************************
 *             SERIAL CONFIGURATION
 *************************************************/

#define SERIAL_BAUD_RATE   115200


/*************************************************
 *          DEFAULT SIGNAL TIMINGS (ms)
 *************************************************/

#define MAIN_GREEN_TIME    20000    // 20 seconds
#define SIDE_GREEN_TIME    15000    // 15 seconds
#define YELLOW_TIME         3000    // 3 seconds
#define ALL_RED_TIME        1000    // 1 second


/*************************************************
 *          SAFETY CONFIGURATION
 *************************************************/

#define COMM_TIMEOUT        5000    // 5 seconds

#define MIN_GREEN_TIME      5000
#define MAX_GREEN_TIME      60000


/*************************************************
 *          SYSTEM INFORMATION
 *************************************************/

#define SYSTEM_NAME         "Smart Traffic Controller"
#define FIRMWARE_VERSION    "1.0.0"

#endif