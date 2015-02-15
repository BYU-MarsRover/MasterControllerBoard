/*
* Author: Marshall Garey
* Created on Jan 24, 2015
* Test code for interrupts with UART - for the GPS
*/
#include <project.h>
#include "gps_uart.h"

int main()
{   
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Start();
    UART_2_Start();
    ISR_UART_1_StartEx(my_UART_ISR);
    init_printf(NULL, putdata);
    
    CyGlobalIntEnable; /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */