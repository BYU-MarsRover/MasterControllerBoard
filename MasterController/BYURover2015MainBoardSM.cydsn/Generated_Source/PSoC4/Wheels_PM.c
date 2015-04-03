/*******************************************************************************
* File Name: Wheels_PM.c
* Version 3.0
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#include "cytypes.h"
#include "Wheels.h"

static Wheels_backupStruct Wheels_backup;


/*******************************************************************************
* Function Name: Wheels_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  Wheels_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Wheels_SaveConfig(void) 
{
    
    #if(!Wheels_UsingFixedFunction)
        #if(!Wheels_PWMModeIsCenterAligned)
            Wheels_backup.PWMPeriod = Wheels_ReadPeriod();
        #endif /* (!Wheels_PWMModeIsCenterAligned) */
        Wheels_backup.PWMUdb = Wheels_ReadCounter();
        #if (Wheels_UseStatus)
            Wheels_backup.InterruptMaskValue = Wheels_STATUS_MASK;
        #endif /* (Wheels_UseStatus) */
        
        #if(Wheels_DeadBandMode == Wheels__B_PWM__DBM_256_CLOCKS || \
            Wheels_DeadBandMode == Wheels__B_PWM__DBM_2_4_CLOCKS)
            Wheels_backup.PWMdeadBandValue = Wheels_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */
        
        #if(Wheels_KillModeMinTime)
             Wheels_backup.PWMKillCounterPeriod = Wheels_ReadKillTime();
        #endif /* (Wheels_KillModeMinTime) */
        
        #if(Wheels_UseControl)
            Wheels_backup.PWMControlRegister = Wheels_ReadControlRegister();
        #endif /* (Wheels_UseControl) */
    #endif  /* (!Wheels_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Wheels_RestoreConfig
********************************************************************************
* 
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  Wheels_backup:  Variables of this global structure are used to  
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Wheels_RestoreConfig(void) 
{
        #if(!Wheels_UsingFixedFunction)
            #if(!Wheels_PWMModeIsCenterAligned)
                Wheels_WritePeriod(Wheels_backup.PWMPeriod);
            #endif /* (!Wheels_PWMModeIsCenterAligned) */
            Wheels_WriteCounter(Wheels_backup.PWMUdb);
            #if (Wheels_UseStatus)
                Wheels_STATUS_MASK = Wheels_backup.InterruptMaskValue;
            #endif /* (Wheels_UseStatus) */
            
            #if(Wheels_DeadBandMode == Wheels__B_PWM__DBM_256_CLOCKS || \
                Wheels_DeadBandMode == Wheels__B_PWM__DBM_2_4_CLOCKS)
                Wheels_WriteDeadTime(Wheels_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */
            
            #if(Wheels_KillModeMinTime)
                Wheels_WriteKillTime(Wheels_backup.PWMKillCounterPeriod);
            #endif /* (Wheels_KillModeMinTime) */
            
            #if(Wheels_UseControl)
                Wheels_WriteControlRegister(Wheels_backup.PWMControlRegister); 
            #endif /* (Wheels_UseControl) */
        #endif  /* (!Wheels_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: Wheels_Sleep
********************************************************************************
* 
* Summary:
*  Disables block's operation and saves the user configuration. Should be called 
*  just prior to entering sleep.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  Wheels_backup.PWMEnableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Wheels_Sleep(void) 
{
    #if(Wheels_UseControl)
        if(Wheels_CTRL_ENABLE == (Wheels_CONTROL & Wheels_CTRL_ENABLE))
        {
            /*Component is enabled */
            Wheels_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            Wheels_backup.PWMEnableState = 0u;
        }
    #endif /* (Wheels_UseControl) */

    /* Stop component */
    Wheels_Stop();
    
    /* Save registers configuration */
    Wheels_SaveConfig();
}


/*******************************************************************************
* Function Name: Wheels_Wakeup
********************************************************************************
* 
* Summary:
*  Restores and enables the user configuration. Should be called just after 
*  awaking from sleep.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  Wheels_backup.pwmEnable:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Wheels_Wakeup(void) 
{
     /* Restore registers values */
    Wheels_RestoreConfig();
    
    if(Wheels_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        Wheels_Enable();
    } /* Do nothing if component's block was disabled before */
    
}


/* [] END OF FILE */
