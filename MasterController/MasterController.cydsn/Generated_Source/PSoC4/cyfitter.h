#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include <cydevice_trm.h>

/* SW */
#define SW__0__DM__MASK 0xE00000u
#define SW__0__DM__SHIFT 21
#define SW__0__DR CYREG_PRT0_DR
#define SW__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define SW__0__HSIOM_MASK 0xF0000000u
#define SW__0__HSIOM_SHIFT 28u
#define SW__0__INTCFG CYREG_PRT0_INTCFG
#define SW__0__INTSTAT CYREG_PRT0_INTSTAT
#define SW__0__MASK 0x80u
#define SW__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define SW__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define SW__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define SW__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define SW__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define SW__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define SW__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define SW__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define SW__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define SW__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define SW__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define SW__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define SW__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define SW__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define SW__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define SW__0__PC CYREG_PRT0_PC
#define SW__0__PC2 CYREG_PRT0_PC2
#define SW__0__PORT 0u
#define SW__0__PS CYREG_PRT0_PS
#define SW__0__SHIFT 7
#define SW__DR CYREG_PRT0_DR
#define SW__INTCFG CYREG_PRT0_INTCFG
#define SW__INTSTAT CYREG_PRT0_INTSTAT
#define SW__MASK 0x80u
#define SW__PA__CFG0 CYREG_UDB_PA0_CFG0
#define SW__PA__CFG1 CYREG_UDB_PA0_CFG1
#define SW__PA__CFG10 CYREG_UDB_PA0_CFG10
#define SW__PA__CFG11 CYREG_UDB_PA0_CFG11
#define SW__PA__CFG12 CYREG_UDB_PA0_CFG12
#define SW__PA__CFG13 CYREG_UDB_PA0_CFG13
#define SW__PA__CFG14 CYREG_UDB_PA0_CFG14
#define SW__PA__CFG2 CYREG_UDB_PA0_CFG2
#define SW__PA__CFG3 CYREG_UDB_PA0_CFG3
#define SW__PA__CFG4 CYREG_UDB_PA0_CFG4
#define SW__PA__CFG5 CYREG_UDB_PA0_CFG5
#define SW__PA__CFG6 CYREG_UDB_PA0_CFG6
#define SW__PA__CFG7 CYREG_UDB_PA0_CFG7
#define SW__PA__CFG8 CYREG_UDB_PA0_CFG8
#define SW__PA__CFG9 CYREG_UDB_PA0_CFG9
#define SW__PC CYREG_PRT0_PC
#define SW__PC2 CYREG_PRT0_PC2
#define SW__PORT 0u
#define SW__PS CYREG_PRT0_PS
#define SW__SHIFT 7

/* LED */
#define LED__0__DM__MASK 0x1C0000u
#define LED__0__DM__SHIFT 18
#define LED__0__DR CYREG_PRT1_DR
#define LED__0__HSIOM CYREG_HSIOM_PORT_SEL1
#define LED__0__HSIOM_MASK 0x0F000000u
#define LED__0__HSIOM_SHIFT 24u
#define LED__0__INTCFG CYREG_PRT1_INTCFG
#define LED__0__INTSTAT CYREG_PRT1_INTSTAT
#define LED__0__MASK 0x40u
#define LED__0__PA__CFG0 CYREG_UDB_PA1_CFG0
#define LED__0__PA__CFG1 CYREG_UDB_PA1_CFG1
#define LED__0__PA__CFG10 CYREG_UDB_PA1_CFG10
#define LED__0__PA__CFG11 CYREG_UDB_PA1_CFG11
#define LED__0__PA__CFG12 CYREG_UDB_PA1_CFG12
#define LED__0__PA__CFG13 CYREG_UDB_PA1_CFG13
#define LED__0__PA__CFG14 CYREG_UDB_PA1_CFG14
#define LED__0__PA__CFG2 CYREG_UDB_PA1_CFG2
#define LED__0__PA__CFG3 CYREG_UDB_PA1_CFG3
#define LED__0__PA__CFG4 CYREG_UDB_PA1_CFG4
#define LED__0__PA__CFG5 CYREG_UDB_PA1_CFG5
#define LED__0__PA__CFG6 CYREG_UDB_PA1_CFG6
#define LED__0__PA__CFG7 CYREG_UDB_PA1_CFG7
#define LED__0__PA__CFG8 CYREG_UDB_PA1_CFG8
#define LED__0__PA__CFG9 CYREG_UDB_PA1_CFG9
#define LED__0__PC CYREG_PRT1_PC
#define LED__0__PC2 CYREG_PRT1_PC2
#define LED__0__PORT 1u
#define LED__0__PS CYREG_PRT1_PS
#define LED__0__SHIFT 6
#define LED__DR CYREG_PRT1_DR
#define LED__INTCFG CYREG_PRT1_INTCFG
#define LED__INTSTAT CYREG_PRT1_INTSTAT
#define LED__MASK 0x40u
#define LED__PA__CFG0 CYREG_UDB_PA1_CFG0
#define LED__PA__CFG1 CYREG_UDB_PA1_CFG1
#define LED__PA__CFG10 CYREG_UDB_PA1_CFG10
#define LED__PA__CFG11 CYREG_UDB_PA1_CFG11
#define LED__PA__CFG12 CYREG_UDB_PA1_CFG12
#define LED__PA__CFG13 CYREG_UDB_PA1_CFG13
#define LED__PA__CFG14 CYREG_UDB_PA1_CFG14
#define LED__PA__CFG2 CYREG_UDB_PA1_CFG2
#define LED__PA__CFG3 CYREG_UDB_PA1_CFG3
#define LED__PA__CFG4 CYREG_UDB_PA1_CFG4
#define LED__PA__CFG5 CYREG_UDB_PA1_CFG5
#define LED__PA__CFG6 CYREG_UDB_PA1_CFG6
#define LED__PA__CFG7 CYREG_UDB_PA1_CFG7
#define LED__PA__CFG8 CYREG_UDB_PA1_CFG8
#define LED__PA__CFG9 CYREG_UDB_PA1_CFG9
#define LED__PC CYREG_PRT1_PC
#define LED__PC2 CYREG_PRT1_PC2
#define LED__PORT 1u
#define LED__PS CYREG_PRT1_PS
#define LED__SHIFT 6

