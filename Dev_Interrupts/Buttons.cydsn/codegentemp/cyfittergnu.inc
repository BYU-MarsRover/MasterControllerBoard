.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu_trm.inc"

/* LED */
.set LED__0__DM__MASK, 0x07
.set LED__0__DM__SHIFT, 0
.set LED__0__DR, CYREG_PRT2_DR
.set LED__0__HSIOM, CYREG_HSIOM_PORT_SEL2
.set LED__0__HSIOM_MASK, 0x0000000F
.set LED__0__HSIOM_SHIFT, 0
.set LED__0__INTCFG, CYREG_PRT2_INTCFG
.set LED__0__INTSTAT, CYREG_PRT2_INTSTAT
.set LED__0__MASK, 0x01
.set LED__0__PA__CFG0, CYREG_UDB_PA2_CFG0
.set LED__0__PA__CFG1, CYREG_UDB_PA2_CFG1
.set LED__0__PA__CFG10, CYREG_UDB_PA2_CFG10
.set LED__0__PA__CFG11, CYREG_UDB_PA2_CFG11
.set LED__0__PA__CFG12, CYREG_UDB_PA2_CFG12
.set LED__0__PA__CFG13, CYREG_UDB_PA2_CFG13
.set LED__0__PA__CFG14, CYREG_UDB_PA2_CFG14
.set LED__0__PA__CFG2, CYREG_UDB_PA2_CFG2
.set LED__0__PA__CFG3, CYREG_UDB_PA2_CFG3
.set LED__0__PA__CFG4, CYREG_UDB_PA2_CFG4
.set LED__0__PA__CFG5, CYREG_UDB_PA2_CFG5
.set LED__0__PA__CFG6, CYREG_UDB_PA2_CFG6
.set LED__0__PA__CFG7, CYREG_UDB_PA2_CFG7
.set LED__0__PA__CFG8, CYREG_UDB_PA2_CFG8
.set LED__0__PA__CFG9, CYREG_UDB_PA2_CFG9
.set LED__0__PC, CYREG_PRT2_PC
.set LED__0__PC2, CYREG_PRT2_PC2
.set LED__0__PORT, 2
.set LED__0__PS, CYREG_PRT2_PS
.set LED__0__SHIFT, 0
.set LED__DR, CYREG_PRT2_DR
.set LED__INTCFG, CYREG_PRT2_INTCFG
.set LED__INTSTAT, CYREG_PRT2_INTSTAT
.set LED__MASK, 0x01
.set LED__PA__CFG0, CYREG_UDB_PA2_CFG0
.set LED__PA__CFG1, CYREG_UDB_PA2_CFG1
.set LED__PA__CFG10, CYREG_UDB_PA2_CFG10
.set LED__PA__CFG11, CYREG_UDB_PA2_CFG11
.set LED__PA__CFG12, CYREG_UDB_PA2_CFG12
.set LED__PA__CFG13, CYREG_UDB_PA2_CFG13
.set LED__PA__CFG14, CYREG_UDB_PA2_CFG14
.set LED__PA__CFG2, CYREG_UDB_PA2_CFG2
.set LED__PA__CFG3, CYREG_UDB_PA2_CFG3
.set LED__PA__CFG4, CYREG_UDB_PA2_CFG4
.set LED__PA__CFG5, CYREG_UDB_PA2_CFG5
.set LED__PA__CFG6, CYREG_UDB_PA2_CFG6
.set LED__PA__CFG7, CYREG_UDB_PA2_CFG7
.set LED__PA__CFG8, CYREG_UDB_PA2_CFG8
.set LED__PA__CFG9, CYREG_UDB_PA2_CFG9
.set LED__PC, CYREG_PRT2_PC
.set LED__PC2, CYREG_PRT2_PC2
.set LED__PORT, 2
.set LED__PS, CYREG_PRT2_PS
.set LED__SHIFT, 0

