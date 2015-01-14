/*******************************************************************************
* File Name: ISR_Btn0.c  
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
#include <ISR_Btn0.h>

#if !defined(ISR_Btn0__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START ISR_Btn0_intc` */
#include "LED.h"
#include "Btn0.h"
#define DEBOUNCE    10 // 10 ms debounce time

volatile uint8_t debounce_cnt_btn0;

/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: ISR_Btn0_Start
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
void ISR_Btn0_Start(void)
{
    /* For all we know the interrupt is active. */
    ISR_Btn0_Disable();

    /* Set the ISR to point to the ISR_Btn0 Interrupt. */
    ISR_Btn0_SetVector(&ISR_Btn0_Interrupt);

    /* Set the priority. */
    ISR_Btn0_SetPriority((uint8)ISR_Btn0_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ISR_Btn0_Enable();
}


/*******************************************************************************
* Function Name: ISR_Btn0_StartEx
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
void ISR_Btn0_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    ISR_Btn0_Disable();

    /* Set the ISR to point to the ISR_Btn0 Interrupt. */
    ISR_Btn0_SetVector(address);

    /* Set the priority. */
    ISR_Btn0_SetPriority((uint8)ISR_Btn0_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ISR_Btn0_Enable();
}


/*******************************************************************************
* Function Name: ISR_Btn0_Stop
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
void ISR_Btn0_Stop(void)
{
    /* Disable this interrupt. */
    ISR_Btn0_Disable();

    /* Set the ISR to point to the passive one. */
    ISR_Btn0_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: ISR_Btn0_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for ISR_Btn0.
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
CY_ISR(ISR_Btn0_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START ISR_Btn0_Interrupt` */
    ISR_Btn0_ClearPending();
    Btn0_ClearInterrupt();
    debounce_cnt_btn0 = DEBOUNCE; // start debouncing
    /* `#END` */
}


/*******************************************************************************
* Function Name: ISR_Btn0_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling ISR_Btn0_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use ISR_Btn0_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void ISR_Btn0_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + ISR_Btn0__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: ISR_Btn0_GetVector
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
cyisraddress ISR_Btn0_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + ISR_Btn0__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: ISR_Btn0_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling ISR_Btn0_Start
*   or ISR_Btn0_StartEx will override any effect this method would 
*   have had. This method should only be called after ISR_Btn0_Start or 
*   ISR_Btn0_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 3, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void ISR_Btn0_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((ISR_Btn0__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *ISR_Btn0_INTC_PRIOR = (*ISR_Btn0_INTC_PRIOR & (uint32)(~ISR_Btn0__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: ISR_Btn0_GetPriority
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
uint8 ISR_Btn0_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((ISR_Btn0__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*ISR_Btn0_INTC_PRIOR & ISR_Btn0__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: ISR_Btn0_Enable
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
void ISR_Btn0_Enable(void)
{
    /* Enable the general interrupt. */
    *ISR_Btn0_INTC_SET_EN = ISR_Btn0__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_Btn0_GetState
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
uint8 ISR_Btn0_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*ISR_Btn0_INTC_SET_EN & (uint32)ISR_Btn0__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: ISR_Btn0_Disable
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
void ISR_Btn0_Disable(void)
{
    /* Disable the general interrupt. */
    *ISR_Btn0_INTC_CLR_EN = ISR_Btn0__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_Btn0_SetPending
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
void ISR_Btn0_SetPending(void)
{
    *ISR_Btn0_INTC_SET_PD = ISR_Btn0__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_Btn0_ClearPending
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
void ISR_Btn0_ClearPending(void)
{
    *ISR_Btn0_INTC_CLR_PD = ISR_Btn0__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
