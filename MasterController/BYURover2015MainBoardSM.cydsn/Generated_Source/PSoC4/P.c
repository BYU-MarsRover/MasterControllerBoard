/*******************************************************************************
* File Name: P.c
* Version 1.10
*
* Description:
*  This file provides the source code to the API for the P
*  component
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "P.h"
#include "CyLib.h"

uint8 P_initVar = 0u;


/*******************************************************************************
* Function Name: P_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default P configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void P_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (P__QUAD == P_CONFIG)
        P_CONTROL_REG =
        (((uint32)(P_QUAD_ENCODING_MODES     << P_QUAD_MODE_SHIFT))       |
         ((uint32)(P_CONFIG                  << P_MODE_SHIFT)));
    #endif  /* (P__QUAD == P_CONFIG) */

    #if (P__PWM_SEL == P_CONFIG)
        P_CONTROL_REG =
        (((uint32)(P_PWM_STOP_EVENT          << P_PWM_STOP_KILL_SHIFT))    |
         ((uint32)(P_PWM_OUT_INVERT          << P_INV_OUT_SHIFT))         |
         ((uint32)(P_PWM_OUT_N_INVERT        << P_INV_COMPL_OUT_SHIFT))     |
         ((uint32)(P_PWM_MODE                << P_MODE_SHIFT)));

        #if (P__PWM_PR == P_PWM_MODE)
            P_CONTROL_REG |=
            ((uint32)(P_PWM_RUN_MODE         << P_ONESHOT_SHIFT));

            P_WriteCounter(P_PWM_PR_INIT_VALUE);
        #else
            P_CONTROL_REG |=
            (((uint32)(P_PWM_ALIGN           << P_UPDOWN_SHIFT))          |
             ((uint32)(P_PWM_KILL_EVENT      << P_PWM_SYNC_KILL_SHIFT)));
        #endif  /* (P__PWM_PR == P_PWM_MODE) */

        #if (P__PWM_DT == P_PWM_MODE)
            P_CONTROL_REG |=
            ((uint32)(P_PWM_DEAD_TIME_CYCLE  << P_PRESCALER_SHIFT));
        #endif  /* (P__PWM_DT == P_PWM_MODE) */

        #if (P__PWM == P_PWM_MODE)
            P_CONTROL_REG |=
            ((uint32)P_PWM_PRESCALER         << P_PRESCALER_SHIFT);
        #endif  /* (P__PWM == P_PWM_MODE) */
    #endif  /* (P__PWM_SEL == P_CONFIG) */

    #if (P__TIMER == P_CONFIG)
        P_CONTROL_REG =
        (((uint32)(P_TC_PRESCALER            << P_PRESCALER_SHIFT))   |
         ((uint32)(P_TC_COUNTER_MODE         << P_UPDOWN_SHIFT))      |
         ((uint32)(P_TC_RUN_MODE             << P_ONESHOT_SHIFT))     |
         ((uint32)(P_TC_COMP_CAP_MODE        << P_MODE_SHIFT)));
    #endif  /* (P__TIMER == P_CONFIG) */

    /* Set values from customizer to CTRL1 */
    #if (P__QUAD == P_CONFIG)
        P_TRIG_CONTROL1_REG  =
        (((uint32)(P_QUAD_PHIA_SIGNAL_MODE   << P_COUNT_SHIFT))       |
         ((uint32)(P_QUAD_INDEX_SIGNAL_MODE  << P_RELOAD_SHIFT))      |
         ((uint32)(P_QUAD_STOP_SIGNAL_MODE   << P_STOP_SHIFT))        |
         ((uint32)(P_QUAD_PHIB_SIGNAL_MODE   << P_START_SHIFT)));
    #endif  /* (P__QUAD == P_CONFIG) */

    #if (P__PWM_SEL == P_CONFIG)
        P_TRIG_CONTROL1_REG  =
        (((uint32)(P_PWM_SWITCH_SIGNAL_MODE  << P_CAPTURE_SHIFT))     |
         ((uint32)(P_PWM_COUNT_SIGNAL_MODE   << P_COUNT_SHIFT))       |
         ((uint32)(P_PWM_RELOAD_SIGNAL_MODE  << P_RELOAD_SHIFT))      |
         ((uint32)(P_PWM_STOP_SIGNAL_MODE    << P_STOP_SHIFT))        |
         ((uint32)(P_PWM_START_SIGNAL_MODE   << P_START_SHIFT)));
    #endif  /* (P__PWM_SEL == P_CONFIG) */

    #if (P__TIMER == P_CONFIG)
        P_TRIG_CONTROL1_REG  =
        (((uint32)(P_TC_CAPTURE_SIGNAL_MODE  << P_CAPTURE_SHIFT))     |
         ((uint32)(P_TC_COUNT_SIGNAL_MODE    << P_COUNT_SHIFT))       |
         ((uint32)(P_TC_RELOAD_SIGNAL_MODE   << P_RELOAD_SHIFT))      |
         ((uint32)(P_TC_STOP_SIGNAL_MODE     << P_STOP_SHIFT))        |
         ((uint32)(P_TC_START_SIGNAL_MODE    << P_START_SHIFT)));
    #endif  /* (P__TIMER == P_CONFIG) */

    /* Set values from customizer to INTR */
    #if (P__QUAD == P_CONFIG)
        P_SetInterruptMode(P_QUAD_INTERRUPT_MASK);
    #endif  /* (P__QUAD == P_CONFIG) */

    #if (P__PWM_SEL == P_CONFIG)
        P_SetInterruptMode(P_PWM_INTERRUPT_MASK);
    #endif  /* (P__PWM_SEL == P_CONFIG) */

    #if (P__TIMER == P_CONFIG)
        P_SetInterruptMode(P_TC_INTERRUPT_MASK);
    #endif  /* (P__TIMER == P_CONFIG) */

    /* Set other values from customizer */
    #if (P__TIMER == P_CONFIG)
        P_WritePeriod(P_TC_PERIOD_VALUE );

        #if (P__COUNT_DOWN == P_TC_COUNTER_MODE)
            P_WriteCounter(P_TC_PERIOD_VALUE );
        #endif  /* (P__COUNT_DOWN == P_TC_COUNTER_MODE) */

        #if (P__COMPARE == P_TC_COMP_CAP_MODE)
            P_WriteCompare(P_TC_COMPARE_VALUE);

            #if (1u == P_TC_COMPARE_SWAP)
                P_SetCompareSwap(1u);
                P_WriteCompareBuf(P_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == P_TC_COMPARE_SWAP) */
        #endif  /* (P__COMPARE == P_TC_COMP_CAP_MODE) */
    #endif  /* (P__TIMER == P_CONFIG) */

    #if (P__PWM_SEL == P_CONFIG)
        P_WritePeriod(P_PWM_PERIOD_VALUE );
        P_WriteCompare(P_PWM_COMPARE_VALUE);

        #if (1u == P_PWM_COMPARE_SWAP)
            P_SetCompareSwap(1u);
            P_WriteCompareBuf(P_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == P_PWM_COMPARE_SWAP) */

        #if (1u == P_PWM_PERIOD_SWAP)
            P_SetPeriodSwap(1u);
            P_WritePeriodBuf(P_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == P_PWM_PERIOD_SWAP) */

        /* Set values from customizer to CTRL2 */
        #if (P__PWM_PR == P_PWM_MODE)
            P_TRIG_CONTROL2_REG =
                    (P_CC_MATCH_NO_CHANGE    |
                    P_OVERLOW_NO_CHANGE      |
                    P_UNDERFLOW_NO_CHANGE);
        #else
            #if (P__LEFT == P_PWM_ALIGN)
                P_TRIG_CONTROL2_REG = P_PWM_MODE_LEFT;
            #endif  /* ( P_PWM_LEFT == P_PWM_ALIGN) */

            #if (P__RIGHT == P_PWM_ALIGN)
                P_WriteCounter(P_PWM_PERIOD_VALUE);
                P_TRIG_CONTROL2_REG = P_PWM_MODE_RIGHT;
            #endif  /* ( P_PWM_RIGHT == P_PWM_ALIGN) */

            #if (P__CENTER == P_PWM_ALIGN)
                P_TRIG_CONTROL2_REG = P_PWM_MODE_CENTER;
            #endif  /* ( P_PWM_CENTER == P_PWM_ALIGN) */

            #if (P__ASYMMETRIC == P_PWM_ALIGN)
                P_TRIG_CONTROL2_REG = P_PWM_MODE_ASYM;
            #endif  /* (P__ASYMMETRIC == P_PWM_ALIGN) */
        #endif  /* (P__PWM_PR == P_PWM_MODE) */
    #endif  /* (P__PWM_SEL == P_CONFIG) */
}


