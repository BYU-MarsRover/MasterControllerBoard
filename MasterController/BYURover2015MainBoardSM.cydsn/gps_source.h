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
#ifndef __GPS_SOURCE_H__
#define __GPS_SOURCE_H__

#include <project.h>
#include <stdbool.h>

#define GPS_MAX_DATA 80

CY_ISR_PROTO(my_UART_ISR);
//void putdata(void*, char);

bool gps_isGoodData(void);
void gps_readGpsData(char* outgoing_array);
void gps_enableGps(void);

#endif /* __GPS_SOURCE_H__ */

/* [] END OF FILE */