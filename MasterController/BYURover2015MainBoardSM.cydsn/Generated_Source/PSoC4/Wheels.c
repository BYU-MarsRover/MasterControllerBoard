/*******************************************************************************
* File Name: Wheels.c  
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
#include "Wheels.h"

uint8 Wheels_initVar = 0u;


/*******************************************************************************
* Function Name: Wheels_Start
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
*  Wheels_initVar: Is modified when this function is called for the 
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void Wheels_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(Wheels_initVar == 0u)
    {
        Wheels_Init();
        Wheels_initVar = 1u;
    }
    Wheels_Enable();

}


/*******************************************************************************
* Function Name: Wheels_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the 
*  customizer of the component placed onto schematic. Usually called in 
*  Wheels_Start().
*
* Parameters:  
*  None
*
* Return: 
*  None
*
*******************************************************************************/
void Wheels_Init(void) 
{
    #if (Wheels_UsingFixedFunction || Wheels_UseControl)
        uint8 ctrl;
    #endif /* (Wheels_UsingFixedFunction || Wheels_UseControl) */
    
    #if(!Wheels_UsingFixedFunction) 
        #if(Wheels_UseStatus)
            /* Interrupt State Backup for Critical Region*/
            uint8 Wheels_interruptState;
        #endif /* (Wheels_UseStatus) */
    #endif /* (!Wheels_UsingFixedFunction) */
    
    #if (Wheels_UsingFixedFunction)
        /* You are allowed to write the compare value (FF only) */
        Wheels_CONTROL |= Wheels_CFG0_MODE;
        #if (Wheels_DeadBand2_4)
            Wheels_CONTROL |= Wheels_CFG0_DB;
        #endif /* (Wheels_DeadBand2_4) */
                
        ctrl = Wheels_CONTROL3 & ((uint8 )(~Wheels_CTRL_CMPMODE1_MASK));
        Wheels_CONTROL3 = ctrl | Wheels_DEFAULT_COMPARE1_MODE;
        
         /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        Wheels_RT1 &= ((uint8)(~Wheels_RT1_MASK));
        Wheels_RT1 |= Wheels_SYNC;     
                
        /*Enable DSI Sync all all inputs of the PWM*/
        Wheels_RT1 &= ((uint8)(~Wheels_SYNCDSI_MASK));
        Wheels_RT1 |= Wheels_SYNCDSI_EN;
       
    #elif (Wheels_UseControl)
        /* Set the default compare mode defined in the parameter */
        ctrl = Wheels_CONTROL & ((uint8)(~Wheels_CTRL_CMPMODE2_MASK)) & ((uint8)(~Wheels_CTRL_CMPMODE1_MASK));
        Wheels_CONTROL = ctrl | Wheels_DEFAULT_COMPARE2_MODE | 
                                   Wheels_DEFAULT_COMPARE1_MODE;
    #endif /* (Wheels_UsingFixedFunction) */
        
    #if (!Wheels_UsingFixedFunction)
        #if (Wheels_Resolution == 8)
            /* Set FIFO 0 to 1 byte register for period*/
            Wheels_AUX_CONTROLDP0 |= (Wheels_AUX_CTRL_FIFO0_CLR);
        #else /* (Wheels_Resolution == 16)*/
            /* Set FIFO 0 to 1 byte register for period */
            Wheels_AUX_CONTROLDP0 |= (Wheels_AUX_CTRL_FIFO0_CLR);
            Wheels_AUX_CONTROLDP1 |= (Wheels_AUX_CTRL_FIFO0_CLR);
        #endif /* (Wheels_Resolution == 8) */

        Wheels_WriteCounter(Wheels_INIT_PERIOD_VALUE);
    #endif /* (!Wheels_UsingFixedFunction) */
        
    Wheels_WritePeriod(Wheels_INIT_PERIOD_VALUE);

        #if (Wheels_UseOneCompareMode)
            Wheels_WriteCompare(Wheels_INIT_COMPARE_VALUE1);
        #else
            Wheels_WriteCompare1(Wheels_INIT_COMPARE_VALUE1);
            Wheels_WriteCompare2(Wheels_INIT_COMPARE_VALUE2);
        #endif /* (Wheels_UseOneCompareMode) */
        
        #if (Wheels_KillModeMinTime)
            Wheels_WriteKillTime(Wheels_MinimumKillTime);
        #endif /* (Wheels_KillModeMinTime) */
        
        #if (Wheels_DeadBandUsed)
            Wheels_WriteDeadTime(Wheels_INIT_DEAD_TIME);
        #endif /* (Wheels_DeadBandUsed) */

    #if (Wheels_UseStatus || Wheels_UsingFixedFunction)
        Wheels_SetInterruptMode(Wheels_INIT_INTERRUPTS_MODE);
    #endif /* (Wheels_UseStatus || Wheels_UsingFixedFunction) */
        
    #if (Wheels_UsingFixedFunction)
        /* Globally Enable the Fixed Function Block chosen */
        Wheels_GLOBAL_ENABLE |= Wheels_BLOCK_EN_MASK;
        /* Set the Interrupt source to come from the status register */
        Wheels_CONTROL2 |= Wheels_CTRL2_IRQ_SEL;
    #else
        #if(Wheels_UseStatus)
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            Wheels_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            Wheels_STATUS_AUX_CTRL |= Wheels_STATUS_ACTL_INT_EN_MASK;
            
             /* Exit Critical Region*/
            CyExitCriticalSection(Wheels_interruptState);
            
            /* Clear the FIFO to enable the Wheels_STATUS_FIFOFULL
                   bit to be set on FIFO full. */
            Wheels_ClearFIFO();
        #endif /* (Wheels_UseStatus) */
    #endif /* (Wheels_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Wheels_Enable
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
void Wheels_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (Wheels_UsingFixedFunction)
        Wheels_GLOBAL_ENABLE |= Wheels_BLOCK_EN_MASK;
        Wheels_GLOBAL_STBY_ENABLE |= Wheels_BLOCK_STBY_EN_MASK;
    #endif /* (Wheels_UsingFixedFunction) */
    
    /* Enable the PWM from the control register  */
    #if (Wheels_UseControl || Wheels_UsingFixedFunction)
        Wheels_CONTROL |= Wheels_CTRL_ENABLE;
    #endif /* (Wheels_UseControl || Wheels_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Wheels_Stop
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
void Wheels_Stop(void) 
{
    #if (Wheels_UseControl || Wheels_UsingFixedFunction)
        Wheels_CONTROL &= ((uint8)(~Wheels_CTRL_ENABLE));
    #endif /* (Wheels_UseControl || Wheels_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (Wheels_UsingFixedFunction)
        Wheels_GLOBAL_ENABLE &= ((uint8)(~Wheels_BLOCK_EN_MASK));
        Wheels_GLOBAL_STBY_ENABLE &= ((uint8)(~Wheels_BLOCK_STBY_EN_MASK));
    #endif /* (Wheels_UsingFixedFunction) */
}


#if (Wheels_UseOneCompareMode)
	#if (Wheels_CompareMode1SW)


		/*******************************************************************************
		* Function Name: Wheels_SetCompareMode
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
		void Wheels_SetCompareMode(uint8 comparemode) 
		{
		    #if(Wheels_UsingFixedFunction)
            
                #if(0 != Wheels_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemodemasked = ((uint8)((uint8)comparemode << Wheels_CTRL_CMPMODE1_SHIFT));
                #else
                    uint8 comparemodemasked = comparemode;
                #endif /* (0 != Wheels_CTRL_CMPMODE1_SHIFT) */
            
	            Wheels_CONTROL3 &= ((uint8)(~Wheels_CTRL_CMPMODE1_MASK)); /*Clear Existing Data */
	            Wheels_CONTROL3 |= comparemodemasked;     
		                
		    #elif (Wheels_UseControl)
		        
                #if(0 != Wheels_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemode1masked = ((uint8)((uint8)comparemode << Wheels_CTRL_CMPMODE1_SHIFT)) & 
    		                                    Wheels_CTRL_CMPMODE1_MASK;
                #else
                    uint8 comparemode1masked = comparemode & Wheels_CTRL_CMPMODE1_MASK;                
                #endif /* (0 != Wheels_CTRL_CMPMODE1_SHIFT) */
                
                #if(0 != Wheels_CTRL_CMPMODE2_SHIFT)                            
    		        uint8 comparemode2masked = ((uint8)((uint8)comparemode << Wheels_CTRL_CMPMODE2_SHIFT)) & 
    		                                   Wheels_CTRL_CMPMODE2_MASK;
                #else
    		        uint8 comparemode2masked = comparemode & Wheels_CTRL_CMPMODE2_MASK;                
                #endif /* (0 != Wheels_CTRL_CMPMODE2_SHIFT) */
                
		        /*Clear existing mode */
		        Wheels_CONTROL &= ((uint8)(~(Wheels_CTRL_CMPMODE1_MASK | Wheels_CTRL_CMPMODE2_MASK))); 
		        Wheels_CONTROL |= (comparemode1masked | comparemode2masked);
		        
		    #else
		        uint8 temp = comparemode;
		    #endif /* (Wheels_UsingFixedFunction) */
		}
	#endif /* Wheels_CompareMode1SW */

