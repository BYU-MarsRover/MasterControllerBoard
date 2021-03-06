# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\Jared\Documents\PSoC Creator\Workspace1\Buttons.cydsn\Buttons.cyprj
# Date: Thu, 11 Dec 2014 00:59:12 GMT
#set_units -time ns
create_clock -name {UART_1_SCBCLK(FFB)} -period 708.33333333333326 -waveform {0 354.166666666667} [list [get_pins {ClockBlock/ff_div_2}]]
create_clock -name {Clock_1(FFB)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/ff_div_8}]]
create_clock -name {Clock_2(FFB)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/ff_div_9}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_generated_clock -name {UART_1_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 17 35} -nominal_period 708.33333333333326 [list]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 25 49} [list]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/hfclk}] -edges {1 25 49} [list]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]


# Component constraints for C:\Users\Jared\Documents\PSoC Creator\Workspace1\Buttons.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Jared\Documents\PSoC Creator\Workspace1\Buttons.cydsn\Buttons.cyprj
# Date: Thu, 11 Dec 2014 00:59:02 GMT
