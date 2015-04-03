/*******************************************************************************
* File Name: BAT_AMPS.h  
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

#if !defined(CY_PINS_BAT_AMPS_H) /* Pins BAT_AMPS_H */
#define CY_PINS_BAT_AMPS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "BAT_AMPS_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    BAT_AMPS_Write(uint8 value) ;
void    BAT_AMPS_SetDriveMode(uint8 mode) ;
uint8   BAT_AMPS_ReadDataReg(void) ;
uint8   BAT_AMPS_Read(void) ;
uint8   BAT_AMPS_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define BAT_AMPS_DRIVE_MODE_BITS        (3)
#define BAT_AMPS_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - BAT_AMPS_DRIVE_MODE_BITS))
#define BAT_AMPS_DRIVE_MODE_SHIFT       (0x00u)
#define BAT_AMPS_DRIVE_MODE_MASK        (0x07u << BAT_AMPS_DRIVE_MODE_SHIFT)

#define BAT_AMPS_DM_ALG_HIZ         (0x00u << BAT_AMPS_DRIVE_MODE_SHIFT)
#define BAT_AMPS_DM_DIG_HIZ         (0x01u << BAT_AMPS_DRIVE_MODE_SHIFT)
#define BAT_AMPS_DM_RES_UP          (0x02u << BAT_AMPS_DRIVE_MODE_SHIFT)
#define BAT_AMPS_DM_RES_DWN         (0x03u << BAT_AMPS_DRIVE_MODE_SHIFT)
#define BAT_AMPS_DM_OD_LO           (0x04u << BAT_AMPS_DRIVE_MODE_SHIFT)
#define BAT_AMPS_DM_OD_HI           (0x05u << BAT_AMPS_DRIVE_MODE_SHIFT)
#define BAT_AMPS_DM_STRONG          (0x06u << BAT_AMPS_DRIVE_MODE_SHIFT)
#define BAT_AMPS_DM_RES_UPDWN       (0x07u << BAT_AMPS_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define BAT_AMPS_MASK               BAT_AMPS__MASK
#define BAT_AMPS_SHIFT              BAT_AMPS__SHIFT
#define BAT_AMPS_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BAT_AMPS_PS                     (* (reg32 *) BAT_AMPS__PS)
/* Port Configuration */
#define BAT_AMPS_PC                     (* (reg32 *) BAT_AMPS__PC)
/* Data Register */
#define BAT_AMPS_DR                     (* (reg32 *) BAT_AMPS__DR)
/* Input Buffer Disable Override */
#define BAT_AMPS_INP_DIS                (* (reg32 *) BAT_AMPS__PC2)


#if defined(BAT_AMPS__INTSTAT)  /* Interrupt Registers */

    #define BAT_AMPS_INTSTAT                (* (reg32 *) BAT_AMPS__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins BAT_AMPS_H */


/* [] END OF FILE */
