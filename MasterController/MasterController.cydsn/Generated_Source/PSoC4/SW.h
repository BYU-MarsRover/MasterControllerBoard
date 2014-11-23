/*******************************************************************************
* File Name: SW.h  
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

#if !defined(CY_PINS_SW_H) /* Pins SW_H */
#define CY_PINS_SW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SW_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SW_Write(uint8 value) ;
void    SW_SetDriveMode(uint8 mode) ;
uint8   SW_ReadDataReg(void) ;
uint8   SW_Read(void) ;
uint8   SW_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SW_DRIVE_MODE_BITS        (3)
#define SW_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SW_DRIVE_MODE_BITS))
#define SW_DRIVE_MODE_SHIFT       (0x00u)
#define SW_DRIVE_MODE_MASK        (0x07u << SW_DRIVE_MODE_SHIFT)

#define SW_DM_ALG_HIZ         (0x00u << SW_DRIVE_MODE_SHIFT)
#define SW_DM_DIG_HIZ         (0x01u << SW_DRIVE_MODE_SHIFT)
#define SW_DM_RES_UP          (0x02u << SW_DRIVE_MODE_SHIFT)
#define SW_DM_RES_DWN         (0x03u << SW_DRIVE_MODE_SHIFT)
#define SW_DM_OD_LO           (0x04u << SW_DRIVE_MODE_SHIFT)
#define SW_DM_OD_HI           (0x05u << SW_DRIVE_MODE_SHIFT)
#define SW_DM_STRONG          (0x06u << SW_DRIVE_MODE_SHIFT)
#define SW_DM_RES_UPDWN       (0x07u << SW_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define SW_MASK               SW__MASK
#define SW_SHIFT              SW__SHIFT
#define SW_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SW_PS                     (* (reg32 *) SW__PS)
/* Port Configuration */
#define SW_PC                     (* (reg32 *) SW__PC)
/* Data Register */
#define SW_DR                     (* (reg32 *) SW__DR)
/* Input Buffer Disable Override */
#define SW_INP_DIS                (* (reg32 *) SW__PC2)


#if defined(SW__INTSTAT)  /* Interrupt Registers */

    #define SW_INTSTAT                (* (reg32 *) SW__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins SW_H */


/* [] END OF FILE */
