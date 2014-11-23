/*******************************************************************************
* File Name: SW.c  
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
#include "SW.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        SW_PC =   (SW_PC & \
                                (uint32)(~(uint32)(SW_DRIVE_MODE_IND_MASK << (SW_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (SW_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: SW_Write
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
void SW_Write(uint8 value) 
{
    uint8 drVal = (uint8)(SW_DR & (uint8)(~SW_MASK));
    drVal = (drVal | ((uint8)(value << SW_SHIFT) & SW_MASK));
    SW_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: SW_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SW_DM_STRONG     Strong Drive 
*  SW_DM_OD_HI      Open Drain, Drives High 
*  SW_DM_OD_LO      Open Drain, Drives Low 
*  SW_DM_RES_UP     Resistive Pull Up 
*  SW_DM_RES_DWN    Resistive Pull Down 
*  SW_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SW_DM_DIG_HIZ    High Impedance Digital 
*  SW_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SW_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(SW__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: SW_Read
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
*  Macro SW_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SW_Read(void) 
{
    return (uint8)((SW_PS & SW_MASK) >> SW_SHIFT);
}


/*******************************************************************************
* Function Name: SW_ReadDataReg
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
uint8 SW_ReadDataReg(void) 
{
    return (uint8)((SW_DR & SW_MASK) >> SW_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SW_INTSTAT) 

    /*******************************************************************************
    * Function Name: SW_ClearInterrupt
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
    uint8 SW_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(SW_INTSTAT & SW_MASK);
		SW_INTSTAT = maskedStatus;
        return maskedStatus >> SW_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
