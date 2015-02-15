/*******************************************************************************
* File Name: ISR_UART_1.c  
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
#include <ISR_UART_1.h>

#if !defined(ISR_UART_1__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START ISR_UART_1_intc` */

/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: ISR_UART_1_Start
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
void ISR_UART_1_Start(void)
{
    /* For all we know the interrupt is active. */
    ISR_UART_1_Disable();

    /* Set the ISR to point to the ISR_UART_1 Interrupt. */
    ISR_UART_1_SetVector(&ISR_UART_1_Interrupt);

    /* Set the priority. */
    ISR_UART_1_SetPriority((uint8)ISR_UART_1_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ISR_UART_1_Enable();
}


/*******************************************************************************
* Function Name: ISR_UART_1_StartEx
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
void ISR_UART_1_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    ISR_UART_1_Disable();

    /* Set the ISR to point to the ISR_UART_1 Interrupt. */
    ISR_UART_1_SetVector(address);

    /* Set the priority. */
    ISR_UART_1_SetPriority((uint8)ISR_UART_1_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ISR_UART_1_Enable();
}


/*******************************************************************************
* Function Name: ISR_UART_1_Stop
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
void ISR_UART_1_Stop(void)
{
    /* Disable this interrupt. */
    ISR_UART_1_Disable();

    /* Set the ISR to point to the passive one. */
    ISR_UART_1_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: ISR_UART_1_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for ISR_UART_1.
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
CY_ISR(ISR_UART_1_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START ISR_UART_1_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: ISR_UART_1_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling ISR_UART_1_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use ISR_UART_1_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void ISR_UART_1_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + ISR_UART_1__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: ISR_UART_1_GetVector
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
cyisraddress ISR_UART_1_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + ISR_UART_1__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: ISR_UART_1_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling ISR_UART_1_Start
*   or ISR_UART_1_StartEx will override any effect this method would 
*   have had. This method should only be called after ISR_UART_1_Start or 
*   ISR_UART_1_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 3, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void ISR_UART_1_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((ISR_UART_1__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *ISR_UART_1_INTC_PRIOR = (*ISR_UART_1_INTC_PRIOR & (uint32)(~ISR_UART_1__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: ISR_UART_1_GetPriority
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
uint8 ISR_UART_1_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((ISR_UART_1__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*ISR_UART_1_INTC_PRIOR & ISR_UART_1__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: ISR_UART_1_Enable
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
void ISR_UART_1_Enable(void)
{
    /* Enable the general interrupt. */
    *ISR_UART_1_INTC_SET_EN = ISR_UART_1__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_UART_1_GetState
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
uint8 ISR_UART_1_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*ISR_UART_1_INTC_SET_EN & (uint32)ISR_UART_1__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: ISR_UART_1_Disable
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
void ISR_UART_1_Disable(void)
{
    /* Disable the general interrupt. */
    *ISR_UART_1_INTC_CLR_EN = ISR_UART_1__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_UART_1_SetPending
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
void ISR_UART_1_SetPending(void)
{
    *ISR_UART_1_INTC_SET_PD = ISR_UART_1__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_UART_1_ClearPending
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
void ISR_UART_1_ClearPending(void)
{
    *ISR_UART_1_INTC_CLR_PD = ISR_UART_1__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