#else /* UseOneCompareMode */

	#if (Wheels_CompareMode1SW)


		/*******************************************************************************
		* Function Name: Wheels_SetCompareMode1
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
		void Wheels_SetCompareMode1(uint8 comparemode) 
		{
		    #if(0 != Wheels_CTRL_CMPMODE1_SHIFT)
                uint8 comparemodemasked = ((uint8)((uint8)comparemode << Wheels_CTRL_CMPMODE1_SHIFT)) & 
    		                               Wheels_CTRL_CMPMODE1_MASK;
		    #else
                uint8 comparemodemasked = comparemode & Wheels_CTRL_CMPMODE1_MASK;                
            #endif /* (0 != Wheels_CTRL_CMPMODE1_SHIFT) */
                   
		    #if (Wheels_UseControl)
		        Wheels_CONTROL &= ((uint8)(~Wheels_CTRL_CMPMODE1_MASK)); /*Clear existing mode */
		        Wheels_CONTROL |= comparemodemasked;
		    #endif /* (Wheels_UseControl) */
		}
	#endif /* Wheels_CompareMode1SW */

#if (Wheels_CompareMode2SW)


    /*******************************************************************************
    * Function Name: Wheels_SetCompareMode2
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
    void Wheels_SetCompareMode2(uint8 comparemode) 
    {

        #if(0 != Wheels_CTRL_CMPMODE2_SHIFT)
            uint8 comparemodemasked = ((uint8)((uint8)comparemode << Wheels_CTRL_CMPMODE2_SHIFT)) & 
                                                 Wheels_CTRL_CMPMODE2_MASK;
        #else
            uint8 comparemodemasked = comparemode & Wheels_CTRL_CMPMODE2_MASK;            
        #endif /* (0 != Wheels_CTRL_CMPMODE2_SHIFT) */
        
        #if (Wheels_UseControl)
            Wheels_CONTROL &= ((uint8)(~Wheels_CTRL_CMPMODE2_MASK)); /*Clear existing mode */
            Wheels_CONTROL |= comparemodemasked;
        #endif /* (Wheels_UseControl) */
    }
    #endif /*Wheels_CompareMode2SW */

