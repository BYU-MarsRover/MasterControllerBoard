/*
 * wiznet_parse.c
 *
 *  Created on: Jan 31, 2015
 *      Author: cramsted
 */
#include "wiznet_parse.h"

//This variable needs to be implemented in the main code base. 
//It should be the variable that the recieved wiznet data is copied to when RX goes high
volatile uint8_t RX[16] = {0x0, 0x1, 0xC, 0x8, 0x0, 0x0, 0x0, 0x4, 0x0, 0x3, 0xE, 0x8, 0x0, 0x0, 0x0, 0x0};
						// 0	1	 2	  3    4    5    6    7    8    9    10   11   12   13   14   15

//parses incoming packets
void wiznet_parse(ToDoList* todo){
	//printf("wiznet_parse is running");		used for debugging
	todo->leftWheels = 	(RX[8]<< 8) | RX[9];
	todo->rightWheels =  (RX[10]<<8) | RX[11];
	todo->gimbalPan = 	(RX[12]<<8) | RX[13];
	todo->gimbalTilt = 	(RX[14]<<8) | RX[15];
	//printf("wiznet_parse is finished");
}

//stores all system status reports and values into a large struct.
//packages the struct and sends it to the wiznet
void send_report(Report* report){//may not need to pass the report struct in since it is in the .h
	//need to double check that I've passed the correct parameters in. 	 
	roverlinkSendFrame(report, sizeof(report));
}
