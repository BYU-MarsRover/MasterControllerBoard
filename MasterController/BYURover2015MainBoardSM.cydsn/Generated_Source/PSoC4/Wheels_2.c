/*******************************************************************************
* File Name: Wheels_2.c
* Version 1.10
*
* Description:
*  This file provides the source code to the API for the Wheels_2
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

#include "Wheels_2.h"
#include "CyLib.h"

uint8 Wheels_2_initVar = 0u;


/*******************************************************************************
* Function Name: Wheels_2_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default Wheels_2 configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_2_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (Wheels_2__QUAD == Wheels_2_CONFIG)
        Wheels_2_CONTROL_REG =
        (((uint32)(Wheels_2_QUAD_ENCODING_MODES     << Wheels_2_QUAD_MODE_SHIFT))       |
         ((uint32)(Wheels_2_CONFIG                  << Wheels_2_MODE_SHIFT)));
    #endif  /* (Wheels_2__QUAD == Wheels_2_CONFIG) */

    #if (Wheels_2__PWM_SEL == Wheels_2_CONFIG)
        Wheels_2_CONTROL_REG =
        (((uint32)(Wheels_2_PWM_STOP_EVENT          << Wheels_2_PWM_STOP_KILL_SHIFT))    |
         ((uint32)(Wheels_2_PWM_OUT_INVERT          << Wheels_2_INV_OUT_SHIFT))         |
         ((uint32)(Wheels_2_PWM_OUT_N_INVERT        << Wheels_2_INV_COMPL_OUT_SHIFT))     |
         ((uint32)(Wheels_2_PWM_MODE                << Wheels_2_MODE_SHIFT)));

        #if (Wheels_2__PWM_PR == Wheels_2_PWM_MODE)
            Wheels_2_CONTROL_REG |=
            ((uint32)(Wheels_2_PWM_RUN_MODE         << Wheels_2_ONESHOT_SHIFT));

            Wheels_2_WriteCounter(Wheels_2_PWM_PR_INIT_VALUE);
        #else
            Wheels_2_CONTROL_REG |=
            (((uint32)(Wheels_2_PWM_ALIGN           << Wheels_2_UPDOWN_SHIFT))          |
             ((uint32)(Wheels_2_PWM_KILL_EVENT      << Wheels_2_PWM_SYNC_KILL_SHIFT)));
        #endif  /* (Wheels_2__PWM_PR == Wheels_2_PWM_MODE) */

        #if (Wheels_2__PWM_DT == Wheels_2_PWM_MODE)
            Wheels_2_CONTROL_REG |=
            ((uint32)(Wheels_2_PWM_DEAD_TIME_CYCLE  << Wheels_2_PRESCALER_SHIFT));
        #endif  /* (Wheels_2__PWM_DT == Wheels_2_PWM_MODE) */

        #if (Wheels_2__PWM == Wheels_2_PWM_MODE)
            Wheels_2_CONTROL_REG |=
            ((uint32)Wheels_2_PWM_PRESCALER         << Wheels_2_PRESCALER_SHIFT);
        #endif  /* (Wheels_2__PWM == Wheels_2_PWM_MODE) */
    #endif  /* (Wheels_2__PWM_SEL == Wheels_2_CONFIG) */

    #if (Wheels_2__TIMER == Wheels_2_CONFIG)
        Wheels_2_CONTROL_REG =
        (((uint32)(Wheels_2_TC_PRESCALER            << Wheels_2_PRESCALER_SHIFT))   |
         ((uint32)(Wheels_2_TC_COUNTER_MODE         << Wheels_2_UPDOWN_SHIFT))      |
         ((uint32)(Wheels_2_TC_RUN_MODE             << Wheels_2_ONESHOT_SHIFT))     |
         ((uint32)(Wheels_2_TC_COMP_CAP_MODE        << Wheels_2_MODE_SHIFT)));
    #endif  /* (Wheels_2__TIMER == Wheels_2_CONFIG) */

    /* Set values from customizer to CTRL1 */
    #if (Wheels_2__QUAD == Wheels_2_CONFIG)
        Wheels_2_TRIG_CONTROL1_REG  =
        (((uint32)(Wheels_2_QUAD_PHIA_SIGNAL_MODE   << Wheels_2_COUNT_SHIFT))       |
         ((uint32)(Wheels_2_QUAD_INDEX_SIGNAL_MODE  << Wheels_2_RELOAD_SHIFT))      |
         ((uint32)(Wheels_2_QUAD_STOP_SIGNAL_MODE   << Wheels_2_STOP_SHIFT))        |
         ((uint32)(Wheels_2_QUAD_PHIB_SIGNAL_MODE   << Wheels_2_START_SHIFT)));
    #endif  /* (Wheels_2__QUAD == Wheels_2_CONFIG) */

    #if (Wheels_2__PWM_SEL == Wheels_2_CONFIG)
        Wheels_2_TRIG_CONTROL1_REG  =
        (((uint32)(Wheels_2_PWM_SWITCH_SIGNAL_MODE  << Wheels_2_CAPTURE_SHIFT))     |
         ((uint32)(Wheels_2_PWM_COUNT_SIGNAL_MODE   << Wheels_2_COUNT_SHIFT))       |
         ((uint32)(Wheels_2_PWM_RELOAD_SIGNAL_MODE  << Wheels_2_RELOAD_SHIFT))      |
         ((uint32)(Wheels_2_PWM_STOP_SIGNAL_MODE    << Wheels_2_STOP_SHIFT))        |
         ((uint32)(Wheels_2_PWM_START_SIGNAL_MODE   << Wheels_2_START_SHIFT)));
    #endif  /* (Wheels_2__PWM_SEL == Wheels_2_CONFIG) */

    #if (Wheels_2__TIMER == Wheels_2_CONFIG)
        Wheels_2_TRIG_CONTROL1_REG  =
        (((uint32)(Wheels_2_TC_CAPTURE_SIGNAL_MODE  << Wheels_2_CAPTURE_SHIFT))     |
         ((uint32)(Wheels_2_TC_COUNT_SIGNAL_MODE    << Wheels_2_COUNT_SHIFT))       |
         ((uint32)(Wheels_2_TC_RELOAD_SIGNAL_MODE   << Wheels_2_RELOAD_SHIFT))      |
         ((uint32)(Wheels_2_TC_STOP_SIGNAL_MODE     << Wheels_2_STOP_SHIFT))        |
         ((uint32)(Wheels_2_TC_START_SIGNAL_MODE    << Wheels_2_START_SHIFT)));
    #endif  /* (Wheels_2__TIMER == Wheels_2_CONFIG) */

    /* Set values from customizer to INTR */
    #if (Wheels_2__QUAD == Wheels_2_CONFIG)
        Wheels_2_SetInterruptMode(Wheels_2_QUAD_INTERRUPT_MASK);
    #endif  /* (Wheels_2__QUAD == Wheels_2_CONFIG) */

    #if (Wheels_2__PWM_SEL == Wheels_2_CONFIG)
        Wheels_2_SetInterruptMode(Wheels_2_PWM_INTERRUPT_MASK);
    #endif  /* (Wheels_2__PWM_SEL == Wheels_2_CONFIG) */

    #if (Wheels_2__TIMER == Wheels_2_CONFIG)
        Wheels_2_SetInterruptMode(Wheels_2_TC_INTERRUPT_MASK);
    #endif  /* (Wheels_2__TIMER == Wheels_2_CONFIG) */

    /* Set other values from customizer */
    #if (Wheels_2__TIMER == Wheels_2_CONFIG)
        Wheels_2_WritePeriod(Wheels_2_TC_PERIOD_VALUE );

        #if (Wheels_2__COUNT_DOWN == Wheels_2_TC_COUNTER_MODE)
            Wheels_2_WriteCounter(Wheels_2_TC_PERIOD_VALUE );
        #endif  /* (Wheels_2__COUNT_DOWN == Wheels_2_TC_COUNTER_MODE) */

        #if (Wheels_2__COMPARE == Wheels_2_TC_COMP_CAP_MODE)
            Wheels_2_WriteCompare(Wheels_2_TC_COMPARE_VALUE);

            #if (1u == Wheels_2_TC_COMPARE_SWAP)
                Wheels_2_SetCompareSwap(1u);
                Wheels_2_WriteCompareBuf(Wheels_2_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == Wheels_2_TC_COMPARE_SWAP) */
        #endif  /* (Wheels_2__COMPARE == Wheels_2_TC_COMP_CAP_MODE) */
    #endif  /* (Wheels_2__TIMER == Wheels_2_CONFIG) */

    #if (Wheels_2__PWM_SEL == Wheels_2_CONFIG)
        Wheels_2_WritePeriod(Wheels_2_PWM_PERIOD_VALUE );
        Wheels_2_WriteCompare(Wheels_2_PWM_COMPARE_VALUE);

        #if (1u == Wheels_2_PWM_COMPARE_SWAP)
            Wheels_2_SetCompareSwap(1u);
            Wheels_2_WriteCompareBuf(Wheels_2_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == Wheels_2_PWM_COMPARE_SWAP) */

        #if (1u == Wheels_2_PWM_PERIOD_SWAP)
            Wheels_2_SetPeriodSwap(1u);
            Wheels_2_WritePeriodBuf(Wheels_2_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == Wheels_2_PWM_PERIOD_SWAP) */

        /* Set values from customizer to CTRL2 */
        #if (Wheels_2__PWM_PR == Wheels_2_PWM_MODE)
            Wheels_2_TRIG_CONTROL2_REG =
                    (Wheels_2_CC_MATCH_NO_CHANGE    |
                    Wheels_2_OVERLOW_NO_CHANGE      |
                    Wheels_2_UNDERFLOW_NO_CHANGE);
        #else
            #if (Wheels_2__LEFT == Wheels_2_PWM_ALIGN)
                Wheels_2_TRIG_CONTROL2_REG = Wheels_2_PWM_MODE_LEFT;
            #endif  /* ( Wheels_2_PWM_LEFT == Wheels_2_PWM_ALIGN) */

            #if (Wheels_2__RIGHT == Wheels_2_PWM_ALIGN)
                Wheels_2_WriteCounter(Wheels_2_PWM_PERIOD_VALUE);
                Wheels_2_TRIG_CONTROL2_REG = Wheels_2_PWM_MODE_RIGHT;
            #endif  /* ( Wheels_2_PWM_RIGHT == Wheels_2_PWM_ALIGN) */

            #if (Wheels_2__CENTER == Wheels_2_PWM_ALIGN)
                Wheels_2_TRIG_CONTROL2_REG = Wheels_2_PWM_MODE_CENTER;
            #endif  /* ( Wheels_2_PWM_CENTER == Wheels_2_PWM_ALIGN) */

            #if (Wheels_2__ASYMMETRIC == Wheels_2_PWM_ALIGN)
                Wheels_2_TRIG_CONTROL2_REG = Wheels_2_PWM_MODE_ASYM;
            #endif  /* (Wheels_2__ASYMMETRIC == Wheels_2_PWM_ALIGN) */
        #endif  /* (Wheels_2__PWM_PR == Wheels_2_PWM_MODE) */
    #endif  /* (Wheels_2__PWM_SEL == Wheels_2_CONFIG) */
}


