/*******************************************************************************
* File Name: R_Servo.c  
* Version 2.10
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
#include "R_Servo.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        R_Servo_PC =   (R_Servo_PC & \
                                (uint32)(~(uint32)(R_Servo_DRIVE_MODE_IND_MASK << (R_Servo_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (R_Servo_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: R_Servo_Write
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
void R_Servo_Write(uint8 value) 
{
    uint8 drVal = (uint8)(R_Servo_DR & (uint8)(~R_Servo_MASK));
    drVal = (drVal | ((uint8)(value << R_Servo_SHIFT) & R_Servo_MASK));
    R_Servo_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: R_Servo_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  R_Servo_DM_STRONG     Strong Drive 
*  R_Servo_DM_OD_HI      Open Drain, Drives High 
*  R_Servo_DM_OD_LO      Open Drain, Drives Low 
*  R_Servo_DM_RES_UP     Resistive Pull Up 
*  R_Servo_DM_RES_DWN    Resistive Pull Down 
*  R_Servo_DM_RES_UPDWN  Resistive Pull Up/Down 
*  R_Servo_DM_DIG_HIZ    High Impedance Digital 
*  R_Servo_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void R_Servo_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(R_Servo__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: R_Servo_Read
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
*  Macro R_Servo_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 R_Servo_Read(void) 
{
    return (uint8)((R_Servo_PS & R_Servo_MASK) >> R_Servo_SHIFT);
}


/*******************************************************************************
* Function Name: R_Servo_ReadDataReg
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
uint8 R_Servo_ReadDataReg(void) 
{
    return (uint8)((R_Servo_DR & R_Servo_MASK) >> R_Servo_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(R_Servo_INTSTAT) 

    /*******************************************************************************
    * Function Name: R_Servo_ClearInterrupt
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
    uint8 R_Servo_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(R_Servo_INTSTAT & R_Servo_MASK);
		R_Servo_INTSTAT = maskedStatus;
        return maskedStatus >> R_Servo_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