/* Btn0 */
.set Btn0__0__DM__MASK, 0x1C0000
.set Btn0__0__DM__SHIFT, 18
.set Btn0__0__DR, CYREG_PRT3_DR
.set Btn0__0__HSIOM, CYREG_HSIOM_PORT_SEL3
.set Btn0__0__HSIOM_MASK, 0x0F000000
.set Btn0__0__HSIOM_SHIFT, 24
.set Btn0__0__INTCFG, CYREG_PRT3_INTCFG
.set Btn0__0__INTSTAT, CYREG_PRT3_INTSTAT
.set Btn0__0__MASK, 0x40
.set Btn0__0__PA__CFG0, CYREG_UDB_PA3_CFG0
.set Btn0__0__PA__CFG1, CYREG_UDB_PA3_CFG1
.set Btn0__0__PA__CFG10, CYREG_UDB_PA3_CFG10
.set Btn0__0__PA__CFG11, CYREG_UDB_PA3_CFG11
.set Btn0__0__PA__CFG12, CYREG_UDB_PA3_CFG12
.set Btn0__0__PA__CFG13, CYREG_UDB_PA3_CFG13
.set Btn0__0__PA__CFG14, CYREG_UDB_PA3_CFG14
.set Btn0__0__PA__CFG2, CYREG_UDB_PA3_CFG2
.set Btn0__0__PA__CFG3, CYREG_UDB_PA3_CFG3
.set Btn0__0__PA__CFG4, CYREG_UDB_PA3_CFG4
.set Btn0__0__PA__CFG5, CYREG_UDB_PA3_CFG5
.set Btn0__0__PA__CFG6, CYREG_UDB_PA3_CFG6
.set Btn0__0__PA__CFG7, CYREG_UDB_PA3_CFG7
.set Btn0__0__PA__CFG8, CYREG_UDB_PA3_CFG8
.set Btn0__0__PA__CFG9, CYREG_UDB_PA3_CFG9
.set Btn0__0__PC, CYREG_PRT3_PC
.set Btn0__0__PC2, CYREG_PRT3_PC2
.set Btn0__0__PORT, 3
.set Btn0__0__PS, CYREG_PRT3_PS
.set Btn0__0__SHIFT, 6
.set Btn0__DR, CYREG_PRT3_DR
.set Btn0__INTCFG, CYREG_PRT3_INTCFG
.set Btn0__INTSTAT, CYREG_PRT3_INTSTAT
.set Btn0__MASK, 0x40
.set Btn0__PA__CFG0, CYREG_UDB_PA3_CFG0
.set Btn0__PA__CFG1, CYREG_UDB_PA3_CFG1
.set Btn0__PA__CFG10, CYREG_UDB_PA3_CFG10
.set Btn0__PA__CFG11, CYREG_UDB_PA3_CFG11
.set Btn0__PA__CFG12, CYREG_UDB_PA3_CFG12
.set Btn0__PA__CFG13, CYREG_UDB_PA3_CFG13
.set Btn0__PA__CFG14, CYREG_UDB_PA3_CFG14
.set Btn0__PA__CFG2, CYREG_UDB_PA3_CFG2
.set Btn0__PA__CFG3, CYREG_UDB_PA3_CFG3
.set Btn0__PA__CFG4, CYREG_UDB_PA3_CFG4
.set Btn0__PA__CFG5, CYREG_UDB_PA3_CFG5
.set Btn0__PA__CFG6, CYREG_UDB_PA3_CFG6
.set Btn0__PA__CFG7, CYREG_UDB_PA3_CFG7
.set Btn0__PA__CFG8, CYREG_UDB_PA3_CFG8
.set Btn0__PA__CFG9, CYREG_UDB_PA3_CFG9
.set Btn0__PC, CYREG_PRT3_PC
.set Btn0__PC2, CYREG_PRT3_PC2
.set Btn0__PORT, 3
.set Btn0__PS, CYREG_PRT3_PS
.set Btn0__SHIFT, 6
.set Btn0__SNAP, CYREG_PRT3_INTSTAT

/* Btn1 */
.set Btn1__0__DM__MASK, 0xE00000
.set Btn1__0__DM__SHIFT, 21
.set Btn1__0__DR, CYREG_PRT2_DR
.set Btn1__0__HSIOM, CYREG_HSIOM_PORT_SEL2
.set Btn1__0__HSIOM_MASK, 0xF0000000
.set Btn1__0__HSIOM_SHIFT, 28
.set Btn1__0__INTCFG, CYREG_PRT2_INTCFG
.set Btn1__0__INTSTAT, CYREG_PRT2_INTSTAT
.set Btn1__0__MASK, 0x80
.set Btn1__0__PA__CFG0, CYREG_UDB_PA2_CFG0
.set Btn1__0__PA__CFG1, CYREG_UDB_PA2_CFG1
.set Btn1__0__PA__CFG10, CYREG_UDB_PA2_CFG10
.set Btn1__0__PA__CFG11, CYREG_UDB_PA2_CFG11
.set Btn1__0__PA__CFG12, CYREG_UDB_PA2_CFG12
.set Btn1__0__PA__CFG13, CYREG_UDB_PA2_CFG13
.set Btn1__0__PA__CFG14, CYREG_UDB_PA2_CFG14
.set Btn1__0__PA__CFG2, CYREG_UDB_PA2_CFG2
.set Btn1__0__PA__CFG3, CYREG_UDB_PA2_CFG3
.set Btn1__0__PA__CFG4, CYREG_UDB_PA2_CFG4
.set Btn1__0__PA__CFG5, CYREG_UDB_PA2_CFG5
.set Btn1__0__PA__CFG6, CYREG_UDB_PA2_CFG6
.set Btn1__0__PA__CFG7, CYREG_UDB_PA2_CFG7
.set Btn1__0__PA__CFG8, CYREG_UDB_PA2_CFG8
.set Btn1__0__PA__CFG9, CYREG_UDB_PA2_CFG9
.set Btn1__0__PC, CYREG_PRT2_PC
.set Btn1__0__PC2, CYREG_PRT2_PC2
.set Btn1__0__PORT, 2
.set Btn1__0__PS, CYREG_PRT2_PS
.set Btn1__0__SHIFT, 7
.set Btn1__DR, CYREG_PRT2_DR
.set Btn1__INTCFG, CYREG_PRT2_INTCFG
.set Btn1__INTSTAT, CYREG_PRT2_INTSTAT
.set Btn1__MASK, 0x80
.set Btn1__PA__CFG0, CYREG_UDB_PA2_CFG0
.set Btn1__PA__CFG1, CYREG_UDB_PA2_CFG1
.set Btn1__PA__CFG10, CYREG_UDB_PA2_CFG10
.set Btn1__PA__CFG11, CYREG_UDB_PA2_CFG11
.set Btn1__PA__CFG12, CYREG_UDB_PA2_CFG12
.set Btn1__PA__CFG13, CYREG_UDB_PA2_CFG13
.set Btn1__PA__CFG14, CYREG_UDB_PA2_CFG14
.set Btn1__PA__CFG2, CYREG_UDB_PA2_CFG2
.set Btn1__PA__CFG3, CYREG_UDB_PA2_CFG3
.set Btn1__PA__CFG4, CYREG_UDB_PA2_CFG4
.set Btn1__PA__CFG5, CYREG_UDB_PA2_CFG5
.set Btn1__PA__CFG6, CYREG_UDB_PA2_CFG6
.set Btn1__PA__CFG7, CYREG_UDB_PA2_CFG7
.set Btn1__PA__CFG8, CYREG_UDB_PA2_CFG8
.set Btn1__PA__CFG9, CYREG_UDB_PA2_CFG9
.set Btn1__PC, CYREG_PRT2_PC
.set Btn1__PC2, CYREG_PRT2_PC2
.set Btn1__PORT, 2
.set Btn1__PS, CYREG_PRT2_PS
.set Btn1__SHIFT, 7
.set Btn1__SNAP, CYREG_PRT2_INTSTAT

