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

#ifndef _EVENTS_H_
#define _EVENTS_H_
    
#include <project.h>

// macros, constants, etc. ----------------
#define BTN0_EVENT              0x01u
#define BTN1_EVENT              0x02u
#define PWM_MOVE_SERVO_EVENT    0x10u
    
#define NEUTRAL                 1500
#define MAX_SERVO               2000
#define MIN_SERVO               1000
#define INC_DEC                 100
    
// funtion prototypes ---------------------
void BTN0_EVENT_func(); // button 1 event handler
void BTN1_EVENT_func(); // button 2 event handler
void PWM_MOVE_SERVO_EVENT_func(); // servo event handler
    
#endif /* _EVENTS_H_ */

/* [] END OF FILE */
