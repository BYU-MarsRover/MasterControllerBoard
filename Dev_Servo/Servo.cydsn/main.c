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
#include <stdint.h>

// macros ------------------------------------------------
#define ONE_SEC         40  // 1 sec - wait time at rest position
#define WAIT_DELAY      30  // 750 ms - time for servo to move
#define NEUTRAL         1500 // 1.5 ms pulse
#define MAX_LEFT        1000 // 1 ms pulse
#define MAX_RIGHT       2000 // 2 ms pulse

// global variables ------------------------------------
static volatile uint16_t compareValue = 0;
static volatile uint16_t waitDelay = 0;
static volatile uint16_t timer = 0;
static volatile enum servoStates { init, rest, moveServo,
    delay } currState = init;


// function prototypes ----------------------------------
static void servoTick();
static void my_putchar(void*, char);//(void* p, char c);

int main()
{
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */

    for(;;)
    {
        servoTick(); // write servo 
        CyDelay(25); // delay 25 ms
    }
}


// state machine
void servoTick()
{
    switch(currState)
    {
    case init:
        // initialize PWM module
        servoClock_Start();
        PWM_1_Start();
        init_printf(NULL,my_putchar);
        //UART_1_Start();        
        timer = ONE_SEC;
        waitDelay = WAIT_DELAY;
        compareValue = MAX_LEFT;
        currState = rest; // go to rest state
        break;
    case rest:
        timer--; // wait for 1 second
        if (timer == 0) // move servo after 1 second
        {
            currState = moveServo;
        }
        break;
    case moveServo:
        if (compareValue == MAX_LEFT)
        { // move it right if it's at left position
            compareValue = MAX_RIGHT;
            
        }
        else
        { // move it left if it's at right position
            compareValue = MAX_LEFT;
        }
        waitDelay = WAIT_DELAY; 
        currState = delay; // go to delay state (wait for servo to get to next position)
        break;
    case delay:
        waitDelay--;
        if (waitDelay == 0)
        { // if we've delayed long enough
            if (compareValue == MAX_LEFT)
            {
                currState = rest; // go to rest state
                timer = ONE_SEC; // reset one second timer
            }
            else
            {
                currState = moveServo; // move servo back
            }
        }
        break;
    default: // shouldn't ever get here!
        currState = init; // reset to init state if we do get here
        break;
    }
    PWM_1_WriteCompare(compareValue); // write servo position every time we get called
}

void my_putchar ( void* p, char c)
{
    // if buffer not full
    // put char c into buffer
    
}


/* [] END OF FILE */