/* LED1 */
.set LED1__0__DM__MASK, 0x38
.set LED1__0__DM__SHIFT, 3
.set LED1__0__DR, CYREG_PRT2_DR
.set LED1__0__HSIOM, CYREG_HSIOM_PORT_SEL2
.set LED1__0__HSIOM_MASK, 0x000000F0
.set LED1__0__HSIOM_SHIFT, 4
.set LED1__0__INTCFG, CYREG_PRT2_INTCFG
.set LED1__0__INTSTAT, CYREG_PRT2_INTSTAT
.set LED1__0__MASK, 0x02
.set LED1__0__PA__CFG0, CYREG_UDB_PA2_CFG0
.set LED1__0__PA__CFG1, CYREG_UDB_PA2_CFG1
.set LED1__0__PA__CFG10, CYREG_UDB_PA2_CFG10
.set LED1__0__PA__CFG11, CYREG_UDB_PA2_CFG11
.set LED1__0__PA__CFG12, CYREG_UDB_PA2_CFG12
.set LED1__0__PA__CFG13, CYREG_UDB_PA2_CFG13
.set LED1__0__PA__CFG14, CYREG_UDB_PA2_CFG14
.set LED1__0__PA__CFG2, CYREG_UDB_PA2_CFG2
.set LED1__0__PA__CFG3, CYREG_UDB_PA2_CFG3
.set LED1__0__PA__CFG4, CYREG_UDB_PA2_CFG4
.set LED1__0__PA__CFG5, CYREG_UDB_PA2_CFG5
.set LED1__0__PA__CFG6, CYREG_UDB_PA2_CFG6
.set LED1__0__PA__CFG7, CYREG_UDB_PA2_CFG7
.set LED1__0__PA__CFG8, CYREG_UDB_PA2_CFG8
.set LED1__0__PA__CFG9, CYREG_UDB_PA2_CFG9
.set LED1__0__PC, CYREG_PRT2_PC
.set LED1__0__PC2, CYREG_PRT2_PC2
.set LED1__0__PORT, 2
.set LED1__0__PS, CYREG_PRT2_PS
.set LED1__0__SHIFT, 1
.set LED1__DR, CYREG_PRT2_DR
.set LED1__INTCFG, CYREG_PRT2_INTCFG
.set LED1__INTSTAT, CYREG_PRT2_INTSTAT
.set LED1__MASK, 0x02
.set LED1__PA__CFG0, CYREG_UDB_PA2_CFG0
.set LED1__PA__CFG1, CYREG_UDB_PA2_CFG1
.set LED1__PA__CFG10, CYREG_UDB_PA2_CFG10
.set LED1__PA__CFG11, CYREG_UDB_PA2_CFG11
.set LED1__PA__CFG12, CYREG_UDB_PA2_CFG12
.set LED1__PA__CFG13, CYREG_UDB_PA2_CFG13
.set LED1__PA__CFG14, CYREG_UDB_PA2_CFG14
.set LED1__PA__CFG2, CYREG_UDB_PA2_CFG2
.set LED1__PA__CFG3, CYREG_UDB_PA2_CFG3
.set LED1__PA__CFG4, CYREG_UDB_PA2_CFG4
.set LED1__PA__CFG5, CYREG_UDB_PA2_CFG5
.set LED1__PA__CFG6, CYREG_UDB_PA2_CFG6
.set LED1__PA__CFG7, CYREG_UDB_PA2_CFG7
.set LED1__PA__CFG8, CYREG_UDB_PA2_CFG8
.set LED1__PA__CFG9, CYREG_UDB_PA2_CFG9
.set LED1__PC, CYREG_PRT2_PC
.set LED1__PC2, CYREG_PRT2_PC2
.set LED1__PORT, 2
.set LED1__PS, CYREG_PRT2_PS
.set LED1__SHIFT, 1

