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
#include "events.h"

extern volatile uint16_t sys_events;
extern volatile uint16_t compareValue;

void BTN0_EVENT_func()
{
    compareValue += INC_DEC;
    if (compareValue > MAX_SERVO)
        compareValue = MAX_SERVO; // we don't allow the servo to go beyond maximum position
    //LED_Write(!LED_Read()); // just toggle LED for now.
}

void BTN1_EVENT_func()
{
    compareValue -= INC_DEC;
    if (compareValue < MIN_SERVO)
        compareValue = MIN_SERVO; // don't allow servo to go beyond min pos
    //LED1_Write(!LED1_Read()); // toggle blue LED    
}

void PWM_MOVE_SERVO_EVENT_func() // should be called every 25ms
{ // just write new compare value to PWM module to move the servo
    PWM_Servo_WriteCompare(compareValue);
}
/* [] END OF FILE */
