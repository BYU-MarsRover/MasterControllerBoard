/*******************************************************************************
* File Name: GimbalP.h  
* Version 2.10
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

#if !defined(CY_PINS_GimbalP_H) /* Pins GimbalP_H */
#define CY_PINS_GimbalP_H

#include "cytypes.h"
#include "cyfitter.h"
#include "GimbalP_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    GimbalP_Write(uint8 value) ;
void    GimbalP_SetDriveMode(uint8 mode) ;
uint8   GimbalP_ReadDataReg(void) ;
uint8   GimbalP_Read(void) ;
uint8   GimbalP_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define GimbalP_DRIVE_MODE_BITS        (3)
#define GimbalP_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - GimbalP_DRIVE_MODE_BITS))

#define GimbalP_DM_ALG_HIZ         (0x00u)
#define GimbalP_DM_DIG_HIZ         (0x01u)
#define GimbalP_DM_RES_UP          (0x02u)
#define GimbalP_DM_RES_DWN         (0x03u)
#define GimbalP_DM_OD_LO           (0x04u)
#define GimbalP_DM_OD_HI           (0x05u)
#define GimbalP_DM_STRONG          (0x06u)
#define GimbalP_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define GimbalP_MASK               GimbalP__MASK
#define GimbalP_SHIFT              GimbalP__SHIFT
#define GimbalP_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define GimbalP_PS                     (* (reg32 *) GimbalP__PS)
/* Port Configuration */
#define GimbalP_PC                     (* (reg32 *) GimbalP__PC)
/* Data Register */
#define GimbalP_DR                     (* (reg32 *) GimbalP__DR)
/* Input Buffer Disable Override */
#define GimbalP_INP_DIS                (* (reg32 *) GimbalP__PC2)


#if defined(GimbalP__INTSTAT)  /* Interrupt Registers */

    #define GimbalP_INTSTAT                (* (reg32 *) GimbalP__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define GimbalP_DRIVE_MODE_SHIFT       (0x00u)
#define GimbalP_DRIVE_MODE_MASK        (0x07u << GimbalP_DRIVE_MODE_SHIFT)


#endif /* End Pins GimbalP_H */


/* [] END OF FILE */
