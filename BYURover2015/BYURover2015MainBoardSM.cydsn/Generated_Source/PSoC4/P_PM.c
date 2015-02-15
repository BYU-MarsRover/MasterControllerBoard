/*******************************************************************************
* File Name: P_PM.c
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

#include "P.h"

static P_BACKUP_STRUCT P_backup;


/*******************************************************************************
* Function Name: P_SaveConfig
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
void P_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: P_Sleep
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
void P_Sleep(void)
{
    if(0u != (P_BLOCK_CONTROL_REG & P_MASK))
    {
        P_backup.enableState = 1u;
    }
    else
    {
        P_backup.enableState = 0u;
    }

    P_Stop();
    P_SaveConfig();
}


/*******************************************************************************
* Function Name: P_RestoreConfig
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
void P_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: P_Wakeup
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
void P_Wakeup(void)
{
    P_RestoreConfig();

    if(0u != P_backup.enableState)
    {
        P_Enable();
    }
}


/* [] END OF FILE */
