/*******************************************************************************
* File Name: ISRUART.c  
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
#include <ISRUART.h>

#if !defined(ISRUART__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START ISRUART_intc` */

/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: ISRUART_Start
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
void ISRUART_Start(void)
{
    /* For all we know the interrupt is active. */
    ISRUART_Disable();

    /* Set the ISR to point to the ISRUART Interrupt. */
    ISRUART_SetVector(&ISRUART_Interrupt);

    /* Set the priority. */
    ISRUART_SetPriority((uint8)ISRUART_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ISRUART_Enable();
}


/*******************************************************************************
* Function Name: ISRUART_StartEx
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
void ISRUART_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    ISRUART_Disable();

    /* Set the ISR to point to the ISRUART Interrupt. */
    ISRUART_SetVector(address);

    /* Set the priority. */
    ISRUART_SetPriority((uint8)ISRUART_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ISRUART_Enable();
}


/*******************************************************************************
* Function Name: ISRUART_Stop
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
void ISRUART_Stop(void)
{
    /* Disable this interrupt. */
    ISRUART_Disable();

    /* Set the ISR to point to the passive one. */
    ISRUART_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: ISRUART_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for ISRUART.
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
CY_ISR(ISRUART_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START ISRUART_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: ISRUART_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling ISRUART_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use ISRUART_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void ISRUART_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + ISRUART__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: ISRUART_GetVector
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
cyisraddress ISRUART_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + ISRUART__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: ISRUART_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling ISRUART_Start
*   or ISRUART_StartEx will override any effect this method would 
*   have had. This method should only be called after ISRUART_Start or 
*   ISRUART_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 3, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void ISRUART_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((ISRUART__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *ISRUART_INTC_PRIOR = (*ISRUART_INTC_PRIOR & (uint32)(~ISRUART__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: ISRUART_GetPriority
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
uint8 ISRUART_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((ISRUART__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*ISRUART_INTC_PRIOR & ISRUART__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: ISRUART_Enable
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
void ISRUART_Enable(void)
{
    /* Enable the general interrupt. */
    *ISRUART_INTC_SET_EN = ISRUART__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISRUART_GetState
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
uint8 ISRUART_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*ISRUART_INTC_SET_EN & (uint32)ISRUART__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: ISRUART_Disable
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
void ISRUART_Disable(void)
{
    /* Disable the general interrupt. */
    *ISRUART_INTC_CLR_EN = ISRUART__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISRUART_SetPending
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
void ISRUART_SetPending(void)
{
    *ISRUART_INTC_SET_PD = ISRUART__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISRUART_ClearPending
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
void ISRUART_ClearPending(void)
{
    *ISRUART_INTC_CLR_PD = ISRUART__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
