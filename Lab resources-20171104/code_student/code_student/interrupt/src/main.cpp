/*-------------------------------
LAB EXERCISE 4 - INTERRUPT IN/OUT
PROGRAMMING USING MBED API
 --------------------------------*/

#include "mbed.h"

//Define your outputs
//Write your code here
#define RED_LED PB_4
#define GREEN_LED PC_7
#define	BLUE LED PA_9

DigitalOut red(RED_LED);
DigitalOut green(GREEN_LED);
DigitalOut blue(BLUE_LED);

//Define your interrupt inputs
//Write your code here
#define JOY_UP PA_4
#define JOY_DOWN PB_0
#define JOY_RIGHT PC_0
#define JOY_CENTER PB_5
#define JOY_LEFT PC_1

InterruptIn joy_up(JOY_UP);
InterruptIn joy_right(JOY_RIGHT);
InterruptIn joy_left(JOY_LEFT);
InterruptIn joy_center(JOY_CENTER);

//Define ISRs for the interrupts
//If the switch is high, so should the LED
//If the switch is low, so should the LED
//Remember, the LED will turn on when we give it a '0'
void button_1_handler(){
	red =! red;
}

void button_2_handler(){
	green =! green;
}

void button_3_handler(){
	blue =! blue;
}

void button_4_handler(){
	red =! red;
	green =! green;
	blue =! blue;
}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	//Enable interrupts
	//Think about which header file has this method
	//Write your code here
	__enable_irq();
	
	
	//Initially turn off all LEDs
	//Remember, the LED will turn on when we give it a '0'
	//Write your code here
	red = 1;
	green = 1;
	blue = 1;
	
	
	//Attach the handler to the rising edge of the interrupt
	//Think about which header file has this method
	//Write your code here
	button_1_handler.rise(button_1_handler);
	button_2_handler.rise(button_2_handler);
	button_3_handler.rise(button_3_handler);
	button_4_handler.rise(button_4_handler);
	
	
	//Attach the handler to the falling edge of the interrupt
	//Think about which header file has this method
	//Write your code here
	button_1_handler.falling(button_1_handler);
	button_2_handler.falling(button_2_handler);
	button_3_handler.falling(button_3_handler);
	button_4_handler.falling(button_4_handler);
	
	//Sleep on exit
	while(1){
		//__wfi();
		//Leave this line of code commented out for now
	}
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2014*************************************
