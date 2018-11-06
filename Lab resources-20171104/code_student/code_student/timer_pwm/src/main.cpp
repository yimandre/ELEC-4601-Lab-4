/*----------------------------
LAB EXERCISE 4 - TIMER AND PWM
 -----------------------------*/

#include "mbed.h"

//Define the musical notes (the frequencies of sound)
# define Do     0.5
# define Re     0.45
# define Mi     0.4
# define Fa     0.36
# define So     0.33
# define La     0.31
# define Si     0.3
# define No     0

//Define the beat lengths (e.g., whole note and half note)
# define b1     0.5
# define b2     0.25
# define b3     0.125
# define b4     0.075

//Define the musical array
float note[] = {Mi,No,Mi,No,Mi,No, Mi,No,Mi,No,Mi,No, Mi,No,So,No,Do,No,Re,No,Mi,No, Fa,No,Fa,No,Fa,No,Fa,No, Fa,No,Mi,No,Mi,No,Mi,No,Mi,No, Mi,Re,No,Re,Mi, Re,No,So,No};
float beat[] = {b3,b3,b3,b3,b2,b2, b3,b3,b3,b3,b2,b2, b3,b3,b3,b3,b3,b3,b3,b3,b2,b1, b3,b3,b3,b3,b3,b3,b3,b3, b3,b3,b3,b3,b3,b3,b4,b4,b4,b4, b2,b3,b3,b2,b2, b2,b2,b2,b2};

//Define your RGB LED
//Write your code here
#define RED_LED PB_4
#define GREEN_LED PC_7
#define BLUE_LED PA_9

PmwOut red (RED_LED);
PmwOut green (GREEN_LED);
PmwOut blue (BLUE_LED);

//Define your speaker
//Write your code here
#define speaker (speaker)
PmwOut speaker(speaker);

//Define your 2 potentiometers
//Write your code here
#define volume PA_1
#define speed PA_0

AnalogIn speed(speed);
AnalogIn volume(volume);

//Static index variable
//Hint: you will need this in the ISR
static int k = 0;

//Define your 'Ticker'
//Write your code here
Ticker ticker;


/*----------------------------------------------------------------------------
 Interrupt Service Routine
 *----------------------------------------------------------------------------*/

void timer_ISR(){ 
	/*
	The time Ticker ISR will be periodically triggered
	On every trigger, update the following:
		+ Update the PWM period of the speaker to play the next audio note
		+ Update the beat length of your interrupt source
		+ Update the colour of the RGB LED to reflect the melody changing (however you'd like)
		+ The inputs from the two potentiometers will be used to adjust the volume and the speed
		+ Switch to the next note in the musical array
	*/
	//Write your code here
	speaker.period(note[x]/300);
	speaker.write(volume/3.3);
	
	red.write(note[k]);
	red.period(k);
	
	green.write(note[k]);
	green.period(k);
	
	blue.write(note[k]);
	blue.period(k);
	
	ticker.attach(&timer_ISR,beat[k]*speed);
	
	k++;
	if(k >= 49){
		k = 0;
	}
} 

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	//Initialize the 'Ticker'
	//Write your code here
	ticker.attach(&time_ISR, 0.0);

	//Sleep on exit
	while(1){
		//__wfi();
		//Leave this line of code commented out for now
	}
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2014*************************************