#endif /* UseOneCompareMode */


#if (!Wheels_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: Wheels_WriteCounter
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
    void Wheels_WriteCounter(uint16 counter) \
                                       
    {
        CY_SET_REG16(Wheels_COUNTER_LSB_PTR, counter);
    }


    /*******************************************************************************
    * Function Name: Wheels_ReadCounter
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
    uint16 Wheels_ReadCounter(void) 
    {
        /* Force capture by reading Accumulator */
        /* Must first do a software capture to be able to read the counter */
        /* It is up to the user code to make sure there isn't already captured data in the FIFO */
        (void)Wheels_COUNTERCAP_LSB;
        
        /* Read the data from the FIFO (or capture register for Fixed Function)*/
        return (CY_GET_REG16(Wheels_CAPTURE_LSB_PTR));
    }

        #if (Wheels_UseStatus)


            /*******************************************************************************
            * Function Name: Wheels_ClearFIFO
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
            void Wheels_ClearFIFO(void) 
            {
                while(0u != (Wheels_ReadStatusRegister() & Wheels_STATUS_FIFONEMPTY))
                {
                    (void)Wheels_ReadCapture();
                }
            }

        #endif /* Wheels_UseStatus */

#endif /* !Wheels_UsingFixedFunction */


/*******************************************************************************
* Function Name: Wheels_WritePeriod
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
void Wheels_WritePeriod(uint16 period) 
{
    #if(Wheels_UsingFixedFunction)
        CY_SET_REG16(Wheels_PERIOD_LSB_PTR, (uint16)period);
    #else
        CY_SET_REG16(Wheels_PERIOD_LSB_PTR, period);
    #endif /* (Wheels_UsingFixedFunction) */
}

