EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:poncho_rescatAR-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "GPIO"
Date "9 oct 2015"
Rev "1.2"
Comp ""
Comment1 "Computadora Industrial Abierta Argentina Versión Educativa EDU-CIAA-NXP"
Comment2 "Licencia: https://github.com/ciaa/Hardware/tree/master/Readme (LICENSE)"
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L +3.3V #PWR020
U 1 1 52CA1E6C
P 1250 1900
F 0 "#PWR020" H 1250 1860 30  0001 C CNN
F 1 "+3.3V" H 1250 2010 30  0000 C CNN
F 2 "" H 1250 1900 60  0000 C CNN
F 3 "" H 1250 1900 60  0000 C CNN
	1    1250 1900
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR021
U 1 1 52DEB0D0
P 1400 6800
F 0 "#PWR021" H 1400 6800 40  0001 C CNN
F 1 "GNDA" H 1400 6730 40  0000 C CNN
F 2 "" H 1400 6800 60  0000 C CNN
F 3 "" H 1400 6800 60  0000 C CNN
	1    1400 6800
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR022
U 1 1 539535EE
P 2250 1900
F 0 "#PWR022" H 2250 1990 20  0001 C CNN
F 1 "+5V" H 2250 1990 30  0000 C CNN
F 2 "" H 2250 1900 60  0000 C CNN
F 3 "" H 2250 1900 60  0000 C CNN
	1    2250 1900
	1    0    0    -1  
$EndComp
$Comp
L CONN_20X2 CON_E-CIAA1
U 1 1 5398AC24
P 1750 3550
F 0 "CON_E-CIAA1" H 1750 4600 60  0000 C CNN
F 1 "CONN_20X2" V 1750 3550 50  0000 C CNN
F 2 "" H 1750 3550 60  0000 C CNN
F 3 "" H 1750 3550 60  0000 C CNN
	1    1750 3550
	1    0    0    -1  
$EndComp
$Comp
L CONN_20X2 CON_E-CIAA2
U 1 1 5398AC33
P 9750 3650
F 0 "CON_E-CIAA2" H 9750 4700 60  0000 C CNN
F 1 "CONN_20X2" V 9750 3650 50  0000 C CNN
F 2 "" H 9750 3650 60  0000 C CNN
F 3 "" H 9750 3650 60  0000 C CNN
	1    9750 3650
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR023
U 1 1 539E165A
P 9250 2000
F 0 "#PWR023" H 9250 1960 30  0001 C CNN
F 1 "+3.3V" H 9250 2110 30  0000 C CNN
F 2 "" H 9250 2000 60  0000 C CNN
F 3 "" H 9250 2000 60  0000 C CNN
	1    9250 2000
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR024
U 1 1 539E1666
P 10250 2000
F 0 "#PWR024" H 10250 2090 20  0001 C CNN
F 1 "+5V" H 10250 2090 30  0000 C CNN
F 2 "" H 10250 2000 60  0000 C CNN
F 3 "" H 10250 2000 60  0000 C CNN
	1    10250 2000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR025
U 1 1 53B8B104
P 1400 7300
F 0 "#PWR025" H 1400 7300 30  0001 C CNN
F 1 "GND" H 1400 7230 30  0001 C CNN
F 2 "" H 1400 7300 60  0000 C CNN
F 3 "" H 1400 7300 60  0000 C CNN
	1    1400 7300
	1    0    0    -1  
$EndComp
Text Label 900  7150 0    60   ~ 0
GPIO_GND
Text Label 850  6700 0    60   ~ 0
ANALOG_GND
Text Label 750  2900 0    60   ~ 0
ANALOG_GND
Text Label 8850 2800 0    60   ~ 0
GPIO_GND
Text Notes 650  800  0    100  ~ 20
rescatAR\n
$Comp
L LM317AH U?
U 1 1 561671E3
P 3550 950
F 0 "U?" H 3350 1150 40  0000 C CNN
F 1 "LM317AH" H 3550 1150 40  0000 L CNN
F 2 "TO-39" H 3550 1050 30  0000 C CIN
F 3 "" H 3550 950 60  0000 C CNN
	1    3550 950 
	1    0    0    -1  
