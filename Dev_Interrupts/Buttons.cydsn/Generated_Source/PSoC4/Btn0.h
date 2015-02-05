/*******************************************************************************
* File Name: Btn0.h  
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

#if !defined(CY_PINS_Btn0_H) /* Pins Btn0_H */
#define CY_PINS_Btn0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Btn0_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Btn0_Write(uint8 value) ;
void    Btn0_SetDriveMode(uint8 mode) ;
uint8   Btn0_ReadDataReg(void) ;
uint8   Btn0_Read(void) ;
uint8   Btn0_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Btn0_DRIVE_MODE_BITS        (3)
#define Btn0_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Btn0_DRIVE_MODE_BITS))
#define Btn0_DRIVE_MODE_SHIFT       (0x00u)
#define Btn0_DRIVE_MODE_MASK        (0x07u << Btn0_DRIVE_MODE_SHIFT)

#define Btn0_DM_ALG_HIZ         (0x00u << Btn0_DRIVE_MODE_SHIFT)
#define Btn0_DM_DIG_HIZ         (0x01u << Btn0_DRIVE_MODE_SHIFT)
#define Btn0_DM_RES_UP          (0x02u << Btn0_DRIVE_MODE_SHIFT)
#define Btn0_DM_RES_DWN         (0x03u << Btn0_DRIVE_MODE_SHIFT)
#define Btn0_DM_OD_LO           (0x04u << Btn0_DRIVE_MODE_SHIFT)
#define Btn0_DM_OD_HI           (0x05u << Btn0_DRIVE_MODE_SHIFT)
#define Btn0_DM_STRONG          (0x06u << Btn0_DRIVE_MODE_SHIFT)
#define Btn0_DM_RES_UPDWN       (0x07u << Btn0_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define Btn0_MASK               Btn0__MASK
#define Btn0_SHIFT              Btn0__SHIFT
#define Btn0_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Btn0_PS                     (* (reg32 *) Btn0__PS)
/* Port Configuration */
#define Btn0_PC                     (* (reg32 *) Btn0__PC)
/* Data Register */
#define Btn0_DR                     (* (reg32 *) Btn0__DR)
/* Input Buffer Disable Override */
#define Btn0_INP_DIS                (* (reg32 *) Btn0__PC2)


#if defined(Btn0__INTSTAT)  /* Interrupt Registers */

    #define Btn0_INTSTAT                (* (reg32 *) Btn0__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins Btn0_H */


/* [] END OF FILE */
