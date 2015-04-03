/*******************************************************************************
* File Name: ISRSPI.c  
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
#include <ISRSPI.h>

#if !defined(ISRSPI__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START ISRSPI_intc` */

/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: ISRSPI_Start
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
void ISRSPI_Start(void)
{
    /* For all we know the interrupt is active. */
    ISRSPI_Disable();

    /* Set the ISR to point to the ISRSPI Interrupt. */
    ISRSPI_SetVector(&ISRSPI_Interrupt);

    /* Set the priority. */
    ISRSPI_SetPriority((uint8)ISRSPI_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ISRSPI_Enable();
}


/*******************************************************************************
* Function Name: ISRSPI_StartEx
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
void ISRSPI_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    ISRSPI_Disable();

    /* Set the ISR to point to the ISRSPI Interrupt. */
    ISRSPI_SetVector(address);

    /* Set the priority. */
    ISRSPI_SetPriority((uint8)ISRSPI_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ISRSPI_Enable();
}


/*******************************************************************************
* Function Name: ISRSPI_Stop
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
void ISRSPI_Stop(void)
{
    /* Disable this interrupt. */
    ISRSPI_Disable();

    /* Set the ISR to point to the passive one. */
    ISRSPI_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: ISRSPI_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for ISRSPI.
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
CY_ISR(ISRSPI_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START ISRSPI_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: ISRSPI_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling ISRSPI_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use ISRSPI_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void ISRSPI_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + ISRSPI__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: ISRSPI_GetVector
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
cyisraddress ISRSPI_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + ISRSPI__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: ISRSPI_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling ISRSPI_Start
*   or ISRSPI_StartEx will override any effect this method would 
*   have had. This method should only be called after ISRSPI_Start or 
*   ISRSPI_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 3, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void ISRSPI_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((ISRSPI__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *ISRSPI_INTC_PRIOR = (*ISRSPI_INTC_PRIOR & (uint32)(~ISRSPI__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: ISRSPI_GetPriority
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
uint8 ISRSPI_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((ISRSPI__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*ISRSPI_INTC_PRIOR & ISRSPI__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: ISRSPI_Enable
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
void ISRSPI_Enable(void)
{
    /* Enable the general interrupt. */
    *ISRSPI_INTC_SET_EN = ISRSPI__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISRSPI_GetState
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
uint8 ISRSPI_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*ISRSPI_INTC_SET_EN & (uint32)ISRSPI__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: ISRSPI_Disable
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
void ISRSPI_Disable(void)
{
    /* Disable the general interrupt. */
    *ISRSPI_INTC_CLR_EN = ISRSPI__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISRSPI_SetPending
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
void ISRSPI_SetPending(void)
{
    *ISRSPI_INTC_SET_PD = ISRSPI__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISRSPI_ClearPending
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
void ISRSPI_ClearPending(void)
{
    *ISRSPI_INTC_CLR_PD = ISRSPI__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
