/*******************************************************************************
* File Name: L.h
* Version 1.10
*
* Description:
*  This file provides constants and parameter values for the L
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

#if !defined(CY_TCPWM_L_H)
#define CY_TCPWM_L_H

#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} L_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  L_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define L_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)

/* TCPWM Configuration */
#define L_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define L_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define L_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define L_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define L_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define L_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define L_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define L_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define L_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define L_TC_RUN_MODE                    (0lu)
#define L_TC_COUNTER_MODE                (0lu)
#define L_TC_COMP_CAP_MODE               (2lu)
#define L_TC_PRESCALER                   (0lu)

/* Signal modes */
#define L_TC_RELOAD_SIGNAL_MODE          (0lu)
#define L_TC_COUNT_SIGNAL_MODE           (3lu)
#define L_TC_START_SIGNAL_MODE           (0lu)
#define L_TC_STOP_SIGNAL_MODE            (0lu)
#define L_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define L_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define L_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define L_TC_START_SIGNAL_PRESENT        (0lu)
#define L_TC_STOP_SIGNAL_PRESENT         (0lu)
#define L_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define L_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define L_PWM_KILL_EVENT                 (0lu)
#define L_PWM_STOP_EVENT                 (0lu)
#define L_PWM_MODE                       (4lu)
#define L_PWM_OUT_N_INVERT               (0lu)
#define L_PWM_OUT_INVERT                 (0lu)
#define L_PWM_ALIGN                      (0lu)
#define L_PWM_RUN_MODE                   (0lu)
#define L_PWM_DEAD_TIME_CYCLE            (0lu)
#define L_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define L_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define L_PWM_COUNT_SIGNAL_MODE          (3lu)
#define L_PWM_START_SIGNAL_MODE          (0lu)
#define L_PWM_STOP_SIGNAL_MODE           (0lu)
#define L_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define L_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define L_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define L_PWM_START_SIGNAL_PRESENT       (0lu)
#define L_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define L_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define L_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define L_TC_PERIOD_VALUE                (65535lu)
#define L_TC_COMPARE_VALUE               (65535lu)
#define L_TC_COMPARE_BUF_VALUE           (65535lu)
#define L_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define L_PWM_PERIOD_VALUE               (1000lu)
#define L_PWM_PERIOD_BUF_VALUE           (65535lu)
#define L_PWM_PERIOD_SWAP                (0lu)
#define L_PWM_COMPARE_VALUE              (500lu)
#define L_PWM_COMPARE_BUF_VALUE          (65535lu)
#define L_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define L__LEFT 0
#define L__RIGHT 1
#define L__CENTER 2
#define L__ASYMMETRIC 3

#define L__X1 0
#define L__X2 1
#define L__X4 2

#define L__PWM 4
#define L__PWM_DT 5
#define L__PWM_PR 6

#define L__INVERSE 1
#define L__DIRECT 0

#define L__CAPTURE 2
#define L__COMPARE 0

#define L__TRIG_LEVEL 3
#define L__TRIG_RISING 0
#define L__TRIG_FALLING 1
#define L__TRIG_BOTH 2

#define L__INTR_MASK_TC 1
#define L__INTR_MASK_CC_MATCH 2
#define L__INTR_MASK_NONE 0
#define L__INTR_MASK_TC_CC 3

#define L__UNCONFIG 8
#define L__TIMER 1
#define L__QUAD 3
#define L__PWM_SEL 7

#define L__COUNT_UP 0
#define L__COUNT_DOWN 1
#define L__COUNT_UPDOWN0 2
#define L__COUNT_UPDOWN1 3


/* Prescaler */
#define L_PRESCALE_DIVBY1                ((uint32)(0u << L_PRESCALER_SHIFT))
#define L_PRESCALE_DIVBY2                ((uint32)(1u << L_PRESCALER_SHIFT))
#define L_PRESCALE_DIVBY4                ((uint32)(2u << L_PRESCALER_SHIFT))
#define L_PRESCALE_DIVBY8                ((uint32)(3u << L_PRESCALER_SHIFT))
#define L_PRESCALE_DIVBY16               ((uint32)(4u << L_PRESCALER_SHIFT))
#define L_PRESCALE_DIVBY32               ((uint32)(5u << L_PRESCALER_SHIFT))
#define L_PRESCALE_DIVBY64               ((uint32)(6u << L_PRESCALER_SHIFT))
#define L_PRESCALE_DIVBY128              ((uint32)(7u << L_PRESCALER_SHIFT))

/* TCPWM set modes */
#define L_MODE_TIMER_COMPARE             ((uint32)(L__COMPARE         <<  \
                                                                  L_MODE_SHIFT))