/* MISO */
#define MISO__0__DM__MASK 0x38000u
#define MISO__0__DM__SHIFT 15
#define MISO__0__DR CYREG_PRT0_DR
#define MISO__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define MISO__0__HSIOM_MASK 0x00F00000u
#define MISO__0__HSIOM_SHIFT 20u
#define MISO__0__INTCFG CYREG_PRT0_INTCFG
#define MISO__0__INTSTAT CYREG_PRT0_INTSTAT
#define MISO__0__MASK 0x20u
#define MISO__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define MISO__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define MISO__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define MISO__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define MISO__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define MISO__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define MISO__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define MISO__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define MISO__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define MISO__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define MISO__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define MISO__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define MISO__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define MISO__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define MISO__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define MISO__0__PC CYREG_PRT0_PC
#define MISO__0__PC2 CYREG_PRT0_PC2
#define MISO__0__PORT 0u
#define MISO__0__PS CYREG_PRT0_PS
#define MISO__0__SHIFT 5
#define MISO__DR CYREG_PRT0_DR
#define MISO__INTCFG CYREG_PRT0_INTCFG
#define MISO__INTSTAT CYREG_PRT0_INTSTAT
#define MISO__MASK 0x20u
#define MISO__PA__CFG0 CYREG_UDB_PA0_CFG0
#define MISO__PA__CFG1 CYREG_UDB_PA0_CFG1
#define MISO__PA__CFG10 CYREG_UDB_PA0_CFG10
#define MISO__PA__CFG11 CYREG_UDB_PA0_CFG11
#define MISO__PA__CFG12 CYREG_UDB_PA0_CFG12
#define MISO__PA__CFG13 CYREG_UDB_PA0_CFG13
#define MISO__PA__CFG14 CYREG_UDB_PA0_CFG14
#define MISO__PA__CFG2 CYREG_UDB_PA0_CFG2
#define MISO__PA__CFG3 CYREG_UDB_PA0_CFG3
#define MISO__PA__CFG4 CYREG_UDB_PA0_CFG4
#define MISO__PA__CFG5 CYREG_UDB_PA0_CFG5
#define MISO__PA__CFG6 CYREG_UDB_PA0_CFG6
#define MISO__PA__CFG7 CYREG_UDB_PA0_CFG7
#define MISO__PA__CFG8 CYREG_UDB_PA0_CFG8
#define MISO__PA__CFG9 CYREG_UDB_PA0_CFG9
#define MISO__PC CYREG_PRT0_PC
#define MISO__PC2 CYREG_PRT0_PC2
#define MISO__PORT 0u
#define MISO__PS CYREG_PRT0_PS
#define MISO__SHIFT 5

/* MOSI */
#define MOSI__0__DM__MASK 0x7000u
#define MOSI__0__DM__SHIFT 12
#define MOSI__0__DR CYREG_PRT0_DR
#define MOSI__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define MOSI__0__HSIOM_MASK 0x000F0000u
#define MOSI__0__HSIOM_SHIFT 16u
#define MOSI__0__INTCFG CYREG_PRT0_INTCFG
#define MOSI__0__INTSTAT CYREG_PRT0_INTSTAT
#define MOSI__0__MASK 0x10u
#define MOSI__0__OUT_SEL CYREG_UDB_PA0_CFG10
#define MOSI__0__OUT_SEL_SHIFT 8u
#define MOSI__0__OUT_SEL_VAL 2u
#define MOSI__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define MOSI__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define MOSI__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define MOSI__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define MOSI__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define MOSI__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define MOSI__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define MOSI__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define MOSI__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define MOSI__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define MOSI__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define MOSI__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define MOSI__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define MOSI__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define MOSI__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define MOSI__0__PC CYREG_PRT0_PC
#define MOSI__0__PC2 CYREG_PRT0_PC2
#define MOSI__0__PORT 0u
#define MOSI__0__PS CYREG_PRT0_PS
#define MOSI__0__SHIFT 4
#define MOSI__DR CYREG_PRT0_DR
#define MOSI__INTCFG CYREG_PRT0_INTCFG
#define MOSI__INTSTAT CYREG_PRT0_INTSTAT
#define MOSI__MASK 0x10u
#define MOSI__PA__CFG0 CYREG_UDB_PA0_CFG0
#define MOSI__PA__CFG1 CYREG_UDB_PA0_CFG1
#define MOSI__PA__CFG10 CYREG_UDB_PA0_CFG10
#define MOSI__PA__CFG11 CYREG_UDB_PA0_CFG11
#define MOSI__PA__CFG12 CYREG_UDB_PA0_CFG12
#define MOSI__PA__CFG13 CYREG_UDB_PA0_CFG13
#define MOSI__PA__CFG14 CYREG_UDB_PA0_CFG14
#define MOSI__PA__CFG2 CYREG_UDB_PA0_CFG2
#define MOSI__PA__CFG3 CYREG_UDB_PA0_CFG3
#define MOSI__PA__CFG4 CYREG_UDB_PA0_CFG4
#define MOSI__PA__CFG5 CYREG_UDB_PA0_CFG5
#define MOSI__PA__CFG6 CYREG_UDB_PA0_CFG6
#define MOSI__PA__CFG7 CYREG_UDB_PA0_CFG7
#define MOSI__PA__CFG8 CYREG_UDB_PA0_CFG8
#define MOSI__PA__CFG9 CYREG_UDB_PA0_CFG9
#define MOSI__PC CYREG_PRT0_PC
#define MOSI__PC2 CYREG_PRT0_PC2
#define MOSI__PORT 0u
#define MOSI__PS CYREG_PRT0_PS
#define MOSI__SHIFT 4

