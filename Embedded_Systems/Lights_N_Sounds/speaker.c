/*
 *  speaker.c
 *
 *  Created on: Feb 5, 2016
 *  Author: Stephen Longofono
 */


#include "speaker.h"
#include "system.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "stdio.h"

//notes to play (delay times for frequencies GAFG~~A#AFG)
//static float scale [10]= {1.2755, 1.1364, 1.4317, 1.2755, 5.0, 5.0, 1.0726, 1.1364, 1.4317, 1.2755};
//iterate over notes
static int index = 0;
static unsigned long timeToExec = 0;
static unsigned long delay = ONE_MS* 1.1364;
void extern soundINIT(){
	//Enable peripheral GPIO H for driving the speaker
	//Here, we use for the positive speaker lead, and for the negative.
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOH);


	//Set pins 0 and 1 to output,
	GPIOPinTypeGPIOOutput(GPIO_PORTH_BASE, GPIO_PIN_0 | GPIO_PIN_1);

	//Initialize them to opposite values
	GPIOPinWrite(GPIO_PORTH_BASE, (GPIO_PIN_1 | GPIO_PIN_2), (0|1));


//	timeToExec = sysTickCount + ONE_MS*scale[index];
	timeToExec = sysTickCount + delay;

}
void extern soundEXEC(){
		if(sysTickCount >= timeToExec){

			switch(GPIOPinRead(GPIO_PORTH_BASE, GPIO_PIN_0)){
					//flip the bits...assumes they are opposite, which should happen in INIT
						case 0:
							GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_0, 1);
							GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_1, 0);
							break;
						case 1:
							GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_0, 0);
							GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_1, 1);
							break;
					}
	/*		if(index<10){
				index++;
			}
			else{
				index = 0;
			}
			timeToExec = sysTickCount + ONE_MS*scale[index];
	*/
			timeToExec = sysTickCount + delay;
		}
}


//This doesn't work because we need to maintain the square wave to emit sound.  To sweep, you need to have a timed sound (note length)
//function at different delays (note pitch)

void extern soundSweepEXEC(){
		if(sysTickCount >= timeToExec){

			switch(GPIOPinRead(GPIO_PORTH_BASE, GPIO_PIN_0)){
					//flip the bits...assumes they are opposite, which should happen in INIT
						case 0:
							GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_0, 1);
							GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_1, 0);
							break;
						case 1:
							GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_0, 0);
							GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_1, 1);
							break;
					}
	/*		if(index<10){
				index++;
			}
			else{
				index = 0;
			}
			timeToExec = sysTickCount + ONE_MS*scale[index];
	*/
			timeToExec = (sysTickCount + delay + (0.02*ONE_MS));
		}
}

