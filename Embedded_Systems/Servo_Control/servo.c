/*
 *  	Created on: 	April 22, 2016
 *      Author: 	slongofo
 *      Purpose:	This program controls the servo, interpreting the signal strength reported by
 *      	  	the joystick program as the magnitude offset from neutral position.  There is an
 *      	    	offset marco defined which may need to be adjusted.  The particular joystick I used
 *      		did not exactly divide Vcc in half at neutral position, so the center reading from
 *      		the ADC was about 75 units off.  I would recommend starting with no offset, and slowly
 *      		adjusting every time you work with a new joystick.
 */

// Header Files
#include "servo.h"
#include "system.h"
#include "driverlib/pwm.h"
#include "joy.h"

// Stellaris driver libraries required by these local function definitions
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/adc.h"


//include freertos stuff
// Required FreeRTOS Libraries
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#define OFFSET -75
//Offset is necessary to compensate for the sensor itself - the voltage divider at neutral position
//shows a value greater than 50% of VCC

//we will divide rotation into 13 semi-regular increments, each representing the tick offset from
//far left over the full range of motion 2344 ticks.  Since the centerpoint did not divide into 2344,
//it is the average of the indices on either side.  Don't tell anyone.
long rotations[13] = {2345+OFFSET,2130+OFFSET,
			1917+OFFSET,1704+OFFSET,
			1491+OFFSET,1278+OFFSET,
			1172+OFFSET,1065+OFFSET,
			852+OFFSET,639+OFFSET,
			426+OFFSET,213+OFFSET,0+OFFSET};

// Reverse direction should you need it.
//{0,213,426,639,852,1065,1172,1278,1491,1704,1917,2130,2343};

//this is an initial position, and thereafter is used to adjust rotation based on the ADC return
unsigned long rotIndex = 6;

//this catches the value popped from the Queue when a new reading is available.
unsigned long queueVal;

//Adjusts the pulse width on the PWM signal to change the servo rotation.
//1172 represents the far right, and each of the rotations above offsets
//from there in terms of ticks.
void rotate(){
	PWMPulseWidthSet(PWM_BASE, PWM_OUT_0, (1172 + rotations[rotIndex]));
}

//converts an ADC value on [0,1023] to an index on [0,12]
unsigned long convertToSteps(unsigned long adcVal){
//	integer division maps it to our 13 divisions of rotation.

	return ((adcVal*12)/1023);
}



void servoTask(void *pvParameters) {


	//enable GPIOG in alternate mode for use as pwm
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);
	GPIOPinTypeGPIOOutput(GPIO_PORTG_BASE, GPIO_PIN_2);
	GPIOPadConfigSet(GPIO_PORTG_BASE, GPIO_PIN_2, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD);
	GPIOPinTypePWM(GPIO_PORTG_BASE, GPIO_PIN_2);



	/* Configure the PWM generator for count down mode with immediate updates
	* to the parameters.  Count down mode works like this:
	* |@           @           @           @
	* |  @           @           @           @
	* |    @           @           @           @
	* |#  #  @  #  #  #  @  #  #  #  @  #  #  #  @  #
	* | #  #  #@ #  #  #  #@ #  #  #  #@ #  #  #  #@ #
	* |__#__#__#_@#__#__#__#_@#__#__#__#_@#__#__#__#_@#__  time->
	*
	* The @ represents the pulse timer.  Every time it hits zero, the pulse is switched
	* to high.  This timer generates the pulse, and is denoted as the period of the PWM.
	* The # represents the pulse width timer.  This timer is checked regularly when a pulse is
	* initiated.  When this timer hits zero, the PWM switched to low until the next pulse is
	* started by the period timer.  Together, they generate a periodic square waveform with
	* a set pulse width, which is exactly what the servo needs to drive it.  Note that the timers
	* are typically aligned to start together, but I have separated them here for clarity.
	*
	*/
	PWMGenConfigure(PWM_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);

	/*Set clock divider, we will choose 32, so 50MHz divided by 32 yields 1.563MHz.
	* Our ticks are set for about 1000 clocks per tick, so to get to a 20 ms period
	* for the servo, we need 31250000 clocks or 31250 ticks.  =(20/1000*(50 MHz/32)^(-1))
	*/
	SysCtlPWMClockSet(SYSCTL_PWMDIV_32);
	PWMGenPeriodSet(PWM_BASE, PWM_GEN_0, 31250);

	/*
	 * From the datasheet for my servo, the range is 0.75 ms to 2.25 ms.
	 * This implies that center is at a 1.5ms pulse width.  Using the total period
	 * calculated above:
	 * for 0.75ms -> (0.75/20)*31250 = 1172, this is the rightmost rotation
	 * for 2.25ms -> (2.25/20)*31250 = 3516, this is the leftmost rotation
	 * Center is a 1.5ms pulse width, so we need (1.5/20)*31250 =2344
	 *
	 */
	PWMPulseWidthSet(PWM_BASE, PWM_OUT_0, 2344);

	// Enable the output of a PWM signal
	PWMOutputState(PWM_BASE, PWM_OUT_0_BIT, true);

	// Start the timers in generator 0.
	PWMGenEnable(PWM_BASE, PWM_GEN_0);

	while(true) {
		//If we get a reading from our ADC queue (populated by the joystick program)
		if(xQueueReceive(dataBuffer, (void*) &queueVal, 0)){

			//map the ADC reading to our rotations index
			rotIndex = convertToSteps(queueVal);

			//rotate to the index we assigned
			rotate();
		}
		vTaskDelay(100*ONE_MS);
	}
}
