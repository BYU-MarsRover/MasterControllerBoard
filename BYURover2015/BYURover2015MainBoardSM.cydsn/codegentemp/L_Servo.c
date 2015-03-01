/*******************************************************************************
* File Name: L_Servo.c  
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
#include "L_Servo.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        L_Servo_PC =   (L_Servo_PC & \
                                (uint32)(~(uint32)(L_Servo_DRIVE_MODE_IND_MASK << (L_Servo_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (L_Servo_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: L_Servo_Write
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
void L_Servo_Write(uint8 value) 
{
    uint8 drVal = (uint8)(L_Servo_DR & (uint8)(~L_Servo_MASK));
    drVal = (drVal | ((uint8)(value << L_Servo_SHIFT) & L_Servo_MASK));
    L_Servo_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: L_Servo_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  L_Servo_DM_STRONG     Strong Drive 
*  L_Servo_DM_OD_HI      Open Drain, Drives High 
*  L_Servo_DM_OD_LO      Open Drain, Drives Low 
*  L_Servo_DM_RES_UP     Resistive Pull Up 
*  L_Servo_DM_RES_DWN    Resistive Pull Down 
*  L_Servo_DM_RES_UPDWN  Resistive Pull Up/Down 
*  L_Servo_DM_DIG_HIZ    High Impedance Digital 
*  L_Servo_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void L_Servo_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(L_Servo__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: L_Servo_Read
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
*  Macro L_Servo_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 L_Servo_Read(void) 
{
    return (uint8)((L_Servo_PS & L_Servo_MASK) >> L_Servo_SHIFT);
}


/*******************************************************************************
* Function Name: L_Servo_ReadDataReg
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
uint8 L_Servo_ReadDataReg(void) 
{
    return (uint8)((L_Servo_DR & L_Servo_MASK) >> L_Servo_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(L_Servo_INTSTAT) 

    /*******************************************************************************
    * Function Name: L_Servo_ClearInterrupt
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
    uint8 L_Servo_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(L_Servo_INTSTAT & L_Servo_MASK);
		L_Servo_INTSTAT = maskedStatus;
        return maskedStatus >> L_Servo_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
