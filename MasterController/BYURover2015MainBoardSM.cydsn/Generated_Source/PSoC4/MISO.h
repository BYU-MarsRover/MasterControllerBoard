/*******************************************************************************
* File Name: MISO.h  
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

#if !defined(CY_PINS_MISO_H) /* Pins MISO_H */
#define CY_PINS_MISO_H

#include "cytypes.h"
#include "cyfitter.h"
#include "MISO_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    MISO_Write(uint8 value) ;
void    MISO_SetDriveMode(uint8 mode) ;
uint8   MISO_ReadDataReg(void) ;
uint8   MISO_Read(void) ;
uint8   MISO_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MISO_DRIVE_MODE_BITS        (3)
#define MISO_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - MISO_DRIVE_MODE_BITS))
#define MISO_DRIVE_MODE_SHIFT       (0x00u)
#define MISO_DRIVE_MODE_MASK        (0x07u << MISO_DRIVE_MODE_SHIFT)

#define MISO_DM_ALG_HIZ         (0x00u << MISO_DRIVE_MODE_SHIFT)
#define MISO_DM_DIG_HIZ         (0x01u << MISO_DRIVE_MODE_SHIFT)
#define MISO_DM_RES_UP          (0x02u << MISO_DRIVE_MODE_SHIFT)
#define MISO_DM_RES_DWN         (0x03u << MISO_DRIVE_MODE_SHIFT)
#define MISO_DM_OD_LO           (0x04u << MISO_DRIVE_MODE_SHIFT)
#define MISO_DM_OD_HI           (0x05u << MISO_DRIVE_MODE_SHIFT)
#define MISO_DM_STRONG          (0x06u << MISO_DRIVE_MODE_SHIFT)
#define MISO_DM_RES_UPDWN       (0x07u << MISO_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define MISO_MASK               MISO__MASK
#define MISO_SHIFT              MISO__SHIFT
#define MISO_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MISO_PS                     (* (reg32 *) MISO__PS)
/* Port Configuration */
#define MISO_PC                     (* (reg32 *) MISO__PC)
/* Data Register */
#define MISO_DR                     (* (reg32 *) MISO__DR)
/* Input Buffer Disable Override */
#define MISO_INP_DIS                (* (reg32 *) MISO__PC2)


#if defined(MISO__INTSTAT)  /* Interrupt Registers */

    #define MISO_INTSTAT                (* (reg32 *) MISO__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins MISO_H */


/* [] END OF FILE */
