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

#include <project.h>
#include <stdbool.h>
#include <string.h>

/* Constant Declarations */

#define INCOMMING_MESSAGE_BUFFER_SIZE 500
#define CHAR_ARRAY_MAX_SIZE 80
/* Internal Structs */
typedef struct todolist
{
    uint16 leftWheels;
    uint16 rightWheels;
    uint16 gimbalPan;
    uint16 gimbalTilt;
} ToDoList;

typedef struct report
{
    uint16 leftWheels;
    uint16 rightWheels;
    uint16 gimbalPan;
    uint16 gimbalTilt;
    char   gpsData[CHAR_ARRAY_MAX_SIZE]; 
} Report;

typedef struct scheduler
{
    ToDoList todo;
    Report report;
    uint16 IncommingMessages[INCOMMING_MESSAGE_BUFFER_SIZE];
    uint16 PWMCurrentValues[4];
} Scheduler;

char gpsIncoming[CHAR_ARRAY_MAX_SIZE];

void initTodoList(ToDoList* todo);

void initReport(Report* report);

void taskScheduler();



/* [] END OF FILE */
