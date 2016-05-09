/********************************************************************************************
 *    	Created on: 	April 22, 2016
 * 		Author: 		Stephen Longofono
 * 		Purpose:		This project demonstrates the use of a 2-axis joystick to control a
 * 						standard servo motor.  The project makes use of the PWM library to
 * 						generate a PWM clock and a series of pulse widths which correspond
 * 						to different rotations of the servo along its range.  The joystick
 * 						acts as a voltage divider, with the neutral position close to 0.5Vcc,
 * 						the far left position at Vcc, and the far right position at reference.
 *
 * 						This project was more involved than previous projects, as the use of
 * 						PWM is poorly documented for the stellaris boards.  The internet forums
 * 						are full of lost souls, hopelessly wandering in hope that some day,
 * 						some benevolent TI employee will grace them with the magical incantations
 * 						that bring the PWM clock to life.  I was fortunate enough to receive
 * 						guidance from Dr. Minden, and leave this journal as a boon for adventurers
 * 						in the distant future.  May the sun always be at your back, and the wind
 * 						buffet your enemies with solder smoke.
 *
 *
 ********************************************************************************************/

// Project libraries
#include "src/system.h"
#include "src/oled.h"
#include "src/servo.h"
#include "src/joy.h"


//*************************************************************************************************
//	Main program to initialize hardware and execute Tasks.
//*************************************************************************************************
void main()  {
	// Create the tasks, the definitions are passed to the scheduler
	/*
	 *  BaseType_t xTaskCreate(
                            TaskFunction_t pvTaskCode,
                            const char * const pcName,
                            unsigned short usStackDepth,
                            void *pvParameters,
                            UBaseType_t uxPriority,
                            TaskHandle_t *pvCreatedTask
                          );

        taskcode = pointer to the task entry function name, which has been set up as an infinite loop
        pcname = human friendly name for debug
        usStackdepth = number of variables the task will need (stack size)
        pvParams = pointer used as a param for this task
        uxPriority - higher is more important
        pvCreated = pointer to this task to be used to reference it if need be
	 */
	xTaskCreate(OLEDTask, "OLEDTask", 256, NULL, 1, NULL);
	xTaskCreate(servoTask, "servoTask", 64, NULL, 1, NULL); // Task for PWM servo control
	xTaskCreate(joyTask, "joyTask", 64, NULL, 2, NULL); // Task for joystick control, it was a JOY! HAHA!

	//  Initialize system and ticks
	systemInit();

	// Display the initial image
	startScreen();

	// Start the FreeRTOS Scheduler, automatically handles execution priority and frequency
	vTaskStartScheduler();

	// The infinite loop is necessary for the FreeRTOS Scheduler
    while(true);
}
