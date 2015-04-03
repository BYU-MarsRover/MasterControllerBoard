/*******************************************************************************
* File Name: BAT_VOLT.h  
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

#if !defined(CY_PINS_BAT_VOLT_H) /* Pins BAT_VOLT_H */
#define CY_PINS_BAT_VOLT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "BAT_VOLT_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    BAT_VOLT_Write(uint8 value) ;
void    BAT_VOLT_SetDriveMode(uint8 mode) ;
uint8   BAT_VOLT_ReadDataReg(void) ;
uint8   BAT_VOLT_Read(void) ;
uint8   BAT_VOLT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define BAT_VOLT_DRIVE_MODE_BITS        (3)
#define BAT_VOLT_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - BAT_VOLT_DRIVE_MODE_BITS))
#define BAT_VOLT_DRIVE_MODE_SHIFT       (0x00u)
#define BAT_VOLT_DRIVE_MODE_MASK        (0x07u << BAT_VOLT_DRIVE_MODE_SHIFT)

#define BAT_VOLT_DM_ALG_HIZ         (0x00u << BAT_VOLT_DRIVE_MODE_SHIFT)
#define BAT_VOLT_DM_DIG_HIZ         (0x01u << BAT_VOLT_DRIVE_MODE_SHIFT)
#define BAT_VOLT_DM_RES_UP          (0x02u << BAT_VOLT_DRIVE_MODE_SHIFT)
#define BAT_VOLT_DM_RES_DWN         (0x03u << BAT_VOLT_DRIVE_MODE_SHIFT)
#define BAT_VOLT_DM_OD_LO           (0x04u << BAT_VOLT_DRIVE_MODE_SHIFT)
#define BAT_VOLT_DM_OD_HI           (0x05u << BAT_VOLT_DRIVE_MODE_SHIFT)
#define BAT_VOLT_DM_STRONG          (0x06u << BAT_VOLT_DRIVE_MODE_SHIFT)
#define BAT_VOLT_DM_RES_UPDWN       (0x07u << BAT_VOLT_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define BAT_VOLT_MASK               BAT_VOLT__MASK
#define BAT_VOLT_SHIFT              BAT_VOLT__SHIFT
#define BAT_VOLT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BAT_VOLT_PS                     (* (reg32 *) BAT_VOLT__PS)
/* Port Configuration */
#define BAT_VOLT_PC                     (* (reg32 *) BAT_VOLT__PC)
/* Data Register */
#define BAT_VOLT_DR                     (* (reg32 *) BAT_VOLT__DR)
/* Input Buffer Disable Override */
#define BAT_VOLT_INP_DIS                (* (reg32 *) BAT_VOLT__PC2)


#if defined(BAT_VOLT__INTSTAT)  /* Interrupt Registers */

    #define BAT_VOLT_INTSTAT                (* (reg32 *) BAT_VOLT__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins BAT_VOLT_H */


/* [] END OF FILE */