/* Timer1_cy_m0s8_tcpwm_1 */
.set Timer1_cy_m0s8_tcpwm_1__CC, CYREG_TCPWM_CNT0_CC
.set Timer1_cy_m0s8_tcpwm_1__CC_BUFF, CYREG_TCPWM_CNT0_CC_BUFF
.set Timer1_cy_m0s8_tcpwm_1__COUNTER, CYREG_TCPWM_CNT0_COUNTER
.set Timer1_cy_m0s8_tcpwm_1__CTRL, CYREG_TCPWM_CNT0_CTRL
.set Timer1_cy_m0s8_tcpwm_1__INTR, CYREG_TCPWM_CNT0_INTR
.set Timer1_cy_m0s8_tcpwm_1__INTR_MASK, CYREG_TCPWM_CNT0_INTR_MASK
.set Timer1_cy_m0s8_tcpwm_1__INTR_MASKED, CYREG_TCPWM_CNT0_INTR_MASKED
.set Timer1_cy_m0s8_tcpwm_1__INTR_SET, CYREG_TCPWM_CNT0_INTR_SET
.set Timer1_cy_m0s8_tcpwm_1__PERIOD, CYREG_TCPWM_CNT0_PERIOD
.set Timer1_cy_m0s8_tcpwm_1__PERIOD_BUFF, CYREG_TCPWM_CNT0_PERIOD_BUFF
.set Timer1_cy_m0s8_tcpwm_1__STATUS, CYREG_TCPWM_CNT0_STATUS
.set Timer1_cy_m0s8_tcpwm_1__TCPWM_CMD, CYREG_TCPWM_CMD
.set Timer1_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK, 0x01
.set Timer1_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT, 0
.set Timer1_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK, 0x100
.set Timer1_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT, 8
.set Timer1_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK, 0x1000000
.set Timer1_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT, 24
.set Timer1_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK, 0x10000
.set Timer1_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT, 16
.set Timer1_cy_m0s8_tcpwm_1__TCPWM_CTRL, CYREG_TCPWM_CTRL
.set Timer1_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK, 0x01
.set Timer1_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT, 0
.set Timer1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE, CYREG_TCPWM_INTR_CAUSE
.set Timer1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK, 0x01
.set Timer1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT, 0
.set Timer1_cy_m0s8_tcpwm_1__TCPWM_NUMBER, 0
.set Timer1_cy_m0s8_tcpwm_1__TR_CTRL0, CYREG_TCPWM_CNT0_TR_CTRL0
.set Timer1_cy_m0s8_tcpwm_1__TR_CTRL1, CYREG_TCPWM_CNT0_TR_CTRL1
.set Timer1_cy_m0s8_tcpwm_1__TR_CTRL2, CYREG_TCPWM_CNT0_TR_CTRL2

/* UART_1_rx */
.set UART_1_rx__0__DM__MASK, 0x07
.set UART_1_rx__0__DM__SHIFT, 0
.set UART_1_rx__0__DR, CYREG_PRT4_DR
.set UART_1_rx__0__HSIOM, CYREG_HSIOM_PORT_SEL4
.set UART_1_rx__0__HSIOM_MASK, 0x0000000F
.set UART_1_rx__0__HSIOM_SHIFT, 0
.set UART_1_rx__0__INTCFG, CYREG_PRT4_INTCFG
.set UART_1_rx__0__INTSTAT, CYREG_PRT4_INTSTAT
.set UART_1_rx__0__MASK, 0x01
.set UART_1_rx__0__PC, CYREG_PRT4_PC
.set UART_1_rx__0__PC2, CYREG_PRT4_PC2
.set UART_1_rx__0__PORT, 4
.set UART_1_rx__0__PS, CYREG_PRT4_PS
.set UART_1_rx__0__SHIFT, 0
.set UART_1_rx__DR, CYREG_PRT4_DR
.set UART_1_rx__INTCFG, CYREG_PRT4_INTCFG
.set UART_1_rx__INTSTAT, CYREG_PRT4_INTSTAT
.set UART_1_rx__MASK, 0x01
.set UART_1_rx__PC, CYREG_PRT4_PC
.set UART_1_rx__PC2, CYREG_PRT4_PC2
.set UART_1_rx__PORT, 4
.set UART_1_rx__PS, CYREG_PRT4_PS
.set UART_1_rx__SHIFT, 0

