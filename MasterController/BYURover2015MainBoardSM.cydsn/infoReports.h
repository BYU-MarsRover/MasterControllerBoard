/* ========================================
 *
 * Copyright BRIGHAM YOUNG UNIVERSITY, 2015
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF BYU.
 *
 * ========================================
*/
#ifndef INFOREPORTS_H
#define INFOREPORTS_H

#include <project.h>


    
#define CHAR_ARRAY_MAX_SIZE 80
    
/* Internal Structs */
typedef struct todolist
{
    uint16 leftWheels;
    uint16 rightWheels;
    uint16 gimbalPan;
    uint16 gimbalTilt;
} ToDoList;

typedef struct report
{
    uint16 leftWheels;
    uint16 rightWheels;
    uint16 gimbalPan;
    uint16 gimbalTilt;
//    char   gpsData[CHAR_ARRAY_MAX_SIZE]; 
} Report;
    
#endif
/* [] END OF FILE */