/* SCLK */
#define SCLK__0__DM__MASK 0x1C0000u
#define SCLK__0__DM__SHIFT 18
#define SCLK__0__DR CYREG_PRT0_DR
#define SCLK__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define SCLK__0__HSIOM_MASK 0x0F000000u
#define SCLK__0__HSIOM_SHIFT 24u
#define SCLK__0__INTCFG CYREG_PRT0_INTCFG
#define SCLK__0__INTSTAT CYREG_PRT0_INTSTAT
#define SCLK__0__MASK 0x40u
#define SCLK__0__OUT_SEL CYREG_UDB_PA0_CFG10
#define SCLK__0__OUT_SEL_SHIFT 12u
#define SCLK__0__OUT_SEL_VAL 1u
#define SCLK__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define SCLK__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define SCLK__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define SCLK__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define SCLK__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define SCLK__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define SCLK__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define SCLK__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define SCLK__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define SCLK__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define SCLK__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define SCLK__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define SCLK__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define SCLK__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define SCLK__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define SCLK__0__PC CYREG_PRT0_PC
#define SCLK__0__PC2 CYREG_PRT0_PC2
#define SCLK__0__PORT 0u
#define SCLK__0__PS CYREG_PRT0_PS
#define SCLK__0__SHIFT 6
#define SCLK__DR CYREG_PRT0_DR
#define SCLK__INTCFG CYREG_PRT0_INTCFG
#define SCLK__INTSTAT CYREG_PRT0_INTSTAT
#define SCLK__MASK 0x40u
#define SCLK__PA__CFG0 CYREG_UDB_PA0_CFG0
#define SCLK__PA__CFG1 CYREG_UDB_PA0_CFG1
#define SCLK__PA__CFG10 CYREG_UDB_PA0_CFG10
#define SCLK__PA__CFG11 CYREG_UDB_PA0_CFG11
#define SCLK__PA__CFG12 CYREG_UDB_PA0_CFG12
#define SCLK__PA__CFG13 CYREG_UDB_PA0_CFG13
#define SCLK__PA__CFG14 CYREG_UDB_PA0_CFG14
#define SCLK__PA__CFG2 CYREG_UDB_PA0_CFG2
#define SCLK__PA__CFG3 CYREG_UDB_PA0_CFG3
#define SCLK__PA__CFG4 CYREG_UDB_PA0_CFG4
#define SCLK__PA__CFG5 CYREG_UDB_PA0_CFG5
#define SCLK__PA__CFG6 CYREG_UDB_PA0_CFG6
#define SCLK__PA__CFG7 CYREG_UDB_PA0_CFG7
#define SCLK__PA__CFG8 CYREG_UDB_PA0_CFG8
#define SCLK__PA__CFG9 CYREG_UDB_PA0_CFG9
#define SCLK__PC CYREG_PRT0_PC
#define SCLK__PC2 CYREG_PRT0_PC2
#define SCLK__PORT 0u
#define SCLK__PS CYREG_PRT0_PS
#define SCLK__SHIFT 6