/* UART_1_SCB */
.set UART_1_SCB__BIST_CONTROL, CYREG_SCB0_BIST_CONTROL
.set UART_1_SCB__BIST_DATA, CYREG_SCB0_BIST_DATA
.set UART_1_SCB__CTRL, CYREG_SCB0_CTRL
.set UART_1_SCB__EZ_DATA00, CYREG_SCB0_EZ_DATA00
.set UART_1_SCB__EZ_DATA01, CYREG_SCB0_EZ_DATA01
.set UART_1_SCB__EZ_DATA02, CYREG_SCB0_EZ_DATA02
.set UART_1_SCB__EZ_DATA03, CYREG_SCB0_EZ_DATA03
.set UART_1_SCB__EZ_DATA04, CYREG_SCB0_EZ_DATA04
.set UART_1_SCB__EZ_DATA05, CYREG_SCB0_EZ_DATA05
.set UART_1_SCB__EZ_DATA06, CYREG_SCB0_EZ_DATA06
.set UART_1_SCB__EZ_DATA07, CYREG_SCB0_EZ_DATA07
.set UART_1_SCB__EZ_DATA08, CYREG_SCB0_EZ_DATA08
.set UART_1_SCB__EZ_DATA09, CYREG_SCB0_EZ_DATA09
.set UART_1_SCB__EZ_DATA10, CYREG_SCB0_EZ_DATA10
.set UART_1_SCB__EZ_DATA11, CYREG_SCB0_EZ_DATA11
.set UART_1_SCB__EZ_DATA12, CYREG_SCB0_EZ_DATA12
.set UART_1_SCB__EZ_DATA13, CYREG_SCB0_EZ_DATA13
.set UART_1_SCB__EZ_DATA14, CYREG_SCB0_EZ_DATA14
.set UART_1_SCB__EZ_DATA15, CYREG_SCB0_EZ_DATA15
.set UART_1_SCB__EZ_DATA16, CYREG_SCB0_EZ_DATA16
.set UART_1_SCB__EZ_DATA17, CYREG_SCB0_EZ_DATA17
.set UART_1_SCB__EZ_DATA18, CYREG_SCB0_EZ_DATA18
.set UART_1_SCB__EZ_DATA19, CYREG_SCB0_EZ_DATA19
.set UART_1_SCB__EZ_DATA20, CYREG_SCB0_EZ_DATA20
.set UART_1_SCB__EZ_DATA21, CYREG_SCB0_EZ_DATA21
.set UART_1_SCB__EZ_DATA22, CYREG_SCB0_EZ_DATA22
.set UART_1_SCB__EZ_DATA23, CYREG_SCB0_EZ_DATA23
.set UART_1_SCB__EZ_DATA24, CYREG_SCB0_EZ_DATA24
.set UART_1_SCB__EZ_DATA25, CYREG_SCB0_EZ_DATA25
.set UART_1_SCB__EZ_DATA26, CYREG_SCB0_EZ_DATA26
.set UART_1_SCB__EZ_DATA27, CYREG_SCB0_EZ_DATA27
.set UART_1_SCB__EZ_DATA28, CYREG_SCB0_EZ_DATA28
.set UART_1_SCB__EZ_DATA29, CYREG_SCB0_EZ_DATA29
.set UART_1_SCB__EZ_DATA30, CYREG_SCB0_EZ_DATA30
.set UART_1_SCB__EZ_DATA31, CYREG_SCB0_EZ_DATA31
.set UART_1_SCB__I2C_CFG, CYREG_SCB0_I2C_CFG
.set UART_1_SCB__I2C_CTRL, CYREG_SCB0_I2C_CTRL
.set UART_1_SCB__I2C_M_CMD, CYREG_SCB0_I2C_M_CMD
.set UART_1_SCB__I2C_S_CMD, CYREG_SCB0_I2C_S_CMD
.set UART_1_SCB__I2C_STATUS, CYREG_SCB0_I2C_STATUS
.set UART_1_SCB__INTR_CAUSE, CYREG_SCB0_INTR_CAUSE
.set UART_1_SCB__INTR_I2C_EC, CYREG_SCB0_INTR_I2C_EC
.set UART_1_SCB__INTR_I2C_EC_MASK, CYREG_SCB0_INTR_I2C_EC_MASK
.set UART_1_SCB__INTR_I2C_EC_MASKED, CYREG_SCB0_INTR_I2C_EC_MASKED
.set UART_1_SCB__INTR_M, CYREG_SCB0_INTR_M
.set UART_1_SCB__INTR_M_MASK, CYREG_SCB0_INTR_M_MASK
.set UART_1_SCB__INTR_M_MASKED, CYREG_SCB0_INTR_M_MASKED
.set UART_1_SCB__INTR_M_SET, CYREG_SCB0_INTR_M_SET
.set UART_1_SCB__INTR_RX, CYREG_SCB0_INTR_RX
.set UART_1_SCB__INTR_RX_MASK, CYREG_SCB0_INTR_RX_MASK
.set UART_1_SCB__INTR_RX_MASKED, CYREG_SCB0_INTR_RX_MASKED
.set UART_1_SCB__INTR_RX_SET, CYREG_SCB0_INTR_RX_SET
.set UART_1_SCB__INTR_S, CYREG_SCB0_INTR_S
.set UART_1_SCB__INTR_S_MASK, CYREG_SCB0_INTR_S_MASK
.set UART_1_SCB__INTR_S_MASKED, CYREG_SCB0_INTR_S_MASKED
.set UART_1_SCB__INTR_S_SET, CYREG_SCB0_INTR_S_SET
.set UART_1_SCB__INTR_SPI_EC, CYREG_SCB0_INTR_SPI_EC
.set UART_1_SCB__INTR_SPI_EC_MASK, CYREG_SCB0_INTR_SPI_EC_MASK
.set UART_1_SCB__INTR_SPI_EC_MASKED, CYREG_SCB0_INTR_SPI_EC_MASKED
.set UART_1_SCB__INTR_TX, CYREG_SCB0_INTR_TX
.set UART_1_SCB__INTR_TX_MASK, CYREG_SCB0_INTR_TX_MASK
.set UART_1_SCB__INTR_TX_MASKED, CYREG_SCB0_INTR_TX_MASKED
.set UART_1_SCB__INTR_TX_SET, CYREG_SCB0_INTR_TX_SET
.set UART_1_SCB__RX_CTRL, CYREG_SCB0_RX_CTRL
.set UART_1_SCB__RX_FIFO_CTRL, CYREG_SCB0_RX_FIFO_CTRL
.set UART_1_SCB__RX_FIFO_RD, CYREG_SCB0_RX_FIFO_RD
.set UART_1_SCB__RX_FIFO_RD_SILENT, CYREG_SCB0_RX_FIFO_RD_SILENT
.set UART_1_SCB__RX_FIFO_STATUS, CYREG_SCB0_RX_FIFO_STATUS
.set UART_1_SCB__RX_MATCH, CYREG_SCB0_RX_MATCH
.set UART_1_SCB__SPI_CTRL, CYREG_SCB0_SPI_CTRL
.set UART_1_SCB__SPI_STATUS, CYREG_SCB0_SPI_STATUS
.set UART_1_SCB__STATUS, CYREG_SCB0_STATUS
.set UART_1_SCB__TX_CTRL, CYREG_SCB0_TX_CTRL
.set UART_1_SCB__TX_FIFO_CTRL, CYREG_SCB0_TX_FIFO_CTRL
.set UART_1_SCB__TX_FIFO_STATUS, CYREG_SCB0_TX_FIFO_STATUS
.set UART_1_SCB__TX_FIFO_WR, CYREG_SCB0_TX_FIFO_WR
.set UART_1_SCB__UART_CTRL, CYREG_SCB0_UART_CTRL
.set UART_1_SCB__UART_RX_CTRL, CYREG_SCB0_UART_RX_CTRL
.set UART_1_SCB__UART_RX_STATUS, CYREG_SCB0_UART_RX_STATUS
.set UART_1_SCB__UART_TX_CTRL, CYREG_SCB0_UART_TX_CTRL

