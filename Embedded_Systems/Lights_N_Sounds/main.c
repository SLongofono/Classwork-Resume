/********************************************************************************************
 *	Modified for classroom use by: 	Stephen Longofono
 * 	Original Author: 				Brad Torrence
 *	Purpose:						Example program that demonstrates:
 *									(1) setting up the system clock and SysTick Counter
 * 									(2) initializing peripherals (LED and OLED screen) and GPIO pins
 *									(3) toggling an LED by reading/writing from/to GPIO pins
 *									(4) creating and displaying a simple image on the OLED
 *									(5) formatting and displaying a string on the OLED
 *
 ********************************************************************************************/

// Project libraries
#include "src/system.h"
#include "src/oled.h"
#include "src/led.h"
#include "src/speaker.h"

//*************************************************************************************************
//	Main program to initialize hardware and execute Tasks.
//*************************************************************************************************
void main()  {
	//  Initialize system counters
	systemInit();

	// Initialize tasks
	OLEDInit();
	LEDInit();
	soundINIT();

	// Execute tasks repeatedly
    while(true){
    	OLEDExec();
    	LEDExec();
    	//soundSweepEXEC();
    	soundEXEC();
    }
}