/*******************************************************************************
* Function Name: Wheels_2_Enable
********************************************************************************
*
* Summary:
*  Enables the Wheels_2.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_2_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    Wheels_2_BLOCK_CONTROL_REG |= Wheels_2_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (Wheels_2__PWM_SEL == Wheels_2_CONFIG)
        #if (0u == Wheels_2_PWM_START_SIGNAL_PRESENT)
            Wheels_2_TriggerCommand(Wheels_2_MASK, Wheels_2_CMD_START);
        #endif /* (0u == Wheels_2_PWM_START_SIGNAL_PRESENT) */
    #endif /* (Wheels_2__PWM_SEL == Wheels_2_CONFIG) */

    #if (Wheels_2__TIMER == Wheels_2_CONFIG)
        #if (0u == Wheels_2_TC_START_SIGNAL_PRESENT)
            Wheels_2_TriggerCommand(Wheels_2_MASK, Wheels_2_CMD_START);
        #endif /* (0u == Wheels_2_TC_START_SIGNAL_PRESENT) */
    #endif /* (Wheels_2__TIMER == Wheels_2_CONFIG) */
}


/*******************************************************************************
* Function Name: Wheels_2_Start
********************************************************************************
*
* Summary:
*  Initializes the Wheels_2 with default customizer
*  values when called the first time and enables the Wheels_2.
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
*  Wheels_2_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time Wheels_2_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the Wheels_2_Start() routine.
*
*******************************************************************************/
void Wheels_2_Start(void)
{
    if (0u == Wheels_2_initVar)
    {
        Wheels_2_Init();
        Wheels_2_initVar = 1u;
    }

    Wheels_2_Enable();
}


