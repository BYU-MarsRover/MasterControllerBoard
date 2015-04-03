/*
    BYU Mars Rover Main Board Scheduler Alpha (v1.0)
    Designed by: Jeffrey Nybo
    
    Description:
        This is a basic Scheduler intended for use on the main board of the BYU 2015
    University Rover Challenge Rover. The Scheduler consists of a basic 4 stage 
    mechanism: read, update, report, wait. Read, reads the top item in the incomming
    commands array. Update updates the actuators. Report, creates the report. Wait simply
    is a wait state to be used when there is nothing in the IncommingCommands array.
    
        Three structures are used in this implementation: IncommingCommands array, ToDoList and Report. 
    The IncommingCommands array stores all of the incomming commands from the Wiznet (or in test cases,
    from the computer via uart). The ToDoList is where all current to be executed commands are stored.
    The report is a structure that maintains all of the information that will be sent back to the 
    source (computer or wiznet).
    
    
    
    
*/
/* ========================================
 *
 * Copyright BRIGHAM YOUNG UNIVERSITY, 2015
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <project.h>
#include <stdbool.h>
#include <string.h>
#include "infoReports.h"
#include "wiznet_parse.h"
#include "gps_source.h"
//#include "wiznet5500.h"

/* Constant Declarations */

#define TIMEOUT 100000u
#define INCOMMING_MESSAGE_BUFFER_SIZE 500
#define NUMBER_OF_PWM_SIGNALS 4


typedef struct scheduler
{
    ToDoList todo;
    Report report;
    char gpsIncoming[CHAR_ARRAY_MAX_SIZE];
   // uint16 PWMCurrentValues[NUMBER_OF_PWM_SIGNALS];
} Scheduler;



void initTodoList(ToDoList* todo);

void initReport(Report* report);

void taskScheduler(Scheduler* sch, volatile uint8_t* testSignal);


#endif
/* [] END OF FILE */
