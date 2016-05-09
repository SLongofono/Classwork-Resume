/*
 * joy.c
 *
 *      Created on: Apr 28, 2016
 *      Author: slongofo
 */


// Header File
#include "joy.h"

// The system.h module will be required in all future task definitions
// This will give the task access to the base libraries as well as the global variables
#include "system.h"

// Stellaris driver libraries required by these local function definitions
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/adc.h"

//include freerots stuff
// Required FreeRTOS Libraries
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


QueueHandle_t dataBuffer;
QueueHandle_t feedBack;

void joyTask(void *pvParameters) {

	//initialize queues for communication and user feedback
	dataBuffer = xQueueCreate(5, sizeof(unsigned long));
	feedBack = xQueueCreate(5, sizeof(unsigned long));

	//Enable ADC peripheral for joystick (left and right only)
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);

	//Set ADC to trigger from software, high priority
	ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0);

	//configure adc to have an interrupt, to throw it at the end of the step sequence
	ADCSequenceStepConfigure(ADC0_BASE, 0, 0,(ADC_CTL_END|ADC_CTL_CH0|ADC_CTL_IE));

	//Enable the configured sequence
	ADCSequenceEnable(ADC0_BASE, 0);

	//clear the interrupt
	ADCIntClear(ADC0_BASE, 0);


	//temporary variable to catch adc vals, since queue docs are full of lies
	unsigned long temp;

	while(true) {
		// Trigger the sample sequence.
		ADCProcessorTrigger(ADC0_BASE, 0);

		// Block until the sampling completes (fcn returns 0 until interrupt is thrown)
		while(!ADCIntStatus(ADC0_BASE, 0, false)){}

		// Read the value from the ADC into a temporary var
		ADCSequenceDataGet(ADC0_BASE, 0, &temp);

		//clear the interrupt
		ADCIntClear(ADC0_BASE, 0);

		//write temp value to queue
		xQueueSend(dataBuffer, (void*) &temp, 0);

		//send ADC value to the OLDE for display
		xQueueSend(feedBack, (void*) &temp, 0);


		//return control to Task scheduler
        vTaskDelay(100*ONE_MS);
	}
}