/*******************************************************************************
* Function Name: Wheels_2_Stop
********************************************************************************
*
* Summary:
*  Disables the Wheels_2.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_2_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Wheels_2_BLOCK_CONTROL_REG &= (uint32)~Wheels_2_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Wheels_2_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the Wheels_2. This function is used when
*  configured as a generic Wheels_2 and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the Wheels_2 to operate in
*   Values:
*   - Wheels_2_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - Wheels_2_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - Wheels_2_MODE_QUAD - Quadrature decoder
*         - Wheels_2_MODE_PWM - PWM
*         - Wheels_2_MODE_PWM_DT - PWM with dead time
*         - Wheels_2_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_2_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Wheels_2_CONTROL_REG &= (uint32)~Wheels_2_MODE_MASK;
    Wheels_2_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Wheels_2_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - Wheels_2_MODE_X1 - Counts on phi 1 rising
*         - Wheels_2_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - Wheels_2_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_2_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Wheels_2_CONTROL_REG &= (uint32)~Wheels_2_QUAD_MODE_MASK;
    Wheels_2_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Wheels_2_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - Wheels_2_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - Wheels_2_PRESCALE_DIVBY2    - Divide by 2
*         - Wheels_2_PRESCALE_DIVBY4    - Divide by 4
*         - Wheels_2_PRESCALE_DIVBY8    - Divide by 8
*         - Wheels_2_PRESCALE_DIVBY16   - Divide by 16
*         - Wheels_2_PRESCALE_DIVBY32   - Divide by 32
*         - Wheels_2_PRESCALE_DIVBY64   - Divide by 64
*         - Wheels_2_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_2_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Wheels_2_CONTROL_REG &= (uint32)~Wheels_2_PRESCALER_MASK;
    Wheels_2_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Wheels_2_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the Wheels_2 runs
*  continuously or stops when terminal count is reached.  By default the
*  Wheels_2 operates in the continuous mode.
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
void Wheels_2_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Wheels_2_CONTROL_REG &= (uint32)~Wheels_2_ONESHOT_MASK;
    Wheels_2_CONTROL_REG |= ((uint32)((oneShotEnable & Wheels_2_1BIT_MASK) <<
                                                               Wheels_2_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Wheels_2_SetPWMMode
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
void Wheels_2_SetPWMMode(uint32 modeMask)
{
    Wheels_2_TRIG_CONTROL2_REG = (modeMask & Wheels_2_6BIT_MASK);
}



/*******************************************************************************
* Function Name: Wheels_2_SetPWMSyncKill
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
void Wheels_2_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Wheels_2_CONTROL_REG &= (uint32)~Wheels_2_PWM_SYNC_KILL_MASK;
    Wheels_2_CONTROL_REG |= ((uint32)((syncKillEnable & Wheels_2_1BIT_MASK)  <<
                                               Wheels_2_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Wheels_2_SetPWMStopOnKill
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
void Wheels_2_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Wheels_2_CONTROL_REG &= (uint32)~Wheels_2_PWM_STOP_KILL_MASK;
    Wheels_2_CONTROL_REG |= ((uint32)((stopOnKillEnable & Wheels_2_1BIT_MASK)  <<
                                                         Wheels_2_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Wheels_2_SetPWMDeadTime
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
void Wheels_2_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Wheels_2_CONTROL_REG &= (uint32)~Wheels_2_PRESCALER_MASK;
    Wheels_2_CONTROL_REG |= ((uint32)((deadTime & Wheels_2_8BIT_MASK) <<
                                                          Wheels_2_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Wheels_2_SetPWMInvert
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
*         - Wheels_2_INVERT_LINE   - Inverts the line output
*         - Wheels_2_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_2_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Wheels_2_CONTROL_REG &= (uint32)~Wheels_2_INV_OUT_MASK;
    Wheels_2_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: Wheels_2_WriteCounter
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
void Wheels_2_WriteCounter(uint32 count)
{
    Wheels_2_COUNTER_REG = (count & Wheels_2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Wheels_2_ReadCounter
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
uint32 Wheels_2_ReadCounter(void)
{
    return (Wheels_2_COUNTER_REG & Wheels_2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Wheels_2_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - Wheels_2_COUNT_UP       - Counts up
*     - Wheels_2_COUNT_DOWN     - Counts down
*     - Wheels_2_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - Wheels_2_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_2_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Wheels_2_CONTROL_REG &= (uint32)~Wheels_2_UPDOWN_MASK;
    Wheels_2_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Wheels_2_WritePeriod
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
void Wheels_2_WritePeriod(uint32 period)
{
    Wheels_2_PERIOD_REG = (period & Wheels_2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Wheels_2_ReadPeriod
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
uint32 Wheels_2_ReadPeriod(void)
{
    return (Wheels_2_PERIOD_REG & Wheels_2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Wheels_2_SetCompareSwap
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
void Wheels_2_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Wheels_2_CONTROL_REG &= (uint32)~Wheels_2_RELOAD_CC_MASK;
    Wheels_2_CONTROL_REG |= (swapEnable & Wheels_2_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Wheels_2_WritePeriodBuf
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
void Wheels_2_WritePeriodBuf(uint32 periodBuf)
{
    Wheels_2_PERIOD_BUF_REG = (periodBuf & Wheels_2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Wheels_2_ReadPeriodBuf
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
uint32 Wheels_2_ReadPeriodBuf(void)
{
    return (Wheels_2_PERIOD_BUF_REG & Wheels_2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Wheels_2_SetPeriodSwap
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
void Wheels_2_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Wheels_2_CONTROL_REG &= (uint32)~Wheels_2_RELOAD_PERIOD_MASK;
    Wheels_2_CONTROL_REG |= ((uint32)((swapEnable & Wheels_2_1BIT_MASK) <<
                                                            Wheels_2_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Wheels_2_WriteCompare
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
void Wheels_2_WriteCompare(uint32 compare)
{
    #if (Wheels_2_CY_TCPWM_V2)
        uint32 currentMode;
    #endif /* (Wheels_2_CY_TCPWM_V2) */

    #if (Wheels_2_CY_TCPWM_V2)
        currentMode = ((Wheels_2_CONTROL_REG & Wheels_2_UPDOWN_MASK) >> Wheels_2_UPDOWN_SHIFT);

        if (Wheels_2__COUNT_DOWN == currentMode)
        {
            Wheels_2_COMP_CAP_REG = ((compare + 1u) & Wheels_2_16BIT_MASK);
        }
        else if (Wheels_2__COUNT_UP == currentMode)
        {
            Wheels_2_COMP_CAP_REG = ((compare - 1u) & Wheels_2_16BIT_MASK);
        }
        else
        {
            Wheels_2_COMP_CAP_REG = (compare & Wheels_2_16BIT_MASK);
        }
    #else
        Wheels_2_COMP_CAP_REG = (compare & Wheels_2_16BIT_MASK);
    #endif /* (Wheels_2_CY_TCPWM_V2) */
}