/* SPIM_BSPIM */
#define SPIM_BSPIM_BitCounter__16BIT_CONTROL_AUX_CTL_REG CYREG_UDB_W16_ACTL_02
#define SPIM_BSPIM_BitCounter__16BIT_CONTROL_CONTROL_REG CYREG_UDB_W16_CTL_02
#define SPIM_BSPIM_BitCounter__16BIT_CONTROL_COUNT_REG CYREG_UDB_W16_CTL_02
#define SPIM_BSPIM_BitCounter__16BIT_COUNT_CONTROL_REG CYREG_UDB_W16_CTL_02
#define SPIM_BSPIM_BitCounter__16BIT_COUNT_COUNT_REG CYREG_UDB_W16_CTL_02
#define SPIM_BSPIM_BitCounter__16BIT_MASK_MASK_REG CYREG_UDB_W16_MSK_02
#define SPIM_BSPIM_BitCounter__16BIT_MASK_PERIOD_REG CYREG_UDB_W16_MSK_02
#define SPIM_BSPIM_BitCounter__16BIT_PERIOD_MASK_REG CYREG_UDB_W16_MSK_02
#define SPIM_BSPIM_BitCounter__16BIT_PERIOD_PERIOD_REG CYREG_UDB_W16_MSK_02
#define SPIM_BSPIM_BitCounter__CONTROL_AUX_CTL_REG CYREG_UDB_W8_ACTL_02
#define SPIM_BSPIM_BitCounter__CONTROL_REG CYREG_UDB_W8_CTL_02
#define SPIM_BSPIM_BitCounter__CONTROL_ST_REG CYREG_UDB_CAT16_CTL_ST_02
#define SPIM_BSPIM_BitCounter__COUNT_REG CYREG_UDB_W8_CTL_02
#define SPIM_BSPIM_BitCounter__COUNT_ST_REG CYREG_UDB_CAT16_CTL_ST_02
#define SPIM_BSPIM_BitCounter__MASK_CTL_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_02
#define SPIM_BSPIM_BitCounter__PER_CTL_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_02
#define SPIM_BSPIM_BitCounter__PERIOD_REG CYREG_UDB_W8_MSK_02
#define SPIM_BSPIM_BitCounter_ST__16BIT_STATUS_AUX_CTL_REG CYREG_UDB_W16_ACTL_02
#define SPIM_BSPIM_BitCounter_ST__16BIT_STATUS_REG CYREG_UDB_W16_ST_02
#define SPIM_BSPIM_BitCounter_ST__MASK_REG CYREG_UDB_W8_MSK_02
#define SPIM_BSPIM_BitCounter_ST__MASK_ST_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_02
#define SPIM_BSPIM_BitCounter_ST__PER_ST_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_02
#define SPIM_BSPIM_BitCounter_ST__STATUS_AUX_CTL_REG CYREG_UDB_W8_ACTL_02
#define SPIM_BSPIM_BitCounter_ST__STATUS_CNT_REG CYREG_UDB_CAT16_CTL_ST_02
#define SPIM_BSPIM_BitCounter_ST__STATUS_CONTROL_REG CYREG_UDB_CAT16_CTL_ST_02
#define SPIM_BSPIM_BitCounter_ST__STATUS_REG CYREG_UDB_W8_ST_02
#define SPIM_BSPIM_RxStsReg__16BIT_STATUS_AUX_CTL_REG CYREG_UDB_W16_ACTL_01
#define SPIM_BSPIM_RxStsReg__16BIT_STATUS_REG CYREG_UDB_W16_ST_01
#define SPIM_BSPIM_RxStsReg__4__MASK 0x10u
#define SPIM_BSPIM_RxStsReg__4__POS 4
#define SPIM_BSPIM_RxStsReg__5__MASK 0x20u
#define SPIM_BSPIM_RxStsReg__5__POS 5
#define SPIM_BSPIM_RxStsReg__6__MASK 0x40u
#define SPIM_BSPIM_RxStsReg__6__POS 6
#define SPIM_BSPIM_RxStsReg__MASK 0x70u
#define SPIM_BSPIM_RxStsReg__MASK_REG CYREG_UDB_W8_MSK_01
#define SPIM_BSPIM_RxStsReg__STATUS_AUX_CTL_REG CYREG_UDB_W8_ACTL_01
#define SPIM_BSPIM_RxStsReg__STATUS_REG CYREG_UDB_W8_ST_01
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_A0_REG CYREG_UDB_W16_A0_01
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_A1_REG CYREG_UDB_W16_A1_01
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_D0_REG CYREG_UDB_W16_D0_01
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_D1_REG CYREG_UDB_W16_D1_01
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_DP_AUX_CTL_REG CYREG_UDB_W16_ACTL_01
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_F0_REG CYREG_UDB_W16_F0_01
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_F1_REG CYREG_UDB_W16_F1_01
#define SPIM_BSPIM_sR8_Dp_u0__A0_A1_REG CYREG_UDB_CAT16_A_01
#define SPIM_BSPIM_sR8_Dp_u0__A0_REG CYREG_UDB_W8_A0_01
#define SPIM_BSPIM_sR8_Dp_u0__A1_REG CYREG_UDB_W8_A1_01
#define SPIM_BSPIM_sR8_Dp_u0__D0_D1_REG CYREG_UDB_CAT16_D_01
#define SPIM_BSPIM_sR8_Dp_u0__D0_REG CYREG_UDB_W8_D0_01
#define SPIM_BSPIM_sR8_Dp_u0__D1_REG CYREG_UDB_W8_D1_01
#define SPIM_BSPIM_sR8_Dp_u0__DP_AUX_CTL_REG CYREG_UDB_W8_ACTL_01
#define SPIM_BSPIM_sR8_Dp_u0__F0_F1_REG CYREG_UDB_CAT16_F_01
#define SPIM_BSPIM_sR8_Dp_u0__F0_REG CYREG_UDB_W8_F0_01
#define SPIM_BSPIM_sR8_Dp_u0__F1_REG CYREG_UDB_W8_F1_01
#define SPIM_BSPIM_TxStsReg__0__MASK 0x01u
#define SPIM_BSPIM_TxStsReg__0__POS 0
#define SPIM_BSPIM_TxStsReg__1__MASK 0x02u
#define SPIM_BSPIM_TxStsReg__1__POS 1
#define SPIM_BSPIM_TxStsReg__16BIT_STATUS_AUX_CTL_REG CYREG_UDB_W16_ACTL_00
#define SPIM_BSPIM_TxStsReg__16BIT_STATUS_REG CYREG_UDB_W16_ST_00
#define SPIM_BSPIM_TxStsReg__2__MASK 0x04u
#define SPIM_BSPIM_TxStsReg__2__POS 2
#define SPIM_BSPIM_TxStsReg__3__MASK 0x08u
#define SPIM_BSPIM_TxStsReg__3__POS 3
#define SPIM_BSPIM_TxStsReg__32BIT_MASK_REG CYREG_UDB_W32_MSK_00
#define SPIM_BSPIM_TxStsReg__32BIT_STATUS_AUX_CTL_REG CYREG_UDB_W32_ACTL_00
#define SPIM_BSPIM_TxStsReg__32BIT_STATUS_REG CYREG_UDB_W32_ST_00
#define SPIM_BSPIM_TxStsReg__4__MASK 0x10u
#define SPIM_BSPIM_TxStsReg__4__POS 4
#define SPIM_BSPIM_TxStsReg__MASK 0x1Fu
#define SPIM_BSPIM_TxStsReg__MASK_REG CYREG_UDB_W8_MSK_00
#define SPIM_BSPIM_TxStsReg__STATUS_AUX_CTL_REG CYREG_UDB_W8_ACTL_00
#define SPIM_BSPIM_TxStsReg__STATUS_REG CYREG_UDB_W8_ST_00

/* SPIM_IntClock */
#define SPIM_IntClock__DIVIDER_MASK 0x0000FFFFu
#define SPIM_IntClock__ENABLE CYREG_CLK_DIVIDER_A00
#define SPIM_IntClock__ENABLE_MASK 0x80000000u
#define SPIM_IntClock__MASK 0x80000000u
#define SPIM_IntClock__REGISTER CYREG_CLK_DIVIDER_A00

/* UART_rx */
#define UART_rx__0__DM__MASK 0x07u
#define UART_rx__0__DM__SHIFT 0
#define UART_rx__0__DR CYREG_PRT4_DR
#define UART_rx__0__HSIOM CYREG_HSIOM_PORT_SEL4
#define UART_rx__0__HSIOM_MASK 0x0000000Fu
#define UART_rx__0__HSIOM_SHIFT 0u
#define UART_rx__0__INTCFG CYREG_PRT4_INTCFG
#define UART_rx__0__INTSTAT CYREG_PRT4_INTSTAT
#define UART_rx__0__MASK 0x01u
#define UART_rx__0__PC CYREG_PRT4_PC
#define UART_rx__0__PC2 CYREG_PRT4_PC2
#define UART_rx__0__PORT 4u
#define UART_rx__0__PS CYREG_PRT4_PS
#define UART_rx__0__SHIFT 0
#define UART_rx__DR CYREG_PRT4_DR
#define UART_rx__INTCFG CYREG_PRT4_INTCFG
#define UART_rx__INTSTAT CYREG_PRT4_INTSTAT
#define UART_rx__MASK 0x01u
#define UART_rx__PC CYREG_PRT4_PC
#define UART_rx__PC2 CYREG_PRT4_PC2
#define UART_rx__PORT 4u
#define UART_rx__PS CYREG_PRT4_PS
#define UART_rx__SHIFT 0

