/*
 * wiznet_parse.h
 *
 *  Created on: Jan 31, 2015
 *      Author: cramsted joint with Jeff Nybo
 */

#ifndef WIZNET_PARSE_H_
#define WIZNET_PARSE_H_

#include <stdint.h>
    

#include "infoReports.h"
    
#define CHAR_ARRAY_MAX_SIZE 80



//needs init function
//ideally as the substructs are changed, we shouldn't have to 
//recall the init function to copy all the updated values back in. 
//typedef struct reportSuperStruct{
//	roverlink_sys_health_t sys_health; 
//	roverlink_rover_status_t rover_status;
//	roverlink_arm_status_t arm_status; 
//	//roverlink_reserved_1_t* reserved_1;		//can be added later
//	roverlink_gps_t gps; 
//	roverlink_imu_t imu;
//	//roverlink_reserved_2_t* reserved_2;		//can be added later
//	roverlink_lrs_t lrs; 
//	roverlink_drive_t drive; 
//	roverlink_video_t video; 
//	roverlink_arm_t arm; 
//	roverlink_ishaama_t ishaama; 
//	roverlink_liferay_t liferay; 
//	//roverlink_custom_debug_1_t* custom_debug_1;	// these structs can be added later if we need them
//	//roverlink_custom_debug_2_t* cutom_debug_2; 
//	//roverlink_custom_debug_3_t* custom_debug_3;
//} Report;

//parses incoming packets
void wiznet_parse(ToDoList* todo, uint8_t* RX);

//stores all system status reports and values into a large struct.
//packages the struct and sends it to the wiznet
//void send_packet(Report* report);// may not need to pass the report in

//initializes the report structure
//void report_init(Report* report);

// used for debugging purposes
//void print_ToDoList(ToDoList *todo); 

#endif /* WIZNET_PARSE_H_ */