$EndComp
Text Label 5200 6950 0    60   ~ 0
I2C_SCL
Text Label 5100 6850 0    60   ~ 0
ANALOG_GND
Text Label 5200 7050 0    60   ~ 0
I2C_SDA
Text Label 700  3700 0    60   ~ 0
RS232_RXD
Text Label 700  3800 0    60   ~ 0
RS232_TXD
Text Label 800  3600 0    60   ~ 0
I2C_SCL
Text Label 800  3500 0    60   ~ 0
I2C_SDA
Text Label 950  3400 0    60   ~ 0
VDD_A
Text Label 950  3300 0    60   ~ 0
DAC
Text Label 950  3200 0    60   ~ 0
ADC0_1
Text Label 950  3100 0    60   ~ 0
ADC0_2
Text Label 950  3000 0    60   ~ 0
ADC0_3
Text Label 1100 2800 0    60   ~ 0
ISP
Text Label 1150 2700 0    60   ~ 0
RESET
Text Label 1250 2300 0    60   ~ 0
VCC_3.3V
Text Label 5200 6750 0    60   ~ 0
VCC_3.3V
$Comp
L CONN_8 P?
U 1 1 56167705
P 6050 7100
F 0 "P?" V 6000 7100 60  0000 C CNN
F 1 "CONN_8" V 6100 7100 60  0000 C CNN
F 2 "" H 6050 7100 60  0000 C CNN
F 3 "" H 6050 7100 60  0000 C CNN
	1    6050 7100
	1    0    0    -1  
$EndComp
Text Label 900  3900 0    60   ~ 0
CAN_RD
Text Label 900  4000 0    60   ~ 0
CAN_TD
Text Label 850  4100 0    60   ~ 0
TEC_COL1
Text Label 900  4200 0    60   ~ 0
TEC_F0
Text Label 900  4300 0    60   ~ 0
TEC_F3
Text Label 900  4400 0    60   ~ 0
TEC_F2
Text Label 850  4500 0    60   ~ 0
TEC_COL0
Text Label 2300 4300 0    60   ~ 0
TEC_F1
Text Label 2300 4400 0    60   ~ 0
GPIO_GND
Text Label 2300 4500 0    60   ~ 0
GPIO_GND
Text Label 2300 3600 0    60   ~ 0
GPIO_GND
Text Label 2300 3700 0    60   ~ 0
GPIO_GND
Text Label 2300 3800 0    60   ~ 0
GPIO_GND
Text Label 2300 3900 0    60   ~ 0
GPIO_GND
Text Label 2300 4000 0    60   ~ 0
GPIO_GND
Text Label 2300 4100 0    60   ~ 0
GPIO_GND
Text Label 2300 4200 0    60   ~ 0
TEC_COL2
Text Label 2300 3500 0    60   ~ 0
GPIO_GND
Text Label 2200 2900 0    60   ~ 0
ANALOG_GND
Text Label 2200 3000 0    60   ~ 0
ANALOG_GND
Text Label 2200 3100 0    60   ~ 0
ANALOG_GND
Text Label 2200 3200 0    60   ~ 0
ANALOG_GND
Text Label 2200 3300 0    60   ~ 0
ANALOG_GND
Text Label 2200 3400 0    60   ~ 0
ANALOG_GND
Text Label 2250 2800 0    60   ~ 0
WAKEUP
Text Label 2250 2700 0    60   ~ 0
GPIO_GND
Text Label 2250 2300 0    60   ~ 0
VCC_5V
Text Label 8850 2900 0    60   ~ 0
GPIO_GND
Text Label 8850 3000 0    60   ~ 0
GPIO_GND
Text Label 8800 3100 0    60   ~ 0
ENET_RXD0
Text Label 8850 3200 0    60   ~ 0
GPIO_GND
Text Label 8850 3300 0    60   ~ 0
GPIO_GND
Text Label 8750 3400 0    60   ~ 0
ENET_REF_CLK
Text Label 8850 3500 0    60   ~ 0
GPIO_GND
Text Label 8850 3600 0    60   ~ 0
GPIO_GND
Text Label 8850 3700 0    60   ~ 0
SPI_MOSI
Text Label 8900 3800 0    60   ~ 0
LCD_EN
Text Label 8850 3900 0    60   ~ 0
GPIO_GND
Text Label 8850 4000 0    60   ~ 0
GPIO_GND
Text Label 8900 4100 0    60   ~ 0
GPIO0
Text Label 8900 4200 0    60   ~ 0
GPIO2
Text Label 8900 4300 0    60   ~ 0
GPIO4
Text Label 8850 4500 0    60   ~ 0
GPIO_GND
Text Label 8850 4600 0    60   ~ 0
GPIO_GND
Text Label 8900 4400 0    60   ~ 0
GPIO6
Text Label 10250 2350 0    60   ~ 0
VCC_5V
Text Label 9250 2350 0    60   ~ 0
VCC_3.3V
Text Label 10200 2800 0    60   ~ 0
ENET_RXD1
Text Label 10200 2900 0    60   ~ 0
ENET_TX_EN
Text Label 10200 3000 0    60   ~ 0
ENET_MDC
Text Label 10200 3100 0    60   ~ 0
ENET_CRS_DV
Text Label 10200 3200 0    60   ~ 0
ENET_MDIO
Text Label 10250 3300 0    60   ~ 0
ENET_TXD0
Text Label 10250 3400 0    60   ~ 0
ENET_TXD1
Text Label 10250 3500 0    60   ~ 0
SPI_MISO
Text Label 10250 3600 0    60   ~ 0
SPI_SCK
Text Label 10250 3700 0    60   ~ 0
LCD4
Text Label 10250 3800 0    60   ~ 0
LCD_RS
Text Label 10250 3900 0    60   ~ 0
LCD3
Text Label 10250 4000 0    60   ~ 0
LCD2
Text Label 10250 4100 0    60   ~ 0
LCD1
Text Label 10250 4200 0    60   ~ 0
GPIO1
Text Label 10250 4300 0    60   ~ 0
GPIO3
Text Label 10250 4400 0    60   ~ 0
GPIO5
Text Label 10250 4500 0    60   ~ 0
GPIO7
Text Label 10250 4600 0    60   ~ 0
GPIO8
Text Label 5300 7150 0    60   ~ 0
XDA
Text Label 5300 7250 0    60   ~ 0
XCL
Text Label 5300 7350 0    60   ~ 0
AD0
Text Label 5300 7450 0    60   ~ 0
INT
$Comp
L CONN_20X2 CON_SO104
U 1 1 56174B48
P 6750 3650
F 0 "CON_SO104" H 6750 4700 60  0000 C CNN
F 1 "CONN_20X2" V 6750 3650 50  0000 C CNN
F 2 "" H 6750 3650 60  0000 C CNN
F 3 "" H 6750 3650 60  0000 C CNN
	1    6750 3650
	1    0    0    -1  