/* UART_SCB */
#define UART_SCB__BIST_CONTROL CYREG_SCB0_BIST_CONTROL
#define UART_SCB__BIST_DATA CYREG_SCB0_BIST_DATA
#define UART_SCB__CTRL CYREG_SCB0_CTRL
#define UART_SCB__EZ_DATA00 CYREG_SCB0_EZ_DATA00
#define UART_SCB__EZ_DATA01 CYREG_SCB0_EZ_DATA01
#define UART_SCB__EZ_DATA02 CYREG_SCB0_EZ_DATA02
#define UART_SCB__EZ_DATA03 CYREG_SCB0_EZ_DATA03
#define UART_SCB__EZ_DATA04 CYREG_SCB0_EZ_DATA04
#define UART_SCB__EZ_DATA05 CYREG_SCB0_EZ_DATA05
#define UART_SCB__EZ_DATA06 CYREG_SCB0_EZ_DATA06
#define UART_SCB__EZ_DATA07 CYREG_SCB0_EZ_DATA07
#define UART_SCB__EZ_DATA08 CYREG_SCB0_EZ_DATA08
#define UART_SCB__EZ_DATA09 CYREG_SCB0_EZ_DATA09
#define UART_SCB__EZ_DATA10 CYREG_SCB0_EZ_DATA10
#define UART_SCB__EZ_DATA11 CYREG_SCB0_EZ_DATA11
#define UART_SCB__EZ_DATA12 CYREG_SCB0_EZ_DATA12
#define UART_SCB__EZ_DATA13 CYREG_SCB0_EZ_DATA13
#define UART_SCB__EZ_DATA14 CYREG_SCB0_EZ_DATA14
#define UART_SCB__EZ_DATA15 CYREG_SCB0_EZ_DATA15
#define UART_SCB__EZ_DATA16 CYREG_SCB0_EZ_DATA16
#define UART_SCB__EZ_DATA17 CYREG_SCB0_EZ_DATA17
#define UART_SCB__EZ_DATA18 CYREG_SCB0_EZ_DATA18
#define UART_SCB__EZ_DATA19 CYREG_SCB0_EZ_DATA19
#define UART_SCB__EZ_DATA20 CYREG_SCB0_EZ_DATA20
#define UART_SCB__EZ_DATA21 CYREG_SCB0_EZ_DATA21
#define UART_SCB__EZ_DATA22 CYREG_SCB0_EZ_DATA22
#define UART_SCB__EZ_DATA23 CYREG_SCB0_EZ_DATA23
#define UART_SCB__EZ_DATA24 CYREG_SCB0_EZ_DATA24
#define UART_SCB__EZ_DATA25 CYREG_SCB0_EZ_DATA25
#define UART_SCB__EZ_DATA26 CYREG_SCB0_EZ_DATA26
#define UART_SCB__EZ_DATA27 CYREG_SCB0_EZ_DATA27
#define UART_SCB__EZ_DATA28 CYREG_SCB0_EZ_DATA28
#define UART_SCB__EZ_DATA29 CYREG_SCB0_EZ_DATA29
#define UART_SCB__EZ_DATA30 CYREG_SCB0_EZ_DATA30
#define UART_SCB__EZ_DATA31 CYREG_SCB0_EZ_DATA31
#define UART_SCB__I2C_CFG CYREG_SCB0_I2C_CFG
#define UART_SCB__I2C_CTRL CYREG_SCB0_I2C_CTRL
#define UART_SCB__I2C_M_CMD CYREG_SCB0_I2C_M_CMD
#define UART_SCB__I2C_S_CMD CYREG_SCB0_I2C_S_CMD
#define UART_SCB__I2C_STATUS CYREG_SCB0_I2C_STATUS
#define UART_SCB__INTR_CAUSE CYREG_SCB0_INTR_CAUSE
#define UART_SCB__INTR_I2C_EC CYREG_SCB0_INTR_I2C_EC
#define UART_SCB__INTR_I2C_EC_MASK CYREG_SCB0_INTR_I2C_EC_MASK
#define UART_SCB__INTR_I2C_EC_MASKED CYREG_SCB0_INTR_I2C_EC_MASKED
#define UART_SCB__INTR_M CYREG_SCB0_INTR_M
#define UART_SCB__INTR_M_MASK CYREG_SCB0_INTR_M_MASK
#define UART_SCB__INTR_M_MASKED CYREG_SCB0_INTR_M_MASKED
#define UART_SCB__INTR_M_SET CYREG_SCB0_INTR_M_SET
#define UART_SCB__INTR_RX CYREG_SCB0_INTR_RX
#define UART_SCB__INTR_RX_MASK CYREG_SCB0_INTR_RX_MASK
#define UART_SCB__INTR_RX_MASKED CYREG_SCB0_INTR_RX_MASKED
#define UART_SCB__INTR_RX_SET CYREG_SCB0_INTR_RX_SET
#define UART_SCB__INTR_S CYREG_SCB0_INTR_S
#define UART_SCB__INTR_S_MASK CYREG_SCB0_INTR_S_MASK
#define UART_SCB__INTR_S_MASKED CYREG_SCB0_INTR_S_MASKED
#define UART_SCB__INTR_S_SET CYREG_SCB0_INTR_S_SET
#define UART_SCB__INTR_SPI_EC CYREG_SCB0_INTR_SPI_EC
#define UART_SCB__INTR_SPI_EC_MASK CYREG_SCB0_INTR_SPI_EC_MASK
#define UART_SCB__INTR_SPI_EC_MASKED CYREG_SCB0_INTR_SPI_EC_MASKED
#define UART_SCB__INTR_TX CYREG_SCB0_INTR_TX
#define UART_SCB__INTR_TX_MASK CYREG_SCB0_INTR_TX_MASK
#define UART_SCB__INTR_TX_MASKED CYREG_SCB0_INTR_TX_MASKED
#define UART_SCB__INTR_TX_SET CYREG_SCB0_INTR_TX_SET
#define UART_SCB__RX_CTRL CYREG_SCB0_RX_CTRL
#define UART_SCB__RX_FIFO_CTRL CYREG_SCB0_RX_FIFO_CTRL
#define UART_SCB__RX_FIFO_RD CYREG_SCB0_RX_FIFO_RD
#define UART_SCB__RX_FIFO_RD_SILENT CYREG_SCB0_RX_FIFO_RD_SILENT
#define UART_SCB__RX_FIFO_STATUS CYREG_SCB0_RX_FIFO_STATUS
#define UART_SCB__RX_MATCH CYREG_SCB0_RX_MATCH
#define UART_SCB__SPI_CTRL CYREG_SCB0_SPI_CTRL
#define UART_SCB__SPI_STATUS CYREG_SCB0_SPI_STATUS
#define UART_SCB__STATUS CYREG_SCB0_STATUS
#define UART_SCB__TX_CTRL CYREG_SCB0_TX_CTRL
#define UART_SCB__TX_FIFO_CTRL CYREG_SCB0_TX_FIFO_CTRL
#define UART_SCB__TX_FIFO_STATUS CYREG_SCB0_TX_FIFO_STATUS
#define UART_SCB__TX_FIFO_WR CYREG_SCB0_TX_FIFO_WR
#define UART_SCB__UART_CTRL CYREG_SCB0_UART_CTRL
#define UART_SCB__UART_RX_CTRL CYREG_SCB0_UART_RX_CTRL
#define UART_SCB__UART_RX_STATUS CYREG_SCB0_UART_RX_STATUS
#define UART_SCB__UART_TX_CTRL CYREG_SCB0_UART_TX_CTRL

