/*
 * oled.c
 *
 *  Created on: 	Aug 28, 2015
 *      Author: 	Brad Torrence
 *      Modified: 	slongofo
 *      Purpose:	This program gathers data from the quake.c program, formats it into a chart,
 *      			and displays the data.  Upon starting, it will wait for a signal (dataFlag)
 *      			indicating that data is ready.  Then, it scales the data into one of 6 divisions
 *      			and formats the data into a chart to display.  The OLED takes longer, and displays
 *      			the data, so it was given priority and the responsibility for resetting the dataFlag
 *      			variable.  In this arrangement, the ADC won't collect another dataset until the OLED is
 *      			ready and waiting.
 */

// Header File
#include "oled.h"
#include "joy.h"

// Base library
#include "system.h"

// Stellaris driver libraries
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

// OLED driver library
#include "rit128x96x4.h" // This is a driver for the OLED display extension

#include "stdio.h"

// Required FreeRTOS Libraries
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "servo.h"


// The function to generate and hold the initial start screen
//Note, this function does not have a while loop, nor does it set a "vTaskDelay", meaning
//it will only execute once.
//This is reflected in the way we use it in main; we call it a single time as a part of
//our system set up (as a blocking task), and then we enter the task scheduler loop
void startScreen(){
    /*
	 * The RIT128x96x4** functions are a part of the driver API for the OLED
	 * The details for this API can be found in drivers/rit128x96x4.c
	 *
     * Create a frame for the OLED display
     * 		The ImageDraw function takes an array of unsigned char
     * 		each 8-bit char represents 2 pixels (side-by-side)
     * 		so, 4 of these bits represent a single pixel's brightness
     * 		with valid brightness values ranging (0-15)
     * 		and the pixels are represented in pairs.
     *
     *  Since the pixels are represented in pairs along the horizontal,
     *  	and the OLED is 128x96 pixels,
     *  	the horizontal frame only needs 64 elements (64 * 2 = 128).
     *  However the vertical frames will require two separate arrays,
     *  	each will have 94 elements (the OLED is 96 pixels high
     *  	but we have taken care of the two ends with the horizontal lines)
     *  The left frame will set the right column of pixels to zero,
     *  	and the right frame will set the left column of pixels to zero.
     *  The blank array elements are initialized to 0 to turn-off pixels later.
     *  It only needs 62 elements because we don't want to erase the frame.
     */
    unsigned char lframe[94], rframe[94], hframe[64], blank[62];

    // The loop is used to initialize the arrays
    unsigned int i;
    for(i = 0; i < 94; i++){
    	lframe[i] = 0xF0; 				// Vertical line for the left edge
    	rframe[i] = 0x0F; 				// Vertical line for the right edge
    	if(i < 64) hframe[i] = 0xFF; 	// Horizontal line for top and bottom
    	if(i < 62) blank[i] = 0x00; 	// The blank line used to clear the screen
    }

    //  Initialize the OLED display
    RIT128x96x4Init(1000000);
    /*
     *  Draw the frame
     *  ImageDraw takes an array of unsigned char as the first argument
     *  	the next two arguments are the x and y coordinates (respectively)
     *  	of the screen position to start drawing, and the final two arguments
     *  	are the width and height (respectively) to which the image is scaled.
     */
    // Draw upper frame starting at (0,0) with width = 128 pixels and height = 1 pixel
    // 	(width and height should match the size of array measured in pixels)
    RIT128x96x4ImageDraw(hframe, 0, 0, 128, 1);
    // Draws lower frame starting at (0,95) width = 128, height = 1
    RIT128x96x4ImageDraw(hframe, 0, 95, 128, 1);
    // Draws left frame starting at (0,1) width = 2, height = 94
    RIT128x96x4ImageDraw(lframe, 0, 1, 2, 94);
    // Draws right frame starting at (127,1) width = 2, height = 94
    RIT128x96x4ImageDraw(rframe, 127, 1, 2, 94);

    /*
     * 	Draw the message
     * 	StringDraw takes a string as the first argument
     * 		the next two arguments are again the x and y coordinates of the starting position
     * 		and the final argument is pixel brightness for the
     * 	The first function writes the first part of the message at (32,24)
     * 		with a brightness of 15 (full brightness)
     */
	RIT128x96x4StringDraw(" Press the", 32, 24, 15);
	RIT128x96x4StringDraw("\"Select\" Button", 16, 33, 15);
	RIT128x96x4StringDraw("To Continue", 32, 42, 15);

	// Enable the select button, wait for the press, then reset and disable the port
	// The button is disabled after the splash screen and the port is reset to default for future use.
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
	GPIOPinTypeGPIOInput(GPIO_PORTG_BASE, GPIO_PIN_7); 	// Set the select button signal PG7 as input
	while(GPIOPinRead(GPIO_PORTG_BASE, GPIO_PIN_7));	// Wait until the signal changes (button pressed)
	SysCtlPeripheralReset(SYSCTL_PERIPH_GPIOG);
	SysCtlPeripheralDisable(SYSCTL_PERIPH_GPIOG);

	/*
	 *  When the select button is pressed we need to wipe the message leaving the frame on the OLED.
	 *   The loop sets the pixels to 0 everywhere except the screen's edges.
	 */
	for(i = 24; i < 50; i++)
		RIT128x96x4ImageDraw(blank, 2, i, 124, 1);
}

//The OLED Task definition
//This is set up like the other taskScheduler tasks, with a while loop and a vDelay
//dictating the control flow and execution frequency
void OLEDTask(void *pvParameters){
	unsigned long queueVal = 0;
	while(true) {
		RIT128x96x4StringDraw("Motor Control", 16, 42, 15);
		char sysTickStr[32];
		sprintf(sysTickStr, "SysTick: %d", sysTickCount);
		RIT128x96x4StringDraw(sysTickStr, 16, 51, 15);
		if(xQueueReceive(feedBack, (void*) &queueVal, 0)){
			char adc[32];
			RIT128x96x4StringDraw("                         ", 16, 60, 15);
			sprintf(adc, "ADCVAL: %d", queueVal);
			RIT128x96x4StringDraw(adc, 16, 60, 15);
		}
		vTaskDelay(ONE_MS * 200);
	}
}
