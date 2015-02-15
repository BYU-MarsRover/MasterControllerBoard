/*******************************************************************************
* File Name: SignalGenerator.h
* Version 1.10
*
* Description:
*  This file provides constants and parameter values for the SignalGenerator
*  component.
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

#if !defined(CY_TCPWM_SignalGenerator_H)
#define CY_TCPWM_SignalGenerator_H

#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} SignalGenerator_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  SignalGenerator_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define SignalGenerator_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)

/* TCPWM Configuration */
#define SignalGenerator_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define SignalGenerator_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define SignalGenerator_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define SignalGenerator_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define SignalGenerator_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define SignalGenerator_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define SignalGenerator_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define SignalGenerator_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define SignalGenerator_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define SignalGenerator_TC_RUN_MODE                    (0lu)
#define SignalGenerator_TC_COUNTER_MODE                (0lu)
#define SignalGenerator_TC_COMP_CAP_MODE               (0lu)
#define SignalGenerator_TC_PRESCALER                   (0lu)

/* Signal modes */
#define SignalGenerator_TC_RELOAD_SIGNAL_MODE          (0lu)
#define SignalGenerator_TC_COUNT_SIGNAL_MODE           (3lu)
#define SignalGenerator_TC_START_SIGNAL_MODE           (0lu)
#define SignalGenerator_TC_STOP_SIGNAL_MODE            (0lu)
#define SignalGenerator_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define SignalGenerator_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define SignalGenerator_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define SignalGenerator_TC_START_SIGNAL_PRESENT        (0lu)
#define SignalGenerator_TC_STOP_SIGNAL_PRESENT         (0lu)
#define SignalGenerator_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define SignalGenerator_TC_INTERRUPT_MASK              (2lu)

/* PWM Mode */
/* Parameters */
#define SignalGenerator_PWM_KILL_EVENT                 (0lu)
#define SignalGenerator_PWM_STOP_EVENT                 (0lu)
#define SignalGenerator_PWM_MODE                       (4lu)
#define SignalGenerator_PWM_OUT_N_INVERT               (0lu)
#define SignalGenerator_PWM_OUT_INVERT                 (0lu)
#define SignalGenerator_PWM_ALIGN                      (0lu)
#define SignalGenerator_PWM_RUN_MODE                   (0lu)
#define SignalGenerator_PWM_DEAD_TIME_CYCLE            (0lu)
#define SignalGenerator_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define SignalGenerator_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define SignalGenerator_PWM_COUNT_SIGNAL_MODE          (3lu)
#define SignalGenerator_PWM_START_SIGNAL_MODE          (0lu)
#define SignalGenerator_PWM_STOP_SIGNAL_MODE           (0lu)
#define SignalGenerator_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define SignalGenerator_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define SignalGenerator_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define SignalGenerator_PWM_START_SIGNAL_PRESENT       (0lu)
#define SignalGenerator_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define SignalGenerator_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define SignalGenerator_PWM_INTERRUPT_MASK             (2lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define SignalGenerator_TC_PERIOD_VALUE                (20000lu)
#define SignalGenerator_TC_COMPARE_VALUE               (1500lu)
#define SignalGenerator_TC_COMPARE_BUF_VALUE           (65535lu)
#define SignalGenerator_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define SignalGenerator_PWM_PERIOD_VALUE               (20000lu)
#define SignalGenerator_PWM_PERIOD_BUF_VALUE           (65535lu)
#define SignalGenerator_PWM_PERIOD_SWAP                (0lu)
#define SignalGenerator_PWM_COMPARE_VALUE              (1000lu)
#define SignalGenerator_PWM_COMPARE_BUF_VALUE          (65535lu)
#define SignalGenerator_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define SignalGenerator__LEFT 0
#define SignalGenerator__RIGHT 1
#define SignalGenerator__CENTER 2
#define SignalGenerator__ASYMMETRIC 3

#define SignalGenerator__X1 0
#define SignalGenerator__X2 1
#define SignalGenerator__X4 2

#define SignalGenerator__PWM 4
#define SignalGenerator__PWM_DT 5
#define SignalGenerator__PWM_PR 6

#define SignalGenerator__INVERSE 1
#define SignalGenerator__DIRECT 0

#define SignalGenerator__CAPTURE 2
#define SignalGenerator__COMPARE 0

#define SignalGenerator__TRIG_LEVEL 3
#define SignalGenerator__TRIG_RISING 0
#define SignalGenerator__TRIG_FALLING 1
#define SignalGenerator__TRIG_BOTH 2