/*******************************************************************************
* Function Name: P_Enable
********************************************************************************
*
* Summary:
*  Enables the P.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void P_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    P_BLOCK_CONTROL_REG |= P_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (P__PWM_SEL == P_CONFIG)
        #if (0u == P_PWM_START_SIGNAL_PRESENT)
            P_TriggerCommand(P_MASK, P_CMD_START);
        #endif /* (0u == P_PWM_START_SIGNAL_PRESENT) */
    #endif /* (P__PWM_SEL == P_CONFIG) */

    #if (P__TIMER == P_CONFIG)
        #if (0u == P_TC_START_SIGNAL_PRESENT)
            P_TriggerCommand(P_MASK, P_CMD_START);
        #endif /* (0u == P_TC_START_SIGNAL_PRESENT) */
    #endif /* (P__TIMER == P_CONFIG) */
}


/*******************************************************************************
* Function Name: P_Start
********************************************************************************
*
* Summary:
*  Initializes the P with default customizer
*  values when called the first time and enables the P.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  P_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time P_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the P_Start() routine.
*
*******************************************************************************/
void P_Start(void)
{
    if (0u == P_initVar)
    {
        P_Init();
        P_initVar = 1u;
    }

    P_Enable();
}


/*******************************************************************************
* Function Name: P_Stop
********************************************************************************
*
* Summary:
*  Disables the P.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void P_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    P_BLOCK_CONTROL_REG &= (uint32)~P_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: P_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the P. This function is used when
*  configured as a generic P and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the P to operate in
*   Values:
*   - P_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - P_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - P_MODE_QUAD - Quadrature decoder
*         - P_MODE_PWM - PWM
*         - P_MODE_PWM_DT - PWM with dead time
*         - P_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void P_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    P_CONTROL_REG &= (uint32)~P_MODE_MASK;
    P_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: P_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - P_MODE_X1 - Counts on phi 1 rising
*         - P_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - P_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void P_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    P_CONTROL_REG &= (uint32)~P_QUAD_MODE_MASK;
    P_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: P_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - P_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - P_PRESCALE_DIVBY2    - Divide by 2
*         - P_PRESCALE_DIVBY4    - Divide by 4
*         - P_PRESCALE_DIVBY8    - Divide by 8
*         - P_PRESCALE_DIVBY16   - Divide by 16
*         - P_PRESCALE_DIVBY32   - Divide by 32
*         - P_PRESCALE_DIVBY64   - Divide by 64
*         - P_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void P_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    P_CONTROL_REG &= (uint32)~P_PRESCALER_MASK;
    P_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: P_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the P runs
*  continuously or stops when terminal count is reached.  By default the
*  P operates in the continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void P_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    P_CONTROL_REG &= (uint32)~P_ONESHOT_MASK;
    P_CONTROL_REG |= ((uint32)((oneShotEnable & P_1BIT_MASK) <<
                                                               P_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: P_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the three must be ORed together to form
*  the mode.
*
* Parameters:
*  modeMask: A combination of three mode settings.  Mask must include a value
*  for each of the three or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on  overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void P_SetPWMMode(uint32 modeMask)
{
    P_TRIG_CONTROL2_REG = (modeMask & P_6BIT_MASK);
}



/*******************************************************************************
* Function Name: P_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to the PWM
*  and PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in the pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void P_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    P_CONTROL_REG &= (uint32)~P_PWM_SYNC_KILL_MASK;
    P_CONTROL_REG |= ((uint32)((syncKillEnable & P_1BIT_MASK)  <<
                                               P_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: P_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void P_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    P_CONTROL_REG &= (uint32)~P_PWM_STOP_KILL_MASK;
    P_CONTROL_REG |= ((uint32)((stopOnKillEnable & P_1BIT_MASK)  <<
                                                         P_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: P_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in the dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void P_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    P_CONTROL_REG &= (uint32)~P_PRESCALER_MASK;
    P_CONTROL_REG |= ((uint32)((deadTime & P_8BIT_MASK) <<
                                                          P_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: P_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - P_INVERT_LINE   - Inverts the line output
*         - P_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void P_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    P_CONTROL_REG &= (uint32)~P_INV_OUT_MASK;
    P_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: P_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void P_WriteCounter(uint32 count)
{
    P_COUNTER_REG = (count & P_16BIT_MASK);
}


/*******************************************************************************
* Function Name: P_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 P_ReadCounter(void)
{
    return (P_COUNTER_REG & P_16BIT_MASK);
}


/*******************************************************************************
* Function Name: P_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - P_COUNT_UP       - Counts up
*     - P_COUNT_DOWN     - Counts down
*     - P_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - P_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void P_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    P_CONTROL_REG &= (uint32)~P_UPDOWN_MASK;
    P_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: P_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void P_WritePeriod(uint32 period)
{
    P_PERIOD_REG = (period & P_16BIT_MASK);
}


/*******************************************************************************
* Function Name: P_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 P_ReadPeriod(void)
{
    return (P_PERIOD_REG & P_16BIT_MASK);
}


/*******************************************************************************
* Function Name: P_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in the Timer/Counter mode(without capture) the swap
*  occurs at a TC event. In the PWM mode the swap occurs at the next TC event
*  following a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void P_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    P_CONTROL_REG &= (uint32)~P_RELOAD_CC_MASK;
    P_CONTROL_REG |= (swapEnable & P_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: P_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void P_WritePeriodBuf(uint32 periodBuf)
{
    P_PERIOD_BUF_REG = (periodBuf & P_16BIT_MASK);
}


/*******************************************************************************
* Function Name: P_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 P_ReadPeriodBuf(void)
{
    return (P_PERIOD_BUF_REG & P_16BIT_MASK);
}


/*******************************************************************************
* Function Name: P_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In the PWM mode the swap occurs at the next TC event following a hardware
*  switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void P_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    P_CONTROL_REG &= (uint32)~P_RELOAD_PERIOD_MASK;
    P_CONTROL_REG |= ((uint32)((swapEnable & P_1BIT_MASK) <<
                                                            P_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: P_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
*******************************************************************************/
void P_WriteCompare(uint32 compare)
{
    #if (P_CY_TCPWM_V2)
        uint32 currentMode;
    #endif /* (P_CY_TCPWM_V2) */

    #if (P_CY_TCPWM_V2)
        currentMode = ((P_CONTROL_REG & P_UPDOWN_MASK) >> P_UPDOWN_SHIFT);

        if (P__COUNT_DOWN == currentMode)
        {
            P_COMP_CAP_REG = ((compare + 1u) & P_16BIT_MASK);
        }
        else if (P__COUNT_UP == currentMode)
        {
            P_COMP_CAP_REG = ((compare - 1u) & P_16BIT_MASK);
        }
        else
        {
            P_COMP_CAP_REG = (compare & P_16BIT_MASK);
        }
    #else
        P_COMP_CAP_REG = (compare & P_16BIT_MASK);
    #endif /* (P_CY_TCPWM_V2) */
}


/*******************************************************************************
* Function Name: P_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
*******************************************************************************/
uint32 P_ReadCompare(void)
{
    #if (P_CY_TCPWM_V2)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (P_CY_TCPWM_V2) */

    #if (P_CY_TCPWM_V2)
        currentMode = ((P_CONTROL_REG & P_UPDOWN_MASK) >> P_UPDOWN_SHIFT);

        if (P__COUNT_DOWN == currentMode)
        {
            regVal = ((P_COMP_CAP_REG - 1u) & P_16BIT_MASK);
        }
        else if (P__COUNT_UP == currentMode)
        {
            regVal = ((P_COMP_CAP_REG + 1u) & P_16BIT_MASK);
        }
        else
        {
            regVal = (P_COMP_CAP_REG & P_16BIT_MASK);
        }
        return (regVal);
    #else
        return (P_COMP_CAP_REG & P_16BIT_MASK);
    #endif /* (P_CY_TCPWM_V2) */
}


/*******************************************************************************
* Function Name: P_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
*******************************************************************************/
void P_WriteCompareBuf(uint32 compareBuf)
{
    #if (P_CY_TCPWM_V2)
        uint32 currentMode;
    #endif /* (P_CY_TCPWM_V2) */

    #if (P_CY_TCPWM_V2)
        currentMode = ((P_CONTROL_REG & P_UPDOWN_MASK) >> P_UPDOWN_SHIFT);

        if (P__COUNT_DOWN == currentMode)
        {
            P_COMP_CAP_BUF_REG = ((compareBuf + 1u) & P_16BIT_MASK);
        }
        else if (P__COUNT_UP == currentMode)
        {
            P_COMP_CAP_BUF_REG = ((compareBuf - 1u) & P_16BIT_MASK);
        }
        else
        {
            P_COMP_CAP_BUF_REG = (compareBuf & P_16BIT_MASK);
        }
    #else
        P_COMP_CAP_BUF_REG = (compareBuf & P_16BIT_MASK);
    #endif /* (P_CY_TCPWM_V2) */
}