#define L_MODE_TIMER_CAPTURE             ((uint32)(L__CAPTURE         <<  \
                                                                  L_MODE_SHIFT))
#define L_MODE_QUAD                      ((uint32)(L__QUAD            <<  \
                                                                  L_MODE_SHIFT))
#define L_MODE_PWM                       ((uint32)(L__PWM             <<  \
                                                                  L_MODE_SHIFT))
#define L_MODE_PWM_DT                    ((uint32)(L__PWM_DT          <<  \
                                                                  L_MODE_SHIFT))
#define L_MODE_PWM_PR                    ((uint32)(L__PWM_PR          <<  \
                                                                  L_MODE_SHIFT))

/* Quad Modes */
#define L_MODE_X1                        ((uint32)(L__X1              <<  \
                                                                  L_QUAD_MODE_SHIFT))
#define L_MODE_X2                        ((uint32)(L__X2              <<  \
                                                                  L_QUAD_MODE_SHIFT))
#define L_MODE_X4                        ((uint32)(L__X4              <<  \
                                                                  L_QUAD_MODE_SHIFT))

/* Counter modes */
#define L_COUNT_UP                       ((uint32)(L__COUNT_UP        <<  \
                                                                  L_UPDOWN_SHIFT))
#define L_COUNT_DOWN                     ((uint32)(L__COUNT_DOWN      <<  \
                                                                  L_UPDOWN_SHIFT))
#define L_COUNT_UPDOWN0                  ((uint32)(L__COUNT_UPDOWN0   <<  \
                                                                  L_UPDOWN_SHIFT))
#define L_COUNT_UPDOWN1                  ((uint32)(L__COUNT_UPDOWN1   <<  \
                                                                  L_UPDOWN_SHIFT))

/* PWM output invert */
#define L_INVERT_LINE                    ((uint32)(L__INVERSE         <<  \
                                                                  L_INV_OUT_SHIFT))
#define L_INVERT_LINE_N                  ((uint32)(L__INVERSE         <<  \
                                                                  L_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define L_TRIG_RISING                    ((uint32)L__TRIG_RISING)
#define L_TRIG_FALLING                   ((uint32)L__TRIG_FALLING)
#define L_TRIG_BOTH                      ((uint32)L__TRIG_BOTH)
#define L_TRIG_LEVEL                     ((uint32)L__TRIG_LEVEL)

/* Interrupt mask */
#define L_INTR_MASK_TC                   ((uint32)L__INTR_MASK_TC)
#define L_INTR_MASK_CC_MATCH             ((uint32)L__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define L_CC_MATCH_SET                   (0x00u)
#define L_CC_MATCH_CLEAR                 (0x01u)
#define L_CC_MATCH_INVERT                (0x02u)
#define L_CC_MATCH_NO_CHANGE             (0x03u)
#define L_OVERLOW_SET                    (0x00u)
#define L_OVERLOW_CLEAR                  (0x04u)
#define L_OVERLOW_INVERT                 (0x08u)
#define L_OVERLOW_NO_CHANGE              (0x0Cu)
#define L_UNDERFLOW_SET                  (0x00u)
#define L_UNDERFLOW_CLEAR                (0x10u)
#define L_UNDERFLOW_INVERT               (0x20u)
#define L_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define L_PWM_MODE_LEFT                  (L_CC_MATCH_CLEAR        |   \
                                                         L_OVERLOW_SET           |   \
                                                         L_UNDERFLOW_NO_CHANGE)
#define L_PWM_MODE_RIGHT                 (L_CC_MATCH_SET          |   \
                                                         L_OVERLOW_NO_CHANGE     |   \
                                                         L_UNDERFLOW_CLEAR)
#define L_PWM_MODE_CENTER                (L_CC_MATCH_INVERT       |   \
                                                         L_OVERLOW_NO_CHANGE     |   \
                                                         L_UNDERFLOW_CLEAR)
#define L_PWM_MODE_ASYM                  (L_CC_MATCH_NO_CHANGE    |   \
                                                         L_OVERLOW_SET           |   \
                                                         L_UNDERFLOW_CLEAR )

/* Command operations without condition */
#define L_CMD_CAPTURE                    (0u)
#define L_CMD_RELOAD                     (8u)
#define L_CMD_STOP                       (16u)
#define L_CMD_START                      (24u)

/* Status */
#define L_STATUS_DOWN                    (1u)
#define L_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   L_Init(void);
void   L_Enable(void);
void   L_Start(void);
void   L_Stop(void);