$EndComp
$Comp
L CONN_20X2 CON_SO101
U 1 1 56174B67
P 4300 3650
F 0 "CON_SO101" H 4300 4700 60  0000 C CNN
F 1 "CONN_20X2" V 4300 3650 50  0000 C CNN
F 2 "" H 4300 3650 60  0000 C CNN
F 3 "" H 4300 3650 60  0000 C CNN
	1    4300 3650
	1    0    0    -1  
$EndComp
Text Notes 3550 1600 0    60   ~ 0
Los "X" que no tienen comentarios\n son los que estan sin asignar en el\n esquematico del fabricante.\n\nLos wires de SO101 que no tienen \nnombre son GND, preguntar:\n+>Que GND conviene poner??\n+>Que diferencia tienen??\n\n
Text Label 3450 3400 0    60   ~ 0
RS232_DCD
Text Label 4700 3400 0    60   ~ 0
RS232_RXD
Text Label 3450 3500 0    60   ~ 0
RS232_TXD
Text Label 4700 3500 0    60   ~ 0
RS232_DTR
Text Label 4700 3600 0    60   ~ 0
RS232_DSR
Text Label 3450 3700 0    60   ~ 0
RS232_RTS
Text Label 4700 3700 0    60   ~ 0
RS232_CTS
Text Label 3450 3800 0    60   ~ 0
RS232_RING
NoConn ~ 3900 4100
NoConn ~ 4700 4100
NoConn ~ 4700 4200
NoConn ~ 4700 4300
NoConn ~ 4700 4400
NoConn ~ 3900 4400
NoConn ~ 3900 4300
NoConn ~ 3900 4200
NoConn ~ 3900 4500
NoConn ~ 4700 2700
NoConn ~ 3900 2800
Text Notes 4750 2700 0    31   ~ 0
PINES 2 Y 3 \nSON PARA DBG\n
Text Label 4100 900  0    60   ~ 0
VCC_3.8V
Text Label 5900 2700 0    60   ~ 0
VCC_3.8V
Text Label 5900 2800 0    60   ~ 0
VCC_3.8V
Text Label 7200 2700 0    60   ~ 0
VCC_3.8V
Text Label 7200 2800 0    60   ~ 0
VCC_3.8V
NoConn ~ 7150 3100
NoConn ~ 6350 3100
Text Label 5800 3400 0    60   ~ 0
GE864_ON_OFF
Text Label 5850 3500 0    60   ~ 0
GE864_RESET
Text Label 5850 3700 0    60   ~ 0
STATUS_LED
NoConn ~ 6350 4400
NoConn ~ 6350 4300
NoConn ~ 6350 4200
NoConn ~ 7150 4300
NoConn ~ 7150 4200
NoConn ~ 7150 4400
NoConn ~ 6350 4500
NoConn ~ 6350 4100
NoConn ~ 7150 4100
NoConn ~ 6350 3800
NoConn ~ 7150 3800
NoConn ~ 7150 3700
NoConn ~ 7150 3600
NoConn ~ 7150 3500
NoConn ~ 7150 3400
Text Notes 7200 3100 0    31   ~ 0
PIN 9 Y 10 SON PARA \nCARGAR UNA BATERIA
Text Notes 7250 4100 0    31   ~ 0
PINES 31,32,33,34,35 SON PARA\nLA TARJETA SIM, OJO QUE SI \nESTAN EN GND PUEDE PROVOCAR \nQUE NO LEA LO DEL MODULO
NoConn ~ 4700 2800
NoConn ~ 4700 2900
NoConn ~ 4700 3000
NoConn ~ 4700 3100
NoConn ~ 3900 3100
NoConn ~ 3900 3000
NoConn ~ 4700 3800
Text Notes 4750 4250 0    31   ~ 0
PINES DE 29 A 38 SON PARA \nFUNCIONES DE AUDIO (NO USAMOS)
NoConn ~ 3900 2700
$Comp
L CONN_4 P?
U 1 1 5617A61D
P 4650 7300
F 0 "P?" V 4600 7300 50  0000 C CNN
F 1 "CONN_4" V 4700 7300 50  0000 C CNN
F 2 "" H 4650 7300 60  0000 C CNN
F 3 "" H 4650 7300 60  0000 C CNN
	1    4650 7300
	-1   0    0    1   