/* UART_1_SCBCLK */
.set UART_1_SCBCLK__DIVIDER_MASK, 0x0000FFFF
.set UART_1_SCBCLK__ENABLE, CYREG_CLK_DIVIDER_A00
.set UART_1_SCBCLK__ENABLE_MASK, 0x80000000
.set UART_1_SCBCLK__MASK, 0x80000000
.set UART_1_SCBCLK__REGISTER, CYREG_CLK_DIVIDER_A00

/* UART_1_tx */
.set UART_1_tx__0__DM__MASK, 0x38
.set UART_1_tx__0__DM__SHIFT, 3
.set UART_1_tx__0__DR, CYREG_PRT4_DR
.set UART_1_tx__0__HSIOM, CYREG_HSIOM_PORT_SEL4
.set UART_1_tx__0__HSIOM_MASK, 0x000000F0
.set UART_1_tx__0__HSIOM_SHIFT, 4
.set UART_1_tx__0__INTCFG, CYREG_PRT4_INTCFG
.set UART_1_tx__0__INTSTAT, CYREG_PRT4_INTSTAT
.set UART_1_tx__0__MASK, 0x02
.set UART_1_tx__0__PC, CYREG_PRT4_PC
.set UART_1_tx__0__PC2, CYREG_PRT4_PC2
.set UART_1_tx__0__PORT, 4
.set UART_1_tx__0__PS, CYREG_PRT4_PS
.set UART_1_tx__0__SHIFT, 1
.set UART_1_tx__DR, CYREG_PRT4_DR
.set UART_1_tx__INTCFG, CYREG_PRT4_INTCFG
.set UART_1_tx__INTSTAT, CYREG_PRT4_INTSTAT
.set UART_1_tx__MASK, 0x02
.set UART_1_tx__PC, CYREG_PRT4_PC
.set UART_1_tx__PC2, CYREG_PRT4_PC2
.set UART_1_tx__PORT, 4
.set UART_1_tx__PS, CYREG_PRT4_PS
.set UART_1_tx__SHIFT, 1

/* Clock_1 */
.set Clock_1__DIVIDER_MASK, 0x0000FFFF
.set Clock_1__ENABLE, CYREG_CLK_DIVIDER_C00
.set Clock_1__ENABLE_MASK, 0x80000000
.set Clock_1__MASK, 0x80000000
.set Clock_1__REGISTER, CYREG_CLK_DIVIDER_C00

/* Clock_2 */
.set Clock_2__DIVIDER_MASK, 0x0000FFFF
.set Clock_2__ENABLE, CYREG_CLK_DIVIDER_B00
.set Clock_2__ENABLE_MASK, 0x80000000
.set Clock_2__MASK, 0x80000000
.set Clock_2__REGISTER, CYREG_CLK_DIVIDER_B00

/* Servo_1 */
.set Servo_1__0__DM__MASK, 0x1C0
.set Servo_1__0__DM__SHIFT, 6
.set Servo_1__0__DR, CYREG_PRT2_DR
.set Servo_1__0__HSIOM, CYREG_HSIOM_PORT_SEL2
.set Servo_1__0__HSIOM_MASK, 0x00000F00
.set Servo_1__0__HSIOM_SHIFT, 8
.set Servo_1__0__INTCFG, CYREG_PRT2_INTCFG
.set Servo_1__0__INTSTAT, CYREG_PRT2_INTSTAT
.set Servo_1__0__MASK, 0x04
.set Servo_1__0__OUT_SEL, CYREG_UDB_PA2_CFG10
.set Servo_1__0__OUT_SEL_SHIFT, 4
.set Servo_1__0__OUT_SEL_VAL, 1
.set Servo_1__0__PA__CFG0, CYREG_UDB_PA2_CFG0
.set Servo_1__0__PA__CFG1, CYREG_UDB_PA2_CFG1
.set Servo_1__0__PA__CFG10, CYREG_UDB_PA2_CFG10
.set Servo_1__0__PA__CFG11, CYREG_UDB_PA2_CFG11
.set Servo_1__0__PA__CFG12, CYREG_UDB_PA2_CFG12
.set Servo_1__0__PA__CFG13, CYREG_UDB_PA2_CFG13
.set Servo_1__0__PA__CFG14, CYREG_UDB_PA2_CFG14
.set Servo_1__0__PA__CFG2, CYREG_UDB_PA2_CFG2
.set Servo_1__0__PA__CFG3, CYREG_UDB_PA2_CFG3
.set Servo_1__0__PA__CFG4, CYREG_UDB_PA2_CFG4
.set Servo_1__0__PA__CFG5, CYREG_UDB_PA2_CFG5
.set Servo_1__0__PA__CFG6, CYREG_UDB_PA2_CFG6
.set Servo_1__0__PA__CFG7, CYREG_UDB_PA2_CFG7
.set Servo_1__0__PA__CFG8, CYREG_UDB_PA2_CFG8
.set Servo_1__0__PA__CFG9, CYREG_UDB_PA2_CFG9
.set Servo_1__0__PC, CYREG_PRT2_PC
.set Servo_1__0__PC2, CYREG_PRT2_PC2
.set Servo_1__0__PORT, 2
.set Servo_1__0__PS, CYREG_PRT2_PS
.set Servo_1__0__SHIFT, 2
.set Servo_1__DR, CYREG_PRT2_DR
.set Servo_1__INTCFG, CYREG_PRT2_INTCFG
.set Servo_1__INTSTAT, CYREG_PRT2_INTSTAT
.set Servo_1__MASK, 0x04
.set Servo_1__PA__CFG0, CYREG_UDB_PA2_CFG0
.set Servo_1__PA__CFG1, CYREG_UDB_PA2_CFG1
.set Servo_1__PA__CFG10, CYREG_UDB_PA2_CFG10
.set Servo_1__PA__CFG11, CYREG_UDB_PA2_CFG11
.set Servo_1__PA__CFG12, CYREG_UDB_PA2_CFG12
.set Servo_1__PA__CFG13, CYREG_UDB_PA2_CFG13
.set Servo_1__PA__CFG14, CYREG_UDB_PA2_CFG14
.set Servo_1__PA__CFG2, CYREG_UDB_PA2_CFG2
.set Servo_1__PA__CFG3, CYREG_UDB_PA2_CFG3
.set Servo_1__PA__CFG4, CYREG_UDB_PA2_CFG4
.set Servo_1__PA__CFG5, CYREG_UDB_PA2_CFG5
.set Servo_1__PA__CFG6, CYREG_UDB_PA2_CFG6
.set Servo_1__PA__CFG7, CYREG_UDB_PA2_CFG7
.set Servo_1__PA__CFG8, CYREG_UDB_PA2_CFG8
.set Servo_1__PA__CFG9, CYREG_UDB_PA2_CFG9
.set Servo_1__PC, CYREG_PRT2_PC
.set Servo_1__PC2, CYREG_PRT2_PC2
.set Servo_1__PORT, 2
.set Servo_1__PS, CYREG_PRT2_PS
.set Servo_1__SHIFT, 2

