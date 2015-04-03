/*******************************************************************************
* File Name: Wheels_1_PM.c
* Version 1.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Wheels_1.h"

static Wheels_1_BACKUP_STRUCT Wheels_1_backup;


/*******************************************************************************
* Function Name: Wheels_1_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_1_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Wheels_1_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_1_Sleep(void)
{
    if(0u != (Wheels_1_BLOCK_CONTROL_REG & Wheels_1_MASK))
    {
        Wheels_1_backup.enableState = 1u;
    }
    else
    {
        Wheels_1_backup.enableState = 0u;
    }

    Wheels_1_Stop();
    Wheels_1_SaveConfig();
}


/*******************************************************************************
* Function Name: Wheels_1_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_1_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Wheels_1_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_1_Wakeup(void)
{
    Wheels_1_RestoreConfig();

    if(0u != Wheels_1_backup.enableState)
    {
        Wheels_1_Enable();
    }
}


/* [] END OF FILE */