$EndComp
Text Notes 4300 7550 0    31   ~ 0
Este conector de 4 es para extender\nfuncionalidades facilmente en un futuro.
NoConn ~ 2900 2800
$Comp
L SW_PUSH SW?
U 1 1 5617A70D
P 10400 6100
F 0 "SW?" H 10550 6210 50  0000 C CNN
F 1 "SW_PUSH" H 10400 6020 50  0000 C CNN
F 2 "~" H 10400 6100 60  0000 C CNN
F 3 "~" H 10400 6100 60  0000 C CNN
	1    10400 6100
	1    0    0    -1  
$EndComp
Text Label 9050 6100 0    31   ~ 0
GE864_RESET
$Comp
L R R?
U 1 1 5617AABD
P 9800 5750
F 0 "R?" V 9880 5750 40  0000 C CNN
F 1 "10k" V 9807 5751 40  0000 C CNN
F 2 "~" V 9730 5750 30  0000 C CNN
F 3 "~" H 9800 5750 30  0000 C CNN
	1    9800 5750
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5617AACA
P 9500 6100
F 0 "R?" V 9580 6100 40  0000 C CNN
F 1 "1k" V 9507 6101 40  0000 C CNN
F 2 "~" V 9430 6100 30  0000 C CNN
F 3 "~" H 9500 6100 30  0000 C CNN
	1    9500 6100
	0    -1   -1   0   
$EndComp
$Comp
L C C?
U 1 1 5617AAD2
P 9900 6350
F 0 "C?" H 9900 6450 40  0000 L CNN
F 1 "100nF" H 9906 6265 40  0000 L CNN
F 2 "~" H 9938 6200 30  0000 C CNN
F 3 "~" H 9900 6350 60  0000 C CNN
	1    9900 6350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5617AF41
P 11100 6150
F 0 "#PWR?" H 11100 6150 30  0001 C CNN
F 1 "GND" H 11100 6080 30  0001 C CNN
F 2 "" H 11100 6150 60  0000 C CNN
F 3 "" H 11100 6150 60  0000 C CNN
	1    11100 6150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5617B081
