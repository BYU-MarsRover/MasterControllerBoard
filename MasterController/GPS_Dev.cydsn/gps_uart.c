/* ========================================
 * gps_uart.c
 * author: Marshall Garey
 * Feb 2015
 * This file contains the uart isr for receiving gps data
 * GPS shield pinout:
 * 1 - Gnd, 2- Vin, 3 - Rx, 4 - Tx, 5 - Gnd, 6 - Directive
 * 
*/
#include "gps_uart.h"
#include <ctype.h>
#define false 0
#define true 1

static volatile enum gps_states { init, dollar, letter_g1, letter_p,
    letter_g2, letter_g3, letter_a, comma, goodData } gps_currentState;
volatile bool gps_array1_canWrite = true;
volatile char gps_data[GPS_MAX_DATA];
volatile uint16_t gps_isrCount = 0;
volatile bool gps_enable = true; 

static void gps_resetCurrState();
static void gps_clearDataArray();
static void gps_printArray();
static bool gps_isValidChar(char);

CY_ISR(my_UART_ISR)
{
    gps_isrCount++; // keep track of how many times we interrupt
    // clear interrupt and stop isr while processing
    ISR_UART_1_ClearPending();
    uint32_t mask = UART_1_GetRxInterruptSourceMasked();
    UART_1_ClearRxInterruptSource(mask);
    ISR_UART_1_Disable();
    
    if (gps_enable == true) // only output if gps_enable signal is true
    {  
        // Get current character in Rx buffer and clear Rx buffer
        char myChar = UART_1_UartGetChar();
        UART_1_SpiUartClearRxBuffer();
        //printf("%c",myChar); // print out the received character (for debugging)
        
        // ===================== perform isr state machine tasks ======================== //
    	// Start in "dollar" state 
    	// If dataArray is writeable, check for the string "$GPGGA,"
    	// If we get that string, clear the array and then
    	// fill up the data array until end of line.
    	// Then lock the array so it can't be written to any more
        static uint8_t gpsArrayIndex = 0;
        // Check for valid data:
        if (gps_isValidChar(myChar))
        {
            switch(gps_currentState)
            {	
            case init:
        	    gps_clearDataArray(); // initialize data array 
                gps_resetCurrState(); // init state 
                gpsArrayIndex = 0;
                break;
            case dollar:
                gps_array1_canWrite = true; // delete this line when we connect to main controller
                if (myChar == '$' && gps_array1_canWrite == true) {
                    gps_currentState = letter_g1;
                }
                break;
            case letter_g1:
                if (myChar == 'G') {
                    gps_currentState = letter_p; 
                } else {
                    //printf("not a G\n\r");
                    gps_resetCurrState();
                }
                break;
            case letter_p:
                if (myChar == 'P') {
                    gps_currentState = letter_g2;   
                } else {
                    //printf("Not a P\n\r");
                    gps_resetCurrState();
                }
                break;
            case letter_g2:
                if (myChar == 'G') {
                    gps_currentState = letter_g3;
                } else {
                    //printf("Not a G\n\r");
                    gps_resetCurrState();
                }
                break;
            case letter_g3:
                if (myChar == 'G') {
                    gps_currentState = letter_a;
                } else {
                    //printf("Not a G\n\r");
                    gps_resetCurrState();
                }
                break;
            case letter_a:
                if (myChar == 'A') {
                    gps_currentState = comma;
        			gps_clearDataArray(); // at this point we know that it's the correct line, so clear the array
        		} else {
                    //printf("Not an A\n\r");
                    gps_resetCurrState();  
                }
                break;
            case comma:
                if (myChar == ',') {
                    gps_currentState = goodData;
        			gpsArrayIndex = 0; // set data array index
                    //printf("gps: getting $GPGGA data\n\r");
                } else { // we shouldn't need this line, but just in case...
                    gps_resetCurrState();
                }
                break;
            case goodData:
        		// add data to buffer:
        		gps_data[gpsArrayIndex] = myChar;
        		gpsArrayIndex++;
        		// next state logic:
                if (myChar == '$') {
                    gps_printArray();
                    gps_resetCurrState(); // reset state machine
        			//gps_array1_canWrite = false; // lock array (main function will unlock it)
                    gps_clearDataArray(); // delete this line when we implement with main controller
                }
                break;
            default:
        		gps_resetCurrState();
                break;
            }
        }
        // ============================ End ISR tasks =================================== //
        
        ISR_UART_1_Enable(); // start isr before exit
    }
    return;
}

