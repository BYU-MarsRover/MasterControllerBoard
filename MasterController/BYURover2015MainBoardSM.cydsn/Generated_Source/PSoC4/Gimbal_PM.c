/*******************************************************************************
* File Name: Gimbal_PM.c
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
#include "Gimbal.h"

static Gimbal_backupStruct Gimbal_backup;


/*******************************************************************************
* Function Name: Gimbal_SaveConfig
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
*  Gimbal_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Gimbal_SaveConfig(void) 
{
    
    #if(!Gimbal_UsingFixedFunction)
        #if(!Gimbal_PWMModeIsCenterAligned)
            Gimbal_backup.PWMPeriod = Gimbal_ReadPeriod();
        #endif /* (!Gimbal_PWMModeIsCenterAligned) */
        Gimbal_backup.PWMUdb = Gimbal_ReadCounter();
        #if (Gimbal_UseStatus)
            Gimbal_backup.InterruptMaskValue = Gimbal_STATUS_MASK;
        #endif /* (Gimbal_UseStatus) */
        
        #if(Gimbal_DeadBandMode == Gimbal__B_PWM__DBM_256_CLOCKS || \
            Gimbal_DeadBandMode == Gimbal__B_PWM__DBM_2_4_CLOCKS)
            Gimbal_backup.PWMdeadBandValue = Gimbal_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */
        
        #if(Gimbal_KillModeMinTime)
             Gimbal_backup.PWMKillCounterPeriod = Gimbal_ReadKillTime();
        #endif /* (Gimbal_KillModeMinTime) */
        
        #if(Gimbal_UseControl)
            Gimbal_backup.PWMControlRegister = Gimbal_ReadControlRegister();
        #endif /* (Gimbal_UseControl) */
    #endif  /* (!Gimbal_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Gimbal_RestoreConfig
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
*  Gimbal_backup:  Variables of this global structure are used to  
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Gimbal_RestoreConfig(void) 
{
        #if(!Gimbal_UsingFixedFunction)
            #if(!Gimbal_PWMModeIsCenterAligned)
                Gimbal_WritePeriod(Gimbal_backup.PWMPeriod);
            #endif /* (!Gimbal_PWMModeIsCenterAligned) */
            Gimbal_WriteCounter(Gimbal_backup.PWMUdb);
            #if (Gimbal_UseStatus)
                Gimbal_STATUS_MASK = Gimbal_backup.InterruptMaskValue;
            #endif /* (Gimbal_UseStatus) */
            
            #if(Gimbal_DeadBandMode == Gimbal__B_PWM__DBM_256_CLOCKS || \
                Gimbal_DeadBandMode == Gimbal__B_PWM__DBM_2_4_CLOCKS)
                Gimbal_WriteDeadTime(Gimbal_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */
            
            #if(Gimbal_KillModeMinTime)
                Gimbal_WriteKillTime(Gimbal_backup.PWMKillCounterPeriod);
            #endif /* (Gimbal_KillModeMinTime) */
            
            #if(Gimbal_UseControl)
                Gimbal_WriteControlRegister(Gimbal_backup.PWMControlRegister); 
            #endif /* (Gimbal_UseControl) */
        #endif  /* (!Gimbal_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: Gimbal_Sleep
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
*  Gimbal_backup.PWMEnableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Gimbal_Sleep(void) 
{
    #if(Gimbal_UseControl)
        if(Gimbal_CTRL_ENABLE == (Gimbal_CONTROL & Gimbal_CTRL_ENABLE))
        {
            /*Component is enabled */
            Gimbal_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            Gimbal_backup.PWMEnableState = 0u;
        }
    #endif /* (Gimbal_UseControl) */

    /* Stop component */
    Gimbal_Stop();
    
    /* Save registers configuration */
    Gimbal_SaveConfig();
}


/*******************************************************************************
* Function Name: Gimbal_Wakeup
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
*  Gimbal_backup.pwmEnable:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Gimbal_Wakeup(void) 
{
     /* Restore registers values */
    Gimbal_RestoreConfig();
    
    if(Gimbal_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        Gimbal_Enable();
    } /* Do nothing if component's block was disabled before */
    
}


/* [] END OF FILE */
