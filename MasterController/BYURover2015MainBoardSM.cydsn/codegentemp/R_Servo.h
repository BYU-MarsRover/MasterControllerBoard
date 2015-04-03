/*******************************************************************************
* File Name: R_Servo.h  
* Version 2.5
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

#if !defined(CY_PINS_R_Servo_H) /* Pins R_Servo_H */
#define CY_PINS_R_Servo_H

#include "cytypes.h"
#include "cyfitter.h"
#include "R_Servo_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    R_Servo_Write(uint8 value) ;
void    R_Servo_SetDriveMode(uint8 mode) ;
uint8   R_Servo_ReadDataReg(void) ;
uint8   R_Servo_Read(void) ;
uint8   R_Servo_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define R_Servo_DRIVE_MODE_BITS        (3)
#define R_Servo_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - R_Servo_DRIVE_MODE_BITS))
#define R_Servo_DRIVE_MODE_SHIFT       (0x00u)
#define R_Servo_DRIVE_MODE_MASK        (0x07u << R_Servo_DRIVE_MODE_SHIFT)

#define R_Servo_DM_ALG_HIZ         (0x00u << R_Servo_DRIVE_MODE_SHIFT)
#define R_Servo_DM_DIG_HIZ         (0x01u << R_Servo_DRIVE_MODE_SHIFT)
#define R_Servo_DM_RES_UP          (0x02u << R_Servo_DRIVE_MODE_SHIFT)
#define R_Servo_DM_RES_DWN         (0x03u << R_Servo_DRIVE_MODE_SHIFT)
#define R_Servo_DM_OD_LO           (0x04u << R_Servo_DRIVE_MODE_SHIFT)
#define R_Servo_DM_OD_HI           (0x05u << R_Servo_DRIVE_MODE_SHIFT)
#define R_Servo_DM_STRONG          (0x06u << R_Servo_DRIVE_MODE_SHIFT)
#define R_Servo_DM_RES_UPDWN       (0x07u << R_Servo_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define R_Servo_MASK               R_Servo__MASK
#define R_Servo_SHIFT              R_Servo__SHIFT
#define R_Servo_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define R_Servo_PS                     (* (reg32 *) R_Servo__PS)
/* Port Configuration */
#define R_Servo_PC                     (* (reg32 *) R_Servo__PC)
/* Data Register */
#define R_Servo_DR                     (* (reg32 *) R_Servo__DR)
/* Input Buffer Disable Override */
#define R_Servo_INP_DIS                (* (reg32 *) R_Servo__PC2)


#if defined(R_Servo__INTSTAT)  /* Interrupt Registers */

    #define R_Servo_INTSTAT                (* (reg32 *) R_Servo__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins R_Servo_H */


/* [] END OF FILE */
