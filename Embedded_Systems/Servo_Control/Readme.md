**joy.c** - Manages monitoring of an analog joystick configured as a voltage divider on V+.

**main.c** - Entry point to the program.  Initiates system, peripherals, and tasks.  Uses script-style loop to execute until a reset interrupt.

**oled.c** - Drives the OLED to display the clock information, ADC values read.

**servo.c** - Generates a PWM signal to drive a standard servo, mapping an ADC reading from the joystick to 13 rotations across the servo's range of motion.
