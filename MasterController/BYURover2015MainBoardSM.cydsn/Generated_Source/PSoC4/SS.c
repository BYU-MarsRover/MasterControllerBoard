/*******************************************************************************
* File Name: SS.c  
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
#include "SS.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        SS_PC =   (SS_PC & \
                                (uint32)(~(uint32)(SS_DRIVE_MODE_IND_MASK << (SS_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (SS_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: SS_Write
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
void SS_Write(uint8 value) 
{
    uint8 drVal = (uint8)(SS_DR & (uint8)(~SS_MASK));
    drVal = (drVal | ((uint8)(value << SS_SHIFT) & SS_MASK));
    SS_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: SS_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SS_DM_STRONG     Strong Drive 
*  SS_DM_OD_HI      Open Drain, Drives High 
*  SS_DM_OD_LO      Open Drain, Drives Low 
*  SS_DM_RES_UP     Resistive Pull Up 
*  SS_DM_RES_DWN    Resistive Pull Down 
*  SS_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SS_DM_DIG_HIZ    High Impedance Digital 
*  SS_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SS_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(SS__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: SS_Read
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
*  Macro SS_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SS_Read(void) 
{
    return (uint8)((SS_PS & SS_MASK) >> SS_SHIFT);
}


/*******************************************************************************
* Function Name: SS_ReadDataReg
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
uint8 SS_ReadDataReg(void) 
{
    return (uint8)((SS_DR & SS_MASK) >> SS_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SS_INTSTAT) 

    /*******************************************************************************
    * Function Name: SS_ClearInterrupt
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
    uint8 SS_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(SS_INTSTAT & SS_MASK);
		SS_INTSTAT = maskedStatus;
        return maskedStatus >> SS_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
