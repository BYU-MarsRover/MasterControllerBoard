/*******************************************************************************
* File Name: Btn1.h  
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

#if !defined(CY_PINS_Btn1_H) /* Pins Btn1_H */
#define CY_PINS_Btn1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Btn1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Btn1_Write(uint8 value) ;
void    Btn1_SetDriveMode(uint8 mode) ;
uint8   Btn1_ReadDataReg(void) ;
uint8   Btn1_Read(void) ;
uint8   Btn1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Btn1_DRIVE_MODE_BITS        (3)
#define Btn1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Btn1_DRIVE_MODE_BITS))
#define Btn1_DRIVE_MODE_SHIFT       (0x00u)
#define Btn1_DRIVE_MODE_MASK        (0x07u << Btn1_DRIVE_MODE_SHIFT)

#define Btn1_DM_ALG_HIZ         (0x00u << Btn1_DRIVE_MODE_SHIFT)
#define Btn1_DM_DIG_HIZ         (0x01u << Btn1_DRIVE_MODE_SHIFT)
#define Btn1_DM_RES_UP          (0x02u << Btn1_DRIVE_MODE_SHIFT)
#define Btn1_DM_RES_DWN         (0x03u << Btn1_DRIVE_MODE_SHIFT)
#define Btn1_DM_OD_LO           (0x04u << Btn1_DRIVE_MODE_SHIFT)
#define Btn1_DM_OD_HI           (0x05u << Btn1_DRIVE_MODE_SHIFT)
#define Btn1_DM_STRONG          (0x06u << Btn1_DRIVE_MODE_SHIFT)
#define Btn1_DM_RES_UPDWN       (0x07u << Btn1_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define Btn1_MASK               Btn1__MASK
#define Btn1_SHIFT              Btn1__SHIFT
#define Btn1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Btn1_PS                     (* (reg32 *) Btn1__PS)
/* Port Configuration */
#define Btn1_PC                     (* (reg32 *) Btn1__PC)
/* Data Register */
#define Btn1_DR                     (* (reg32 *) Btn1__DR)
/* Input Buffer Disable Override */
#define Btn1_INP_DIS                (* (reg32 *) Btn1__PC2)


#if defined(Btn1__INTSTAT)  /* Interrupt Registers */

    #define Btn1_INTSTAT                (* (reg32 *) Btn1__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins Btn1_H */


/* [] END OF FILE */
