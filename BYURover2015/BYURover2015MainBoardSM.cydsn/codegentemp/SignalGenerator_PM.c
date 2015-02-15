/*******************************************************************************
* File Name: SignalGenerator_PM.c
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

#include "SignalGenerator.h"

static SignalGenerator_BACKUP_STRUCT SignalGenerator_backup;


/*******************************************************************************
* Function Name: SignalGenerator_SaveConfig
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
void SignalGenerator_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: SignalGenerator_Sleep
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
void SignalGenerator_Sleep(void)
{
    if(0u != (SignalGenerator_BLOCK_CONTROL_REG & SignalGenerator_MASK))
    {
        SignalGenerator_backup.enableState = 1u;
    }
    else
    {
        SignalGenerator_backup.enableState = 0u;
    }

    SignalGenerator_Stop();
    SignalGenerator_SaveConfig();
}


/*******************************************************************************
* Function Name: SignalGenerator_RestoreConfig
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
void SignalGenerator_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: SignalGenerator_Wakeup
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
void SignalGenerator_Wakeup(void)
{
    SignalGenerator_RestoreConfig();

    if(0u != SignalGenerator_backup.enableState)
    {
        SignalGenerator_Enable();
    }
}


/* [] END OF FILE */
