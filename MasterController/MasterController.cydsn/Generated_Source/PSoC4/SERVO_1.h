/*******************************************************************************
* File Name: SERVO_1.h  
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

#if !defined(CY_PINS_SERVO_1_H) /* Pins SERVO_1_H */
#define CY_PINS_SERVO_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SERVO_1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SERVO_1_Write(uint8 value) ;
void    SERVO_1_SetDriveMode(uint8 mode) ;
uint8   SERVO_1_ReadDataReg(void) ;
uint8   SERVO_1_Read(void) ;
uint8   SERVO_1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SERVO_1_DRIVE_MODE_BITS        (3)
#define SERVO_1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SERVO_1_DRIVE_MODE_BITS))
#define SERVO_1_DRIVE_MODE_SHIFT       (0x00u)
#define SERVO_1_DRIVE_MODE_MASK        (0x07u << SERVO_1_DRIVE_MODE_SHIFT)

#define SERVO_1_DM_ALG_HIZ         (0x00u << SERVO_1_DRIVE_MODE_SHIFT)
#define SERVO_1_DM_DIG_HIZ         (0x01u << SERVO_1_DRIVE_MODE_SHIFT)
#define SERVO_1_DM_RES_UP          (0x02u << SERVO_1_DRIVE_MODE_SHIFT)
#define SERVO_1_DM_RES_DWN         (0x03u << SERVO_1_DRIVE_MODE_SHIFT)
#define SERVO_1_DM_OD_LO           (0x04u << SERVO_1_DRIVE_MODE_SHIFT)
#define SERVO_1_DM_OD_HI           (0x05u << SERVO_1_DRIVE_MODE_SHIFT)
#define SERVO_1_DM_STRONG          (0x06u << SERVO_1_DRIVE_MODE_SHIFT)
#define SERVO_1_DM_RES_UPDWN       (0x07u << SERVO_1_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define SERVO_1_MASK               SERVO_1__MASK
#define SERVO_1_SHIFT              SERVO_1__SHIFT
#define SERVO_1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SERVO_1_PS                     (* (reg32 *) SERVO_1__PS)
/* Port Configuration */
#define SERVO_1_PC                     (* (reg32 *) SERVO_1__PC)
/* Data Register */
#define SERVO_1_DR                     (* (reg32 *) SERVO_1__DR)
/* Input Buffer Disable Override */
#define SERVO_1_INP_DIS                (* (reg32 *) SERVO_1__PC2)


#if defined(SERVO_1__INTSTAT)  /* Interrupt Registers */

    #define SERVO_1_INTSTAT                (* (reg32 *) SERVO_1__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins SERVO_1_H */


/* [] END OF FILE */
