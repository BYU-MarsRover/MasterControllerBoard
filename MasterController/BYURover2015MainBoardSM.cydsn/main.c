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
#include "wiznet5500.h"

#define UDP_SIZE 20

volatile uint16_t simulatedIncommingInfo[] = {1500, 1500, 1500, 1500};

uint8_t incomingUDP[UDP_SIZE];



/* Local vars */

volatile bool tick = true;
static const uint32 INCREMENT_AMMOUNT = 20;

volatile bool wiznetMilk = false;

Scheduler sch;


void putdata(void* p, char c)
{
    if(c == '\n')
    {
     UART_1_UartPutChar('\r');   
    }
    
 UART_1_UartPutChar(c);
}



/*Tick function ISR*/
//put tick functions here!!!!!
CY_ISR(myISR)
{
    
    uint32 intr = (uint32) Timer_GetInterruptSourceMasked();
    Timer_ClearInterrupt(intr);
    isr_ClearPending();
    
    
    /* Insert routine code here */
        tick = true;
    
    // taskScheduler(&sch, simulatedIncommingInfo);
    //printf("tick\n\r");
    
    
}

/* UART Keyboard Command Module Interrupt Service Routine (KCMISR) */

CY_ISR(uartISR)
{
    uint32 intre = (uint32) UART_1_GetRxInterruptSourceMasked();
    uint32 getChar = (uint32) UART_1_UartGetChar();
   printf("Btn");
    /* Insert interrupt code here */
    switch(getChar)
    {
        case 'w':
            printf("w");
           simulatedIncommingInfo[0] = 1900;
           simulatedIncommingInfo[1] = 1900;
        break;
        
        case 'a':
           simulatedIncommingInfo[0] = 1900;
           simulatedIncommingInfo[1] = 1500;
        break;
        
        case 's':
            simulatedIncommingInfo[0] = 1100;
            simulatedIncommingInfo[1] = 1100;
        break;
        
        case 'd':
            simulatedIncommingInfo[0] = 1500;
            simulatedIncommingInfo[1] = 1900;
        break;
        
        case '8':
        
        break;
        
        case '2':
       
        break;
        
        case '4':
        
        break;
        
        case '6':
        
        break;
        
        default:
        for(int i = 0; i<4; i++)
        {
            simulatedIncommingInfo[i] = 1500;
        }
        break;
        
    }
    
    UART_1_ClearRxInterruptSource(intre);
}

CY_ISR(spiISR)
{
    //wiznetClearInterrupts();
    
    //wiznetReadUdpFrame(incomingUDP, UDP_SIZE);  
    
    wiznetMilk = true;
    
    WIZ_INT_ClearInterrupt();
}



int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    /* Print */
    init_printf(NULL, putdata);
    
     /* Timers */
    Timer_Start();
     /* Comms */
    UART_1_Start();
    GPS_UART_Start();
    SPIM_Start();
    isr_StartEx(myISR);
    ISRUART_StartEx(uartISR);
    WIZ_RST_Write(1);
    WIZ_SS_Write(1);
    
    
    
    WIZ_RST_Write(0);
    CyDelay(10);
    WIZ_RST_Write(1);
    // CyDelay(50);
    
    for(uint8_t i=0; i<100; i++) if(WIZ_RDY_Read()) continue; else CyDelay(1);
    
      //Todo: the ip addresss constants
    //printf("%u",wiznetInit(3u,1u,27015u));
    wiznetInit(3u,1u,27015u);
    
    Wheels_1_Start();
    Wheels_2_Start();
    Gimbal_Start();
    
    ISRSPI_StartEx(spiISR);
    
    CyDelay(5000);
    isr_StartEx(myISR);
    
     CyGlobalIntEnable;  /* Uncomment this line to enable global interrupts. */
    
    //printf("BYU ROVER IS READY!");
   
   
    for(;;)
    {
        /* Place your application code here. */
        if(tick)
        {
         tick = false;
         taskScheduler(&sch, incomingUDP);
        }
        //if(wiznetMilk)
        if(WIZ_INT_Read()==0)
        {
        
        
        
        wiznetMilk = false;
        wiznetClearInterrupts();
        
        wiznetReadUdpFrame(incomingUDP, UDP_SIZE); 
        //printf("RecievedUDP: %u", incomingUDP[4]);
        }
       
        
        
       
       
    }
}

/* [] END OF FILE */
