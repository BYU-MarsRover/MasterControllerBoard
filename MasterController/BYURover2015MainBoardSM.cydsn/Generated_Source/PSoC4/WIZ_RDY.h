/*******************************************************************************
* File Name: WIZ_RDY.h  
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

#if !defined(CY_PINS_WIZ_RDY_H) /* Pins WIZ_RDY_H */
#define CY_PINS_WIZ_RDY_H

#include "cytypes.h"
#include "cyfitter.h"
#include "WIZ_RDY_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    WIZ_RDY_Write(uint8 value) ;
void    WIZ_RDY_SetDriveMode(uint8 mode) ;
uint8   WIZ_RDY_ReadDataReg(void) ;
uint8   WIZ_RDY_Read(void) ;
uint8   WIZ_RDY_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define WIZ_RDY_DRIVE_MODE_BITS        (3)
#define WIZ_RDY_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - WIZ_RDY_DRIVE_MODE_BITS))
#define WIZ_RDY_DRIVE_MODE_SHIFT       (0x00u)
#define WIZ_RDY_DRIVE_MODE_MASK        (0x07u << WIZ_RDY_DRIVE_MODE_SHIFT)

#define WIZ_RDY_DM_ALG_HIZ         (0x00u << WIZ_RDY_DRIVE_MODE_SHIFT)
#define WIZ_RDY_DM_DIG_HIZ         (0x01u << WIZ_RDY_DRIVE_MODE_SHIFT)
#define WIZ_RDY_DM_RES_UP          (0x02u << WIZ_RDY_DRIVE_MODE_SHIFT)
#define WIZ_RDY_DM_RES_DWN         (0x03u << WIZ_RDY_DRIVE_MODE_SHIFT)
#define WIZ_RDY_DM_OD_LO           (0x04u << WIZ_RDY_DRIVE_MODE_SHIFT)
#define WIZ_RDY_DM_OD_HI           (0x05u << WIZ_RDY_DRIVE_MODE_SHIFT)
#define WIZ_RDY_DM_STRONG          (0x06u << WIZ_RDY_DRIVE_MODE_SHIFT)
#define WIZ_RDY_DM_RES_UPDWN       (0x07u << WIZ_RDY_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define WIZ_RDY_MASK               WIZ_RDY__MASK
#define WIZ_RDY_SHIFT              WIZ_RDY__SHIFT
#define WIZ_RDY_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define WIZ_RDY_PS                     (* (reg32 *) WIZ_RDY__PS)
/* Port Configuration */
#define WIZ_RDY_PC                     (* (reg32 *) WIZ_RDY__PC)
/* Data Register */
#define WIZ_RDY_DR                     (* (reg32 *) WIZ_RDY__DR)
/* Input Buffer Disable Override */
#define WIZ_RDY_INP_DIS                (* (reg32 *) WIZ_RDY__PC2)


#if defined(WIZ_RDY__INTSTAT)  /* Interrupt Registers */

    #define WIZ_RDY_INTSTAT                (* (reg32 *) WIZ_RDY__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins WIZ_RDY_H */


/* [] END OF FILE */