/* UART_SCBCLK */
#define UART_SCBCLK__DIVIDER_MASK 0x0000FFFFu
#define UART_SCBCLK__ENABLE CYREG_CLK_DIVIDER_B00
#define UART_SCBCLK__ENABLE_MASK 0x80000000u
#define UART_SCBCLK__MASK 0x80000000u
#define UART_SCBCLK__REGISTER CYREG_CLK_DIVIDER_B00

/* UART_tx */
#define UART_tx__0__DM__MASK 0x38u
#define UART_tx__0__DM__SHIFT 3
#define UART_tx__0__DR CYREG_PRT4_DR
#define UART_tx__0__HSIOM CYREG_HSIOM_PORT_SEL4
#define UART_tx__0__HSIOM_MASK 0x000000F0u
#define UART_tx__0__HSIOM_SHIFT 4u
#define UART_tx__0__INTCFG CYREG_PRT4_INTCFG
#define UART_tx__0__INTSTAT CYREG_PRT4_INTSTAT
#define UART_tx__0__MASK 0x02u
#define UART_tx__0__PC CYREG_PRT4_PC
#define UART_tx__0__PC2 CYREG_PRT4_PC2
#define UART_tx__0__PORT 4u
#define UART_tx__0__PS CYREG_PRT4_PS
#define UART_tx__0__SHIFT 1
#define UART_tx__DR CYREG_PRT4_DR
#define UART_tx__INTCFG CYREG_PRT4_INTCFG
#define UART_tx__INTSTAT CYREG_PRT4_INTSTAT
#define UART_tx__MASK 0x02u
#define UART_tx__PC CYREG_PRT4_PC
#define UART_tx__PC2 CYREG_PRT4_PC2
#define UART_tx__PORT 4u
#define UART_tx__PS CYREG_PRT4_PS
#define UART_tx__SHIFT 1

/* WIZ_SS */
#define WIZ_SS__0__DM__MASK 0xE00u
#define WIZ_SS__0__DM__SHIFT 9
#define WIZ_SS__0__DR CYREG_PRT0_DR
#define WIZ_SS__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define WIZ_SS__0__HSIOM_MASK 0x0000F000u
#define WIZ_SS__0__HSIOM_SHIFT 12u
#define WIZ_SS__0__INTCFG CYREG_PRT0_INTCFG
#define WIZ_SS__0__INTSTAT CYREG_PRT0_INTSTAT
#define WIZ_SS__0__MASK 0x08u
#define WIZ_SS__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define WIZ_SS__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define WIZ_SS__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define WIZ_SS__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define WIZ_SS__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define WIZ_SS__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define WIZ_SS__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define WIZ_SS__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define WIZ_SS__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define WIZ_SS__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define WIZ_SS__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define WIZ_SS__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define WIZ_SS__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define WIZ_SS__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define WIZ_SS__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define WIZ_SS__0__PC CYREG_PRT0_PC
#define WIZ_SS__0__PC2 CYREG_PRT0_PC2
#define WIZ_SS__0__PORT 0u
#define WIZ_SS__0__PS CYREG_PRT0_PS
#define WIZ_SS__0__SHIFT 3
#define WIZ_SS__DR CYREG_PRT0_DR
#define WIZ_SS__INTCFG CYREG_PRT0_INTCFG
#define WIZ_SS__INTSTAT CYREG_PRT0_INTSTAT
#define WIZ_SS__MASK 0x08u
#define WIZ_SS__PA__CFG0 CYREG_UDB_PA0_CFG0
#define WIZ_SS__PA__CFG1 CYREG_UDB_PA0_CFG1
#define WIZ_SS__PA__CFG10 CYREG_UDB_PA0_CFG10
#define WIZ_SS__PA__CFG11 CYREG_UDB_PA0_CFG11
#define WIZ_SS__PA__CFG12 CYREG_UDB_PA0_CFG12
#define WIZ_SS__PA__CFG13 CYREG_UDB_PA0_CFG13
#define WIZ_SS__PA__CFG14 CYREG_UDB_PA0_CFG14
#define WIZ_SS__PA__CFG2 CYREG_UDB_PA0_CFG2
#define WIZ_SS__PA__CFG3 CYREG_UDB_PA0_CFG3
#define WIZ_SS__PA__CFG4 CYREG_UDB_PA0_CFG4
#define WIZ_SS__PA__CFG5 CYREG_UDB_PA0_CFG5
#define WIZ_SS__PA__CFG6 CYREG_UDB_PA0_CFG6
#define WIZ_SS__PA__CFG7 CYREG_UDB_PA0_CFG7
#define WIZ_SS__PA__CFG8 CYREG_UDB_PA0_CFG8
#define WIZ_SS__PA__CFG9 CYREG_UDB_PA0_CFG9
#define WIZ_SS__PC CYREG_PRT0_PC
#define WIZ_SS__PC2 CYREG_PRT0_PC2
#define WIZ_SS__PORT 0u
#define WIZ_SS__PS CYREG_PRT0_PS
#define WIZ_SS__SHIFT 3

