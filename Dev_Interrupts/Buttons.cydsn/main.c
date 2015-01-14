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
#include <project.h>
#include "events.h"

void putdata(void* p, char c);

volatile uint16_t sys_events = 0;
volatile uint16_t compareValue = NEUTRAL;


int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    CyGlobalIntEnable;  /* Uncomment this line to enable global interrupts. */
    // start various components
    ISR_Btn0_StartEx(ISR_Btn0_Interrupt);
    ISR_Bnt1_StartEx(ISR_Bnt1_Interrupt);
    ISR_Timer1_StartEx(ISR_Timer1_Interrupt);
    Timer1_Start();
    PWM_Servo_Start();
    Clock_2_Start();
    init_printf(NULL, putdata);
    UART_1_Start();
    ISR_UART_Rx_StartEx(ISR_UART_Rx_Interrupt);
    
    // init variables and LEDs
    sys_events = 0; // clear all pending events
    compareValue = NEUTRAL;
    LED_Write(0); // turn LED's off
    LED1_Write(0); 
    for(;;)
    {
        //CyDisableInts()
        CySysPmSleep(); // sleep until interrupt wakes up processor
        //printf("wake up!");
        if (sys_events) // if any events are pending
        {
            if (sys_events & PWM_MOVE_SERVO_EVENT)
            {
                sys_events &= ~PWM_MOVE_SERVO_EVENT;
                PWM_MOVE_SERVO_EVENT_func();
                //printf("move servo\n");
            }
            else if (sys_events & BTN0_EVENT)
            {
                sys_events &= ~BTN0_EVENT; // clear pending event flag
                BTN0_EVENT_func(); // call event.
                printf("btn0!\n");
            }
            else if (sys_events & BTN1_EVENT)
            {
                sys_events &= ~BTN1_EVENT;  
                BTN1_EVENT_func(); 
                printf("btn1!\n");
            }
        } // end if (sys_events)
    } // end while(1)
} // end main

void putdata(void* p, char c)
{
    
    if (c == '\n')
    {
        UART_1_UartPutChar('\r'); // insert carriage return
    }
    UART_1_UartPutChar(c);
}
/*
void doStuff()
{
    char currChar = UART_1_UartGetChar();  
    
    switch(currChar)
    {
     case 'w':   
        break;
    }
}*/

/* [] END OF FILE */
