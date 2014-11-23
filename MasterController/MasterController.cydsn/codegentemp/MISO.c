/*******************************************************************************
* File Name: MISO.c  
* Version 2.5
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "MISO.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        MISO_PC =   (MISO_PC & \
                                (uint32)(~(uint32)(MISO_DRIVE_MODE_IND_MASK << (MISO_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (MISO_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: MISO_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void MISO_Write(uint8 value) 
{
    uint8 drVal = (uint8)(MISO_DR & (uint8)(~MISO_MASK));
    drVal = (drVal | ((uint8)(value << MISO_SHIFT) & MISO_MASK));
    MISO_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: MISO_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  MISO_DM_STRONG     Strong Drive 
*  MISO_DM_OD_HI      Open Drain, Drives High 
*  MISO_DM_OD_LO      Open Drain, Drives Low 
*  MISO_DM_RES_UP     Resistive Pull Up 
*  MISO_DM_RES_DWN    Resistive Pull Down 
*  MISO_DM_RES_UPDWN  Resistive Pull Up/Down 
*  MISO_DM_DIG_HIZ    High Impedance Digital 
*  MISO_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void MISO_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(MISO__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: MISO_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro MISO_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 MISO_Read(void) 
{
    return (uint8)((MISO_PS & MISO_MASK) >> MISO_SHIFT);
}


/*******************************************************************************
* Function Name: MISO_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 MISO_ReadDataReg(void) 
{
    return (uint8)((MISO_DR & MISO_MASK) >> MISO_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(MISO_INTSTAT) 

    /*******************************************************************************
    * Function Name: MISO_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 MISO_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(MISO_INTSTAT & MISO_MASK);
		MISO_INTSTAT = maskedStatus;
        return maskedStatus >> MISO_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
