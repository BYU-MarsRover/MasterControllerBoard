/*******************************************************************************
* File Name: MOSI.h  
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

#if !defined(CY_PINS_MOSI_H) /* Pins MOSI_H */
#define CY_PINS_MOSI_H

#include "cytypes.h"
#include "cyfitter.h"
#include "MOSI_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    MOSI_Write(uint8 value) ;
void    MOSI_SetDriveMode(uint8 mode) ;
uint8   MOSI_ReadDataReg(void) ;
uint8   MOSI_Read(void) ;
uint8   MOSI_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MOSI_DRIVE_MODE_BITS        (3)
#define MOSI_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - MOSI_DRIVE_MODE_BITS))
#define MOSI_DRIVE_MODE_SHIFT       (0x00u)
#define MOSI_DRIVE_MODE_MASK        (0x07u << MOSI_DRIVE_MODE_SHIFT)

#define MOSI_DM_ALG_HIZ         (0x00u << MOSI_DRIVE_MODE_SHIFT)
#define MOSI_DM_DIG_HIZ         (0x01u << MOSI_DRIVE_MODE_SHIFT)
#define MOSI_DM_RES_UP          (0x02u << MOSI_DRIVE_MODE_SHIFT)
#define MOSI_DM_RES_DWN         (0x03u << MOSI_DRIVE_MODE_SHIFT)
#define MOSI_DM_OD_LO           (0x04u << MOSI_DRIVE_MODE_SHIFT)
#define MOSI_DM_OD_HI           (0x05u << MOSI_DRIVE_MODE_SHIFT)
#define MOSI_DM_STRONG          (0x06u << MOSI_DRIVE_MODE_SHIFT)
#define MOSI_DM_RES_UPDWN       (0x07u << MOSI_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define MOSI_MASK               MOSI__MASK
#define MOSI_SHIFT              MOSI__SHIFT
#define MOSI_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MOSI_PS                     (* (reg32 *) MOSI__PS)
/* Port Configuration */
#define MOSI_PC                     (* (reg32 *) MOSI__PC)
/* Data Register */
#define MOSI_DR                     (* (reg32 *) MOSI__DR)
/* Input Buffer Disable Override */
#define MOSI_INP_DIS                (* (reg32 *) MOSI__PC2)


#if defined(MOSI__INTSTAT)  /* Interrupt Registers */

    #define MOSI_INTSTAT                (* (reg32 *) MOSI__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins MOSI_H */


/* [] END OF FILE */
