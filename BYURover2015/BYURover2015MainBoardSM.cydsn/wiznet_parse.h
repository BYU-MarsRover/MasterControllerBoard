/*
 * wiznet_parse.h
 *
 *  Created on: Jan 31, 2015
 *      Author: cramsted
 */

#ifndef WIZNET_PARSE_H_
#define WIZNET_PARSE_H_

#include <stdint.h>
#include <stdio.h>
#include "roverlink.h"
#include "wiznet5500.h"

#define CHAR_ARRAY_MAX_SIZE 80

/*
volatile uint8_t RX[16] = {0x0, 0x1, 0xC, 0x8, 0x0, 0x0, 0x0, 0x4, 0x0, 0x3, 0xE, 0x8, 0x0, 0x0, 0x0, 0x0};
						// 0	1	 2	  3    4    5    6    7    8    9    10   11   12   13   14   15
*/
//roverlinkSendFrame(pointer to first bit, size of file)
//#include wiznet5500.h
//create a super struct that contains structures 0-15 in the .xml file
//call sizeof(super_struct) to pass the size

typedef struct todolist{ //Jeff needs to change this in his code
	uint16_t leftWheels;
	uint16_t rightWheels;
	uint16_t gimbalPan;
	uint16_t gimbalTilt;
} ToDoList;

//183 bytes
typedef struct reportSuperStruct{
	roverlink_sys_health_t sys_health; 
	roverlink_rover_status_t rover_status;
	roverlink_arm_status_t arm_status; 
	//roverlink_reserved_1_t* reserved_1;		//can be added later
	roverlink_gps_t gps; 
	roverlink_imu_t imu;
	//roverlink_reserved_2_t* reserved_2;		//can be added later
	roverlink_lrs_t lrs; 
	roverlink_drive_t drive; 
	roverlink_video_t video; 
	roverlink_arm_t arm; 
	roverlink_ishaama_t ishaama; 
	roverlink_liferay_t liferay; 
	//roverlink_custom_debug_1_t* custom_debug_1;
	//roverlink_custom_debug_2_t* cutom_debug_2; 
	//roverlink_custom_debug_3_t* custom_debug_3;
} Report;


void wiznet_parse(ToDoList* todo);
void send_packet(Report *report);
//void print_ToDoList(ToDoList *todo);

#endif /* WIZNET_PARSE_H_ */
