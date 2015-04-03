/*******************************************************************************
* File Name: Gimbal.c  
* Version 3.0
*
* Description:
*  The PWM User Module consist of an 8 or 16-bit counter with two 8 or 16-bit
*  comparitors. Each instance of this user module is capable of generating
*  two PWM outputs with the same period. The pulse width is selectable between
*  1 and 255/65535. The period is selectable between 2 and 255/65536 clocks. 
*  The compare value output may be configured to be active when the present 
*  counter is less than or less than/equal to the compare value.
*  A terminal count output is also provided. It generates a pulse one clock
*  width wide when the counter is equal to zero.
*
* Note:
*
*******************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "cytypes.h"
#include "Gimbal.h"

uint8 Gimbal_initVar = 0u;


/*******************************************************************************
* Function Name: Gimbal_Start
********************************************************************************
*
* Summary:
*  The start function initializes the pwm with the default values, the 
*  enables the counter to begin counting.  It does not enable interrupts,
*  the EnableInt command should be called if interrupt generation is required.
*
* Parameters:  
*  None  
*
* Return: 
*  None
*
* Global variables:
*  Gimbal_initVar: Is modified when this function is called for the 
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void Gimbal_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(Gimbal_initVar == 0u)
    {
        Gimbal_Init();
        Gimbal_initVar = 1u;
    }
    Gimbal_Enable();

}


/*******************************************************************************
* Function Name: Gimbal_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the 
*  customizer of the component placed onto schematic. Usually called in 
*  Gimbal_Start().
*
* Parameters:  
*  None
*
* Return: 
*  None
*
*******************************************************************************/
void Gimbal_Init(void) 
{
    #if (Gimbal_UsingFixedFunction || Gimbal_UseControl)
        uint8 ctrl;
    #endif /* (Gimbal_UsingFixedFunction || Gimbal_UseControl) */
    
    #if(!Gimbal_UsingFixedFunction) 
        #if(Gimbal_UseStatus)
            /* Interrupt State Backup for Critical Region*/
            uint8 Gimbal_interruptState;
        #endif /* (Gimbal_UseStatus) */
    #endif /* (!Gimbal_UsingFixedFunction) */
    
    #if (Gimbal_UsingFixedFunction)
        /* You are allowed to write the compare value (FF only) */
        Gimbal_CONTROL |= Gimbal_CFG0_MODE;
        #if (Gimbal_DeadBand2_4)
            Gimbal_CONTROL |= Gimbal_CFG0_DB;
        #endif /* (Gimbal_DeadBand2_4) */
                
        ctrl = Gimbal_CONTROL3 & ((uint8 )(~Gimbal_CTRL_CMPMODE1_MASK));
        Gimbal_CONTROL3 = ctrl | Gimbal_DEFAULT_COMPARE1_MODE;
        
         /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        Gimbal_RT1 &= ((uint8)(~Gimbal_RT1_MASK));
        Gimbal_RT1 |= Gimbal_SYNC;     
                
        /*Enable DSI Sync all all inputs of the PWM*/
        Gimbal_RT1 &= ((uint8)(~Gimbal_SYNCDSI_MASK));
        Gimbal_RT1 |= Gimbal_SYNCDSI_EN;
       
    #elif (Gimbal_UseControl)
        /* Set the default compare mode defined in the parameter */
        ctrl = Gimbal_CONTROL & ((uint8)(~Gimbal_CTRL_CMPMODE2_MASK)) & ((uint8)(~Gimbal_CTRL_CMPMODE1_MASK));
        Gimbal_CONTROL = ctrl | Gimbal_DEFAULT_COMPARE2_MODE | 
                                   Gimbal_DEFAULT_COMPARE1_MODE;
    #endif /* (Gimbal_UsingFixedFunction) */
        
    #if (!Gimbal_UsingFixedFunction)
        #if (Gimbal_Resolution == 8)
            /* Set FIFO 0 to 1 byte register for period*/
            Gimbal_AUX_CONTROLDP0 |= (Gimbal_AUX_CTRL_FIFO0_CLR);
        #else /* (Gimbal_Resolution == 16)*/
            /* Set FIFO 0 to 1 byte register for period */
            Gimbal_AUX_CONTROLDP0 |= (Gimbal_AUX_CTRL_FIFO0_CLR);
            Gimbal_AUX_CONTROLDP1 |= (Gimbal_AUX_CTRL_FIFO0_CLR);
        #endif /* (Gimbal_Resolution == 8) */

        Gimbal_WriteCounter(Gimbal_INIT_PERIOD_VALUE);
    #endif /* (!Gimbal_UsingFixedFunction) */
        
    Gimbal_WritePeriod(Gimbal_INIT_PERIOD_VALUE);

        #if (Gimbal_UseOneCompareMode)
            Gimbal_WriteCompare(Gimbal_INIT_COMPARE_VALUE1);
        #else
            Gimbal_WriteCompare1(Gimbal_INIT_COMPARE_VALUE1);
            Gimbal_WriteCompare2(Gimbal_INIT_COMPARE_VALUE2);
        #endif /* (Gimbal_UseOneCompareMode) */
        
        #if (Gimbal_KillModeMinTime)
            Gimbal_WriteKillTime(Gimbal_MinimumKillTime);
        #endif /* (Gimbal_KillModeMinTime) */
        
        #if (Gimbal_DeadBandUsed)
            Gimbal_WriteDeadTime(Gimbal_INIT_DEAD_TIME);
        #endif /* (Gimbal_DeadBandUsed) */

    #if (Gimbal_UseStatus || Gimbal_UsingFixedFunction)
        Gimbal_SetInterruptMode(Gimbal_INIT_INTERRUPTS_MODE);
    #endif /* (Gimbal_UseStatus || Gimbal_UsingFixedFunction) */
        
    #if (Gimbal_UsingFixedFunction)
        /* Globally Enable the Fixed Function Block chosen */
        Gimbal_GLOBAL_ENABLE |= Gimbal_BLOCK_EN_MASK;
        /* Set the Interrupt source to come from the status register */
        Gimbal_CONTROL2 |= Gimbal_CTRL2_IRQ_SEL;
    #else
        #if(Gimbal_UseStatus)
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            Gimbal_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            Gimbal_STATUS_AUX_CTRL |= Gimbal_STATUS_ACTL_INT_EN_MASK;
            
             /* Exit Critical Region*/
            CyExitCriticalSection(Gimbal_interruptState);
            
            /* Clear the FIFO to enable the Gimbal_STATUS_FIFOFULL
                   bit to be set on FIFO full. */
            Gimbal_ClearFIFO();
        #endif /* (Gimbal_UseStatus) */
    #endif /* (Gimbal_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Gimbal_Enable
********************************************************************************
*
* Summary: 
*  Enables the PWM block operation
*
* Parameters:  
*  None
*
* Return: 
*  None
*
* Side Effects: 
*  This works only if software enable mode is chosen
*
*******************************************************************************/
void Gimbal_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (Gimbal_UsingFixedFunction)
        Gimbal_GLOBAL_ENABLE |= Gimbal_BLOCK_EN_MASK;
        Gimbal_GLOBAL_STBY_ENABLE |= Gimbal_BLOCK_STBY_EN_MASK;
    #endif /* (Gimbal_UsingFixedFunction) */
    
    /* Enable the PWM from the control register  */
    #if (Gimbal_UseControl || Gimbal_UsingFixedFunction)
        Gimbal_CONTROL |= Gimbal_CTRL_ENABLE;
    #endif /* (Gimbal_UseControl || Gimbal_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Gimbal_Stop
********************************************************************************
*
* Summary:
*  The stop function halts the PWM, but does not change any modes or disable
*  interrupts.
*
* Parameters:  
*  None  
*
* Return: 
*  None
*
* Side Effects:
*  If the Enable mode is set to Hardware only then this function
*  has no effect on the operation of the PWM
*
*******************************************************************************/
void Gimbal_Stop(void) 
{
    #if (Gimbal_UseControl || Gimbal_UsingFixedFunction)
        Gimbal_CONTROL &= ((uint8)(~Gimbal_CTRL_ENABLE));
    #endif /* (Gimbal_UseControl || Gimbal_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (Gimbal_UsingFixedFunction)
        Gimbal_GLOBAL_ENABLE &= ((uint8)(~Gimbal_BLOCK_EN_MASK));
        Gimbal_GLOBAL_STBY_ENABLE &= ((uint8)(~Gimbal_BLOCK_STBY_EN_MASK));
    #endif /* (Gimbal_UsingFixedFunction) */
}


#if (Gimbal_UseOneCompareMode)
	#if (Gimbal_CompareMode1SW)


		/*******************************************************************************
		* Function Name: Gimbal_SetCompareMode
		********************************************************************************
		* 
		* Summary:
		*  This function writes the Compare Mode for the pwm output when in Dither mode,
		*  Center Align Mode or One Output Mode.
		*
		* Parameters:
		*  comparemode:  The new compare mode for the PWM output. Use the compare types
		*                defined in the H file as input arguments.
		*
		* Return:
		*  None
		*
		*******************************************************************************/
		void Gimbal_SetCompareMode(uint8 comparemode) 
		{
		    #if(Gimbal_UsingFixedFunction)
            
                #if(0 != Gimbal_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemodemasked = ((uint8)((uint8)comparemode << Gimbal_CTRL_CMPMODE1_SHIFT));
                #else
                    uint8 comparemodemasked = comparemode;
                #endif /* (0 != Gimbal_CTRL_CMPMODE1_SHIFT) */
            
	            Gimbal_CONTROL3 &= ((uint8)(~Gimbal_CTRL_CMPMODE1_MASK)); /*Clear Existing Data */
	            Gimbal_CONTROL3 |= comparemodemasked;     
		                
		    #elif (Gimbal_UseControl)
		        
                #if(0 != Gimbal_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemode1masked = ((uint8)((uint8)comparemode << Gimbal_CTRL_CMPMODE1_SHIFT)) & 
    		                                    Gimbal_CTRL_CMPMODE1_MASK;
                #else
                    uint8 comparemode1masked = comparemode & Gimbal_CTRL_CMPMODE1_MASK;                
                #endif /* (0 != Gimbal_CTRL_CMPMODE1_SHIFT) */
                
                #if(0 != Gimbal_CTRL_CMPMODE2_SHIFT)                            
    		        uint8 comparemode2masked = ((uint8)((uint8)comparemode << Gimbal_CTRL_CMPMODE2_SHIFT)) & 
    		                                   Gimbal_CTRL_CMPMODE2_MASK;
                #else
    		        uint8 comparemode2masked = comparemode & Gimbal_CTRL_CMPMODE2_MASK;                
                #endif /* (0 != Gimbal_CTRL_CMPMODE2_SHIFT) */
                
		        /*Clear existing mode */
		        Gimbal_CONTROL &= ((uint8)(~(Gimbal_CTRL_CMPMODE1_MASK | Gimbal_CTRL_CMPMODE2_MASK))); 
		        Gimbal_CONTROL |= (comparemode1masked | comparemode2masked);
		        
		    #else
		        uint8 temp = comparemode;
		    #endif /* (Gimbal_UsingFixedFunction) */
		}
	#endif /* Gimbal_CompareMode1SW */

#else /* UseOneCompareMode */

	#if (Gimbal_CompareMode1SW)


		/*******************************************************************************
		* Function Name: Gimbal_SetCompareMode1
		********************************************************************************
		* 
		* Summary:
		*  This function writes the Compare Mode for the pwm or pwm1 output
		*
		* Parameters:  
		*  comparemode:  The new compare mode for the PWM output. Use the compare types
		*                defined in the H file as input arguments.
		*
		* Return: 
		*  None
		*
		*******************************************************************************/
		void Gimbal_SetCompareMode1(uint8 comparemode) 
		{
		    #if(0 != Gimbal_CTRL_CMPMODE1_SHIFT)
                uint8 comparemodemasked = ((uint8)((uint8)comparemode << Gimbal_CTRL_CMPMODE1_SHIFT)) & 
    		                               Gimbal_CTRL_CMPMODE1_MASK;
		    #else
                uint8 comparemodemasked = comparemode & Gimbal_CTRL_CMPMODE1_MASK;                
            #endif /* (0 != Gimbal_CTRL_CMPMODE1_SHIFT) */
                   
		    #if (Gimbal_UseControl)
		        Gimbal_CONTROL &= ((uint8)(~Gimbal_CTRL_CMPMODE1_MASK)); /*Clear existing mode */
		        Gimbal_CONTROL |= comparemodemasked;
		    #endif /* (Gimbal_UseControl) */
		}
	#endif /* Gimbal_CompareMode1SW */

#if (Gimbal_CompareMode2SW)


    /*******************************************************************************
    * Function Name: Gimbal_SetCompareMode2
    ********************************************************************************
    * 
    * Summary:
    *  This function writes the Compare Mode for the pwm or pwm2 output
    *
    * Parameters:  
    *  comparemode:  The new compare mode for the PWM output. Use the compare types
    *                defined in the H file as input arguments.
    *
    * Return: 
    *  None
    *
    *******************************************************************************/
    void Gimbal_SetCompareMode2(uint8 comparemode) 
    {

        #if(0 != Gimbal_CTRL_CMPMODE2_SHIFT)
            uint8 comparemodemasked = ((uint8)((uint8)comparemode << Gimbal_CTRL_CMPMODE2_SHIFT)) & 
                                                 Gimbal_CTRL_CMPMODE2_MASK;
        #else
            uint8 comparemodemasked = comparemode & Gimbal_CTRL_CMPMODE2_MASK;            
        #endif /* (0 != Gimbal_CTRL_CMPMODE2_SHIFT) */
        
        #if (Gimbal_UseControl)
            Gimbal_CONTROL &= ((uint8)(~Gimbal_CTRL_CMPMODE2_MASK)); /*Clear existing mode */
            Gimbal_CONTROL |= comparemodemasked;
        #endif /* (Gimbal_UseControl) */
    }
    #endif /*Gimbal_CompareMode2SW */

#endif /* UseOneCompareMode */


#if (!Gimbal_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: Gimbal_WriteCounter
    ********************************************************************************
    * 
    * Summary:
    *  Writes a new counter value directly to the counter register. This will be 
    *  implemented for that currently running period and only that period. This API 
    *  is valid only for UDB implementation and not available for fixed function 
    *  PWM implementation.    
    *
    * Parameters:  
    *  counter:  The period new period counter value.
    *
    * Return: 
    *  None
    *
    * Side Effects: 
    *  The PWM Period will be reloaded when a counter value will be a zero
    *
    *******************************************************************************/
    void Gimbal_WriteCounter(uint16 counter) \
                                       
    {
        CY_SET_REG16(Gimbal_COUNTER_LSB_PTR, counter);
    }


    /*******************************************************************************
    * Function Name: Gimbal_ReadCounter
    ********************************************************************************
    * 
    * Summary:
    *  This function returns the current value of the counter.  It doesn't matter
    *  if the counter is enabled or running.
    *
    * Parameters:  
    *  None  
    *
    * Return: 
    *  The current value of the counter.
    *
    *******************************************************************************/
    uint16 Gimbal_ReadCounter(void) 
    {
        /* Force capture by reading Accumulator */
        /* Must first do a software capture to be able to read the counter */
        /* It is up to the user code to make sure there isn't already captured data in the FIFO */
        (void)Gimbal_COUNTERCAP_LSB;
        
        /* Read the data from the FIFO (or capture register for Fixed Function)*/
        return (CY_GET_REG16(Gimbal_CAPTURE_LSB_PTR));
    }

        #if (Gimbal_UseStatus)


            /*******************************************************************************
            * Function Name: Gimbal_ClearFIFO
            ********************************************************************************
            * 
            * Summary:
            *  This function clears all capture data from the capture FIFO
            *
            * Parameters:  
            *  None
            *
            * Return: 
            *  None
            *
            *******************************************************************************/
            void Gimbal_ClearFIFO(void) 
            {
                while(0u != (Gimbal_ReadStatusRegister() & Gimbal_STATUS_FIFONEMPTY))
                {
                    (void)Gimbal_ReadCapture();
                }
            }

        #endif /* Gimbal_UseStatus */

#endif /* !Gimbal_UsingFixedFunction */


/*******************************************************************************
* Function Name: Gimbal_WritePeriod
********************************************************************************
* 
* Summary:
*  This function is used to change the period of the counter.  The new period 
*  will be loaded the next time terminal count is detected.
*
* Parameters:  
*  period:  Period value. May be between 1 and (2^Resolution)-1.  A value of 0 
*           will result in the counter remaining at zero.
*
* Return: 
*  None
*
*******************************************************************************/
void Gimbal_WritePeriod(uint16 period) 
{
    #if(Gimbal_UsingFixedFunction)
        CY_SET_REG16(Gimbal_PERIOD_LSB_PTR, (uint16)period);
    #else
        CY_SET_REG16(Gimbal_PERIOD_LSB_PTR, period);
    #endif /* (Gimbal_UsingFixedFunction) */
}

#if (Gimbal_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: Gimbal_WriteCompare
    ********************************************************************************
    * 
    * Summary:
    *  This funtion is used to change the compare1 value when the PWM is in Dither
    *  mode. The compare output will reflect the new value on the next UDB clock. 
    *  The compare output will be driven high when the present counter value is 
    *  compared to the compare value based on the compare mode defined in 
    *  Dither Mode.
    *
    * Parameters:  
    *  compare:  New compare value.  
    *
    * Return: 
    *  None
    *
    * Side Effects:
    *  This function is only available if the PWM mode parameter is set to
    *  Dither Mode, Center Aligned Mode or One Output Mode
    *
    *******************************************************************************/
    void Gimbal_WriteCompare(uint16 compare) \
                                       
    {	
		#if(Gimbal_UsingFixedFunction)
			CY_SET_REG16(Gimbal_COMPARE1_LSB_PTR, (uint16)compare);
		#else
	        CY_SET_REG16(Gimbal_COMPARE1_LSB_PTR, compare);	
		#endif /* (Gimbal_UsingFixedFunction) */
        
        #if (Gimbal_PWMMode == Gimbal__B_PWM__DITHER)
            #if(Gimbal_UsingFixedFunction)
    			CY_SET_REG16(Gimbal_COMPARE2_LSB_PTR, (uint16)(compare + 1u));
    		#else
    	        CY_SET_REG16(Gimbal_COMPARE2_LSB_PTR, (compare + 1u));	
    		#endif /* (Gimbal_UsingFixedFunction) */
        #endif /* (Gimbal_PWMMode == Gimbal__B_PWM__DITHER) */
    }


#else


    /*******************************************************************************
    * Function Name: Gimbal_WriteCompare1
    ********************************************************************************
    * 
    * Summary:
    *  This funtion is used to change the compare1 value.  The compare output will 
    *  reflect the new value on the next UDB clock.  The compare output will be 
    *  driven high when the present counter value is less than or less than or 
    *  equal to the compare register, depending on the mode.
    *
    * Parameters:  
    *  compare:  New compare value.  
    *
    * Return: 
    *  None
    *
    *******************************************************************************/
    void Gimbal_WriteCompare1(uint16 compare) \
                                        
    {
        #if(Gimbal_UsingFixedFunction)
            CY_SET_REG16(Gimbal_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(Gimbal_COMPARE1_LSB_PTR, compare);
        #endif /* (Gimbal_UsingFixedFunction) */
    }


    /*******************************************************************************
    * Function Name: Gimbal_WriteCompare2
    ********************************************************************************
    * 
    * Summary:
    *  This funtion is used to change the compare value, for compare1 output.  
    *  The compare output will reflect the new value on the next UDB clock.  
    *  The compare output will be driven high when the present counter value is 
    *  less than or less than or equal to the compare register, depending on the 
    *  mode.
    *
    * Parameters:  
    *  compare:  New compare value.  
    *
    * Return: 
    *  None
    *
    *******************************************************************************/
    void Gimbal_WriteCompare2(uint16 compare) \
                                        
    {
        #if(Gimbal_UsingFixedFunction)
            CY_SET_REG16(Gimbal_COMPARE2_LSB_PTR, compare);
        #else
            CY_SET_REG16(Gimbal_COMPARE2_LSB_PTR, compare);
        #endif /* (Gimbal_UsingFixedFunction) */
    }
#endif /* UseOneCompareMode */

#if (Gimbal_DeadBandUsed)


    /*******************************************************************************
    * Function Name: Gimbal_WriteDeadTime
    ********************************************************************************
    * 
    * Summary:
    *  This function writes the dead-band counts to the corresponding register
    *
    * Parameters:  
    *  deadtime:  Number of counts for dead time 
    *
    * Return: 
    *  None
    *
    *******************************************************************************/
    void Gimbal_WriteDeadTime(uint8 deadtime) 
    {
        /* If using the Dead Band 1-255 mode then just write the register */
        #if(!Gimbal_DeadBand2_4)
            CY_SET_REG8(Gimbal_DEADBAND_COUNT_PTR, deadtime);
        #else
            /* Otherwise the data has to be masked and offset */        
            /* Clear existing data */
            Gimbal_DEADBAND_COUNT &= ((uint8)(~Gimbal_DEADBAND_COUNT_MASK));
            
            /* Set new dead time */
            #if(Gimbal_DEADBAND_COUNT_SHIFT)        
                Gimbal_DEADBAND_COUNT |= ((uint8)((uint8)deadtime << Gimbal_DEADBAND_COUNT_SHIFT)) & 
                                                    Gimbal_DEADBAND_COUNT_MASK;
            #else
                Gimbal_DEADBAND_COUNT |= deadtime & Gimbal_DEADBAND_COUNT_MASK;        
            #endif /* (Gimbal_DEADBAND_COUNT_SHIFT) */
        
        #endif /* (!Gimbal_DeadBand2_4) */
    }


    /*******************************************************************************
    * Function Name: Gimbal_ReadDeadTime
    ********************************************************************************
    * 
    * Summary:
    *  This function reads the dead-band counts from the corresponding register
    *
    * Parameters:  
    *  None
    *
    * Return: 
    *  Dead Band Counts
    *
    *******************************************************************************/
    uint8 Gimbal_ReadDeadTime(void) 
    {
        /* If using the Dead Band 1-255 mode then just read the register */
        #if(!Gimbal_DeadBand2_4)
            return (CY_GET_REG8(Gimbal_DEADBAND_COUNT_PTR));
        #else
        
            /* Otherwise the data has to be masked and offset */
            #if(Gimbal_DEADBAND_COUNT_SHIFT)      
                return ((uint8)(((uint8)(Gimbal_DEADBAND_COUNT & Gimbal_DEADBAND_COUNT_MASK)) >> 
                                                                           Gimbal_DEADBAND_COUNT_SHIFT));
            #else
                return (Gimbal_DEADBAND_COUNT & Gimbal_DEADBAND_COUNT_MASK);
            #endif /* (Gimbal_DEADBAND_COUNT_SHIFT) */
        #endif /* (!Gimbal_DeadBand2_4) */
    }
#endif /* DeadBandUsed */

#if (Gimbal_UseStatus || Gimbal_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: Gimbal_SetInterruptMode
    ********************************************************************************
    * 
    * Summary:
    *  This function configures the interrupts mask control of theinterrupt 
    *  source status register.
    *
    * Parameters:  
    *  uint8 interruptMode: Bit field containing the interrupt sources enabled 
    *
    * Return: 
    *  None
    *
    *******************************************************************************/
    void Gimbal_SetInterruptMode(uint8 interruptMode)  
    {
    	CY_SET_REG8(Gimbal_STATUS_MASK_PTR, interruptMode);
    }


    /*******************************************************************************
    * Function Name: Gimbal_ReadStatusRegister
    ********************************************************************************
    * 
    * Summary:
    *  This function returns the current state of the status register. 
    *
    * Parameters:  
    *  None
    *
    * Return: 
    *  uint8 : Current status register value. The status register bits are:
    *  [7:6] : Unused(0)
    *  [5]   : Kill event output
    *  [4]   : FIFO not empty
    *  [3]   : FIFO full
    *  [2]   : Terminal count
    *  [1]   : Compare output 2
    *  [0]   : Compare output 1
    *
    *******************************************************************************/
    uint8 Gimbal_ReadStatusRegister(void)   
    {
    	uint8 result;
    	
    	result = CY_GET_REG8(Gimbal_STATUS_PTR);
    	return (result);
    }

#endif /* (Gimbal_UseStatus || Gimbal_UsingFixedFunction) */


#if (Gimbal_UseControl)


    /*******************************************************************************
    * Function Name: Gimbal_ReadControlRegister
    ********************************************************************************
    * 
    * Summary:
    *  Returns the current state of the control register. This API is available 
    *  only if the control register is not removed.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  uint8 : Current control register value
    *
    *******************************************************************************/    
    uint8 Gimbal_ReadControlRegister(void) 
    {
    	uint8 result;
    	
    	result = CY_GET_REG8(Gimbal_CONTROL_PTR);
    	return (result);
    }


    /*******************************************************************************
    * Function Name: Gimbal_WriteControlRegister
    ********************************************************************************
    * 
    * Summary:
    *  Sets the bit field of the control register. This API is available only if 
    *  the control register is not removed.
    *
    * Parameters:  
    *  uint8 control: Control register bit field, The status register bits are:
    *  [7]   : PWM Enable
    *  [6]   : Reset
    *  [5:3] : Compare Mode2
    *  [2:0] : Compare Mode2
    *
    * Return: 
    *  None
    *
    *******************************************************************************/  
    void Gimbal_WriteControlRegister(uint8 control) 
    {
    	CY_SET_REG8(Gimbal_CONTROL_PTR, control);
    }
	
#endif /* (Gimbal_UseControl) */


#if (!Gimbal_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: Gimbal_ReadCapture
    ********************************************************************************
    * 
    * Summary:
    *  Reads the capture value from the capture FIFO.
    *
    * Parameters:  
    *  None
    *
    * Return: 
    *  uint8/uint16: The current capture value
    *
    *******************************************************************************/  
    uint16 Gimbal_ReadCapture(void)  
    {
    	return (CY_GET_REG16(Gimbal_CAPTURE_LSB_PTR));
    }
	
#endif /* (!Gimbal_UsingFixedFunction) */


#if (Gimbal_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: Gimbal_ReadCompare
    ********************************************************************************
    * 
    * Summary:
    *  Reads the compare value for the compare output when the PWM Mode parameter is 
    *  set to Dither mode, Center Aligned mode, or One Output mode.
    *
    * Parameters:  
    *  None
    *
    * Return: 
    *  uint8/uint16: Current compare value
    *
    *******************************************************************************/  
    uint16 Gimbal_ReadCompare(void)  
    {
		#if(Gimbal_UsingFixedFunction)
            return ((uint16)CY_GET_REG16(Gimbal_COMPARE1_LSB_PTR));
        #else
            return (CY_GET_REG16(Gimbal_COMPARE1_LSB_PTR));
        #endif /* (Gimbal_UsingFixedFunction) */
    }

#else


    /*******************************************************************************
    * Function Name: Gimbal_ReadCompare1
    ********************************************************************************
    * 
    * Summary:
    *  Reads the compare value for the compare1 output.
    *
    * Parameters:  
    *  None
    *
    * Return: 
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/  
    uint16 Gimbal_ReadCompare1(void) 
    {
		return (CY_GET_REG16(Gimbal_COMPARE1_LSB_PTR));
    }


    /*******************************************************************************
    * Function Name: Gimbal_ReadCompare2
    ********************************************************************************
    * 
    * Summary:
    *  Reads the compare value for the compare2 output.
    *
    * Parameters:  
    *  None
    *
    * Return: 
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/  
    uint16 Gimbal_ReadCompare2(void)  
    {
		return (CY_GET_REG16(Gimbal_COMPARE2_LSB_PTR));
    }

#endif /* (Gimbal_UseOneCompareMode) */


/*******************************************************************************
* Function Name: Gimbal_ReadPeriod
********************************************************************************
* 
* Summary:
*  Reads the period value used by the PWM hardware.
*
* Parameters:  
*  None
*
* Return: 
*  uint8/16: Period value
*
*******************************************************************************/ 
uint16 Gimbal_ReadPeriod(void) 
{
	#if(Gimbal_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(Gimbal_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(Gimbal_PERIOD_LSB_PTR));
    #endif /* (Gimbal_UsingFixedFunction) */
}

#if ( Gimbal_KillModeMinTime)


    /*******************************************************************************
    * Function Name: Gimbal_WriteKillTime
    ********************************************************************************
    * 
    * Summary:
    *  Writes the kill time value used by the hardware when the Kill Mode 
    *  is set to Minimum Time.
    *
    * Parameters:  
    *  uint8: Minimum Time kill counts
    *
    * Return: 
    *  None
    *
    *******************************************************************************/ 
    void Gimbal_WriteKillTime(uint8 killtime) 
    {
    	CY_SET_REG8(Gimbal_KILLMODEMINTIME_PTR, killtime);
    }


    /*******************************************************************************
    * Function Name: Gimbal_ReadKillTime
    ********************************************************************************
    * 
    * Summary:
    *  Reads the kill time value used by the hardware when the Kill Mode is set 
    *  to Minimum Time.
    *
    * Parameters:  
    *  None
    *
    * Return: 
    *  uint8: The current Minimum Time kill counts
    *
    *******************************************************************************/ 
    uint8 Gimbal_ReadKillTime(void) 
    {
    	return (CY_GET_REG8(Gimbal_KILLMODEMINTIME_PTR));
    }

#endif /* ( Gimbal_KillModeMinTime) */

/* [] END OF FILE */