#if (Wheels_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: Wheels_WriteCompare
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
    void Wheels_WriteCompare(uint16 compare) \
                                       
    {	
		#if(Wheels_UsingFixedFunction)
			CY_SET_REG16(Wheels_COMPARE1_LSB_PTR, (uint16)compare);
		#else
	        CY_SET_REG16(Wheels_COMPARE1_LSB_PTR, compare);	
		#endif /* (Wheels_UsingFixedFunction) */
        
        #if (Wheels_PWMMode == Wheels__B_PWM__DITHER)
            #if(Wheels_UsingFixedFunction)
    			CY_SET_REG16(Wheels_COMPARE2_LSB_PTR, (uint16)(compare + 1u));
    		#else
    	        CY_SET_REG16(Wheels_COMPARE2_LSB_PTR, (compare + 1u));	
    		#endif /* (Wheels_UsingFixedFunction) */
        #endif /* (Wheels_PWMMode == Wheels__B_PWM__DITHER) */
    }


#else


    /*******************************************************************************
    * Function Name: Wheels_WriteCompare1
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
    void Wheels_WriteCompare1(uint16 compare) \
                                        
    {
        #if(Wheels_UsingFixedFunction)
            CY_SET_REG16(Wheels_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(Wheels_COMPARE1_LSB_PTR, compare);
        #endif /* (Wheels_UsingFixedFunction) */
    }


    /*******************************************************************************
    * Function Name: Wheels_WriteCompare2
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
    void Wheels_WriteCompare2(uint16 compare) \
                                        
    {
        #if(Wheels_UsingFixedFunction)
            CY_SET_REG16(Wheels_COMPARE2_LSB_PTR, compare);
        #else
            CY_SET_REG16(Wheels_COMPARE2_LSB_PTR, compare);
        #endif /* (Wheels_UsingFixedFunction) */
    }
#endif /* UseOneCompareMode */

#if (Wheels_DeadBandUsed)


    /*******************************************************************************
    * Function Name: Wheels_WriteDeadTime
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
    void Wheels_WriteDeadTime(uint8 deadtime) 
    {
        /* If using the Dead Band 1-255 mode then just write the register */
        #if(!Wheels_DeadBand2_4)
            CY_SET_REG8(Wheels_DEADBAND_COUNT_PTR, deadtime);
        #else
            /* Otherwise the data has to be masked and offset */        
            /* Clear existing data */
            Wheels_DEADBAND_COUNT &= ((uint8)(~Wheels_DEADBAND_COUNT_MASK));
            
            /* Set new dead time */
            #if(Wheels_DEADBAND_COUNT_SHIFT)        
                Wheels_DEADBAND_COUNT |= ((uint8)((uint8)deadtime << Wheels_DEADBAND_COUNT_SHIFT)) & 
                                                    Wheels_DEADBAND_COUNT_MASK;
            #else
                Wheels_DEADBAND_COUNT |= deadtime & Wheels_DEADBAND_COUNT_MASK;        
            #endif /* (Wheels_DEADBAND_COUNT_SHIFT) */
        
        #endif /* (!Wheels_DeadBand2_4) */
    }


    /*******************************************************************************
    * Function Name: Wheels_ReadDeadTime
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
    uint8 Wheels_ReadDeadTime(void) 
    {
        /* If using the Dead Band 1-255 mode then just read the register */
        #if(!Wheels_DeadBand2_4)
            return (CY_GET_REG8(Wheels_DEADBAND_COUNT_PTR));
        #else
        
            /* Otherwise the data has to be masked and offset */
            #if(Wheels_DEADBAND_COUNT_SHIFT)      
                return ((uint8)(((uint8)(Wheels_DEADBAND_COUNT & Wheels_DEADBAND_COUNT_MASK)) >> 
                                                                           Wheels_DEADBAND_COUNT_SHIFT));
            #else
                return (Wheels_DEADBAND_COUNT & Wheels_DEADBAND_COUNT_MASK);
            #endif /* (Wheels_DEADBAND_COUNT_SHIFT) */
        #endif /* (!Wheels_DeadBand2_4) */
    }
