/*******************************************************************************
* File Name: GimbalT.h  
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

#if !defined(CY_PINS_GimbalT_H) /* Pins GimbalT_H */
#define CY_PINS_GimbalT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "GimbalT_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    GimbalT_Write(uint8 value) ;
void    GimbalT_SetDriveMode(uint8 mode) ;
uint8   GimbalT_ReadDataReg(void) ;
uint8   GimbalT_Read(void) ;
uint8   GimbalT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define GimbalT_DRIVE_MODE_BITS        (3)
#define GimbalT_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - GimbalT_DRIVE_MODE_BITS))
#define GimbalT_DRIVE_MODE_SHIFT       (0x00u)
#define GimbalT_DRIVE_MODE_MASK        (0x07u << GimbalT_DRIVE_MODE_SHIFT)

#define GimbalT_DM_ALG_HIZ         (0x00u << GimbalT_DRIVE_MODE_SHIFT)
#define GimbalT_DM_DIG_HIZ         (0x01u << GimbalT_DRIVE_MODE_SHIFT)
#define GimbalT_DM_RES_UP          (0x02u << GimbalT_DRIVE_MODE_SHIFT)
#define GimbalT_DM_RES_DWN         (0x03u << GimbalT_DRIVE_MODE_SHIFT)
#define GimbalT_DM_OD_LO           (0x04u << GimbalT_DRIVE_MODE_SHIFT)
#define GimbalT_DM_OD_HI           (0x05u << GimbalT_DRIVE_MODE_SHIFT)
#define GimbalT_DM_STRONG          (0x06u << GimbalT_DRIVE_MODE_SHIFT)
#define GimbalT_DM_RES_UPDWN       (0x07u << GimbalT_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define GimbalT_MASK               GimbalT__MASK
#define GimbalT_SHIFT              GimbalT__SHIFT
#define GimbalT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define GimbalT_PS                     (* (reg32 *) GimbalT__PS)
/* Port Configuration */
#define GimbalT_PC                     (* (reg32 *) GimbalT__PC)
/* Data Register */
#define GimbalT_DR                     (* (reg32 *) GimbalT__DR)
/* Input Buffer Disable Override */
#define GimbalT_INP_DIS                (* (reg32 *) GimbalT__PC2)


#if defined(GimbalT__INTSTAT)  /* Interrupt Registers */

    #define GimbalT_INTSTAT                (* (reg32 *) GimbalT__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins GimbalT_H */


/* [] END OF FILE */
