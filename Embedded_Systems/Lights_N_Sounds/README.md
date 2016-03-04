**led.c** - Drives the status LED at regular intervals, at a scaled version of the clock frequency.

**main.c** - Entry point to the program.  Initiates system, peripherals, and tasks.  Uses script-style loop to execute until a reset interrupt.

**oled.c** - Drives the OLED to display the clock information, tick counter, and tick period.

**speaker.c** - Drives a pair of GPIO pins 180 degrees out of phase to generate a single tone on the system speaker.

**system.c** - Initializes the necessary routines to set up an artificial clock "sysTickCount" for use in the other files.
