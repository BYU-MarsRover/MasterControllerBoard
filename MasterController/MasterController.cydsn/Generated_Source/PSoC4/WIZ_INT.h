/*******************************************************************************
* File Name: WIZ_INT.h  
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

#if !defined(CY_PINS_WIZ_INT_H) /* Pins WIZ_INT_H */
#define CY_PINS_WIZ_INT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "WIZ_INT_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    WIZ_INT_Write(uint8 value) ;
void    WIZ_INT_SetDriveMode(uint8 mode) ;
uint8   WIZ_INT_ReadDataReg(void) ;
uint8   WIZ_INT_Read(void) ;
uint8   WIZ_INT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define WIZ_INT_DRIVE_MODE_BITS        (3)
#define WIZ_INT_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - WIZ_INT_DRIVE_MODE_BITS))
#define WIZ_INT_DRIVE_MODE_SHIFT       (0x00u)
#define WIZ_INT_DRIVE_MODE_MASK        (0x07u << WIZ_INT_DRIVE_MODE_SHIFT)

#define WIZ_INT_DM_ALG_HIZ         (0x00u << WIZ_INT_DRIVE_MODE_SHIFT)
#define WIZ_INT_DM_DIG_HIZ         (0x01u << WIZ_INT_DRIVE_MODE_SHIFT)
#define WIZ_INT_DM_RES_UP          (0x02u << WIZ_INT_DRIVE_MODE_SHIFT)
#define WIZ_INT_DM_RES_DWN         (0x03u << WIZ_INT_DRIVE_MODE_SHIFT)
#define WIZ_INT_DM_OD_LO           (0x04u << WIZ_INT_DRIVE_MODE_SHIFT)
#define WIZ_INT_DM_OD_HI           (0x05u << WIZ_INT_DRIVE_MODE_SHIFT)
#define WIZ_INT_DM_STRONG          (0x06u << WIZ_INT_DRIVE_MODE_SHIFT)
#define WIZ_INT_DM_RES_UPDWN       (0x07u << WIZ_INT_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define WIZ_INT_MASK               WIZ_INT__MASK
#define WIZ_INT_SHIFT              WIZ_INT__SHIFT
#define WIZ_INT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define WIZ_INT_PS                     (* (reg32 *) WIZ_INT__PS)
/* Port Configuration */
#define WIZ_INT_PC                     (* (reg32 *) WIZ_INT__PC)
/* Data Register */
#define WIZ_INT_DR                     (* (reg32 *) WIZ_INT__DR)
/* Input Buffer Disable Override */
#define WIZ_INT_INP_DIS                (* (reg32 *) WIZ_INT__PC2)


#if defined(WIZ_INT__INTSTAT)  /* Interrupt Registers */

    #define WIZ_INT_INTSTAT                (* (reg32 *) WIZ_INT__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins WIZ_INT_H */


/* [] END OF FILE */
