/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "Scheduler.h"


volatile uint16 timeoutCounter;
volatile bool recievedMessage = false;
bool messageStillNotRecievedError = false;

void initTodoList(ToDoList* todo)
{
    todo->gimbalPan   = 1500;
    todo->gimbalTilt  = 1500;
    todo->leftWheels  = 1500;
    todo->rightWheels = 1500;
}

void initReport(Report* report)
{
    report->gimbalPan   = 1500;
    report->gimbalTilt  = 1500;
//    memset(report->gpsData, 0, CHAR_ARRAY_MAX_SIZE);
    report->leftWheels  = 1500;
    report->rightWheels = 1500;
}

//static void gps_printArray(Scheduler* sch)
//{
//    printf("Printing gps data array:\r\n");
//    uint8_t i = 0;
//    for(i = 0; i < GPS_MAX_DATA; i++)
//    {
//        printf("%c",sch->gpsIncoming[i]);    
//    }
//    printf("\r\n");
//    return;
//}

enum taskSchedulerStates {init_taskScheduler, read, update, read_sensors, report, wait, reset} taskSchedulerState;


void taskScheduler(Scheduler* sch, volatile uint8_t* testSignal)
{
    //State Actions
    switch (taskSchedulerState) 
    {
        case init_taskScheduler:
        //printf("init state");
        timeoutCounter = 0;
//        gps_enableGps();
            
        break;
        case read:
        
        //Take top Package off of Wiznet Buffer
       /* sch->todo.leftWheels = testSignal[0]; 
        //printf("Test Signal 0 value read: %u", testSignal[0]);
        sch->todo.rightWheels = testSignal[1];
        sch->todo.gimbalPan = testSignal[2];
        sch->todo.gimbalTilt = testSignal[3];*/
        //Open it up
        //Parse and save all pieces of data into ToDo list struct
        
        
        
        wiznet_parse(&(sch->todo), testSignal);
        
        //printf("Left wheelie: %u \n\r", sch->todo.leftWheels);
        //printf("Right Wheelie: %u \n\r", sch->todo.leftWheels);
        //printf("Gimbal Peter Pan: %u \n\r", sch->todo.gimbalPan);
        //printf("Gimbal Tilt-a-Whirl: %u \n\r", sch->todo.gimbalTilt);
        
        //printf("READ\n\r");
        break;
        
        case update:
        
        //Write var to pwm components
        Wheels_1_WriteCompare(sch->todo.leftWheels);
        Wheels_2_WriteCompare(sch->todo.rightWheels);
        Gimbal_WriteCompare1(sch->todo.gimbalPan);
        Gimbal_WriteCompare2(sch->todo.gimbalTilt);
        
       // printf("..............Update\n\r");
        
        //Switch camera
        break;
       
        //read incomming GPS and IMU data
        case read_sensors:
//            if(gps_isGoodData())
//            {
//                gps_readGpsData(sch->gpsIncoming);
//                //gps_printArray(sch);
//            }
        break;
        
        case report:
            //wiznetWriteUdpFrame(sch->gpsIncoming, sizeof(sch->gpsIncoming));
            //wiznetSend();
        break;
        case wait:
        timeoutCounter++;
        break;
        case reset:
            sch->todo.leftWheels = 1500;
            sch->todo.rightWheels = 1500;
        break;
    }    
       
    //Transitions
    switch(taskSchedulerState)
    {
        case init_taskScheduler:
            taskSchedulerState = wait;
        break;
        case read:
            taskSchedulerState = update;
        break;
        case update:
            taskSchedulerState = read_sensors;
        break;
        case read_sensors:
            taskSchedulerState = report;
        break;
        case report:
            taskSchedulerState = wait;
        break;
        case wait:
            taskSchedulerState = read;
//            if(WIZ_INT_Read() == 0)
//            {
//                timeoutCounter = 0;
//                taskSchedulerState = read;
//            }
//            else if(timeoutCounter >= 2000)
//            {
//                timeoutCounter = 0;
//                taskSchedulerState = reset;   
//            }
//            else
//            {
//                
//                messageStillNotRecievedError = false;
//                taskSchedulerState = wait;
//            }
        break;
        case reset:
            if(WIZ_INT_Read() == 0)
            {
            taskSchedulerState = read;
            }
            else
            {
            taskSchedulerState = reset;   
            }
        break;
        
    }
    
}

/* [] END OF FILE */