/* ISR_Bnt1 */
.set ISR_Bnt1__INTC_CLR_EN_REG, CYREG_CM0_ICER
.set ISR_Bnt1__INTC_CLR_PD_REG, CYREG_CM0_ICPR
.set ISR_Bnt1__INTC_MASK, 0x04
.set ISR_Bnt1__INTC_NUMBER, 2
.set ISR_Bnt1__INTC_PRIOR_MASK, 0xC00000
.set ISR_Bnt1__INTC_PRIOR_NUM, 3
.set ISR_Bnt1__INTC_PRIOR_REG, CYREG_CM0_IPR0
.set ISR_Bnt1__INTC_SET_EN_REG, CYREG_CM0_ISER
.set ISR_Bnt1__INTC_SET_PD_REG, CYREG_CM0_ISPR

/* ISR_Btn0 */
.set ISR_Btn0__INTC_CLR_EN_REG, CYREG_CM0_ICER
.set ISR_Btn0__INTC_CLR_PD_REG, CYREG_CM0_ICPR
.set ISR_Btn0__INTC_MASK, 0x08
.set ISR_Btn0__INTC_NUMBER, 3
.set ISR_Btn0__INTC_PRIOR_MASK, 0xC0000000
.set ISR_Btn0__INTC_PRIOR_NUM, 3
.set ISR_Btn0__INTC_PRIOR_REG, CYREG_CM0_IPR0
.set ISR_Btn0__INTC_SET_EN_REG, CYREG_CM0_ISER
.set ISR_Btn0__INTC_SET_PD_REG, CYREG_CM0_ISPR

/* PWM_Servo_cy_m0s8_tcpwm_1 */
.set PWM_Servo_cy_m0s8_tcpwm_1__CC, CYREG_TCPWM_CNT1_CC
.set PWM_Servo_cy_m0s8_tcpwm_1__CC_BUFF, CYREG_TCPWM_CNT1_CC_BUFF
.set PWM_Servo_cy_m0s8_tcpwm_1__COUNTER, CYREG_TCPWM_CNT1_COUNTER
.set PWM_Servo_cy_m0s8_tcpwm_1__CTRL, CYREG_TCPWM_CNT1_CTRL
.set PWM_Servo_cy_m0s8_tcpwm_1__INTR, CYREG_TCPWM_CNT1_INTR
.set PWM_Servo_cy_m0s8_tcpwm_1__INTR_MASK, CYREG_TCPWM_CNT1_INTR_MASK
.set PWM_Servo_cy_m0s8_tcpwm_1__INTR_MASKED, CYREG_TCPWM_CNT1_INTR_MASKED
.set PWM_Servo_cy_m0s8_tcpwm_1__INTR_SET, CYREG_TCPWM_CNT1_INTR_SET
.set PWM_Servo_cy_m0s8_tcpwm_1__PERIOD, CYREG_TCPWM_CNT1_PERIOD
.set PWM_Servo_cy_m0s8_tcpwm_1__PERIOD_BUFF, CYREG_TCPWM_CNT1_PERIOD_BUFF
.set PWM_Servo_cy_m0s8_tcpwm_1__STATUS, CYREG_TCPWM_CNT1_STATUS
.set PWM_Servo_cy_m0s8_tcpwm_1__TCPWM_CMD, CYREG_TCPWM_CMD
.set PWM_Servo_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK, 0x02
.set PWM_Servo_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT, 1
.set PWM_Servo_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK, 0x200
.set PWM_Servo_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT, 9
.set PWM_Servo_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK, 0x2000000
.set PWM_Servo_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT, 25
.set PWM_Servo_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK, 0x20000
.set PWM_Servo_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT, 17
.set PWM_Servo_cy_m0s8_tcpwm_1__TCPWM_CTRL, CYREG_TCPWM_CTRL
.set PWM_Servo_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK, 0x02
.set PWM_Servo_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT, 1
.set PWM_Servo_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE, CYREG_TCPWM_INTR_CAUSE
.set PWM_Servo_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK, 0x02
.set PWM_Servo_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT, 1
.set PWM_Servo_cy_m0s8_tcpwm_1__TCPWM_NUMBER, 1
.set PWM_Servo_cy_m0s8_tcpwm_1__TR_CTRL0, CYREG_TCPWM_CNT1_TR_CTRL0
.set PWM_Servo_cy_m0s8_tcpwm_1__TR_CTRL1, CYREG_TCPWM_CNT1_TR_CTRL1
.set PWM_Servo_cy_m0s8_tcpwm_1__TR_CTRL2, CYREG_TCPWM_CNT1_TR_CTRL2

