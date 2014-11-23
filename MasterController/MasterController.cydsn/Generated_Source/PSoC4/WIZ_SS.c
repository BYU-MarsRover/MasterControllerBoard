/*******************************************************************************
* File Name: WIZ_SS.c  
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
#include "WIZ_SS.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        WIZ_SS_PC =   (WIZ_SS_PC & \
                                (uint32)(~(uint32)(WIZ_SS_DRIVE_MODE_IND_MASK << (WIZ_SS_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (WIZ_SS_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: WIZ_SS_Write
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
void WIZ_SS_Write(uint8 value) 
{
    uint8 drVal = (uint8)(WIZ_SS_DR & (uint8)(~WIZ_SS_MASK));
    drVal = (drVal | ((uint8)(value << WIZ_SS_SHIFT) & WIZ_SS_MASK));
    WIZ_SS_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: WIZ_SS_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  WIZ_SS_DM_STRONG     Strong Drive 
*  WIZ_SS_DM_OD_HI      Open Drain, Drives High 
*  WIZ_SS_DM_OD_LO      Open Drain, Drives Low 
*  WIZ_SS_DM_RES_UP     Resistive Pull Up 
*  WIZ_SS_DM_RES_DWN    Resistive Pull Down 
*  WIZ_SS_DM_RES_UPDWN  Resistive Pull Up/Down 
*  WIZ_SS_DM_DIG_HIZ    High Impedance Digital 
*  WIZ_SS_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void WIZ_SS_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(WIZ_SS__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: WIZ_SS_Read
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
*  Macro WIZ_SS_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 WIZ_SS_Read(void) 
{
    return (uint8)((WIZ_SS_PS & WIZ_SS_MASK) >> WIZ_SS_SHIFT);
}


/*******************************************************************************
* Function Name: WIZ_SS_ReadDataReg
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
uint8 WIZ_SS_ReadDataReg(void) 
{
    return (uint8)((WIZ_SS_DR & WIZ_SS_MASK) >> WIZ_SS_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(WIZ_SS_INTSTAT) 

    /*******************************************************************************
    * Function Name: WIZ_SS_ClearInterrupt
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
    uint8 WIZ_SS_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(WIZ_SS_INTSTAT & WIZ_SS_MASK);
		WIZ_SS_INTSTAT = maskedStatus;
        return maskedStatus >> WIZ_SS_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
