/*******************************************************************************
* File Name: SignalGenerator.c
* Version 1.10
*
* Description:
*  This file provides the source code to the API for the SignalGenerator
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

#include "SignalGenerator.h"
#include "CyLib.h"

uint8 SignalGenerator_initVar = 0u;


/*******************************************************************************
* Function Name: SignalGenerator_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default SignalGenerator configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SignalGenerator_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (SignalGenerator__QUAD == SignalGenerator_CONFIG)
        SignalGenerator_CONTROL_REG =
        (((uint32)(SignalGenerator_QUAD_ENCODING_MODES     << SignalGenerator_QUAD_MODE_SHIFT))       |
         ((uint32)(SignalGenerator_CONFIG                  << SignalGenerator_MODE_SHIFT)));
    #endif  /* (SignalGenerator__QUAD == SignalGenerator_CONFIG) */

    #if (SignalGenerator__PWM_SEL == SignalGenerator_CONFIG)
        SignalGenerator_CONTROL_REG =
        (((uint32)(SignalGenerator_PWM_STOP_EVENT          << SignalGenerator_PWM_STOP_KILL_SHIFT))    |
         ((uint32)(SignalGenerator_PWM_OUT_INVERT          << SignalGenerator_INV_OUT_SHIFT))         |
         ((uint32)(SignalGenerator_PWM_OUT_N_INVERT        << SignalGenerator_INV_COMPL_OUT_SHIFT))     |
         ((uint32)(SignalGenerator_PWM_MODE                << SignalGenerator_MODE_SHIFT)));

        #if (SignalGenerator__PWM_PR == SignalGenerator_PWM_MODE)
            SignalGenerator_CONTROL_REG |=
            ((uint32)(SignalGenerator_PWM_RUN_MODE         << SignalGenerator_ONESHOT_SHIFT));

            SignalGenerator_WriteCounter(SignalGenerator_PWM_PR_INIT_VALUE);
        #else
            SignalGenerator_CONTROL_REG |=
            (((uint32)(SignalGenerator_PWM_ALIGN           << SignalGenerator_UPDOWN_SHIFT))          |
             ((uint32)(SignalGenerator_PWM_KILL_EVENT      << SignalGenerator_PWM_SYNC_KILL_SHIFT)));
        #endif  /* (SignalGenerator__PWM_PR == SignalGenerator_PWM_MODE) */

        #if (SignalGenerator__PWM_DT == SignalGenerator_PWM_MODE)
            SignalGenerator_CONTROL_REG |=
            ((uint32)(SignalGenerator_PWM_DEAD_TIME_CYCLE  << SignalGenerator_PRESCALER_SHIFT));
        #endif  /* (SignalGenerator__PWM_DT == SignalGenerator_PWM_MODE) */

        #if (SignalGenerator__PWM == SignalGenerator_PWM_MODE)
            SignalGenerator_CONTROL_REG |=
            ((uint32)SignalGenerator_PWM_PRESCALER         << SignalGenerator_PRESCALER_SHIFT);
        #endif  /* (SignalGenerator__PWM == SignalGenerator_PWM_MODE) */
    #endif  /* (SignalGenerator__PWM_SEL == SignalGenerator_CONFIG) */

    #if (SignalGenerator__TIMER == SignalGenerator_CONFIG)
        SignalGenerator_CONTROL_REG =
        (((uint32)(SignalGenerator_TC_PRESCALER            << SignalGenerator_PRESCALER_SHIFT))   |
         ((uint32)(SignalGenerator_TC_COUNTER_MODE         << SignalGenerator_UPDOWN_SHIFT))      |
         ((uint32)(SignalGenerator_TC_RUN_MODE             << SignalGenerator_ONESHOT_SHIFT))     |
         ((uint32)(SignalGenerator_TC_COMP_CAP_MODE        << SignalGenerator_MODE_SHIFT)));
    #endif  /* (SignalGenerator__TIMER == SignalGenerator_CONFIG) */

    /* Set values from customizer to CTRL1 */
    #if (SignalGenerator__QUAD == SignalGenerator_CONFIG)
        SignalGenerator_TRIG_CONTROL1_REG  =
        (((uint32)(SignalGenerator_QUAD_PHIA_SIGNAL_MODE   << SignalGenerator_COUNT_SHIFT))       |
         ((uint32)(SignalGenerator_QUAD_INDEX_SIGNAL_MODE  << SignalGenerator_RELOAD_SHIFT))      |
         ((uint32)(SignalGenerator_QUAD_STOP_SIGNAL_MODE   << SignalGenerator_STOP_SHIFT))        |
         ((uint32)(SignalGenerator_QUAD_PHIB_SIGNAL_MODE   << SignalGenerator_START_SHIFT)));
    #endif  /* (SignalGenerator__QUAD == SignalGenerator_CONFIG) */

    #if (SignalGenerator__PWM_SEL == SignalGenerator_CONFIG)
        SignalGenerator_TRIG_CONTROL1_REG  =
        (((uint32)(SignalGenerator_PWM_SWITCH_SIGNAL_MODE  << SignalGenerator_CAPTURE_SHIFT))     |
         ((uint32)(SignalGenerator_PWM_COUNT_SIGNAL_MODE   << SignalGenerator_COUNT_SHIFT))       |
         ((uint32)(SignalGenerator_PWM_RELOAD_SIGNAL_MODE  << SignalGenerator_RELOAD_SHIFT))      |
         ((uint32)(SignalGenerator_PWM_STOP_SIGNAL_MODE    << SignalGenerator_STOP_SHIFT))        |
         ((uint32)(SignalGenerator_PWM_START_SIGNAL_MODE   << SignalGenerator_START_SHIFT)));
    #endif  /* (SignalGenerator__PWM_SEL == SignalGenerator_CONFIG) */

    #if (SignalGenerator__TIMER == SignalGenerator_CONFIG)
        SignalGenerator_TRIG_CONTROL1_REG  =
        (((uint32)(SignalGenerator_TC_CAPTURE_SIGNAL_MODE  << SignalGenerator_CAPTURE_SHIFT))     |
         ((uint32)(SignalGenerator_TC_COUNT_SIGNAL_MODE    << SignalGenerator_COUNT_SHIFT))       |
         ((uint32)(SignalGenerator_TC_RELOAD_SIGNAL_MODE   << SignalGenerator_RELOAD_SHIFT))      |
         ((uint32)(SignalGenerator_TC_STOP_SIGNAL_MODE     << SignalGenerator_STOP_SHIFT))        |
         ((uint32)(SignalGenerator_TC_START_SIGNAL_MODE    << SignalGenerator_START_SHIFT)));
    #endif  /* (SignalGenerator__TIMER == SignalGenerator_CONFIG) */

    /* Set values from customizer to INTR */
    #if (SignalGenerator__QUAD == SignalGenerator_CONFIG)
        SignalGenerator_SetInterruptMode(SignalGenerator_QUAD_INTERRUPT_MASK);
    #endif  /* (SignalGenerator__QUAD == SignalGenerator_CONFIG) */

    #if (SignalGenerator__PWM_SEL == SignalGenerator_CONFIG)
        SignalGenerator_SetInterruptMode(SignalGenerator_PWM_INTERRUPT_MASK);
    #endif  /* (SignalGenerator__PWM_SEL == SignalGenerator_CONFIG) */

    #if (SignalGenerator__TIMER == SignalGenerator_CONFIG)
        SignalGenerator_SetInterruptMode(SignalGenerator_TC_INTERRUPT_MASK);
    #endif  /* (SignalGenerator__TIMER == SignalGenerator_CONFIG) */

    /* Set other values from customizer */
    #if (SignalGenerator__TIMER == SignalGenerator_CONFIG)
        SignalGenerator_WritePeriod(SignalGenerator_TC_PERIOD_VALUE );

        #if (SignalGenerator__COUNT_DOWN == SignalGenerator_TC_COUNTER_MODE)
            SignalGenerator_WriteCounter(SignalGenerator_TC_PERIOD_VALUE );
        #endif  /* (SignalGenerator__COUNT_DOWN == SignalGenerator_TC_COUNTER_MODE) */

        #if (SignalGenerator__COMPARE == SignalGenerator_TC_COMP_CAP_MODE)
            SignalGenerator_WriteCompare(SignalGenerator_TC_COMPARE_VALUE);

            #if (1u == SignalGenerator_TC_COMPARE_SWAP)
                SignalGenerator_SetCompareSwap(1u);
                SignalGenerator_WriteCompareBuf(SignalGenerator_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == SignalGenerator_TC_COMPARE_SWAP) */
        #endif  /* (SignalGenerator__COMPARE == SignalGenerator_TC_COMP_CAP_MODE) */
    #endif  /* (SignalGenerator__TIMER == SignalGenerator_CONFIG) */

    #if (SignalGenerator__PWM_SEL == SignalGenerator_CONFIG)
        SignalGenerator_WritePeriod(SignalGenerator_PWM_PERIOD_VALUE );
        SignalGenerator_WriteCompare(SignalGenerator_PWM_COMPARE_VALUE);

        #if (1u == SignalGenerator_PWM_COMPARE_SWAP)
            SignalGenerator_SetCompareSwap(1u);
            SignalGenerator_WriteCompareBuf(SignalGenerator_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == SignalGenerator_PWM_COMPARE_SWAP) */

        #if (1u == SignalGenerator_PWM_PERIOD_SWAP)
            SignalGenerator_SetPeriodSwap(1u);
            SignalGenerator_WritePeriodBuf(SignalGenerator_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == SignalGenerator_PWM_PERIOD_SWAP) */

        /* Set values from customizer to CTRL2 */
        #if (SignalGenerator__PWM_PR == SignalGenerator_PWM_MODE)
            SignalGenerator_TRIG_CONTROL2_REG =
                    (SignalGenerator_CC_MATCH_NO_CHANGE    |
                    SignalGenerator_OVERLOW_NO_CHANGE      |
                    SignalGenerator_UNDERFLOW_NO_CHANGE);
        #else
            #if (SignalGenerator__LEFT == SignalGenerator_PWM_ALIGN)
                SignalGenerator_TRIG_CONTROL2_REG = SignalGenerator_PWM_MODE_LEFT;
            #endif  /* ( SignalGenerator_PWM_LEFT == SignalGenerator_PWM_ALIGN) */

            #if (SignalGenerator__RIGHT == SignalGenerator_PWM_ALIGN)
                SignalGenerator_WriteCounter(SignalGenerator_PWM_PERIOD_VALUE);
                SignalGenerator_TRIG_CONTROL2_REG = SignalGenerator_PWM_MODE_RIGHT;
            #endif  /* ( SignalGenerator_PWM_RIGHT == SignalGenerator_PWM_ALIGN) */

            #if (SignalGenerator__CENTER == SignalGenerator_PWM_ALIGN)
                SignalGenerator_TRIG_CONTROL2_REG = SignalGenerator_PWM_MODE_CENTER;
            #endif  /* ( SignalGenerator_PWM_CENTER == SignalGenerator_PWM_ALIGN) */

            #if (SignalGenerator__ASYMMETRIC == SignalGenerator_PWM_ALIGN)
                SignalGenerator_TRIG_CONTROL2_REG = SignalGenerator_PWM_MODE_ASYM;
            #endif  /* (SignalGenerator__ASYMMETRIC == SignalGenerator_PWM_ALIGN) */
        #endif  /* (SignalGenerator__PWM_PR == SignalGenerator_PWM_MODE) */
    #endif  /* (SignalGenerator__PWM_SEL == SignalGenerator_CONFIG) */
}


