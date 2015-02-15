/*******************************************************************************
* File Name: L_PM.c
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

#include "L.h"

static L_BACKUP_STRUCT L_backup;


/*******************************************************************************
* Function Name: L_SaveConfig
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
void L_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: L_Sleep
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
void L_Sleep(void)
{
    if(0u != (L_BLOCK_CONTROL_REG & L_MASK))
    {
        L_backup.enableState = 1u;
    }
    else
    {
        L_backup.enableState = 0u;
    }

    L_Stop();
    L_SaveConfig();
}


/*******************************************************************************
* Function Name: L_RestoreConfig
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
void L_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: L_Wakeup
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
void L_Wakeup(void)
{
    L_RestoreConfig();

    if(0u != L_backup.enableState)
    {
        L_Enable();
    }
}


/* [] END OF FILE */
