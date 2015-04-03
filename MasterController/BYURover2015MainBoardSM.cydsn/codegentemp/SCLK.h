/*******************************************************************************
* File Name: SCLK.h  
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

#if !defined(CY_PINS_SCLK_H) /* Pins SCLK_H */
#define CY_PINS_SCLK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SCLK_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SCLK_Write(uint8 value) ;
void    SCLK_SetDriveMode(uint8 mode) ;
uint8   SCLK_ReadDataReg(void) ;
uint8   SCLK_Read(void) ;
uint8   SCLK_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SCLK_DRIVE_MODE_BITS        (3)
#define SCLK_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SCLK_DRIVE_MODE_BITS))
#define SCLK_DRIVE_MODE_SHIFT       (0x00u)
#define SCLK_DRIVE_MODE_MASK        (0x07u << SCLK_DRIVE_MODE_SHIFT)

#define SCLK_DM_ALG_HIZ         (0x00u << SCLK_DRIVE_MODE_SHIFT)
#define SCLK_DM_DIG_HIZ         (0x01u << SCLK_DRIVE_MODE_SHIFT)
#define SCLK_DM_RES_UP          (0x02u << SCLK_DRIVE_MODE_SHIFT)
#define SCLK_DM_RES_DWN         (0x03u << SCLK_DRIVE_MODE_SHIFT)
#define SCLK_DM_OD_LO           (0x04u << SCLK_DRIVE_MODE_SHIFT)
#define SCLK_DM_OD_HI           (0x05u << SCLK_DRIVE_MODE_SHIFT)
#define SCLK_DM_STRONG          (0x06u << SCLK_DRIVE_MODE_SHIFT)
#define SCLK_DM_RES_UPDWN       (0x07u << SCLK_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define SCLK_MASK               SCLK__MASK
#define SCLK_SHIFT              SCLK__SHIFT
#define SCLK_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SCLK_PS                     (* (reg32 *) SCLK__PS)
/* Port Configuration */
#define SCLK_PC                     (* (reg32 *) SCLK__PC)
/* Data Register */
#define SCLK_DR                     (* (reg32 *) SCLK__DR)
/* Input Buffer Disable Override */
#define SCLK_INP_DIS                (* (reg32 *) SCLK__PC2)


#if defined(SCLK__INTSTAT)  /* Interrupt Registers */

    #define SCLK_INTSTAT                (* (reg32 *) SCLK__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins SCLK_H */


/* [] END OF FILE */
