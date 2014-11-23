/*******************************************************************************
* File Name: WIZ_SS.h  
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

#if !defined(CY_PINS_WIZ_SS_H) /* Pins WIZ_SS_H */
#define CY_PINS_WIZ_SS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "WIZ_SS_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    WIZ_SS_Write(uint8 value) ;
void    WIZ_SS_SetDriveMode(uint8 mode) ;
uint8   WIZ_SS_ReadDataReg(void) ;
uint8   WIZ_SS_Read(void) ;
uint8   WIZ_SS_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define WIZ_SS_DRIVE_MODE_BITS        (3)
#define WIZ_SS_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - WIZ_SS_DRIVE_MODE_BITS))
#define WIZ_SS_DRIVE_MODE_SHIFT       (0x00u)
#define WIZ_SS_DRIVE_MODE_MASK        (0x07u << WIZ_SS_DRIVE_MODE_SHIFT)

#define WIZ_SS_DM_ALG_HIZ         (0x00u << WIZ_SS_DRIVE_MODE_SHIFT)
#define WIZ_SS_DM_DIG_HIZ         (0x01u << WIZ_SS_DRIVE_MODE_SHIFT)
#define WIZ_SS_DM_RES_UP          (0x02u << WIZ_SS_DRIVE_MODE_SHIFT)
#define WIZ_SS_DM_RES_DWN         (0x03u << WIZ_SS_DRIVE_MODE_SHIFT)
#define WIZ_SS_DM_OD_LO           (0x04u << WIZ_SS_DRIVE_MODE_SHIFT)
#define WIZ_SS_DM_OD_HI           (0x05u << WIZ_SS_DRIVE_MODE_SHIFT)
#define WIZ_SS_DM_STRONG          (0x06u << WIZ_SS_DRIVE_MODE_SHIFT)
#define WIZ_SS_DM_RES_UPDWN       (0x07u << WIZ_SS_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define WIZ_SS_MASK               WIZ_SS__MASK
#define WIZ_SS_SHIFT              WIZ_SS__SHIFT
#define WIZ_SS_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define WIZ_SS_PS                     (* (reg32 *) WIZ_SS__PS)
/* Port Configuration */
#define WIZ_SS_PC                     (* (reg32 *) WIZ_SS__PC)
/* Data Register */
#define WIZ_SS_DR                     (* (reg32 *) WIZ_SS__DR)
/* Input Buffer Disable Override */
#define WIZ_SS_INP_DIS                (* (reg32 *) WIZ_SS__PC2)


#if defined(WIZ_SS__INTSTAT)  /* Interrupt Registers */

    #define WIZ_SS_INTSTAT                (* (reg32 *) WIZ_SS__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins WIZ_SS_H */


/* [] END OF FILE */
