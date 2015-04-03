/*******************************************************************************
* File Name: WIZ_RDY.c  
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
#include "WIZ_RDY.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        WIZ_RDY_PC =   (WIZ_RDY_PC & \
                                (uint32)(~(uint32)(WIZ_RDY_DRIVE_MODE_IND_MASK << (WIZ_RDY_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (WIZ_RDY_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: WIZ_RDY_Write
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
void WIZ_RDY_Write(uint8 value) 
{
    uint8 drVal = (uint8)(WIZ_RDY_DR & (uint8)(~WIZ_RDY_MASK));
    drVal = (drVal | ((uint8)(value << WIZ_RDY_SHIFT) & WIZ_RDY_MASK));
    WIZ_RDY_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: WIZ_RDY_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  WIZ_RDY_DM_STRONG     Strong Drive 
*  WIZ_RDY_DM_OD_HI      Open Drain, Drives High 
*  WIZ_RDY_DM_OD_LO      Open Drain, Drives Low 
*  WIZ_RDY_DM_RES_UP     Resistive Pull Up 
*  WIZ_RDY_DM_RES_DWN    Resistive Pull Down 
*  WIZ_RDY_DM_RES_UPDWN  Resistive Pull Up/Down 
*  WIZ_RDY_DM_DIG_HIZ    High Impedance Digital 
*  WIZ_RDY_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void WIZ_RDY_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(WIZ_RDY__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: WIZ_RDY_Read
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
*  Macro WIZ_RDY_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 WIZ_RDY_Read(void) 
{
    return (uint8)((WIZ_RDY_PS & WIZ_RDY_MASK) >> WIZ_RDY_SHIFT);
}


/*******************************************************************************
* Function Name: WIZ_RDY_ReadDataReg
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
uint8 WIZ_RDY_ReadDataReg(void) 
{
    return (uint8)((WIZ_RDY_DR & WIZ_RDY_MASK) >> WIZ_RDY_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(WIZ_RDY_INTSTAT) 

    /*******************************************************************************
    * Function Name: WIZ_RDY_ClearInterrupt
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
    uint8 WIZ_RDY_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(WIZ_RDY_INTSTAT & WIZ_RDY_MASK);
		WIZ_RDY_INTSTAT = maskedStatus;
        return maskedStatus >> WIZ_RDY_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
