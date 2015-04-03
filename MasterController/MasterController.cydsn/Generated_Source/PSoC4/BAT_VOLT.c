/*******************************************************************************
* File Name: BAT_VOLT.c  
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
#include "BAT_VOLT.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        BAT_VOLT_PC =   (BAT_VOLT_PC & \
                                (uint32)(~(uint32)(BAT_VOLT_DRIVE_MODE_IND_MASK << (BAT_VOLT_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (BAT_VOLT_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: BAT_VOLT_Write
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
void BAT_VOLT_Write(uint8 value) 
{
    uint8 drVal = (uint8)(BAT_VOLT_DR & (uint8)(~BAT_VOLT_MASK));
    drVal = (drVal | ((uint8)(value << BAT_VOLT_SHIFT) & BAT_VOLT_MASK));
    BAT_VOLT_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: BAT_VOLT_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  BAT_VOLT_DM_STRONG     Strong Drive 
*  BAT_VOLT_DM_OD_HI      Open Drain, Drives High 
*  BAT_VOLT_DM_OD_LO      Open Drain, Drives Low 
*  BAT_VOLT_DM_RES_UP     Resistive Pull Up 
*  BAT_VOLT_DM_RES_DWN    Resistive Pull Down 
*  BAT_VOLT_DM_RES_UPDWN  Resistive Pull Up/Down 
*  BAT_VOLT_DM_DIG_HIZ    High Impedance Digital 
*  BAT_VOLT_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void BAT_VOLT_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(BAT_VOLT__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: BAT_VOLT_Read
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
*  Macro BAT_VOLT_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 BAT_VOLT_Read(void) 
{
    return (uint8)((BAT_VOLT_PS & BAT_VOLT_MASK) >> BAT_VOLT_SHIFT);
}


/*******************************************************************************
* Function Name: BAT_VOLT_ReadDataReg
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
uint8 BAT_VOLT_ReadDataReg(void) 
{
    return (uint8)((BAT_VOLT_DR & BAT_VOLT_MASK) >> BAT_VOLT_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(BAT_VOLT_INTSTAT) 

    /*******************************************************************************
    * Function Name: BAT_VOLT_ClearInterrupt
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
    uint8 BAT_VOLT_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(BAT_VOLT_INTSTAT & BAT_VOLT_MASK);
		BAT_VOLT_INTSTAT = maskedStatus;
        return maskedStatus >> BAT_VOLT_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