P 9900 6600
F 0 "#PWR?" H 9900 6600 30  0001 C CNN
F 1 "GND" H 9900 6530 30  0001 C CNN
F 2 "" H 9900 6600 60  0000 C CNN
F 3 "" H 9900 6600 60  0000 C CNN
	1    9900 6600
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 5617B090
P 9800 5450
F 0 "#PWR?" H 9800 5550 30  0001 C CNN
F 1 "+3.3V" H 9800 5550 30  0000 C CNN
F 2 "" H 9800 5450 60  0000 C CNN
F 3 "" H 9800 5450 60  0000 C CNN
	1    9800 5450
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5617B149
P 8150 6050
F 0 "SW?" H 8300 6160 50  0000 C CNN
F 1 "SW_PUSH" H 8150 5970 50  0000 C CNN
F 2 "~" H 8150 6050 60  0000 C CNN
F 3 "~" H 8150 6050 60  0000 C CNN
	1    8150 6050
	1    0    0    -1  
$EndComp
Text Label 6800 6050 0    31   ~ 0
GE864_ON_OFF
$Comp
L R R?
U 1 1 5617B151
P 7550 5700
F 0 "R?" V 7630 5700 40  0000 C CNN
F 1 "10k" V 7557 5701 40  0000 C CNN
F 2 "~" V 7480 5700 30  0000 C CNN
F 3 "~" H 7550 5700 30  0000 C CNN
	1    7550 5700
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5617B157
P 7250 6050
F 0 "R?" V 7330 6050 40  0000 C CNN
F 1 "1k" V 7257 6051 40  0000 C CNN
F 2 "~" V 7180 6050 30  0000 C CNN
F 3 "~" H 7250 6050 30  0000 C CNN
	1    7250 6050
	0    -1   -1   0   
$EndComp
$Comp
L C C?
U 1 1 5617B15D
P 7650 6300
F 0 "C?" H 7650 6400 40  0000 L CNN
F 1 "100nF" H 7656 6215 40  0000 L CNN
F 2 "~" H 7688 6150 30  0000 C CNN
F 3 "~" H 7650 6300 60  0000 C CNN
	1    7650 6300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5617B169
P 8850 6100
F 0 "#PWR?" H 8850 6100 30  0001 C CNN
F 1 "GND" H 8850 6030 30  0001 C CNN
F 2 "" H 8850 6100 60  0000 C CNN
F 3 "" H 8850 6100 60  0000 C CNN
	1    8850 6100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5617B170
P 7650 6550
F 0 "#PWR?" H 7650 6550 30  0001 C CNN
F 1 "GND" H 7650 6480 30  0001 C CNN
F 2 "" H 7650 6550 60  0000 C CNN
F 3 "" H 7650 6550 60  0000 C CNN
	1    7650 6550
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 5617B176
P 7550 5400
F 0 "#PWR?" H 7550 5500 30  0001 C CNN
F 1 "+3.3V" H 7550 5500 30  0000 C CNN
F 2 "" H 7550 5400 60  0000 C CNN
F 3 "" H 7550 5400 60  0000 C CNN
	1    7550 5400
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 5617B2C7
P 6000 4900
F 0 "#PWR?" H 6000 5000 30  0001 C CNN
F 1 "+5V" H 6000 5000 30  0000 C CNN
F 2 "" H 6000 4900 60  0000 C CNN
F 3 "" H 6000 4900 60  0000 C CNN
	1    6000 4900
	1    0    0    -1  
$EndComp
$Comp
L LED D?
U 1 1 5617B2D6
P 6000 5150
F 0 "D?" H 6000 5250 50  0000 C CNN
F 1 "LED" H 6000 5050 50  0000 C CNN
F 2 "~" H 6000 5150 60  0000 C CNN
F 3 "~" H 6000 5150 60  0000 C CNN
	1    6000 5150
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 5617B2E5
P 5250 5750
F 0 "R?" V 5330 5750 40  0000 C CNN
F 1 "330k" V 5257 5751 40  0000 C CNN
F 2 "~" V 5180 5750 30  0000 C CNN
F 3 "~" H 5250 5750 30  0000 C CNN
	1    5250 5750
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5617B2F2
P 5700 5750
F 0 "R?" V 5780 5750 40  0000 C CNN
F 1 "10k" V 5707 5751 40  0000 C CNN
F 2 "~" V 5630 5750 30  0000 C CNN
F 3 "~" H 5700 5750 30  0000 C CNN
	1    5700 5750
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5617B2F8
P 6000 5750
F 0 "R?" V 6080 5750 40  0000 C CNN
F 1 "680" V 6007 5751 40  0000 C CNN
F 2 "~" V 5930 5750 30  0000 C CNN
F 3 "~" H 6000 5750 30  0000 C CNN
	1    6000 5750
	1    0    0    -1  