/*******************************************************************************
* Function Name: SignalGenerator_Enable
********************************************************************************
*
* Summary:
*  Enables the SignalGenerator.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SignalGenerator_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    SignalGenerator_BLOCK_CONTROL_REG |= SignalGenerator_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (SignalGenerator__PWM_SEL == SignalGenerator_CONFIG)
        #if (0u == SignalGenerator_PWM_START_SIGNAL_PRESENT)
            SignalGenerator_TriggerCommand(SignalGenerator_MASK, SignalGenerator_CMD_START);
        #endif /* (0u == SignalGenerator_PWM_START_SIGNAL_PRESENT) */
    #endif /* (SignalGenerator__PWM_SEL == SignalGenerator_CONFIG) */

    #if (SignalGenerator__TIMER == SignalGenerator_CONFIG)
        #if (0u == SignalGenerator_TC_START_SIGNAL_PRESENT)
            SignalGenerator_TriggerCommand(SignalGenerator_MASK, SignalGenerator_CMD_START);
        #endif /* (0u == SignalGenerator_TC_START_SIGNAL_PRESENT) */
    #endif /* (SignalGenerator__TIMER == SignalGenerator_CONFIG) */
}


/*******************************************************************************
* Function Name: SignalGenerator_Start
********************************************************************************
*
* Summary:
*  Initializes the SignalGenerator with default customizer
*  values when called the first time and enables the SignalGenerator.
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
*  SignalGenerator_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time SignalGenerator_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the SignalGenerator_Start() routine.
*
*******************************************************************************/
void SignalGenerator_Start(void)
{
    if (0u == SignalGenerator_initVar)
    {
        SignalGenerator_Init();
        SignalGenerator_initVar = 1u;
    }

    SignalGenerator_Enable();
}


