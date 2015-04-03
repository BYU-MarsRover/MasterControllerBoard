/*******************************************************************************
* File Name: PPM_IN.h  
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

#if !defined(CY_PINS_PPM_IN_H) /* Pins PPM_IN_H */
#define CY_PINS_PPM_IN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PPM_IN_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    PPM_IN_Write(uint8 value) ;
void    PPM_IN_SetDriveMode(uint8 mode) ;
uint8   PPM_IN_ReadDataReg(void) ;
uint8   PPM_IN_Read(void) ;
uint8   PPM_IN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PPM_IN_DRIVE_MODE_BITS        (3)
#define PPM_IN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PPM_IN_DRIVE_MODE_BITS))
#define PPM_IN_DRIVE_MODE_SHIFT       (0x00u)
#define PPM_IN_DRIVE_MODE_MASK        (0x07u << PPM_IN_DRIVE_MODE_SHIFT)

#define PPM_IN_DM_ALG_HIZ         (0x00u << PPM_IN_DRIVE_MODE_SHIFT)
#define PPM_IN_DM_DIG_HIZ         (0x01u << PPM_IN_DRIVE_MODE_SHIFT)
#define PPM_IN_DM_RES_UP          (0x02u << PPM_IN_DRIVE_MODE_SHIFT)
#define PPM_IN_DM_RES_DWN         (0x03u << PPM_IN_DRIVE_MODE_SHIFT)
#define PPM_IN_DM_OD_LO           (0x04u << PPM_IN_DRIVE_MODE_SHIFT)
#define PPM_IN_DM_OD_HI           (0x05u << PPM_IN_DRIVE_MODE_SHIFT)
#define PPM_IN_DM_STRONG          (0x06u << PPM_IN_DRIVE_MODE_SHIFT)
#define PPM_IN_DM_RES_UPDWN       (0x07u << PPM_IN_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define PPM_IN_MASK               PPM_IN__MASK
#define PPM_IN_SHIFT              PPM_IN__SHIFT
#define PPM_IN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PPM_IN_PS                     (* (reg32 *) PPM_IN__PS)
/* Port Configuration */
#define PPM_IN_PC                     (* (reg32 *) PPM_IN__PC)
/* Data Register */
#define PPM_IN_DR                     (* (reg32 *) PPM_IN__DR)
/* Input Buffer Disable Override */
#define PPM_IN_INP_DIS                (* (reg32 *) PPM_IN__PC2)


#if defined(PPM_IN__INTSTAT)  /* Interrupt Registers */

    #define PPM_IN_INTSTAT                (* (reg32 *) PPM_IN__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins PPM_IN_H */


/* [] END OF FILE */
