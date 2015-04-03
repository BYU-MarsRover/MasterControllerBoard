/*******************************************************************************
* File Name: SS.h  
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

#if !defined(CY_PINS_SS_H) /* Pins SS_H */
#define CY_PINS_SS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SS_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SS_Write(uint8 value) ;
void    SS_SetDriveMode(uint8 mode) ;
uint8   SS_ReadDataReg(void) ;
uint8   SS_Read(void) ;
uint8   SS_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SS_DRIVE_MODE_BITS        (3)
#define SS_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SS_DRIVE_MODE_BITS))
#define SS_DRIVE_MODE_SHIFT       (0x00u)
#define SS_DRIVE_MODE_MASK        (0x07u << SS_DRIVE_MODE_SHIFT)

#define SS_DM_ALG_HIZ         (0x00u << SS_DRIVE_MODE_SHIFT)
#define SS_DM_DIG_HIZ         (0x01u << SS_DRIVE_MODE_SHIFT)
#define SS_DM_RES_UP          (0x02u << SS_DRIVE_MODE_SHIFT)
#define SS_DM_RES_DWN         (0x03u << SS_DRIVE_MODE_SHIFT)
#define SS_DM_OD_LO           (0x04u << SS_DRIVE_MODE_SHIFT)
#define SS_DM_OD_HI           (0x05u << SS_DRIVE_MODE_SHIFT)
#define SS_DM_STRONG          (0x06u << SS_DRIVE_MODE_SHIFT)
#define SS_DM_RES_UPDWN       (0x07u << SS_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define SS_MASK               SS__MASK
#define SS_SHIFT              SS__SHIFT
#define SS_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SS_PS                     (* (reg32 *) SS__PS)
/* Port Configuration */
#define SS_PC                     (* (reg32 *) SS__PC)
/* Data Register */
#define SS_DR                     (* (reg32 *) SS__DR)
/* Input Buffer Disable Override */
#define SS_INP_DIS                (* (reg32 *) SS__PC2)


#if defined(SS__INTSTAT)  /* Interrupt Registers */

    #define SS_INTSTAT                (* (reg32 *) SS__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins SS_H */


/* [] END OF FILE */