#define SignalGenerator__INTR_MASK_TC 1
#define SignalGenerator__INTR_MASK_CC_MATCH 2
#define SignalGenerator__INTR_MASK_NONE 0
#define SignalGenerator__INTR_MASK_TC_CC 3

#define SignalGenerator__UNCONFIG 8
#define SignalGenerator__TIMER 1
#define SignalGenerator__QUAD 3
#define SignalGenerator__PWM_SEL 7

#define SignalGenerator__COUNT_UP 0
#define SignalGenerator__COUNT_DOWN 1
#define SignalGenerator__COUNT_UPDOWN0 2
#define SignalGenerator__COUNT_UPDOWN1 3


/* Prescaler */
#define SignalGenerator_PRESCALE_DIVBY1                ((uint32)(0u << SignalGenerator_PRESCALER_SHIFT))
#define SignalGenerator_PRESCALE_DIVBY2                ((uint32)(1u << SignalGenerator_PRESCALER_SHIFT))
#define SignalGenerator_PRESCALE_DIVBY4                ((uint32)(2u << SignalGenerator_PRESCALER_SHIFT))
#define SignalGenerator_PRESCALE_DIVBY8                ((uint32)(3u << SignalGenerator_PRESCALER_SHIFT))
#define SignalGenerator_PRESCALE_DIVBY16               ((uint32)(4u << SignalGenerator_PRESCALER_SHIFT))
#define SignalGenerator_PRESCALE_DIVBY32               ((uint32)(5u << SignalGenerator_PRESCALER_SHIFT))
#define SignalGenerator_PRESCALE_DIVBY64               ((uint32)(6u << SignalGenerator_PRESCALER_SHIFT))
#define SignalGenerator_PRESCALE_DIVBY128              ((uint32)(7u << SignalGenerator_PRESCALER_SHIFT))

/* TCPWM set modes */
#define SignalGenerator_MODE_TIMER_COMPARE             ((uint32)(SignalGenerator__COMPARE         <<  \
                                                                  SignalGenerator_MODE_SHIFT))
#define SignalGenerator_MODE_TIMER_CAPTURE             ((uint32)(SignalGenerator__CAPTURE         <<  \
                                                                  SignalGenerator_MODE_SHIFT))
#define SignalGenerator_MODE_QUAD                      ((uint32)(SignalGenerator__QUAD            <<  \
                                                                  SignalGenerator_MODE_SHIFT))
#define SignalGenerator_MODE_PWM                       ((uint32)(SignalGenerator__PWM             <<  \
                                                                  SignalGenerator_MODE_SHIFT))
#define SignalGenerator_MODE_PWM_DT                    ((uint32)(SignalGenerator__PWM_DT          <<  \
                                                                  SignalGenerator_MODE_SHIFT))
#define SignalGenerator_MODE_PWM_PR                    ((uint32)(SignalGenerator__PWM_PR          <<  \
                                                                  SignalGenerator_MODE_SHIFT))

/* Quad Modes */
#define SignalGenerator_MODE_X1                        ((uint32)(SignalGenerator__X1              <<  \
                                                                  SignalGenerator_QUAD_MODE_SHIFT))
#define SignalGenerator_MODE_X2                        ((uint32)(SignalGenerator__X2              <<  \
                                                                  SignalGenerator_QUAD_MODE_SHIFT))
#define SignalGenerator_MODE_X4                        ((uint32)(SignalGenerator__X4              <<  \
                                                                  SignalGenerator_QUAD_MODE_SHIFT))

/* Counter modes */
#define SignalGenerator_COUNT_UP                       ((uint32)(SignalGenerator__COUNT_UP        <<  \
                                                                  SignalGenerator_UPDOWN_SHIFT))
#define SignalGenerator_COUNT_DOWN                     ((uint32)(SignalGenerator__COUNT_DOWN      <<  \
                                                                  SignalGenerator_UPDOWN_SHIFT))
#define SignalGenerator_COUNT_UPDOWN0                  ((uint32)(SignalGenerator__COUNT_UPDOWN0   <<  \
                                                                  SignalGenerator_UPDOWN_SHIFT))
#define SignalGenerator_COUNT_UPDOWN1                  ((uint32)(SignalGenerator__COUNT_UPDOWN1   <<  \
                                                                  SignalGenerator_UPDOWN_SHIFT))

/* PWM output invert */
#define SignalGenerator_INVERT_LINE                    ((uint32)(SignalGenerator__INVERSE         <<  \
                                                                  SignalGenerator_INV_OUT_SHIFT))
