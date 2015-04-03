/*******************************************************************************
* File Name: SERVO_4.h  
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

#if !defined(CY_PINS_SERVO_4_H) /* Pins SERVO_4_H */
#define CY_PINS_SERVO_4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SERVO_4_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SERVO_4_Write(uint8 value) ;
void    SERVO_4_SetDriveMode(uint8 mode) ;
uint8   SERVO_4_ReadDataReg(void) ;
uint8   SERVO_4_Read(void) ;
uint8   SERVO_4_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SERVO_4_DRIVE_MODE_BITS        (3)
#define SERVO_4_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SERVO_4_DRIVE_MODE_BITS))
#define SERVO_4_DRIVE_MODE_SHIFT       (0x00u)
#define SERVO_4_DRIVE_MODE_MASK        (0x07u << SERVO_4_DRIVE_MODE_SHIFT)

#define SERVO_4_DM_ALG_HIZ         (0x00u << SERVO_4_DRIVE_MODE_SHIFT)
#define SERVO_4_DM_DIG_HIZ         (0x01u << SERVO_4_DRIVE_MODE_SHIFT)
#define SERVO_4_DM_RES_UP          (0x02u << SERVO_4_DRIVE_MODE_SHIFT)
#define SERVO_4_DM_RES_DWN         (0x03u << SERVO_4_DRIVE_MODE_SHIFT)
#define SERVO_4_DM_OD_LO           (0x04u << SERVO_4_DRIVE_MODE_SHIFT)
#define SERVO_4_DM_OD_HI           (0x05u << SERVO_4_DRIVE_MODE_SHIFT)
#define SERVO_4_DM_STRONG          (0x06u << SERVO_4_DRIVE_MODE_SHIFT)
#define SERVO_4_DM_RES_UPDWN       (0x07u << SERVO_4_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define SERVO_4_MASK               SERVO_4__MASK
#define SERVO_4_SHIFT              SERVO_4__SHIFT
#define SERVO_4_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SERVO_4_PS                     (* (reg32 *) SERVO_4__PS)
/* Port Configuration */
#define SERVO_4_PC                     (* (reg32 *) SERVO_4__PC)
/* Data Register */
#define SERVO_4_DR                     (* (reg32 *) SERVO_4__DR)
/* Input Buffer Disable Override */
#define SERVO_4_INP_DIS                (* (reg32 *) SERVO_4__PC2)


#if defined(SERVO_4__INTSTAT)  /* Interrupt Registers */

    #define SERVO_4_INTSTAT                (* (reg32 *) SERVO_4__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins SERVO_4_H */


/* [] END OF FILE */