/* WIZ_INT */
#define WIZ_INT__0__DM__MASK 0x07u
#define WIZ_INT__0__DM__SHIFT 0
#define WIZ_INT__0__DR CYREG_PRT0_DR
#define WIZ_INT__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define WIZ_INT__0__HSIOM_MASK 0x0000000Fu
#define WIZ_INT__0__HSIOM_SHIFT 0u
#define WIZ_INT__0__INTCFG CYREG_PRT0_INTCFG
#define WIZ_INT__0__INTSTAT CYREG_PRT0_INTSTAT
#define WIZ_INT__0__MASK 0x01u
#define WIZ_INT__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define WIZ_INT__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define WIZ_INT__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define WIZ_INT__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define WIZ_INT__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define WIZ_INT__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define WIZ_INT__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define WIZ_INT__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define WIZ_INT__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define WIZ_INT__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define WIZ_INT__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define WIZ_INT__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define WIZ_INT__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define WIZ_INT__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define WIZ_INT__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define WIZ_INT__0__PC CYREG_PRT0_PC
#define WIZ_INT__0__PC2 CYREG_PRT0_PC2
#define WIZ_INT__0__PORT 0u
#define WIZ_INT__0__PS CYREG_PRT0_PS
#define WIZ_INT__0__SHIFT 0
#define WIZ_INT__DR CYREG_PRT0_DR
#define WIZ_INT__INTCFG CYREG_PRT0_INTCFG
#define WIZ_INT__INTSTAT CYREG_PRT0_INTSTAT
#define WIZ_INT__MASK 0x01u
#define WIZ_INT__PA__CFG0 CYREG_UDB_PA0_CFG0
#define WIZ_INT__PA__CFG1 CYREG_UDB_PA0_CFG1
#define WIZ_INT__PA__CFG10 CYREG_UDB_PA0_CFG10
#define WIZ_INT__PA__CFG11 CYREG_UDB_PA0_CFG11
#define WIZ_INT__PA__CFG12 CYREG_UDB_PA0_CFG12
#define WIZ_INT__PA__CFG13 CYREG_UDB_PA0_CFG13
#define WIZ_INT__PA__CFG14 CYREG_UDB_PA0_CFG14
#define WIZ_INT__PA__CFG2 CYREG_UDB_PA0_CFG2
#define WIZ_INT__PA__CFG3 CYREG_UDB_PA0_CFG3
#define WIZ_INT__PA__CFG4 CYREG_UDB_PA0_CFG4
#define WIZ_INT__PA__CFG5 CYREG_UDB_PA0_CFG5
#define WIZ_INT__PA__CFG6 CYREG_UDB_PA0_CFG6
#define WIZ_INT__PA__CFG7 CYREG_UDB_PA0_CFG7
#define WIZ_INT__PA__CFG8 CYREG_UDB_PA0_CFG8
#define WIZ_INT__PA__CFG9 CYREG_UDB_PA0_CFG9
#define WIZ_INT__PC CYREG_PRT0_PC
#define WIZ_INT__PC2 CYREG_PRT0_PC2
#define WIZ_INT__PORT 0u
#define WIZ_INT__PS CYREG_PRT0_PS
#define WIZ_INT__SHIFT 0

/* WIZ_RDY */
#define WIZ_RDY__0__DM__MASK 0x38u
#define WIZ_RDY__0__DM__SHIFT 3
#define WIZ_RDY__0__DR CYREG_PRT0_DR
#define WIZ_RDY__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define WIZ_RDY__0__HSIOM_MASK 0x000000F0u
#define WIZ_RDY__0__HSIOM_SHIFT 4u
#define WIZ_RDY__0__INTCFG CYREG_PRT0_INTCFG
#define WIZ_RDY__0__INTSTAT CYREG_PRT0_INTSTAT
#define WIZ_RDY__0__MASK 0x02u
#define WIZ_RDY__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define WIZ_RDY__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define WIZ_RDY__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define WIZ_RDY__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define WIZ_RDY__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define WIZ_RDY__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define WIZ_RDY__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define WIZ_RDY__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define WIZ_RDY__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define WIZ_RDY__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define WIZ_RDY__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define WIZ_RDY__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define WIZ_RDY__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define WIZ_RDY__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define WIZ_RDY__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define WIZ_RDY__0__PC CYREG_PRT0_PC
#define WIZ_RDY__0__PC2 CYREG_PRT0_PC2
#define WIZ_RDY__0__PORT 0u
#define WIZ_RDY__0__PS CYREG_PRT0_PS
#define WIZ_RDY__0__SHIFT 1
#define WIZ_RDY__DR CYREG_PRT0_DR
#define WIZ_RDY__INTCFG CYREG_PRT0_INTCFG
#define WIZ_RDY__INTSTAT CYREG_PRT0_INTSTAT
#define WIZ_RDY__MASK 0x02u
#define WIZ_RDY__PA__CFG0 CYREG_UDB_PA0_CFG0
#define WIZ_RDY__PA__CFG1 CYREG_UDB_PA0_CFG1
#define WIZ_RDY__PA__CFG10 CYREG_UDB_PA0_CFG10
#define WIZ_RDY__PA__CFG11 CYREG_UDB_PA0_CFG11
#define WIZ_RDY__PA__CFG12 CYREG_UDB_PA0_CFG12
#define WIZ_RDY__PA__CFG13 CYREG_UDB_PA0_CFG13
#define WIZ_RDY__PA__CFG14 CYREG_UDB_PA0_CFG14
#define WIZ_RDY__PA__CFG2 CYREG_UDB_PA0_CFG2
#define WIZ_RDY__PA__CFG3 CYREG_UDB_PA0_CFG3
#define WIZ_RDY__PA__CFG4 CYREG_UDB_PA0_CFG4
#define WIZ_RDY__PA__CFG5 CYREG_UDB_PA0_CFG5
#define WIZ_RDY__PA__CFG6 CYREG_UDB_PA0_CFG6
#define WIZ_RDY__PA__CFG7 CYREG_UDB_PA0_CFG7
#define WIZ_RDY__PA__CFG8 CYREG_UDB_PA0_CFG8
#define WIZ_RDY__PA__CFG9 CYREG_UDB_PA0_CFG9
#define WIZ_RDY__PC CYREG_PRT0_PC
#define WIZ_RDY__PC2 CYREG_PRT0_PC2
#define WIZ_RDY__PORT 0u
#define WIZ_RDY__PS CYREG_PRT0_PS
#define WIZ_RDY__SHIFT 1