#define SignalGenerator_INVERT_LINE_N                  ((uint32)(SignalGenerator__INVERSE         <<  \
                                                                  SignalGenerator_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define SignalGenerator_TRIG_RISING                    ((uint32)SignalGenerator__TRIG_RISING)
#define SignalGenerator_TRIG_FALLING                   ((uint32)SignalGenerator__TRIG_FALLING)
#define SignalGenerator_TRIG_BOTH                      ((uint32)SignalGenerator__TRIG_BOTH)
#define SignalGenerator_TRIG_LEVEL                     ((uint32)SignalGenerator__TRIG_LEVEL)

/* Interrupt mask */
#define SignalGenerator_INTR_MASK_TC                   ((uint32)SignalGenerator__INTR_MASK_TC)
#define SignalGenerator_INTR_MASK_CC_MATCH             ((uint32)SignalGenerator__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define SignalGenerator_CC_MATCH_SET                   (0x00u)
#define SignalGenerator_CC_MATCH_CLEAR                 (0x01u)
#define SignalGenerator_CC_MATCH_INVERT                (0x02u)
#define SignalGenerator_CC_MATCH_NO_CHANGE             (0x03u)
#define SignalGenerator_OVERLOW_SET                    (0x00u)
#define SignalGenerator_OVERLOW_CLEAR                  (0x04u)
#define SignalGenerator_OVERLOW_INVERT                 (0x08u)
#define SignalGenerator_OVERLOW_NO_CHANGE              (0x0Cu)
#define SignalGenerator_UNDERFLOW_SET                  (0x00u)
#define SignalGenerator_UNDERFLOW_CLEAR                (0x10u)
#define SignalGenerator_UNDERFLOW_INVERT               (0x20u)
#define SignalGenerator_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define SignalGenerator_PWM_MODE_LEFT                  (SignalGenerator_CC_MATCH_CLEAR        |   \
                                                         SignalGenerator_OVERLOW_SET           |   \
                                                         SignalGenerator_UNDERFLOW_NO_CHANGE)
#define SignalGenerator_PWM_MODE_RIGHT                 (SignalGenerator_CC_MATCH_SET          |   \
                                                         SignalGenerator_OVERLOW_NO_CHANGE     |   \
                                                         SignalGenerator_UNDERFLOW_CLEAR)
#define SignalGenerator_PWM_MODE_CENTER                (SignalGenerator_CC_MATCH_INVERT       |   \
                                                         SignalGenerator_OVERLOW_NO_CHANGE     |   \
                                                         SignalGenerator_UNDERFLOW_CLEAR)
#define SignalGenerator_PWM_MODE_ASYM                  (SignalGenerator_CC_MATCH_NO_CHANGE    |   \
                                                         SignalGenerator_OVERLOW_SET           |   \
                                                         SignalGenerator_UNDERFLOW_CLEAR )

/* Command operations without condition */
#define SignalGenerator_CMD_CAPTURE                    (0u)
#define SignalGenerator_CMD_RELOAD                     (8u)
#define SignalGenerator_CMD_STOP                       (16u)
#define SignalGenerator_CMD_START                      (24u)

/* Status */
#define SignalGenerator_STATUS_DOWN                    (1u)
#define SignalGenerator_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   SignalGenerator_Init(void);
void   SignalGenerator_Enable(void);
void   SignalGenerator_Start(void);
void   SignalGenerator_Stop(void);

void   SignalGenerator_SetMode(uint32 mode);
void   SignalGenerator_SetCounterMode(uint32 counterMode);
void   SignalGenerator_SetPWMMode(uint32 modeMask);
void   SignalGenerator_SetQDMode(uint32 qdMode);

void   SignalGenerator_SetPrescaler(uint32 prescaler);
void   SignalGenerator_TriggerCommand(uint32 mask, uint32 command);
void   SignalGenerator_SetOneShot(uint32 oneShotEnable);
uint32 SignalGenerator_ReadStatus(void);

void   SignalGenerator_SetPWMSyncKill(uint32 syncKillEnable);
void   SignalGenerator_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   SignalGenerator_SetPWMDeadTime(uint32 deadTime);
void   SignalGenerator_SetPWMInvert(uint32 mask);

void   SignalGenerator_SetInterruptMode(uint32 interruptMask);
uint32 SignalGenerator_GetInterruptSourceMasked(void);
uint32 SignalGenerator_GetInterruptSource(void);
void   SignalGenerator_ClearInterrupt(uint32 interruptMask);
void   SignalGenerator_SetInterrupt(uint32 interruptMask);