/*******************************************************************************
* Function Name: P_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
*******************************************************************************/
uint32 P_ReadCompareBuf(void)
{
    #if (P_CY_TCPWM_V2)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (P_CY_TCPWM_V2) */

    #if (P_CY_TCPWM_V2)
        currentMode = ((P_CONTROL_REG & P_UPDOWN_MASK) >> P_UPDOWN_SHIFT);

        if (P__COUNT_DOWN == currentMode)
        {
            regVal = ((P_COMP_CAP_BUF_REG - 1u) & P_16BIT_MASK);
        }
        else if (P__COUNT_UP == currentMode)
        {
            regVal = ((P_COMP_CAP_BUF_REG + 1u) & P_16BIT_MASK);
        }
        else
        {
            regVal = (P_COMP_CAP_BUF_REG & P_16BIT_MASK);
        }
        return (regVal);
    #else
        return (P_COMP_CAP_BUF_REG & P_16BIT_MASK);
    #endif /* (P_CY_TCPWM_V2) */
}


/*******************************************************************************
* Function Name: P_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 P_ReadCapture(void)
{
    return (P_COMP_CAP_REG & P_16BIT_MASK);
}


/*******************************************************************************
* Function Name: P_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 P_ReadCaptureBuf(void)
{
    return (P_COMP_CAP_BUF_REG & P_16BIT_MASK);
}


/*******************************************************************************
* Function Name: P_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - P_TRIG_LEVEL     - Level
*     - P_TRIG_RISING    - Rising edge
*     - P_TRIG_FALLING   - Falling edge
*     - P_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void P_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    P_TRIG_CONTROL1_REG &= (uint32)~P_CAPTURE_MASK;
    P_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: P_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - P_TRIG_LEVEL     - Level
*     - P_TRIG_RISING    - Rising edge
*     - P_TRIG_FALLING   - Falling edge
*     - P_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void P_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    P_TRIG_CONTROL1_REG &= (uint32)~P_RELOAD_MASK;
    P_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << P_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: P_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - P_TRIG_LEVEL     - Level
*     - P_TRIG_RISING    - Rising edge
*     - P_TRIG_FALLING   - Falling edge
*     - P_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void P_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    P_TRIG_CONTROL1_REG &= (uint32)~P_START_MASK;
    P_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << P_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: P_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - P_TRIG_LEVEL     - Level
*     - P_TRIG_RISING    - Rising edge
*     - P_TRIG_FALLING   - Falling edge
*     - P_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void P_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    P_TRIG_CONTROL1_REG &= (uint32)~P_STOP_MASK;
    P_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << P_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: P_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - P_TRIG_LEVEL     - Level
*     - P_TRIG_RISING    - Rising edge
*     - P_TRIG_FALLING   - Falling edge
*     - P_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void P_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    P_TRIG_CONTROL1_REG &= (uint32)~P_COUNT_MASK;
    P_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << P_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: P_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: A combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - P_CMD_CAPTURE    - Trigger Capture command
*     - P_CMD_RELOAD     - Trigger Reload command
*     - P_CMD_STOP       - Trigger Stop command
*     - P_CMD_START      - Trigger Start command
*
* Return:
*  None
*
*******************************************************************************/
void P_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    P_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: P_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the P.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - P_STATUS_DOWN    - Set if counting down
*     - P_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 P_ReadStatus(void)
{
    return ((P_STATUS_REG >> P_RUNNING_STATUS_SHIFT) |
            (P_STATUS_REG & P_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: P_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - P_INTR_MASK_TC       - Terminal count mask
*     - P_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void P_SetInterruptMode(uint32 interruptMask)
{
    P_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: P_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - P_INTR_MASK_TC       - Terminal count mask
*     - P_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 P_GetInterruptSourceMasked(void)
{
    return (P_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: P_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - P_INTR_MASK_TC       - Terminal count mask
*     - P_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 P_GetInterruptSource(void)
{
    return (P_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: P_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - P_INTR_MASK_TC       - Terminal count mask
*     - P_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void P_ClearInterrupt(uint32 interruptMask)
{
    P_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: P_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - P_INTR_MASK_TC       - Terminal count mask
*     - P_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void P_SetInterrupt(uint32 interruptMask)
{
    P_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