void   L_SetMode(uint32 mode);
void   L_SetCounterMode(uint32 counterMode);
void   L_SetPWMMode(uint32 modeMask);
void   L_SetQDMode(uint32 qdMode);

void   L_SetPrescaler(uint32 prescaler);
void   L_TriggerCommand(uint32 mask, uint32 command);
void   L_SetOneShot(uint32 oneShotEnable);
uint32 L_ReadStatus(void);

void   L_SetPWMSyncKill(uint32 syncKillEnable);
void   L_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   L_SetPWMDeadTime(uint32 deadTime);
void   L_SetPWMInvert(uint32 mask);

void   L_SetInterruptMode(uint32 interruptMask);
uint32 L_GetInterruptSourceMasked(void);
uint32 L_GetInterruptSource(void);
void   L_ClearInterrupt(uint32 interruptMask);
void   L_SetInterrupt(uint32 interruptMask);

void   L_WriteCounter(uint32 count);
uint32 L_ReadCounter(void);

uint32 L_ReadCapture(void);
uint32 L_ReadCaptureBuf(void);

void   L_WritePeriod(uint32 period);
uint32 L_ReadPeriod(void);
void   L_WritePeriodBuf(uint32 periodBuf);
uint32 L_ReadPeriodBuf(void);

void   L_WriteCompare(uint32 compare);
uint32 L_ReadCompare(void);
void   L_WriteCompareBuf(uint32 compareBuf);
uint32 L_ReadCompareBuf(void);

void   L_SetPeriodSwap(uint32 swapEnable);
void   L_SetCompareSwap(uint32 swapEnable);

void   L_SetCaptureMode(uint32 triggerMode);
void   L_SetReloadMode(uint32 triggerMode);
void   L_SetStartMode(uint32 triggerMode);
void   L_SetStopMode(uint32 triggerMode);
void   L_SetCountMode(uint32 triggerMode);

void   L_SaveConfig(void);
void   L_RestoreConfig(void);
void   L_Sleep(void);
void   L_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define L_BLOCK_CONTROL_REG              (*(reg32 *) L_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define L_BLOCK_CONTROL_PTR              ( (reg32 *) L_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define L_COMMAND_REG                    (*(reg32 *) L_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define L_COMMAND_PTR                    ( (reg32 *) L_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define L_INTRRUPT_CAUSE_REG             (*(reg32 *) L_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define L_INTRRUPT_CAUSE_PTR             ( (reg32 *) L_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define L_CONTROL_REG                    (*(reg32 *) L_cy_m0s8_tcpwm_1__CTRL )
#define L_CONTROL_PTR                    ( (reg32 *) L_cy_m0s8_tcpwm_1__CTRL )
#define L_STATUS_REG                     (*(reg32 *) L_cy_m0s8_tcpwm_1__STATUS )
#define L_STATUS_PTR                     ( (reg32 *) L_cy_m0s8_tcpwm_1__STATUS )
#define L_COUNTER_REG                    (*(reg32 *) L_cy_m0s8_tcpwm_1__COUNTER )
#define L_COUNTER_PTR                    ( (reg32 *) L_cy_m0s8_tcpwm_1__COUNTER )
#define L_COMP_CAP_REG                   (*(reg32 *) L_cy_m0s8_tcpwm_1__CC )
#define L_COMP_CAP_PTR                   ( (reg32 *) L_cy_m0s8_tcpwm_1__CC )
#define L_COMP_CAP_BUF_REG               (*(reg32 *) L_cy_m0s8_tcpwm_1__CC_BUFF )
#define L_COMP_CAP_BUF_PTR               ( (reg32 *) L_cy_m0s8_tcpwm_1__CC_BUFF )
#define L_PERIOD_REG                     (*(reg32 *) L_cy_m0s8_tcpwm_1__PERIOD )
#define L_PERIOD_PTR                     ( (reg32 *) L_cy_m0s8_tcpwm_1__PERIOD )
#define L_PERIOD_BUF_REG                 (*(reg32 *) L_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define L_PERIOD_BUF_PTR                 ( (reg32 *) L_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define L_TRIG_CONTROL0_REG              (*(reg32 *) L_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define L_TRIG_CONTROL0_PTR              ( (reg32 *) L_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define L_TRIG_CONTROL1_REG              (*(reg32 *) L_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define L_TRIG_CONTROL1_PTR              ( (reg32 *) L_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define L_TRIG_CONTROL2_REG              (*(reg32 *) L_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define L_TRIG_CONTROL2_PTR              ( (reg32 *) L_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define L_INTERRUPT_REQ_REG              (*(reg32 *) L_cy_m0s8_tcpwm_1__INTR )
#define L_INTERRUPT_REQ_PTR              ( (reg32 *) L_cy_m0s8_tcpwm_1__INTR )
#define L_INTERRUPT_SET_REG              (*(reg32 *) L_cy_m0s8_tcpwm_1__INTR_SET )
#define L_INTERRUPT_SET_PTR              ( (reg32 *) L_cy_m0s8_tcpwm_1__INTR_SET )
#define L_INTERRUPT_MASK_REG             (*(reg32 *) L_cy_m0s8_tcpwm_1__INTR_MASK )
#define L_INTERRUPT_MASK_PTR             ( (reg32 *) L_cy_m0s8_tcpwm_1__INTR_MASK )
#define L_INTERRUPT_MASKED_REG           (*(reg32 *) L_cy_m0s8_tcpwm_1__INTR_MASKED )
#define L_INTERRUPT_MASKED_PTR           ( (reg32 *) L_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define L_MASK                           ((uint32)L_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define L_RELOAD_CC_SHIFT                (0u)
#define L_RELOAD_PERIOD_SHIFT            (1u)
#define L_PWM_SYNC_KILL_SHIFT            (2u)
#define L_PWM_STOP_KILL_SHIFT            (3u)
#define L_PRESCALER_SHIFT                (8u)
#define L_UPDOWN_SHIFT                   (16u)
#define L_ONESHOT_SHIFT                  (18u)
#define L_QUAD_MODE_SHIFT                (20u)
#define L_INV_OUT_SHIFT                  (20u)
#define L_INV_COMPL_OUT_SHIFT            (21u)
#define L_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define L_RELOAD_CC_MASK                 ((uint32)(L_1BIT_MASK        <<  \
                                                                            L_RELOAD_CC_SHIFT))
#define L_RELOAD_PERIOD_MASK             ((uint32)(L_1BIT_MASK        <<  \
                                                                            L_RELOAD_PERIOD_SHIFT))
#define L_PWM_SYNC_KILL_MASK             ((uint32)(L_1BIT_MASK        <<  \
                                                                            L_PWM_SYNC_KILL_SHIFT))