void   SignalGenerator_WriteCounter(uint32 count);
uint32 SignalGenerator_ReadCounter(void);

uint32 SignalGenerator_ReadCapture(void);
uint32 SignalGenerator_ReadCaptureBuf(void);

void   SignalGenerator_WritePeriod(uint32 period);
uint32 SignalGenerator_ReadPeriod(void);
void   SignalGenerator_WritePeriodBuf(uint32 periodBuf);
uint32 SignalGenerator_ReadPeriodBuf(void);

void   SignalGenerator_WriteCompare(uint32 compare);
uint32 SignalGenerator_ReadCompare(void);
void   SignalGenerator_WriteCompareBuf(uint32 compareBuf);
uint32 SignalGenerator_ReadCompareBuf(void);

void   SignalGenerator_SetPeriodSwap(uint32 swapEnable);
void   SignalGenerator_SetCompareSwap(uint32 swapEnable);

void   SignalGenerator_SetCaptureMode(uint32 triggerMode);
void   SignalGenerator_SetReloadMode(uint32 triggerMode);
void   SignalGenerator_SetStartMode(uint32 triggerMode);
void   SignalGenerator_SetStopMode(uint32 triggerMode);
void   SignalGenerator_SetCountMode(uint32 triggerMode);

void   SignalGenerator_SaveConfig(void);
void   SignalGenerator_RestoreConfig(void);
void   SignalGenerator_Sleep(void);
void   SignalGenerator_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define SignalGenerator_BLOCK_CONTROL_REG              (*(reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define SignalGenerator_BLOCK_CONTROL_PTR              ( (reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define SignalGenerator_COMMAND_REG                    (*(reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define SignalGenerator_COMMAND_PTR                    ( (reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define SignalGenerator_INTRRUPT_CAUSE_REG             (*(reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define SignalGenerator_INTRRUPT_CAUSE_PTR             ( (reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define SignalGenerator_CONTROL_REG                    (*(reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__CTRL )
#define SignalGenerator_CONTROL_PTR                    ( (reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__CTRL )
#define SignalGenerator_STATUS_REG                     (*(reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__STATUS )
#define SignalGenerator_STATUS_PTR                     ( (reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__STATUS )
#define SignalGenerator_COUNTER_REG                    (*(reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__COUNTER )
#define SignalGenerator_COUNTER_PTR                    ( (reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__COUNTER )
#define SignalGenerator_COMP_CAP_REG                   (*(reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__CC )
#define SignalGenerator_COMP_CAP_PTR                   ( (reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__CC )
#define SignalGenerator_COMP_CAP_BUF_REG               (*(reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__CC_BUFF )
#define SignalGenerator_COMP_CAP_BUF_PTR               ( (reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__CC_BUFF )
#define SignalGenerator_PERIOD_REG                     (*(reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__PERIOD )
#define SignalGenerator_PERIOD_PTR                     ( (reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__PERIOD )
#define SignalGenerator_PERIOD_BUF_REG                 (*(reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define SignalGenerator_PERIOD_BUF_PTR                 ( (reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define SignalGenerator_TRIG_CONTROL0_REG              (*(reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define SignalGenerator_TRIG_CONTROL0_PTR              ( (reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define SignalGenerator_TRIG_CONTROL1_REG              (*(reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define SignalGenerator_TRIG_CONTROL1_PTR              ( (reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define SignalGenerator_TRIG_CONTROL2_REG              (*(reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define SignalGenerator_TRIG_CONTROL2_PTR              ( (reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define SignalGenerator_INTERRUPT_REQ_REG              (*(reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__INTR )
#define SignalGenerator_INTERRUPT_REQ_PTR              ( (reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__INTR )
#define SignalGenerator_INTERRUPT_SET_REG              (*(reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__INTR_SET )
#define SignalGenerator_INTERRUPT_SET_PTR              ( (reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__INTR_SET )
#define SignalGenerator_INTERRUPT_MASK_REG             (*(reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__INTR_MASK )
#define SignalGenerator_INTERRUPT_MASK_PTR             ( (reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__INTR_MASK )
#define SignalGenerator_INTERRUPT_MASKED_REG           (*(reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__INTR_MASKED )
#define SignalGenerator_INTERRUPT_MASKED_PTR           ( (reg32 *) SignalGenerator_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define SignalGenerator_MASK                           ((uint32)SignalGenerator_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define SignalGenerator_RELOAD_CC_SHIFT                (0u)
#define SignalGenerator_RELOAD_PERIOD_SHIFT            (1u)
#define SignalGenerator_PWM_SYNC_KILL_SHIFT            (2u)
#define SignalGenerator_PWM_STOP_KILL_SHIFT            (3u)
#define SignalGenerator_PRESCALER_SHIFT                (8u)
#define SignalGenerator_UPDOWN_SHIFT                   (16u)
#define SignalGenerator_ONESHOT_SHIFT                  (18u)
#define SignalGenerator_QUAD_MODE_SHIFT                (20u)
#define SignalGenerator_INV_OUT_SHIFT                  (20u)
#define SignalGenerator_INV_COMPL_OUT_SHIFT            (21u)
#define SignalGenerator_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define SignalGenerator_RELOAD_CC_MASK                 ((uint32)(SignalGenerator_1BIT_MASK        <<  \
                                                                            SignalGenerator_RELOAD_CC_SHIFT))
#define SignalGenerator_RELOAD_PERIOD_MASK             ((uint32)(SignalGenerator_1BIT_MASK        <<  \
                                                                            SignalGenerator_RELOAD_PERIOD_SHIFT))
#define SignalGenerator_PWM_SYNC_KILL_MASK             ((uint32)(SignalGenerator_1BIT_MASK        <<  \
                                                                            SignalGenerator_PWM_SYNC_KILL_SHIFT))
#define SignalGenerator_PWM_STOP_KILL_MASK             ((uint32)(SignalGenerator_1BIT_MASK        <<  \
                                                                            SignalGenerator_PWM_STOP_KILL_SHIFT))
#define SignalGenerator_PRESCALER_MASK                 ((uint32)(SignalGenerator_8BIT_MASK        <<  \
                                                                            SignalGenerator_PRESCALER_SHIFT))
#define SignalGenerator_UPDOWN_MASK                    ((uint32)(SignalGenerator_2BIT_MASK        <<  \
                                                                            SignalGenerator_UPDOWN_SHIFT))
#define SignalGenerator_ONESHOT_MASK                   ((uint32)(SignalGenerator_1BIT_MASK        <<  \
                                                                            SignalGenerator_ONESHOT_SHIFT))