$EndComp
$Comp
L MOSFET_N Q?
U 1 1 5617AFD6
P 5900 6250
F 0 "Q?" H 5910 6420 60  0000 R CNN
F 1 "2N7002" H 5910 6100 60  0000 R CNN
F 2 "~" H 5900 6250 60  0000 C CNN
F 3 "~" H 5900 6250 60  0000 C CNN
	1    5900 6250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5617B031
P 5250 6250
F 0 "#PWR?" H 5250 6250 30  0001 C CNN
F 1 "GND" H 5250 6180 30  0001 C CNN
F 2 "" H 5250 6250 60  0000 C CNN
F 3 "" H 5250 6250 60  0000 C CNN
	1    5250 6250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5617B5C3
P 6000 6500
F 0 "#PWR?" H 6000 6500 30  0001 C CNN
F 1 "GND" H 6000 6430 30  0001 C CNN
F 2 "" H 6000 6500 60  0000 C CNN
F 3 "" H 6000 6500 60  0000 C CNN
	1    6000 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 3400 5200 3400
Wire Wire Line
	3900 3400 3400 3400
Wire Wire Line
	4700 3300 5200 3300
Wire Wire Line
	4700 3200 5200 3200
Wire Wire Line
	3900 3300 3400 3300
Wire Wire Line
	3900 3200 3400 3200
Wire Wire Line
	3400 2900 3900 2900
Wire Wire Line
	5700 7450 5000 7450
Wire Wire Line
	5000 7350 5700 7350
Wire Wire Line
	5700 7250 5000 7250
Wire Notes Line
	1350 850  600  850 
Wire Notes Line
	1350 600  600  600 
Wire Notes Line
	1350 600  1350 850 
Wire Wire Line
	10150 4600 10800 4600
Wire Wire Line
	10800 4500 10150 4500
Wire Wire Line
	10150 4400 10800 4400
Wire Wire Line
	10800 4300 10150 4300
Wire Wire Line
	10150 4200 10800 4200
Wire Wire Line
	10800 4100 10150 4100
Wire Wire Line
	10150 4000 10800 4000
Wire Wire Line
	10800 3900 10150 3900
Wire Wire Line
	10150 3800 10800 3800
Wire Wire Line
	10800 3700 10150 3700
Wire Wire Line
	10150 3600 10800 3600
Wire Wire Line
	10800 3500 10150 3500
Wire Wire Line
	10150 3400 10800 3400
Wire Wire Line
	10800 3300 10150 3300
Wire Wire Line
	8700 4600 9350 4600
Wire Wire Line
	9350 4500 8700 4500
Wire Wire Line
	8700 4400 9350 4400
Wire Wire Line
	9350 4300 8700 4300
Wire Wire Line
	8700 4200 9350 4200
Wire Wire Line
	9350 4100 8700 4100
Wire Wire Line
	8700 4000 9350 4000
Wire Wire Line
	9350 3900 8700 3900
Wire Wire Line
	9350 3800 8700 3800
Wire Wire Line
	9350 3700 8700 3700
Wire Wire Line
	9350 3600 8700 3600
Wire Wire Line
	9350 3500 8700 3500
Wire Wire Line
	9350 3400 8700 3400
Wire Wire Line
	2150 3400 2900 3400
Wire Wire Line
	2150 3500 2900 3500
Wire Wire Line
	2150 3600 2900 3600
Wire Wire Line
	2150 3700 2900 3700
Wire Wire Line
	2150 3800 2900 3800
Wire Wire Line
	2150 3900 2900 3900
Wire Wire Line
	2150 4000 2900 4000
Wire Wire Line
	2150 4100 2900 4100
Wire Wire Line
	2150 4200 2900 4200
Wire Wire Line
	2150 4300 2900 4300
Wire Wire Line
	2150 4400 2900 4400