static void gps_resetCurrState()
{
    gps_currentState = dollar;
    return;
}

static void gps_clearDataArray()
{
    uint8_t i = 0;
    while (i < GPS_MAX_DATA)
    {
        gps_data[i] = '$';
        i++;
    }
    return;
}

static void gps_printArray()
{
    printf("Printing gps data array:\r\n");
    uint8_t i = 0;
    for(i = 0; i < GPS_MAX_DATA; i++)
    {
        printf("%c",gps_data[i]);    
    }
    printf("\r\n");
    return;
}

// putdata function is necessary for printf
void putdata(void* p, char c)
{
    UART_2_UartPutChar(c);
    return;
}

static bool gps_isValidChar(char myChar)
{
    if (isalpha(myChar) || isdigit(myChar) || (myChar == ',') ||
        (myChar == '$') || (myChar == '.') || (myChar == '*'))
    {
        return true;    
    }
    else return false;
}

/* [] END OF FILE */


/* ====================== EXTRA CODE ======================

    switch(gps_currentState)
    {
    case init:
	    gps_clearDataArray(); // initialize data array 
        gps_resetCurrState(); // init state 
        gpsArrayIndex = 0;
        break;
    case dollar:
        gps_printArray();
        gps_resetCurrState();
        break;
    case letter_g1:
        gps_resetCurrState();
        break;
    case letter_p:
        gps_resetCurrState();
        break;
    case letter_g2:
        gps_resetCurrState();
        break;
    case letter_g3:
        gps_resetCurrState();
        break;
    case letter_a:
        gps_resetCurrState();
        break;
    case comma:
        gps_resetCurrState();
        break;
    case goodData:
        gps_resetCurrState();
        break;
    default:
        gps_currentState = init;
        break;
    }
*/


/* Old Code:

    //printf("%u. %c, Current State: %d\n\r", gps_isrCount, myChar, gps_currentState);
    //UART_1_SpiUartClearRxBuffer(); // after printf

    switch(gps_currentState)
    {	
    case init:
	    gps_clearDataArray(); // initialize data array 
        gps_resetCurrState(); // init state 
        gpsArrayIndex = 0;
        break;
    case dollar:
        gps_array1_canWrite = true; // until I integrate this with the master 
        // controller board, just allow writing to this array
        if (myChar == '$' && gps_array1_canWrite == true)
        {
            gps_currentState = letter_g1;
        }
        break;
    case letter_g1:
        if (myChar == 'G')
        {
            gps_currentState = letter_p; 
        }
        else
        {
            //printf("not a G\n\r");
            gps_resetCurrState();
        }
        break;
        
    case letter_p:
        if (myChar == 'P')
        {
            gps_currentState = letter_g2;   
        }
        else
        {
            //printf("Not a P\n\r");
            gps_resetCurrState();
        }
        break;
    case letter_g2:
        if (myChar == 'G')
        {
            gps_currentState = letter_g3;
        }
        else
        {
            //printf("Not a G\n\r");
            gps_resetCurrState();
        }
        break;
    case letter_g3:
        if (myChar == 'G')
        {
            gps_currentState = letter_a;
        }
        else
        {
            //printf("Not a G\n\r");
            gps_resetCurrState();
        }
        break;
    case letter_a:
        if (myChar == 'A')
        {
            gps_currentState = comma;
			gps_clearDataArray(); // at this point we know that it's the correct line, so clear the array
		}
        else
        {
            //printf("Not an A\n\r");
            gps_resetCurrState();  
        }
        break;
    case comma:
        if (myChar == ',')
        {
            gps_currentState = goodData;
			gpsArrayIndex = 0; // set data array index
            //printf("gps: getting $GPGGA data\n\r");
        }
        else
        { // we shouldn't need this line, but just in case...
            gps_resetCurrState();
        }
        break;
    case goodData:
		// add data to buffer:
		gps_data[gpsArrayIndex] = myChar;
		gpsArrayIndex++;
		// next state logic:
        if (myChar == '$')
        {
            gps_printArray();
            gps_resetCurrState(); // reset state machine
			gps_array1_canWrite = false; // lock array (main function will unlock it)
            gps_clearDataArray(); // 
        }
        break;
    default:
		gps_resetCurrState();
        break;
    }
*/
