/*
 * wiznet_parse.c
 *
 *  Created on: Jan 31, 2015
 *      Author: cramsted joint with Jeff Nybo and Steve
 */
#include "wiznet_parse.h"

//This variable needs to be implemented in the main code base. 
//It should be the variable that the recieved wiznet data is copied to when RX goes high
//volatile uint8_t RX[16] = {0x0, 0x1, 0xC, 0x8, 0x0, 0x0, 0x0, 0x4, 0x0, 0x3, 0xE, 0x8, 0x0, 0x0, 0x0, 0x0};
						// 0	1	 2	  3    4    5    6    7    8    9    10   11   12   13   14   15
// Steve's Note: Here is what the (WIZNET) payload looks like:
//  Byte:   0   1   2   3   4   5   6   7   8   9   A   B   C   D   E   F
//  Value:  C0  A8  1   al  ph  pl  zh  zl  0th 1st 2nd 3rd etc
//  Means:  |Src Ip Addr  |Src Port|#bytes| Actual Payload for the rest of the packet
//  For reference, the Python Payload Line: [0x01,0xC8,(mainSeqCount&0xFF),DRIVE_LEN,(gimbal[0]>>8)&0xFF,gimbal[0]&0xFF,(gimbal[1]>>8)&0xFF,gimbal[1]&0xFF]
//  WHAT THIS MEANS FOR YOU! : The High and Low bytes for the gimbal are 12,13 for X, 14,15 for Y, as indexed from the RX[] array
//  Here is a real (WIZNET) packet:
//  Byte:   0   1   2   3   4   5   6   7   8   9   A   B   C   D   E   F
//  Value:  C0  A8  01  01  E4  F0  00  08  01  C8  7A  05  02  89  02  06
//  Means: |Src Ip Addr   |SrcPort|#bytes | See Aligned Below:
//                                          From Basestation to Main Controller Board
//                                              Write Drive Message ID
//                                                  Packet Sequence #
//                                                      #bytes remaining in this message
//                                                          X Axis High Byte
//                                                              X Axis Low Byte
//                                                                  Y Axis High Byte
//                                                                      Y Axis Low Byte
//  Note: The X and Y Axis values are between -1000 and +1000, in this case, X is 649, Y is 518
//parses incoming packets
void wiznet_parse(ToDoList* todo, uint8_t* RX){

    int16_t left_y = ((int16_t)(((RX[12]<<8) & 0xFF00) | RX[13]) );
    int16_t right_y = ((int16_t)(((RX[14]<<8) & 0xFF00) | RX[15]) );
    
    uint16_t lw = (uint16_t)(((left_y)>>1)+1500);
    uint16_t rw = (uint16_t)(((right_y)>>1)+1500);
    
    
    
    // boundary checking:
    if (lw > 2000) todo->leftWheels = 2000;
    else if (lw < 1000) todo->leftWheels = 1000;
    else todo->leftWheels = lw;
    
    if (rw > 2000) todo->rightWheels = 2000;
    else if (rw < 1000) todo->rightWheels = 1000;
    else todo->rightWheels = rw;
    // done with boundary check
    
    
    int16_t peter =        ((int16_t)(((RX[16]<<8) & 0xFF00) | RX[17]) / 2) + 1500;
    int16_t tilt_a_whirl = ((int16_t)(((RX[18]<<8) & 0xFF00) | RX[19]) / 2) + 1500; 
    
    
	todo->gimbalPan = 	(uint16_t) peter;
	todo->gimbalTilt = 	(uint16_t) tilt_a_whirl;
	//printf("wiznet_parse is finished");
}

//stores all system status reports and values into a large struct.
//packages the struct and sends it to the wiznet
//void send_report(Report* report){//may not need to pass the report struct in since it is in the .h
//	//need to double check that I've passed the correct parameters in. 	 
//	roverlinkSendFrame(report, sizeof(report));
//}