Wire Wire Line
	2150 4500 2900 4500
Wire Wire Line
	1350 4100 600  4100
Wire Wire Line
	1350 4000 600  4000
Wire Wire Line
	1350 3900 600  3900
Wire Wire Line
	5700 7150 5000 7150
Wire Wire Line
	5700 7050 5000 7050
Wire Wire Line
	5700 6950 5000 6950
Wire Wire Line
	5700 6850 5000 6850
Wire Wire Line
	5000 6750 5700 6750
Wire Wire Line
	1350 3600 700  3600
Wire Wire Line
	1350 3700 600  3700
Wire Wire Line
	1350 3800 600  3800
Wire Wire Line
	600  4200 1350 4200
Wire Wire Line
	600  4300 1350 4300
Wire Wire Line
	600  4400 1350 4400
Wire Wire Line
	600  4500 1350 4500
Wire Wire Line
	700  3400 1350 3400
Wire Wire Line
	700  3300 1350 3300
Wire Wire Line
	1400 6700 850  6700
Wire Wire Line
	1400 6800 1400 6700
Wire Wire Line
	700  2800 1350 2800
Wire Wire Line
	700  2700 1350 2700
Wire Wire Line
	1400 7150 850  7150
Wire Wire Line
	1400 7300 1400 7150
Wire Wire Line
	2150 2900 2900 2900
Wire Wire Line
	700  2900 1350 2900
Wire Wire Line
	700  3000 1350 3000
Wire Wire Line
	700  3100 1350 3100
Wire Wire Line
	700  3200 1350 3200
Wire Wire Line
	700  3500 1350 3500
Wire Wire Line
	8700 2800 9350 2800
Wire Wire Line
	8700 2900 9350 2900
Wire Wire Line
	8700 3000 9350 3000
Wire Wire Line
	8700 3100 9350 3100
Wire Wire Line
	8700 3200 9350 3200
Wire Wire Line
	8700 3300 9350 3300
Wire Wire Line
	2150 3200 2900 3200
Wire Wire Line
	2150 3300 2900 3300
Wire Wire Line
	2150 2700 2900 2700
Wire Wire Line
	2150 2800 2900 2800
Wire Wire Line
	2150 3000 2900 3000
Wire Wire Line
	2150 3100 2900 3100
Wire Wire Line
	10150 2800 10800 2800
Wire Wire Line
	10150 2900 10800 2900
Wire Wire Line
	10150 3100 10800 3100
Wire Wire Line
	10150 3000 10800 3000
Wire Wire Line
	10150 3200 10800 3200
Wire Wire Line
	1250 1900 1250 2600
Wire Wire Line
	1250 2600 1350 2600
Wire Wire Line
	2250 2600 2150 2600
Wire Wire Line
	2250 1900 2250 2600
Wire Wire Line
	9250 2000 9250 2700
Wire Wire Line
	10250 2000 10250 2700
Wire Wire Line
	9250 2700 9350 2700
Wire Wire Line
	10250 2700 10150 2700
Wire Notes Line
	600  600  600  850 
Wire Wire Line
	3400 3500 3900 3500
Wire Wire Line
	3900 3600 3400 3600
Wire Wire Line
	4700 3500 5200 3500
Wire Wire Line
	3400 3700 3900 3700
Wire Wire Line
	4700 3600 5200 3600
Wire Wire Line
	5200 3700 4700 3700
Wire Wire Line
	3900 3800 3400 3800
Wire Wire Line
	3400 3900 3900 3900
Wire Wire Line
	3900 4000 3400 4000
Wire Wire Line
	4700 4000 5200 4000
Wire Wire Line
	5200 3900 4700 3900
Wire Wire Line
	4700 4600 5200 4600
Wire Wire Line
	5200 4500 4700 4500
Wire Wire Line
	3900 4600 3400 4600
Wire Wire Line
	5800 2700 6350 2700
Wire Wire Line
	6350 2800 5800 2800
Wire Wire Line
	7150 2800 7700 2800
Wire Wire Line
	7700 2700 7150 2700
Wire Wire Line
	3950 900  4550 900 
Wire Wire Line
	7150 3000 7700 3000
Wire Wire Line
	7150 2900 7700 2900
Wire Wire Line
	5800 2900 6350 2900
Wire Wire Line
	5800 3000 6350 3000
Wire Wire Line
	7150 3300 7700 3300
