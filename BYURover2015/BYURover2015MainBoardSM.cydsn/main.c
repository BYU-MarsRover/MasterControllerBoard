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
/*========================================
 *
 * Copyright BRIGHAM YOUNG UNIVERSITY, 2015
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF BRIGHAM YOUNG UNIVERSITY.
 *
 * ========================================
*/
#include <project.h>
#include <stdbool.h>
#include <string.h>

#include "Scheduler.h"

/* Local vars */
uint32 currentPos = 1500;
volatile bool tick = true;
static const uint32 INCREMENT_AMMOUNT = 20;
Scheduler sch;

void putdata(void* p, char c)
{
    if(c == '\n')
    {
     UART_1_UartPutChar('\r');   
    }
    
 UART_1_UartPutChar(c);
}

uint32 incrementPos(uint32* pos)
{
    if(*pos > 2000)
    {
        *pos = 2000;
    }
    else if(*pos < 1000)
    {
     *pos = 1000;   
    }
    else
    {
     *pos = *pos + INCREMENT_AMMOUNT;  
    }
    
    return *pos;
}

uint32 decrementPos(uint32* pos)
{
     if(*pos > 2000)
    {
        *pos = 2000;
    }
    else if(*pos < 1000)
    {
     *pos = 1000;   
    }
    else
    {
     *pos = *pos - INCREMENT_AMMOUNT;  
    }
    
    return *pos;
}

CY_ISR(myISR)
{
    uint32 intr = (uint32) Timer_GetInterruptSourceMasked();
    
    /* Insert interrupt code here */
    
    
    Timer_ClearInterrupt(intr);
}

/* UART Keyboard Command Module Interrupt Service Routine (KCMISR) */

CY_ISR(uartISR)
{
//    uint32 intre = (uint32) UART_1_GetRxInterruptSourceMasked();
//    uint32 getChar = (uint32) UART_1_UartGetChar();
//    printf("Btn");
//    /* Insert interrupt code here */
//    switch(getChar)
//    {
//        case 'a':
//        currentPos = 1920;
//        P_WriteCompare(1920);
//        break;
//        
//        case 'd':
//        currentPos = 920;
//        SignalGenerator_WriteCompare(920);
//        break;
//        
//        case 'w':
//        currentPos = 1420;
//        P_WriteCompare(1420);
//        break;
//        
//        case 'q':
//        currentPos = 1670;
//        P_WriteCompare(1670);
//        break;
//        
//        case 'e':
//        currentPos = 1170;
//        P_WriteCompare(1170);
//        break;
//        
//        
//        
//        case ',':
//        P_WriteCompare(incrementPos(&currentPos));
//        break;
//        
//        case '.':
//        P_WriteCompare(decrementPos(&currentPos));
//        break;
//    }
//    
//    UART_1_ClearRxInterruptSource(intre);
}


CY_ISR(Servo_isr)
{
        switch(SignalSel_Read())
        {
            
            case 0:
            SignalGenerator_WriteCompare(sch.PWMCurrentValues[0]);
            InputValue_Write(1);
            SignalSel_Write(1);  
            break;
            
            case 1:
            SignalGenerator_WriteCompare(sch.PWMCurrentValues[1]);
            InputValue_Write(1);
            SignalSel_Write(2);
            break;
            
            case 2:
            SignalGenerator_WriteCompare(sch.PWMCurrentValues[2]);
            InputValue_Write(1);
            SignalSel_Write(3);
            break;
            
            case 3:
            SignalGenerator_WriteCompare(sch.PWMCurrentValues[3]);
            InputValue_Write(1);
            SignalSel_Write(0);
            break;
            
            default:
            InputValue_Write(0);
            SignalSel_Write(0);
            break;
        
        
    }
}


int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    init_printf(NULL, putdata);
    Timer_Start();
    UART_1_Start();
    isr_StartEx(myISR);
    ISRUART_StartEx(uartISR);
    //SignalSel_Start();
    //P_Start();
    CyDelay(5000);
    isr_StartEx(myISR);
    
     CyGlobalIntEnable;  /* Uncomment this line to enable global interrupts. */
    
   
   
    tick = false;
   // breatheState = init;
    for(;;)
    {
        /* Place your application code here. */
        //printf("Hello World \n\r");
        //CyDelay(50);
       
        
        if(tick == true)
        {
        printf("tick TRUE \n\r");
        
        printf("runningTick \n\r");
       // breatheTickFunction();
        
        tick = false;
        
        }
        //Tasks to perform
        //read input State Machine
        //Ouptuts State Machine
    }
}

/* [] END OF FILE */