/*void report_init(Report* report){
//system_health
	report->sys_health.systemTimestamp = 0x00;//uint32_t
	report->sys_health.systemTimestamp = 0x00; //uint8_t
	report->sys_health.cpuLoad = 0x00;//uint16_t
	report->sys_health.busErrors = 0x00;//uint16_t
	report->sys_health.ethernetErrors = 0x00;//uint16_t
	report->sys_health.someOtherMetric = 0x00;//uint16_t
//rover_status init
	report->rover_status.systemState = 0x00; //uint8_t
	report->rover_status.roverVoltage = 0x00;//uint16_t
	report->rover_status.roverCurrent = -0x7D0; //int16_t
	report->rover_status.mAhCounter = 0x00; //int32_t
	report->rover_status.ubntLinkInteg = 0x00; //uint16_t
	report->rover_status.dragonLinkRSSI = 0x00; //uint16_t
//arm_status
	report->arm_status.systemState  = 0x00; //uint8_t
	report->arm_status.dynamixelErrors = 0x00; //uint16_t
	report->arm_status.pid1_error = -0x7D0; //uint16_t
	report->arm_status.pid2_error = -0x7D0; //uint16_t
	report->arm_status.pid3_error = -0x7D0; //uint16_t
//reserved_1
//gps
	report->gps.systemTimestamp = 0x00; //uint32_t
	report->gps.lat = -0x35A4E8FF; //int32_t
	report->gps.lon = -0x6B49D1FF; //int32_t
	report->gps.alt = -0x989680; //int32_t
	report->gps.hdop = 0x00; //uint16_t
	report->gps.vdop = 0x00; //uint16_t
	report->gps.vel = 0x00; //uint16_t
	report->gps.course = 0x00; //uint16_t
	report->gps.fix_type = 0x00; //uint8_t
	report->gps.sats = 0x00; //uint8_t
//IMU
	report->imu.xacc = 0x00; //int16_t
	report->imu.yacc = 0x00; //int16_t
	report->imu.zacc = 0x00; //int16_t
	report->imu.xgyro = 0x00; //int16_t
	report->imu.ygyro = 0x00; //int16_t
	report->imu.zgyro = 0x00; //int16_t
	report->imu.xmag = 0x00; //int16_t
	report->imu.ymag = 0x00; //int16_t
	report->imu.zmag = 0x00; //int16_t
//reserved_2
//LRS 
 	report->lrs.ppmCh1 = 0x5DC; //uint16_t
 	report->lrs.ppmCh2 = 0x5DC; //uint16_t
 	report->lrs.ppmCh3 = 0x5DC; //uint16_t
 	report->lrs.ppmCh4 = 0x5DC; //uint16_t
 	report->lrs.ppmCh5 = 0x5DC; //uint16_t
 	report->lrs.ppmCh6 = 0x5DC; //uint16_t
 	report->lrs.ppmCh7 = 0x5DC; //uint16_t
 	report->lrs.ppmCh8 = 0x5DC; //uint16_t
 //DRIVE
 	report->drive.driveFwd = 0x00; //in16_t
 	report->drive.driveTurn = 0x00; //int16_t
 //VIDEO
 	report->video.gimbalPan = 0x00; //int16_t
 	report->video.gimbalTilt = 0x00; // int16_t
 	report->video.gimbalZoom = 0x00; //uint16_t
 	report->video.camSelect = 0x00; //int8_t
 //ARM
 	report->arm.baseAzimuth = 0x00; //int16_t
 	report->arm.shoulder = 0x00; //int16_t
 	report->arm.elbow = 0x00; //int16_t
 	report->arm.wristTilt = 0x00; //int16_t
 	report->arm.wristRotate = 0x00; //int16_t
 	report->arm.effectorA = 0x00; //int16_t
 	report->arm.effectorB = 0x00; //int16_t
//ISHAAMA
 	report->ishaama.hygrometer = 0x00; //uint16-t
 	report->ishaama.phMeter = 0x00; //uint16_t
 //LIFERAY
 	report->liferay.laserDutyCycle = 0x00; //uint8_t
 //custom_debug_1
 //custom_debug_2
 //custom_debug_3
}*/