Wire Wire Line
	7150 3200 7700 3200
Wire Wire Line
	5800 3300 6350 3300
Wire Wire Line
	5800 3200 6350 3200
Wire Wire Line
	6350 3400 5800 3400
Wire Wire Line
	5800 3500 6350 3500
Wire Wire Line
	6350 3700 5800 3700
Wire Wire Line
	7150 4000 7700 4000
Wire Wire Line
	7150 3900 7700 3900
Wire Wire Line
	5800 4000 6350 4000
Wire Wire Line
	5800 3900 6350 3900
Wire Wire Line
	7150 4600 7700 4600
Wire Wire Line
	7150 4500 7700 4500
Wire Wire Line
	6350 4600 5800 4600
Wire Wire Line
	9750 6100 10100 6100
Wire Wire Line
	9900 6150 9900 6100
Connection ~ 9900 6100
Wire Wire Line
	9800 6000 9800 6100
Connection ~ 9800 6100
Wire Wire Line
	9050 6100 9250 6100
Wire Wire Line
	10700 6100 11100 6100
Wire Wire Line
	11100 6100 11100 6150
Wire Wire Line
	9800 5450 9800 5500
Wire Wire Line
	7500 6050 7850 6050
Wire Wire Line
	7650 6100 7650 6050
Connection ~ 7650 6050
Wire Wire Line
	7550 5950 7550 6050
Connection ~ 7550 6050
Wire Wire Line
	6800 6050 7000 6050
Wire Wire Line
	8450 6050 8850 6050
Wire Wire Line
	8850 6050 8850 6100
Wire Wire Line
	7550 5400 7550 5450
Wire Wire Line
	7650 6500 7650 6550
Wire Wire Line
	9900 6550 9900 6600
Wire Wire Line
	5250 6000 5250 6250
Wire Wire Line
	5700 6250 5700 6000
Wire Wire Line
	5700 5500 5250 5500
Wire Wire Line
	6000 6050 6000 6000
Wire Wire Line
	6000 4900 6000 4950
Wire Wire Line
	6000 5350 6000 5500
Wire Wire Line
	6000 6450 6000 6500
Wire Wire Line
	5700 5400 5700 5500
Wire Wire Line
	5200 5400 5700 5400
Text Label 5250 5400 0    60   ~ 0
STATUS_LED
NoConn ~ 1900 4550
NoConn ~ 700  2700
NoConn ~ 700  2800
NoConn ~ 700  3000
NoConn ~ 700  3100
NoConn ~ 700  3200
NoConn ~ 700  3300
NoConn ~ 700  3400
NoConn ~ 600  3900
NoConn ~ 600  4000
NoConn ~ 600  4100
NoConn ~ 600  4200
NoConn ~ 600  4300
NoConn ~ 600  4400
NoConn ~ 600  4500
NoConn ~ 2900 4300
NoConn ~ 2900 4200
NoConn ~ 5200 3500
NoConn ~ 5200 3600
NoConn ~ 5200 3700
NoConn ~ 3400 3400
NoConn ~ 3400 3700
NoConn ~ 3400 3800
NoConn ~ 8700 3100
NoConn ~ 8700 3400
NoConn ~ 8700 3700
NoConn ~ 8700 3800
NoConn ~ 8700 4100
NoConn ~ 8700 4200
NoConn ~ 8700 4300
NoConn ~ 8700 4400
NoConn ~ 10800 4400
NoConn ~ 10800 4300
NoConn ~ 10800 4500
NoConn ~ 10800 4600
NoConn ~ 10800 4200
NoConn ~ 10800 4100
NoConn ~ 10800 4000
NoConn ~ 10800 3900
NoConn ~ 10800 3800
NoConn ~ 10800 3700
NoConn ~ 10800 3600
NoConn ~ 10800 3500
NoConn ~ 10800 3400
NoConn ~ 10800 3300
NoConn ~ 10800 3200
NoConn ~ 10800 3100
NoConn ~ 10800 3000
NoConn ~ 10800 2900
NoConn ~ 10800 2800
Text Notes 10000 4700 0    31   ~ 0
Acá podriamos conectar algun GPIO\nal la linea INT del acelerometro y a la\nlinea AD0 para controlar la direccion.
Wire Wire Line
	3150 900  2500 900 
Text Label 2700 900  0    31   ~ 0
VCC_5V
$EndSCHEMATC
