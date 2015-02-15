/*******************************************************************************
* File Name: Servo_isr.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <Servo_isr.h>

#if !defined(Servo_isr__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START Servo_isr_intc` */

/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: Servo_isr_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void Servo_isr_Start(void)
{
    /* For all we know the interrupt is active. */
    Servo_isr_Disable();

    /* Set the ISR to point to the Servo_isr Interrupt. */
    Servo_isr_SetVector(&Servo_isr_Interrupt);

    /* Set the priority. */
    Servo_isr_SetPriority((uint8)Servo_isr_INTC_PRIOR_NUMBER);

    /* Enable it. */
    Servo_isr_Enable();
}


/*******************************************************************************
* Function Name: Servo_isr_StartEx
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void Servo_isr_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    Servo_isr_Disable();

    /* Set the ISR to point to the Servo_isr Interrupt. */
    Servo_isr_SetVector(address);

    /* Set the priority. */
    Servo_isr_SetPriority((uint8)Servo_isr_INTC_PRIOR_NUMBER);

    /* Enable it. */
    Servo_isr_Enable();
}


/*******************************************************************************
* Function Name: Servo_isr_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
void Servo_isr_Stop(void)
{
    /* Disable this interrupt. */
    Servo_isr_Disable();

    /* Set the ISR to point to the passive one. */
    Servo_isr_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: Servo_isr_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for Servo_isr.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(Servo_isr_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START Servo_isr_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: Servo_isr_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling Servo_isr_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use Servo_isr_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void Servo_isr_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + Servo_isr__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: Servo_isr_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress Servo_isr_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + Servo_isr__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: Servo_isr_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling Servo_isr_Start
*   or Servo_isr_StartEx will override any effect this method would 
*   have had. This method should only be called after Servo_isr_Start or 
*   Servo_isr_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 3, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void Servo_isr_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((Servo_isr__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *Servo_isr_INTC_PRIOR = (*Servo_isr_INTC_PRIOR & (uint32)(~Servo_isr__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Servo_isr_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt. 0 - 3, 0 being the highest.
*
*******************************************************************************/
uint8 Servo_isr_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((Servo_isr__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*Servo_isr_INTC_PRIOR & Servo_isr__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: Servo_isr_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void Servo_isr_Enable(void)
{
    /* Enable the general interrupt. */
    *Servo_isr_INTC_SET_EN = Servo_isr__INTC_MASK;
}


/*******************************************************************************
* Function Name: Servo_isr_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 Servo_isr_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*Servo_isr_INTC_SET_EN & (uint32)Servo_isr__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: Servo_isr_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void Servo_isr_Disable(void)
{
    /* Disable the general interrupt. */
    *Servo_isr_INTC_CLR_EN = Servo_isr__INTC_MASK;
}


/*******************************************************************************
* Function Name: Servo_isr_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void Servo_isr_SetPending(void)
{
    *Servo_isr_INTC_SET_PD = Servo_isr__INTC_MASK;
}


/*******************************************************************************
* Function Name: Servo_isr_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void Servo_isr_ClearPending(void)
{
    *Servo_isr_INTC_CLR_PD = Servo_isr__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