#define L_PWM_STOP_KILL_MASK             ((uint32)(L_1BIT_MASK        <<  \
                                                                            L_PWM_STOP_KILL_SHIFT))
#define L_PRESCALER_MASK                 ((uint32)(L_8BIT_MASK        <<  \
                                                                            L_PRESCALER_SHIFT))
#define L_UPDOWN_MASK                    ((uint32)(L_2BIT_MASK        <<  \
                                                                            L_UPDOWN_SHIFT))
#define L_ONESHOT_MASK                   ((uint32)(L_1BIT_MASK        <<  \
                                                                            L_ONESHOT_SHIFT))
#define L_QUAD_MODE_MASK                 ((uint32)(L_3BIT_MASK        <<  \
                                                                            L_QUAD_MODE_SHIFT))
#define L_INV_OUT_MASK                   ((uint32)(L_2BIT_MASK        <<  \
                                                                            L_INV_OUT_SHIFT))
#define L_MODE_MASK                      ((uint32)(L_3BIT_MASK        <<  \
                                                                            L_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define L_CAPTURE_SHIFT                  (0u)
#define L_COUNT_SHIFT                    (2u)
#define L_RELOAD_SHIFT                   (4u)
#define L_STOP_SHIFT                     (6u)
#define L_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define L_CAPTURE_MASK                   ((uint32)(L_2BIT_MASK        <<  \
                                                                  L_CAPTURE_SHIFT))
#define L_COUNT_MASK                     ((uint32)(L_2BIT_MASK        <<  \
                                                                  L_COUNT_SHIFT))
#define L_RELOAD_MASK                    ((uint32)(L_2BIT_MASK        <<  \
                                                                  L_RELOAD_SHIFT))
#define L_STOP_MASK                      ((uint32)(L_2BIT_MASK        <<  \
                                                                  L_STOP_SHIFT))
#define L_START_MASK                     ((uint32)(L_2BIT_MASK        <<  \
                                                                  L_START_SHIFT))

/* MASK */
#define L_1BIT_MASK                      ((uint32)0x01u)
#define L_2BIT_MASK                      ((uint32)0x03u)
#define L_3BIT_MASK                      ((uint32)0x07u)
#define L_6BIT_MASK                      ((uint32)0x3Fu)
#define L_8BIT_MASK                      ((uint32)0xFFu)
#define L_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define L_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define L_PWM_PR_INIT_VALUE              (1u)

#endif /* End CY_TCPWM_L_H */

/* [] END OF FILE */