/* ISR_Timer1 */
.set ISR_Timer1__INTC_CLR_EN_REG, CYREG_CM0_ICER
.set ISR_Timer1__INTC_CLR_PD_REG, CYREG_CM0_ICPR
.set ISR_Timer1__INTC_MASK, 0x10000
.set ISR_Timer1__INTC_NUMBER, 16
.set ISR_Timer1__INTC_PRIOR_MASK, 0xC0
.set ISR_Timer1__INTC_PRIOR_NUM, 3
.set ISR_Timer1__INTC_PRIOR_REG, CYREG_CM0_IPR4
.set ISR_Timer1__INTC_SET_EN_REG, CYREG_CM0_ISER
.set ISR_Timer1__INTC_SET_PD_REG, CYREG_CM0_ISPR

/* ISR_UART_Rx */
.set ISR_UART_Rx__INTC_CLR_EN_REG, CYREG_CM0_ICER
.set ISR_UART_Rx__INTC_CLR_PD_REG, CYREG_CM0_ICPR
.set ISR_UART_Rx__INTC_MASK, 0x400
.set ISR_UART_Rx__INTC_NUMBER, 10
.set ISR_UART_Rx__INTC_PRIOR_MASK, 0xC00000
.set ISR_UART_Rx__INTC_PRIOR_NUM, 3
.set ISR_UART_Rx__INTC_PRIOR_REG, CYREG_CM0_IPR2
.set ISR_UART_Rx__INTC_SET_EN_REG, CYREG_CM0_ISER
.set ISR_UART_Rx__INTC_SET_PD_REG, CYREG_CM0_ISPR

/* Miscellaneous */
.set CYDEV_BCLK__HFCLK__HZ, 24000000
.set CYDEV_BCLK__HFCLK__KHZ, 24000
.set CYDEV_BCLK__HFCLK__MHZ, 24
.set CYDEV_BCLK__SYSCLK__HZ, 24000000
.set CYDEV_BCLK__SYSCLK__KHZ, 24000
.set CYDEV_BCLK__SYSCLK__MHZ, 24
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PANTHER, 4
.set CYDEV_CHIP_DIE_PSOC4A, 2
.set CYDEV_CHIP_DIE_PSOC5LP, 5
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC4
.set CYDEV_CHIP_JTAG_ID, 0x04C81193
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 2
.set CYDEV_CHIP_MEMBER_4D, 3
.set CYDEV_CHIP_MEMBER_5A, 4
.set CYDEV_CHIP_MEMBER_5B, 5
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_4A
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_MEMBER_USED
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PANTHER_ES0, 0
.set CYDEV_CHIP_REV_PANTHER_ES1, 1
.set CYDEV_CHIP_REV_PANTHER_PRODUCTION, 1
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4D_ES0, 0
.set CYDEV_CHIP_REVISION_4D_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_4A_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REVISION_USED
.set CYDEV_CONFIG_READ_ACCELERATOR, 1
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowButWarn
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_DEBUG_PROTECT_KILL, 4
.set CYDEV_DEBUG_PROTECT_OPEN, 1
.set CYDEV_DEBUG_PROTECT, CYDEV_DEBUG_PROTECT_OPEN
.set CYDEV_DEBUG_PROTECT_PROTECTED, 2
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_HEAP_SIZE, 0x0100
.set CYDEV_PROJ_TYPE, 2
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_STACK_SIZE, 0x0400
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 1
.set CYDEV_VDDA_MV, 3300
.set CYDEV_VDDD_MV, 3300
.set CYIPBLOCK_M0S8_CTBM_VERSION, 0
.set CYIPBLOCK_m0s8cpuss_VERSION, 0
.set CYIPBLOCK_m0s8csd_VERSION, 0
.set CYIPBLOCK_m0s8gpio2_VERSION, 0
.set CYIPBLOCK_m0s8hsiom4a_VERSION, 0
.set CYIPBLOCK_m0s8lcd_VERSION, 0
.set CYIPBLOCK_m0s8lpcomp_VERSION, 0
.set CYIPBLOCK_m0s8pclk_VERSION, 0
.set CYIPBLOCK_m0s8sar_VERSION, 0
.set CYIPBLOCK_m0s8scb_VERSION, 0
.set CYIPBLOCK_m0s8srssv2_VERSION, 1
.set CYIPBLOCK_m0s8tcpwm_VERSION, 0
.set CYIPBLOCK_m0s8udbif_VERSION, 0
.set CYIPBLOCK_S8_GPIO_VERSION, 2
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif
