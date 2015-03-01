/*******************************************************************************
* File Name: L_Servo.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_L_Servo_H) /* Pins L_Servo_H */
#define CY_PINS_L_Servo_H

#include "cytypes.h"
#include "cyfitter.h"
#include "L_Servo_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    L_Servo_Write(uint8 value) ;
void    L_Servo_SetDriveMode(uint8 mode) ;
uint8   L_Servo_ReadDataReg(void) ;
uint8   L_Servo_Read(void) ;
uint8   L_Servo_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define L_Servo_DRIVE_MODE_BITS        (3)
#define L_Servo_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - L_Servo_DRIVE_MODE_BITS))

#define L_Servo_DM_ALG_HIZ         (0x00u)
#define L_Servo_DM_DIG_HIZ         (0x01u)
#define L_Servo_DM_RES_UP          (0x02u)
#define L_Servo_DM_RES_DWN         (0x03u)
#define L_Servo_DM_OD_LO           (0x04u)
#define L_Servo_DM_OD_HI           (0x05u)
#define L_Servo_DM_STRONG          (0x06u)
#define L_Servo_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define L_Servo_MASK               L_Servo__MASK
#define L_Servo_SHIFT              L_Servo__SHIFT
#define L_Servo_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define L_Servo_PS                     (* (reg32 *) L_Servo__PS)
/* Port Configuration */
#define L_Servo_PC                     (* (reg32 *) L_Servo__PC)
/* Data Register */
#define L_Servo_DR                     (* (reg32 *) L_Servo__DR)
/* Input Buffer Disable Override */
#define L_Servo_INP_DIS                (* (reg32 *) L_Servo__PC2)


#if defined(L_Servo__INTSTAT)  /* Interrupt Registers */

    #define L_Servo_INTSTAT                (* (reg32 *) L_Servo__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define L_Servo_DRIVE_MODE_SHIFT       (0x00u)
#define L_Servo_DRIVE_MODE_MASK        (0x07u << L_Servo_DRIVE_MODE_SHIFT)


#endif /* End Pins L_Servo_H */


/* [] END OF FILE */