/*******************************************************************************
* Function Name: SignalGenerator_Stop
********************************************************************************
*
* Summary:
*  Disables the SignalGenerator.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SignalGenerator_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    SignalGenerator_BLOCK_CONTROL_REG &= (uint32)~SignalGenerator_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: SignalGenerator_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the SignalGenerator. This function is used when
*  configured as a generic SignalGenerator and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the SignalGenerator to operate in
*   Values:
*   - SignalGenerator_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - SignalGenerator_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - SignalGenerator_MODE_QUAD - Quadrature decoder
*         - SignalGenerator_MODE_PWM - PWM
*         - SignalGenerator_MODE_PWM_DT - PWM with dead time
*         - SignalGenerator_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void SignalGenerator_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    SignalGenerator_CONTROL_REG &= (uint32)~SignalGenerator_MODE_MASK;
    SignalGenerator_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: SignalGenerator_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - SignalGenerator_MODE_X1 - Counts on phi 1 rising
*         - SignalGenerator_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - SignalGenerator_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void SignalGenerator_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    SignalGenerator_CONTROL_REG &= (uint32)~SignalGenerator_QUAD_MODE_MASK;
    SignalGenerator_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: SignalGenerator_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - SignalGenerator_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - SignalGenerator_PRESCALE_DIVBY2    - Divide by 2
*         - SignalGenerator_PRESCALE_DIVBY4    - Divide by 4
*         - SignalGenerator_PRESCALE_DIVBY8    - Divide by 8
*         - SignalGenerator_PRESCALE_DIVBY16   - Divide by 16
*         - SignalGenerator_PRESCALE_DIVBY32   - Divide by 32
*         - SignalGenerator_PRESCALE_DIVBY64   - Divide by 64
*         - SignalGenerator_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void SignalGenerator_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    SignalGenerator_CONTROL_REG &= (uint32)~SignalGenerator_PRESCALER_MASK;
    SignalGenerator_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: SignalGenerator_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the SignalGenerator runs
*  continuously or stops when terminal count is reached.  By default the
*  SignalGenerator operates in the continuous mode.
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
void SignalGenerator_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    SignalGenerator_CONTROL_REG &= (uint32)~SignalGenerator_ONESHOT_MASK;
    SignalGenerator_CONTROL_REG |= ((uint32)((oneShotEnable & SignalGenerator_1BIT_MASK) <<
                                                               SignalGenerator_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: SignalGenerator_SetPWMMode
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
void SignalGenerator_SetPWMMode(uint32 modeMask)
{
    SignalGenerator_TRIG_CONTROL2_REG = (modeMask & SignalGenerator_6BIT_MASK);
}



/*******************************************************************************
* Function Name: SignalGenerator_SetPWMSyncKill
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
void SignalGenerator_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    SignalGenerator_CONTROL_REG &= (uint32)~SignalGenerator_PWM_SYNC_KILL_MASK;
    SignalGenerator_CONTROL_REG |= ((uint32)((syncKillEnable & SignalGenerator_1BIT_MASK)  <<
                                               SignalGenerator_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: SignalGenerator_SetPWMStopOnKill
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
void SignalGenerator_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    SignalGenerator_CONTROL_REG &= (uint32)~SignalGenerator_PWM_STOP_KILL_MASK;
    SignalGenerator_CONTROL_REG |= ((uint32)((stopOnKillEnable & SignalGenerator_1BIT_MASK)  <<
                                                         SignalGenerator_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: SignalGenerator_SetPWMDeadTime
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
void SignalGenerator_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    SignalGenerator_CONTROL_REG &= (uint32)~SignalGenerator_PRESCALER_MASK;
    SignalGenerator_CONTROL_REG |= ((uint32)((deadTime & SignalGenerator_8BIT_MASK) <<
                                                          SignalGenerator_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: SignalGenerator_SetPWMInvert
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
*         - SignalGenerator_INVERT_LINE   - Inverts the line output
*         - SignalGenerator_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void SignalGenerator_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    SignalGenerator_CONTROL_REG &= (uint32)~SignalGenerator_INV_OUT_MASK;
    SignalGenerator_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: SignalGenerator_WriteCounter
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
void SignalGenerator_WriteCounter(uint32 count)
{
    SignalGenerator_COUNTER_REG = (count & SignalGenerator_16BIT_MASK);
}


/*******************************************************************************
* Function Name: SignalGenerator_ReadCounter
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
uint32 SignalGenerator_ReadCounter(void)
{
    return (SignalGenerator_COUNTER_REG & SignalGenerator_16BIT_MASK);
}


/*******************************************************************************
* Function Name: SignalGenerator_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - SignalGenerator_COUNT_UP       - Counts up
*     - SignalGenerator_COUNT_DOWN     - Counts down
*     - SignalGenerator_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - SignalGenerator_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void SignalGenerator_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    SignalGenerator_CONTROL_REG &= (uint32)~SignalGenerator_UPDOWN_MASK;
    SignalGenerator_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: SignalGenerator_WritePeriod
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
void SignalGenerator_WritePeriod(uint32 period)
{
    SignalGenerator_PERIOD_REG = (period & SignalGenerator_16BIT_MASK);
}


/*******************************************************************************
* Function Name: SignalGenerator_ReadPeriod
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
uint32 SignalGenerator_ReadPeriod(void)
{
    return (SignalGenerator_PERIOD_REG & SignalGenerator_16BIT_MASK);
}


/*******************************************************************************
* Function Name: SignalGenerator_SetCompareSwap
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
void SignalGenerator_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    SignalGenerator_CONTROL_REG &= (uint32)~SignalGenerator_RELOAD_CC_MASK;
    SignalGenerator_CONTROL_REG |= (swapEnable & SignalGenerator_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: SignalGenerator_WritePeriodBuf
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
void SignalGenerator_WritePeriodBuf(uint32 periodBuf)
{
    SignalGenerator_PERIOD_BUF_REG = (periodBuf & SignalGenerator_16BIT_MASK);
}


/*******************************************************************************
* Function Name: SignalGenerator_ReadPeriodBuf
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
uint32 SignalGenerator_ReadPeriodBuf(void)
{
    return (SignalGenerator_PERIOD_BUF_REG & SignalGenerator_16BIT_MASK);
}


/*******************************************************************************
* Function Name: SignalGenerator_SetPeriodSwap
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
void SignalGenerator_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    SignalGenerator_CONTROL_REG &= (uint32)~SignalGenerator_RELOAD_PERIOD_MASK;
    SignalGenerator_CONTROL_REG |= ((uint32)((swapEnable & SignalGenerator_1BIT_MASK) <<
                                                            SignalGenerator_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: SignalGenerator_WriteCompare
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
void SignalGenerator_WriteCompare(uint32 compare)
{
    #if (SignalGenerator_CY_TCPWM_V2)
        uint32 currentMode;
    #endif /* (SignalGenerator_CY_TCPWM_V2) */

    #if (SignalGenerator_CY_TCPWM_V2)
        currentMode = ((SignalGenerator_CONTROL_REG & SignalGenerator_UPDOWN_MASK) >> SignalGenerator_UPDOWN_SHIFT);

        if (SignalGenerator__COUNT_DOWN == currentMode)
        {
            SignalGenerator_COMP_CAP_REG = ((compare + 1u) & SignalGenerator_16BIT_MASK);
        }
        else if (SignalGenerator__COUNT_UP == currentMode)
        {
            SignalGenerator_COMP_CAP_REG = ((compare - 1u) & SignalGenerator_16BIT_MASK);
        }
        else
        {
            SignalGenerator_COMP_CAP_REG = (compare & SignalGenerator_16BIT_MASK);
        }
    #else
        SignalGenerator_COMP_CAP_REG = (compare & SignalGenerator_16BIT_MASK);
    #endif /* (SignalGenerator_CY_TCPWM_V2) */
}