/*******************************************************************************
* Function Name: Wheels_2_ReadCompare
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
uint32 Wheels_2_ReadCompare(void)
{
    #if (Wheels_2_CY_TCPWM_V2)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (Wheels_2_CY_TCPWM_V2) */

    #if (Wheels_2_CY_TCPWM_V2)
        currentMode = ((Wheels_2_CONTROL_REG & Wheels_2_UPDOWN_MASK) >> Wheels_2_UPDOWN_SHIFT);

        if (Wheels_2__COUNT_DOWN == currentMode)
        {
            regVal = ((Wheels_2_COMP_CAP_REG - 1u) & Wheels_2_16BIT_MASK);
        }
        else if (Wheels_2__COUNT_UP == currentMode)
        {
            regVal = ((Wheels_2_COMP_CAP_REG + 1u) & Wheels_2_16BIT_MASK);
        }
        else
        {
            regVal = (Wheels_2_COMP_CAP_REG & Wheels_2_16BIT_MASK);
        }
        return (regVal);
    #else
        return (Wheels_2_COMP_CAP_REG & Wheels_2_16BIT_MASK);
    #endif /* (Wheels_2_CY_TCPWM_V2) */
}


/*******************************************************************************
* Function Name: Wheels_2_WriteCompareBuf
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
void Wheels_2_WriteCompareBuf(uint32 compareBuf)
{
    #if (Wheels_2_CY_TCPWM_V2)
        uint32 currentMode;
    #endif /* (Wheels_2_CY_TCPWM_V2) */

    #if (Wheels_2_CY_TCPWM_V2)
        currentMode = ((Wheels_2_CONTROL_REG & Wheels_2_UPDOWN_MASK) >> Wheels_2_UPDOWN_SHIFT);

        if (Wheels_2__COUNT_DOWN == currentMode)
        {
            Wheels_2_COMP_CAP_BUF_REG = ((compareBuf + 1u) & Wheels_2_16BIT_MASK);
        }
        else if (Wheels_2__COUNT_UP == currentMode)
        {
            Wheels_2_COMP_CAP_BUF_REG = ((compareBuf - 1u) & Wheels_2_16BIT_MASK);
        }
        else
        {
            Wheels_2_COMP_CAP_BUF_REG = (compareBuf & Wheels_2_16BIT_MASK);
        }
    #else
        Wheels_2_COMP_CAP_BUF_REG = (compareBuf & Wheels_2_16BIT_MASK);
    #endif /* (Wheels_2_CY_TCPWM_V2) */
}


