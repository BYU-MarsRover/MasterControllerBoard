/* ========================================
 * gps_uart.c
 * author: Marshall Garey
 * Feb 2015
 * This file contains the uart isr for receiving gps data
 * GPS shield pinout:
 * 1 - Gnd, 2- Vin, 3 - Rx, 4 - Tx, 5 - Gnd, 6 - Directive
 * 
*/
#include "gps_source.h"
#include <ctype.h>
#define false 0
#define true 1

static volatile enum gps_states { init, dollar, letter_g1, letter_p,
    letter_g2, letter_g3, letter_a, comma, goodData, wait } gps_currentState;
volatile uint16_t gps_isrCount = 0;

static volatile char gps_data[GPS_MAX_DATA];
static volatile bool gps_enable = false;

volatile static bool gps_good_data = true;
volatile static bool gps_dataWasRead = false;

static void gps_resetCurrState();
static void gps_clearDataArray();
static void gps_printArray();
static bool gps_isValidChar(char);

CY_ISR(my_UART_ISR)
{
    gps_isrCount++; // keep track of how many times we interrupt
    // clear interrupt and stop isr while processing
    ISR_UART_2_ClearPending();
    uint32_t mask = GPS_UART_GetRxInterruptSourceMasked();
    GPS_UART_ClearRxInterruptSource(mask);
    ISR_UART_2_Disable();
    
    if (gps_enable == true) // only output if gps_enable signal is true
    {  
        // Get current character in Rx buffer and clear Rx buffer
        char myChar = GPS_UART_UartGetChar();
        GPS_UART_SpiUartClearRxBuffer();
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
                if (myChar == '$') {
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
                    //gps_printArray();
                    gps_good_data = true;
                    gps_currentState = wait;
                    
        			//gps_array1_canWrite = false; // lock array (main function will unlock it)
                    //gps_clearDataArray(); // delete this line when we implement with main controller
                }
                break;
            case wait:
                if (gps_dataWasRead == true) {
                    gps_good_data = false;
                    gps_resetCurrState();
                    gps_dataWasRead = false;
                    gps_clearDataArray();
                }
                break;
            default:
        		gps_resetCurrState();
                break;
            }
        }
        // ============================ End ISR tasks =================================== //
        
        ISR_UART_2_Enable(); // start isr before exit
    }
    return;
}


bool gps_isGoodData()
{
    return gps_good_data;    
}
    

static void gps_resetCurrState()
{
    gps_currentState = dollar;
    gps_dataWasRead = false;
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

//static void gps_printArray()
//{
//    printf("Printing gps data array:\r\n");
//    uint8_t i = 0;
//    for(i = 0; i < GPS_MAX_DATA; i++)
//    {
//        printf("%c",gps_data[i]);    
//    }
//    printf("\r\n");
//    return;
//}


static bool gps_isValidChar(char myChar)
{
    if (isalpha(myChar) || isdigit(myChar) || (myChar == ',') ||
        (myChar == '$') || (myChar == '.') || (myChar == '*'))
    {
        return true;    
    }
    else return false;
}

void gps_readGpsData(char* outgoing_array)
{
    memcpy(outgoing_array, gps_data, GPS_MAX_DATA);
    gps_dataWasRead = true;
}

void gps_enableGps()
{
    gps_enable = true;
}

/* [] END OF FILE */
