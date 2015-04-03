/*******************************************************************************
* File Name: PPM_IN.c  
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
#include "PPM_IN.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        PPM_IN_PC =   (PPM_IN_PC & \
                                (uint32)(~(uint32)(PPM_IN_DRIVE_MODE_IND_MASK << (PPM_IN_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (PPM_IN_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: PPM_IN_Write
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
void PPM_IN_Write(uint8 value) 
{
    uint8 drVal = (uint8)(PPM_IN_DR & (uint8)(~PPM_IN_MASK));
    drVal = (drVal | ((uint8)(value << PPM_IN_SHIFT) & PPM_IN_MASK));
    PPM_IN_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: PPM_IN_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  PPM_IN_DM_STRONG     Strong Drive 
*  PPM_IN_DM_OD_HI      Open Drain, Drives High 
*  PPM_IN_DM_OD_LO      Open Drain, Drives Low 
*  PPM_IN_DM_RES_UP     Resistive Pull Up 
*  PPM_IN_DM_RES_DWN    Resistive Pull Down 
*  PPM_IN_DM_RES_UPDWN  Resistive Pull Up/Down 
*  PPM_IN_DM_DIG_HIZ    High Impedance Digital 
*  PPM_IN_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void PPM_IN_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(PPM_IN__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: PPM_IN_Read
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
*  Macro PPM_IN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PPM_IN_Read(void) 
{
    return (uint8)((PPM_IN_PS & PPM_IN_MASK) >> PPM_IN_SHIFT);
}


/*******************************************************************************
* Function Name: PPM_IN_ReadDataReg
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
uint8 PPM_IN_ReadDataReg(void) 
{
    return (uint8)((PPM_IN_DR & PPM_IN_MASK) >> PPM_IN_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PPM_IN_INTSTAT) 

    /*******************************************************************************
    * Function Name: PPM_IN_ClearInterrupt
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
    uint8 PPM_IN_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(PPM_IN_INTSTAT & PPM_IN_MASK);
		PPM_IN_INTSTAT = maskedStatus;
        return maskedStatus >> PPM_IN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