/*******************************************************************************
* Function Name: Wheels_2_ReadCompareBuf
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
uint32 Wheels_2_ReadCompareBuf(void)
{
    #if (Wheels_2_CY_TCPWM_V2)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (Wheels_2_CY_TCPWM_V2) */

    #if (Wheels_2_CY_TCPWM_V2)
        currentMode = ((Wheels_2_CONTROL_REG & Wheels_2_UPDOWN_MASK) >> Wheels_2_UPDOWN_SHIFT);

        if (Wheels_2__COUNT_DOWN == currentMode)
        {
            regVal = ((Wheels_2_COMP_CAP_BUF_REG - 1u) & Wheels_2_16BIT_MASK);
        }
        else if (Wheels_2__COUNT_UP == currentMode)
        {
            regVal = ((Wheels_2_COMP_CAP_BUF_REG + 1u) & Wheels_2_16BIT_MASK);
        }
        else
        {
            regVal = (Wheels_2_COMP_CAP_BUF_REG & Wheels_2_16BIT_MASK);
        }
        return (regVal);
    #else
        return (Wheels_2_COMP_CAP_BUF_REG & Wheels_2_16BIT_MASK);
    #endif /* (Wheels_2_CY_TCPWM_V2) */
}


/*******************************************************************************
* Function Name: Wheels_2_ReadCapture
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
uint32 Wheels_2_ReadCapture(void)
{
    return (Wheels_2_COMP_CAP_REG & Wheels_2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Wheels_2_ReadCaptureBuf
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
uint32 Wheels_2_ReadCaptureBuf(void)
{
    return (Wheels_2_COMP_CAP_BUF_REG & Wheels_2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Wheels_2_SetCaptureMode
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
*     - Wheels_2_TRIG_LEVEL     - Level
*     - Wheels_2_TRIG_RISING    - Rising edge
*     - Wheels_2_TRIG_FALLING   - Falling edge
*     - Wheels_2_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_2_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Wheels_2_TRIG_CONTROL1_REG &= (uint32)~Wheels_2_CAPTURE_MASK;
    Wheels_2_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Wheels_2_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - Wheels_2_TRIG_LEVEL     - Level
*     - Wheels_2_TRIG_RISING    - Rising edge
*     - Wheels_2_TRIG_FALLING   - Falling edge
*     - Wheels_2_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_2_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Wheels_2_TRIG_CONTROL1_REG &= (uint32)~Wheels_2_RELOAD_MASK;
    Wheels_2_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << Wheels_2_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Wheels_2_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - Wheels_2_TRIG_LEVEL     - Level
*     - Wheels_2_TRIG_RISING    - Rising edge
*     - Wheels_2_TRIG_FALLING   - Falling edge
*     - Wheels_2_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_2_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Wheels_2_TRIG_CONTROL1_REG &= (uint32)~Wheels_2_START_MASK;
    Wheels_2_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << Wheels_2_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Wheels_2_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - Wheels_2_TRIG_LEVEL     - Level
*     - Wheels_2_TRIG_RISING    - Rising edge
*     - Wheels_2_TRIG_FALLING   - Falling edge
*     - Wheels_2_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_2_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Wheels_2_TRIG_CONTROL1_REG &= (uint32)~Wheels_2_STOP_MASK;
    Wheels_2_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << Wheels_2_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Wheels_2_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - Wheels_2_TRIG_LEVEL     - Level
*     - Wheels_2_TRIG_RISING    - Rising edge
*     - Wheels_2_TRIG_FALLING   - Falling edge
*     - Wheels_2_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_2_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Wheels_2_TRIG_CONTROL1_REG &= (uint32)~Wheels_2_COUNT_MASK;
    Wheels_2_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << Wheels_2_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Wheels_2_TriggerCommand
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
*     - Wheels_2_CMD_CAPTURE    - Trigger Capture command
*     - Wheels_2_CMD_RELOAD     - Trigger Reload command
*     - Wheels_2_CMD_STOP       - Trigger Stop command
*     - Wheels_2_CMD_START      - Trigger Start command
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_2_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Wheels_2_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Wheels_2_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the Wheels_2.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - Wheels_2_STATUS_DOWN    - Set if counting down
*     - Wheels_2_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 Wheels_2_ReadStatus(void)
{
    return ((Wheels_2_STATUS_REG >> Wheels_2_RUNNING_STATUS_SHIFT) |
            (Wheels_2_STATUS_REG & Wheels_2_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: Wheels_2_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - Wheels_2_INTR_MASK_TC       - Terminal count mask
*     - Wheels_2_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_2_SetInterruptMode(uint32 interruptMask)
{
    Wheels_2_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: Wheels_2_GetInterruptSourceMasked
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
*     - Wheels_2_INTR_MASK_TC       - Terminal count mask
*     - Wheels_2_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 Wheels_2_GetInterruptSourceMasked(void)
{
    return (Wheels_2_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: Wheels_2_GetInterruptSource
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
*     - Wheels_2_INTR_MASK_TC       - Terminal count mask
*     - Wheels_2_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 Wheels_2_GetInterruptSource(void)
{
    return (Wheels_2_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: Wheels_2_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - Wheels_2_INTR_MASK_TC       - Terminal count mask
*     - Wheels_2_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_2_ClearInterrupt(uint32 interruptMask)
{
    Wheels_2_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: Wheels_2_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - Wheels_2_INTR_MASK_TC       - Terminal count mask
*     - Wheels_2_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void Wheels_2_SetInterrupt(uint32 interruptMask)
{
    Wheels_2_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