/*******************************************************************************
* Function Name: SignalGenerator_ReadCompare
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
uint32 SignalGenerator_ReadCompare(void)
{
    #if (SignalGenerator_CY_TCPWM_V2)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (SignalGenerator_CY_TCPWM_V2) */

    #if (SignalGenerator_CY_TCPWM_V2)
        currentMode = ((SignalGenerator_CONTROL_REG & SignalGenerator_UPDOWN_MASK) >> SignalGenerator_UPDOWN_SHIFT);

        if (SignalGenerator__COUNT_DOWN == currentMode)
        {
            regVal = ((SignalGenerator_COMP_CAP_REG - 1u) & SignalGenerator_16BIT_MASK);
        }
        else if (SignalGenerator__COUNT_UP == currentMode)
        {
            regVal = ((SignalGenerator_COMP_CAP_REG + 1u) & SignalGenerator_16BIT_MASK);
        }
        else
        {
            regVal = (SignalGenerator_COMP_CAP_REG & SignalGenerator_16BIT_MASK);
        }
        return (regVal);
    #else
        return (SignalGenerator_COMP_CAP_REG & SignalGenerator_16BIT_MASK);
    #endif /* (SignalGenerator_CY_TCPWM_V2) */
}


/*******************************************************************************
* Function Name: SignalGenerator_WriteCompareBuf
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
void SignalGenerator_WriteCompareBuf(uint32 compareBuf)
{
    #if (SignalGenerator_CY_TCPWM_V2)
        uint32 currentMode;
    #endif /* (SignalGenerator_CY_TCPWM_V2) */

    #if (SignalGenerator_CY_TCPWM_V2)
        currentMode = ((SignalGenerator_CONTROL_REG & SignalGenerator_UPDOWN_MASK) >> SignalGenerator_UPDOWN_SHIFT);

        if (SignalGenerator__COUNT_DOWN == currentMode)
        {
            SignalGenerator_COMP_CAP_BUF_REG = ((compareBuf + 1u) & SignalGenerator_16BIT_MASK);
        }
        else if (SignalGenerator__COUNT_UP == currentMode)
        {
            SignalGenerator_COMP_CAP_BUF_REG = ((compareBuf - 1u) & SignalGenerator_16BIT_MASK);
        }
        else
        {
            SignalGenerator_COMP_CAP_BUF_REG = (compareBuf & SignalGenerator_16BIT_MASK);
        }
    #else
        SignalGenerator_COMP_CAP_BUF_REG = (compareBuf & SignalGenerator_16BIT_MASK);
    #endif /* (SignalGenerator_CY_TCPWM_V2) */
}


/*******************************************************************************
* Function Name: SignalGenerator_ReadCompareBuf
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
uint32 SignalGenerator_ReadCompareBuf(void)
{
    #if (SignalGenerator_CY_TCPWM_V2)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (SignalGenerator_CY_TCPWM_V2) */

    #if (SignalGenerator_CY_TCPWM_V2)
        currentMode = ((SignalGenerator_CONTROL_REG & SignalGenerator_UPDOWN_MASK) >> SignalGenerator_UPDOWN_SHIFT);

        if (SignalGenerator__COUNT_DOWN == currentMode)
        {
            regVal = ((SignalGenerator_COMP_CAP_BUF_REG - 1u) & SignalGenerator_16BIT_MASK);
        }
        else if (SignalGenerator__COUNT_UP == currentMode)
        {
            regVal = ((SignalGenerator_COMP_CAP_BUF_REG + 1u) & SignalGenerator_16BIT_MASK);
        }
        else
        {
            regVal = (SignalGenerator_COMP_CAP_BUF_REG & SignalGenerator_16BIT_MASK);
        }
        return (regVal);
    #else
        return (SignalGenerator_COMP_CAP_BUF_REG & SignalGenerator_16BIT_MASK);
    #endif /* (SignalGenerator_CY_TCPWM_V2) */
}


/*******************************************************************************
* Function Name: SignalGenerator_ReadCapture
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
uint32 SignalGenerator_ReadCapture(void)
{
    return (SignalGenerator_COMP_CAP_REG & SignalGenerator_16BIT_MASK);
}


/*******************************************************************************
* Function Name: SignalGenerator_ReadCaptureBuf
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
uint32 SignalGenerator_ReadCaptureBuf(void)
{
    return (SignalGenerator_COMP_CAP_BUF_REG & SignalGenerator_16BIT_MASK);
}


/*******************************************************************************
* Function Name: SignalGenerator_SetCaptureMode
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
*     - SignalGenerator_TRIG_LEVEL     - Level
*     - SignalGenerator_TRIG_RISING    - Rising edge
*     - SignalGenerator_TRIG_FALLING   - Falling edge
*     - SignalGenerator_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void SignalGenerator_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    SignalGenerator_TRIG_CONTROL1_REG &= (uint32)~SignalGenerator_CAPTURE_MASK;
    SignalGenerator_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: SignalGenerator_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - SignalGenerator_TRIG_LEVEL     - Level
*     - SignalGenerator_TRIG_RISING    - Rising edge
*     - SignalGenerator_TRIG_FALLING   - Falling edge
*     - SignalGenerator_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void SignalGenerator_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    SignalGenerator_TRIG_CONTROL1_REG &= (uint32)~SignalGenerator_RELOAD_MASK;
    SignalGenerator_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << SignalGenerator_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: SignalGenerator_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - SignalGenerator_TRIG_LEVEL     - Level
*     - SignalGenerator_TRIG_RISING    - Rising edge
*     - SignalGenerator_TRIG_FALLING   - Falling edge
*     - SignalGenerator_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void SignalGenerator_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    SignalGenerator_TRIG_CONTROL1_REG &= (uint32)~SignalGenerator_START_MASK;
    SignalGenerator_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << SignalGenerator_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: SignalGenerator_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - SignalGenerator_TRIG_LEVEL     - Level
*     - SignalGenerator_TRIG_RISING    - Rising edge
*     - SignalGenerator_TRIG_FALLING   - Falling edge
*     - SignalGenerator_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void SignalGenerator_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    SignalGenerator_TRIG_CONTROL1_REG &= (uint32)~SignalGenerator_STOP_MASK;
    SignalGenerator_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << SignalGenerator_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: SignalGenerator_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - SignalGenerator_TRIG_LEVEL     - Level
*     - SignalGenerator_TRIG_RISING    - Rising edge
*     - SignalGenerator_TRIG_FALLING   - Falling edge
*     - SignalGenerator_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void SignalGenerator_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    SignalGenerator_TRIG_CONTROL1_REG &= (uint32)~SignalGenerator_COUNT_MASK;
    SignalGenerator_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << SignalGenerator_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: SignalGenerator_TriggerCommand
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
*     - SignalGenerator_CMD_CAPTURE    - Trigger Capture command
*     - SignalGenerator_CMD_RELOAD     - Trigger Reload command
*     - SignalGenerator_CMD_STOP       - Trigger Stop command
*     - SignalGenerator_CMD_START      - Trigger Start command
*
* Return:
*  None
*
*******************************************************************************/
void SignalGenerator_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    SignalGenerator_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: SignalGenerator_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the SignalGenerator.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - SignalGenerator_STATUS_DOWN    - Set if counting down
*     - SignalGenerator_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 SignalGenerator_ReadStatus(void)
{
    return ((SignalGenerator_STATUS_REG >> SignalGenerator_RUNNING_STATUS_SHIFT) |
            (SignalGenerator_STATUS_REG & SignalGenerator_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: SignalGenerator_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - SignalGenerator_INTR_MASK_TC       - Terminal count mask
*     - SignalGenerator_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void SignalGenerator_SetInterruptMode(uint32 interruptMask)
{
    SignalGenerator_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: SignalGenerator_GetInterruptSourceMasked
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
*     - SignalGenerator_INTR_MASK_TC       - Terminal count mask
*     - SignalGenerator_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 SignalGenerator_GetInterruptSourceMasked(void)
{
    return (SignalGenerator_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: SignalGenerator_GetInterruptSource
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
*     - SignalGenerator_INTR_MASK_TC       - Terminal count mask
*     - SignalGenerator_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 SignalGenerator_GetInterruptSource(void)
{
    return (SignalGenerator_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: SignalGenerator_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - SignalGenerator_INTR_MASK_TC       - Terminal count mask
*     - SignalGenerator_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void SignalGenerator_ClearInterrupt(uint32 interruptMask)
{
    SignalGenerator_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: SignalGenerator_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - SignalGenerator_INTR_MASK_TC       - Terminal count mask
*     - SignalGenerator_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void SignalGenerator_SetInterrupt(uint32 interruptMask)
{
    SignalGenerator_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