/* WIZ_RST */
#define WIZ_RST__0__DM__MASK 0x1C0u
#define WIZ_RST__0__DM__SHIFT 6
#define WIZ_RST__0__DR CYREG_PRT0_DR
#define WIZ_RST__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define WIZ_RST__0__HSIOM_MASK 0x00000F00u
#define WIZ_RST__0__HSIOM_SHIFT 8u
#define WIZ_RST__0__INTCFG CYREG_PRT0_INTCFG
#define WIZ_RST__0__INTSTAT CYREG_PRT0_INTSTAT
#define WIZ_RST__0__MASK 0x04u
#define WIZ_RST__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define WIZ_RST__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define WIZ_RST__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define WIZ_RST__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define WIZ_RST__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define WIZ_RST__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define WIZ_RST__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define WIZ_RST__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define WIZ_RST__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define WIZ_RST__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define WIZ_RST__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define WIZ_RST__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define WIZ_RST__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define WIZ_RST__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define WIZ_RST__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define WIZ_RST__0__PC CYREG_PRT0_PC
#define WIZ_RST__0__PC2 CYREG_PRT0_PC2
#define WIZ_RST__0__PORT 0u
#define WIZ_RST__0__PS CYREG_PRT0_PS
#define WIZ_RST__0__SHIFT 2
#define WIZ_RST__DR CYREG_PRT0_DR
#define WIZ_RST__INTCFG CYREG_PRT0_INTCFG
#define WIZ_RST__INTSTAT CYREG_PRT0_INTSTAT
#define WIZ_RST__MASK 0x04u
#define WIZ_RST__PA__CFG0 CYREG_UDB_PA0_CFG0
#define WIZ_RST__PA__CFG1 CYREG_UDB_PA0_CFG1
#define WIZ_RST__PA__CFG10 CYREG_UDB_PA0_CFG10
#define WIZ_RST__PA__CFG11 CYREG_UDB_PA0_CFG11
#define WIZ_RST__PA__CFG12 CYREG_UDB_PA0_CFG12
#define WIZ_RST__PA__CFG13 CYREG_UDB_PA0_CFG13
#define WIZ_RST__PA__CFG14 CYREG_UDB_PA0_CFG14
#define WIZ_RST__PA__CFG2 CYREG_UDB_PA0_CFG2
#define WIZ_RST__PA__CFG3 CYREG_UDB_PA0_CFG3
#define WIZ_RST__PA__CFG4 CYREG_UDB_PA0_CFG4
#define WIZ_RST__PA__CFG5 CYREG_UDB_PA0_CFG5
#define WIZ_RST__PA__CFG6 CYREG_UDB_PA0_CFG6
#define WIZ_RST__PA__CFG7 CYREG_UDB_PA0_CFG7
#define WIZ_RST__PA__CFG8 CYREG_UDB_PA0_CFG8
#define WIZ_RST__PA__CFG9 CYREG_UDB_PA0_CFG9
#define WIZ_RST__PC CYREG_PRT0_PC
#define WIZ_RST__PC2 CYREG_PRT0_PC2
#define WIZ_RST__PORT 0u
#define WIZ_RST__PS CYREG_PRT0_PS
#define WIZ_RST__SHIFT 2

/* Miscellaneous */
#define CYDEV_BCLK__HFCLK__HZ 24000000U
#define CYDEV_BCLK__HFCLK__KHZ 24000U
#define CYDEV_BCLK__HFCLK__MHZ 24U
#define CYDEV_BCLK__SYSCLK__HZ 24000000U
#define CYDEV_BCLK__SYSCLK__KHZ 24000U
#define CYDEV_BCLK__SYSCLK__MHZ 24U
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PANTHER 4u
#define CYDEV_CHIP_DIE_PSOC4A 2u
#define CYDEV_CHIP_DIE_PSOC5LP 5u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC4
#define CYDEV_CHIP_JTAG_ID 0x04C81193u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 2u
#define CYDEV_CHIP_MEMBER_4D 3u
#define CYDEV_CHIP_MEMBER_5A 4u
#define CYDEV_CHIP_MEMBER_5B 5u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_4A
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PANTHER_ES0 0u
#define CYDEV_CHIP_REV_PANTHER_ES1 1u
#define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4D_ES0 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_4A_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_READ_ACCELERATOR 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_PROTECT_KILL 4
#define CYDEV_DEBUG_PROTECT_OPEN 1
#define CYDEV_DEBUG_PROTECT CYDEV_DEBUG_PROTECT_OPEN
#define CYDEV_DEBUG_PROTECT_PROTECTED 2
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_HEAP_SIZE 0x0100
#define CYDEV_PROJ_TYPE 2
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_STACK_SIZE 0x0400
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 1
#define CYDEV_VDDA 3.3
#define CYDEV_VDDA_MV 3300
#define CYDEV_VDDD 3.3
#define CYDEV_VDDD_MV 3300
#define CYIPBLOCK_M0S8_CTBM_VERSION 0
#define CYIPBLOCK_m0s8cpuss_VERSION 0
#define CYIPBLOCK_m0s8csd_VERSION 0
#define CYIPBLOCK_m0s8gpio2_VERSION 0
#define CYIPBLOCK_m0s8hsiom4a_VERSION 0
#define CYIPBLOCK_m0s8lcd_VERSION 0
#define CYIPBLOCK_m0s8lpcomp_VERSION 0
#define CYIPBLOCK_m0s8pclk_VERSION 0
#define CYIPBLOCK_m0s8sar_VERSION 0
#define CYIPBLOCK_m0s8scb_VERSION 0
#define CYIPBLOCK_m0s8srssv2_VERSION 1
#define CYIPBLOCK_m0s8tcpwm_VERSION 0
#define CYIPBLOCK_m0s8udbif_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 2
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */