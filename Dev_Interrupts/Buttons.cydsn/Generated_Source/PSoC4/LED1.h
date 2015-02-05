/*******************************************************************************
* File Name: LED1.h  
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

#if !defined(CY_PINS_LED1_H) /* Pins LED1_H */
#define CY_PINS_LED1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LED1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LED1_Write(uint8 value) ;
void    LED1_SetDriveMode(uint8 mode) ;
uint8   LED1_ReadDataReg(void) ;
uint8   LED1_Read(void) ;
uint8   LED1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LED1_DRIVE_MODE_BITS        (3)
#define LED1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LED1_DRIVE_MODE_BITS))
#define LED1_DRIVE_MODE_SHIFT       (0x00u)
#define LED1_DRIVE_MODE_MASK        (0x07u << LED1_DRIVE_MODE_SHIFT)

#define LED1_DM_ALG_HIZ         (0x00u << LED1_DRIVE_MODE_SHIFT)
#define LED1_DM_DIG_HIZ         (0x01u << LED1_DRIVE_MODE_SHIFT)
#define LED1_DM_RES_UP          (0x02u << LED1_DRIVE_MODE_SHIFT)
#define LED1_DM_RES_DWN         (0x03u << LED1_DRIVE_MODE_SHIFT)
#define LED1_DM_OD_LO           (0x04u << LED1_DRIVE_MODE_SHIFT)
#define LED1_DM_OD_HI           (0x05u << LED1_DRIVE_MODE_SHIFT)
#define LED1_DM_STRONG          (0x06u << LED1_DRIVE_MODE_SHIFT)
#define LED1_DM_RES_UPDWN       (0x07u << LED1_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define LED1_MASK               LED1__MASK
#define LED1_SHIFT              LED1__SHIFT
#define LED1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED1_PS                     (* (reg32 *) LED1__PS)
/* Port Configuration */
#define LED1_PC                     (* (reg32 *) LED1__PC)
/* Data Register */
#define LED1_DR                     (* (reg32 *) LED1__DR)
/* Input Buffer Disable Override */
#define LED1_INP_DIS                (* (reg32 *) LED1__PC2)


#if defined(LED1__INTSTAT)  /* Interrupt Registers */

    #define LED1_INTSTAT                (* (reg32 *) LED1__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins LED1_H */


/* [] END OF FILE */
