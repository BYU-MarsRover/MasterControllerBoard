/*******************************************************************************
* File Name: BAT_AMPS.c  
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
#include "BAT_AMPS.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        BAT_AMPS_PC =   (BAT_AMPS_PC & \
                                (uint32)(~(uint32)(BAT_AMPS_DRIVE_MODE_IND_MASK << (BAT_AMPS_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (BAT_AMPS_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: BAT_AMPS_Write
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
void BAT_AMPS_Write(uint8 value) 
{
    uint8 drVal = (uint8)(BAT_AMPS_DR & (uint8)(~BAT_AMPS_MASK));
    drVal = (drVal | ((uint8)(value << BAT_AMPS_SHIFT) & BAT_AMPS_MASK));
    BAT_AMPS_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: BAT_AMPS_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  BAT_AMPS_DM_STRONG     Strong Drive 
*  BAT_AMPS_DM_OD_HI      Open Drain, Drives High 
*  BAT_AMPS_DM_OD_LO      Open Drain, Drives Low 
*  BAT_AMPS_DM_RES_UP     Resistive Pull Up 
*  BAT_AMPS_DM_RES_DWN    Resistive Pull Down 
*  BAT_AMPS_DM_RES_UPDWN  Resistive Pull Up/Down 
*  BAT_AMPS_DM_DIG_HIZ    High Impedance Digital 
*  BAT_AMPS_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void BAT_AMPS_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(BAT_AMPS__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: BAT_AMPS_Read
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
*  Macro BAT_AMPS_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 BAT_AMPS_Read(void) 
{
    return (uint8)((BAT_AMPS_PS & BAT_AMPS_MASK) >> BAT_AMPS_SHIFT);
}


/*******************************************************************************
* Function Name: BAT_AMPS_ReadDataReg
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
uint8 BAT_AMPS_ReadDataReg(void) 
{
    return (uint8)((BAT_AMPS_DR & BAT_AMPS_MASK) >> BAT_AMPS_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(BAT_AMPS_INTSTAT) 

    /*******************************************************************************
    * Function Name: BAT_AMPS_ClearInterrupt
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
    uint8 BAT_AMPS_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(BAT_AMPS_INTSTAT & BAT_AMPS_MASK);
		BAT_AMPS_INTSTAT = maskedStatus;
        return maskedStatus >> BAT_AMPS_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
