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

void initTodoList(ToDoList* todo)
{
    todo->gimbalPan = 0;
    todo->gimbalTilt = 0;
    todo->leftWheels = 0;
    todo->rightWheels = 0;
}

void initReport(Report* report)
{
    report->gimbalPan = 0;
    report->gimbalTilt = 0;
    memset(report->gpsData, 0, CHAR_ARRAY_MAX_SIZE);
    report->leftWheels = 0;
    report->rightWheels = 0;
}

enum taskSchedulerStates {init_taskScheduler, read, update, report, wait} taskSchedulerState;

void taskScheduler()
{
    //State Actions
    switch (taskSchedulerState) 
    {
        case init_taskScheduler:
            
        break;
        case read:
        //Take top Package off of Wiznet Buffer
        //Open it up
        //Parse and save all pieces of data into ToDo list struct
        break;
        case update:
        //Write var to pwm components
        //Switch camera
        break;
        case report:
        
        break;
        case wait:
        
        break;
    }    
       
    //Transitions
    switch(taskSchedulerState)
    {
        case init_taskScheduler:
            taskSchedulerState = wait;
        break;
        case read:
        
        break;
        case update:
        
        break;
        case report:
        
        break;
        case wait:
            
        break;
        
    }
    
}

/* [] END OF FILE */