#endif /* DeadBandUsed */

#if (Wheels_UseStatus || Wheels_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: Wheels_SetInterruptMode
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
    void Wheels_SetInterruptMode(uint8 interruptMode)  
    {
    	CY_SET_REG8(Wheels_STATUS_MASK_PTR, interruptMode);
    }


    /*******************************************************************************
    * Function Name: Wheels_ReadStatusRegister
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
    uint8 Wheels_ReadStatusRegister(void)   
    {
    	uint8 result;
    	
    	result = CY_GET_REG8(Wheels_STATUS_PTR);
    	return (result);
    }

#endif /* (Wheels_UseStatus || Wheels_UsingFixedFunction) */


#if (Wheels_UseControl)


    /*******************************************************************************
    * Function Name: Wheels_ReadControlRegister
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
    uint8 Wheels_ReadControlRegister(void) 
    {
    	uint8 result;
    	
    	result = CY_GET_REG8(Wheels_CONTROL_PTR);
    	return (result);
    }


    /*******************************************************************************
    * Function Name: Wheels_WriteControlRegister
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
    void Wheels_WriteControlRegister(uint8 control) 
    {
    	CY_SET_REG8(Wheels_CONTROL_PTR, control);
    }
	
#endif /* (Wheels_UseControl) */


#if (!Wheels_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: Wheels_ReadCapture
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
    uint16 Wheels_ReadCapture(void)  
    {
    	return (CY_GET_REG16(Wheels_CAPTURE_LSB_PTR));
    }
	
#endif /* (!Wheels_UsingFixedFunction) */


#if (Wheels_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: Wheels_ReadCompare
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
    uint16 Wheels_ReadCompare(void)  
    {
		#if(Wheels_UsingFixedFunction)
            return ((uint16)CY_GET_REG16(Wheels_COMPARE1_LSB_PTR));
        #else
            return (CY_GET_REG16(Wheels_COMPARE1_LSB_PTR));
        #endif /* (Wheels_UsingFixedFunction) */
    }

#else


    /*******************************************************************************
    * Function Name: Wheels_ReadCompare1
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
    uint16 Wheels_ReadCompare1(void) 
    {
		return (CY_GET_REG16(Wheels_COMPARE1_LSB_PTR));
    }


    /*******************************************************************************
    * Function Name: Wheels_ReadCompare2
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
    uint16 Wheels_ReadCompare2(void)  
    {
		return (CY_GET_REG16(Wheels_COMPARE2_LSB_PTR));
    }

#endif /* (Wheels_UseOneCompareMode) */


/*******************************************************************************
* Function Name: Wheels_ReadPeriod
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
uint16 Wheels_ReadPeriod(void) 
{
	#if(Wheels_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(Wheels_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(Wheels_PERIOD_LSB_PTR));
    #endif /* (Wheels_UsingFixedFunction) */
}

#if ( Wheels_KillModeMinTime)


    /*******************************************************************************
    * Function Name: Wheels_WriteKillTime
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
    void Wheels_WriteKillTime(uint8 killtime) 
    {
    	CY_SET_REG8(Wheels_KILLMODEMINTIME_PTR, killtime);
    }


    /*******************************************************************************
    * Function Name: Wheels_ReadKillTime
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
    uint8 Wheels_ReadKillTime(void) 
    {
    	return (CY_GET_REG8(Wheels_KILLMODEMINTIME_PTR));
    }

#endif /* ( Wheels_KillModeMinTime) */

/* [] END OF FILE */