#define SignalGenerator_QUAD_MODE_MASK                 ((uint32)(SignalGenerator_3BIT_MASK        <<  \
                                                                            SignalGenerator_QUAD_MODE_SHIFT))
#define SignalGenerator_INV_OUT_MASK                   ((uint32)(SignalGenerator_2BIT_MASK        <<  \
                                                                            SignalGenerator_INV_OUT_SHIFT))
#define SignalGenerator_MODE_MASK                      ((uint32)(SignalGenerator_3BIT_MASK        <<  \
                                                                            SignalGenerator_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define SignalGenerator_CAPTURE_SHIFT                  (0u)
#define SignalGenerator_COUNT_SHIFT                    (2u)
#define SignalGenerator_RELOAD_SHIFT                   (4u)
#define SignalGenerator_STOP_SHIFT                     (6u)
#define SignalGenerator_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define SignalGenerator_CAPTURE_MASK                   ((uint32)(SignalGenerator_2BIT_MASK        <<  \
                                                                  SignalGenerator_CAPTURE_SHIFT))
#define SignalGenerator_COUNT_MASK                     ((uint32)(SignalGenerator_2BIT_MASK        <<  \
                                                                  SignalGenerator_COUNT_SHIFT))
#define SignalGenerator_RELOAD_MASK                    ((uint32)(SignalGenerator_2BIT_MASK        <<  \
                                                                  SignalGenerator_RELOAD_SHIFT))
#define SignalGenerator_STOP_MASK                      ((uint32)(SignalGenerator_2BIT_MASK        <<  \
                                                                  SignalGenerator_STOP_SHIFT))
#define SignalGenerator_START_MASK                     ((uint32)(SignalGenerator_2BIT_MASK        <<  \
                                                                  SignalGenerator_START_SHIFT))

/* MASK */
#define SignalGenerator_1BIT_MASK                      ((uint32)0x01u)
#define SignalGenerator_2BIT_MASK                      ((uint32)0x03u)
#define SignalGenerator_3BIT_MASK                      ((uint32)0x07u)
#define SignalGenerator_6BIT_MASK                      ((uint32)0x3Fu)
#define SignalGenerator_8BIT_MASK                      ((uint32)0xFFu)
#define SignalGenerator_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define SignalGenerator_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define SignalGenerator_PWM_PR_INIT_VALUE              (1u)

#endif /* End CY_TCPWM_SignalGenerator_H */

/* [] END OF FILE */
