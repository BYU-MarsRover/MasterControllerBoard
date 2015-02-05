/*******************************************************************************
* File Name: Servo_1.h  
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

#if !defined(CY_PINS_Servo_1_H) /* Pins Servo_1_H */
#define CY_PINS_Servo_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Servo_1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Servo_1_Write(uint8 value) ;
void    Servo_1_SetDriveMode(uint8 mode) ;
uint8   Servo_1_ReadDataReg(void) ;
uint8   Servo_1_Read(void) ;
uint8   Servo_1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Servo_1_DRIVE_MODE_BITS        (3)
#define Servo_1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Servo_1_DRIVE_MODE_BITS))
#define Servo_1_DRIVE_MODE_SHIFT       (0x00u)
#define Servo_1_DRIVE_MODE_MASK        (0x07u << Servo_1_DRIVE_MODE_SHIFT)

#define Servo_1_DM_ALG_HIZ         (0x00u << Servo_1_DRIVE_MODE_SHIFT)
#define Servo_1_DM_DIG_HIZ         (0x01u << Servo_1_DRIVE_MODE_SHIFT)
#define Servo_1_DM_RES_UP          (0x02u << Servo_1_DRIVE_MODE_SHIFT)
#define Servo_1_DM_RES_DWN         (0x03u << Servo_1_DRIVE_MODE_SHIFT)
#define Servo_1_DM_OD_LO           (0x04u << Servo_1_DRIVE_MODE_SHIFT)
#define Servo_1_DM_OD_HI           (0x05u << Servo_1_DRIVE_MODE_SHIFT)
#define Servo_1_DM_STRONG          (0x06u << Servo_1_DRIVE_MODE_SHIFT)
#define Servo_1_DM_RES_UPDWN       (0x07u << Servo_1_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define Servo_1_MASK               Servo_1__MASK
#define Servo_1_SHIFT              Servo_1__SHIFT
#define Servo_1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Servo_1_PS                     (* (reg32 *) Servo_1__PS)
/* Port Configuration */
#define Servo_1_PC                     (* (reg32 *) Servo_1__PC)
/* Data Register */
#define Servo_1_DR                     (* (reg32 *) Servo_1__DR)
/* Input Buffer Disable Override */
#define Servo_1_INP_DIS                (* (reg32 *) Servo_1__PC2)


#if defined(Servo_1__INTSTAT)  /* Interrupt Registers */

    #define Servo_1_INTSTAT                (* (reg32 *) Servo_1__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins Servo_1_H */


/* [] END OF FILE */
