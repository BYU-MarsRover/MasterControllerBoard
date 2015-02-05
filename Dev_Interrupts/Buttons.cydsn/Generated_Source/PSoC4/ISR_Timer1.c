/*******************************************************************************
* File Name: ISR_Timer1.c  
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
#include <ISR_Timer1.h>

#if !defined(ISR_Timer1__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START ISR_Timer1_intc` */
#include "events.h"
#include "Btn0.h"
#include "Btn1.h"
    
#define WRITE_SERVO_DELAY_CNT  25 // every 25 ms we will trigger an interrupt

extern volatile uint8_t debounce_cnt_btn0;
extern volatile uint8_t debounce_cnt_btn1;
extern volatile uint16_t sys_events;
/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: ISR_Timer1_Start
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
void ISR_Timer1_Start(void)
{
    /* For all we know the interrupt is active. */
    ISR_Timer1_Disable();

    /* Set the ISR to point to the ISR_Timer1 Interrupt. */
    ISR_Timer1_SetVector(&ISR_Timer1_Interrupt);

    /* Set the priority. */
    ISR_Timer1_SetPriority((uint8)ISR_Timer1_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ISR_Timer1_Enable();
}


/*******************************************************************************
* Function Name: ISR_Timer1_StartEx
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
void ISR_Timer1_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    ISR_Timer1_Disable();

    /* Set the ISR to point to the ISR_Timer1 Interrupt. */
    ISR_Timer1_SetVector(address);

    /* Set the priority. */
    ISR_Timer1_SetPriority((uint8)ISR_Timer1_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ISR_Timer1_Enable();
}


/*******************************************************************************
* Function Name: ISR_Timer1_Stop
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
void ISR_Timer1_Stop(void)
{
    /* Disable this interrupt. */
    ISR_Timer1_Disable();

    /* Set the ISR to point to the passive one. */
    ISR_Timer1_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: ISR_Timer1_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for ISR_Timer1.
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
CY_ISR(ISR_Timer1_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START ISR_Timer1_Interrupt` */
    // this ISR interrupts every 1 ms (1000times/second)
    static int16_t servoEventDelayCnt = WRITE_SERVO_DELAY_CNT;
    ISR_Timer1_ClearPending();
    uint32_t mask = Timer1_GetInterruptSourceMasked();
    Timer1_ClearInterrupt(mask);
    ISR_Timer1_Disable();
    // debouncing --------------------------------------
    if (debounce_cnt_btn0 && (--debounce_cnt_btn0 == 0))
    {
        sys_events |= BTN0_EVENT; // trigger btn0 event
    }
    if (debounce_cnt_btn1 && (--debounce_cnt_btn1 == 0))
    {
        sys_events |= BTN1_EVENT; // trigger btn1 event
    }
    // servo event timer -------------------------------
    if (--servoEventDelayCnt <= 0) // delay over
    {
        servoEventDelayCnt = WRITE_SERVO_DELAY_CNT; // reset counter
        sys_events |= PWM_MOVE_SERVO_EVENT; // trigger move servo event
    }
    /*if (--SM_TICK_counter2 == 0)
    {
        SM_TICK_counter2 = 100;
        sys_events |= SM_TICK;
    }*/
    ISR_Timer1_Enable();
    /* `#END` */
}


/*******************************************************************************
* Function Name: ISR_Timer1_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling ISR_Timer1_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use ISR_Timer1_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void ISR_Timer1_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + ISR_Timer1__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: ISR_Timer1_GetVector
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
cyisraddress ISR_Timer1_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + ISR_Timer1__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: ISR_Timer1_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling ISR_Timer1_Start
*   or ISR_Timer1_StartEx will override any effect this method would 
*   have had. This method should only be called after ISR_Timer1_Start or 
*   ISR_Timer1_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 3, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void ISR_Timer1_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((ISR_Timer1__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *ISR_Timer1_INTC_PRIOR = (*ISR_Timer1_INTC_PRIOR & (uint32)(~ISR_Timer1__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: ISR_Timer1_GetPriority
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
uint8 ISR_Timer1_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((ISR_Timer1__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*ISR_Timer1_INTC_PRIOR & ISR_Timer1__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: ISR_Timer1_Enable
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
void ISR_Timer1_Enable(void)
{
    /* Enable the general interrupt. */
    *ISR_Timer1_INTC_SET_EN = ISR_Timer1__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_Timer1_GetState
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
uint8 ISR_Timer1_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*ISR_Timer1_INTC_SET_EN & (uint32)ISR_Timer1__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: ISR_Timer1_Disable
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
void ISR_Timer1_Disable(void)
{
    /* Disable the general interrupt. */
    *ISR_Timer1_INTC_CLR_EN = ISR_Timer1__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_Timer1_SetPending
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
void ISR_Timer1_SetPending(void)
{
    *ISR_Timer1_INTC_SET_PD = ISR_Timer1__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_Timer1_ClearPending
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
void ISR_Timer1_ClearPending(void)
{
    *ISR_Timer1_INTC_CLR_PD = ISR_Timer1__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
