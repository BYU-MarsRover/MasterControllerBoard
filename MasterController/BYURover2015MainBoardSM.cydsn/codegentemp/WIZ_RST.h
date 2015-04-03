/*******************************************************************************
* File Name: WIZ_RST.h  
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

#if !defined(CY_PINS_WIZ_RST_H) /* Pins WIZ_RST_H */
#define CY_PINS_WIZ_RST_H

#include "cytypes.h"
#include "cyfitter.h"
#include "WIZ_RST_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    WIZ_RST_Write(uint8 value) ;
void    WIZ_RST_SetDriveMode(uint8 mode) ;
uint8   WIZ_RST_ReadDataReg(void) ;
uint8   WIZ_RST_Read(void) ;
uint8   WIZ_RST_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define WIZ_RST_DRIVE_MODE_BITS        (3)
#define WIZ_RST_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - WIZ_RST_DRIVE_MODE_BITS))
#define WIZ_RST_DRIVE_MODE_SHIFT       (0x00u)
#define WIZ_RST_DRIVE_MODE_MASK        (0x07u << WIZ_RST_DRIVE_MODE_SHIFT)

#define WIZ_RST_DM_ALG_HIZ         (0x00u << WIZ_RST_DRIVE_MODE_SHIFT)
#define WIZ_RST_DM_DIG_HIZ         (0x01u << WIZ_RST_DRIVE_MODE_SHIFT)
#define WIZ_RST_DM_RES_UP          (0x02u << WIZ_RST_DRIVE_MODE_SHIFT)
#define WIZ_RST_DM_RES_DWN         (0x03u << WIZ_RST_DRIVE_MODE_SHIFT)
#define WIZ_RST_DM_OD_LO           (0x04u << WIZ_RST_DRIVE_MODE_SHIFT)
#define WIZ_RST_DM_OD_HI           (0x05u << WIZ_RST_DRIVE_MODE_SHIFT)
#define WIZ_RST_DM_STRONG          (0x06u << WIZ_RST_DRIVE_MODE_SHIFT)
#define WIZ_RST_DM_RES_UPDWN       (0x07u << WIZ_RST_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define WIZ_RST_MASK               WIZ_RST__MASK
#define WIZ_RST_SHIFT              WIZ_RST__SHIFT
#define WIZ_RST_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define WIZ_RST_PS                     (* (reg32 *) WIZ_RST__PS)
/* Port Configuration */
#define WIZ_RST_PC                     (* (reg32 *) WIZ_RST__PC)
/* Data Register */
#define WIZ_RST_DR                     (* (reg32 *) WIZ_RST__DR)
/* Input Buffer Disable Override */
#define WIZ_RST_INP_DIS                (* (reg32 *) WIZ_RST__PC2)


#if defined(WIZ_RST__INTSTAT)  /* Interrupt Registers */

    #define WIZ_RST_INTSTAT                (* (reg32 *) WIZ_RST__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins WIZ_RST_H */


/* [] END OF FILE */
