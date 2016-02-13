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
Title "poncho_rescatAR"
Date "3 dec 2015"
Rev "0.1"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
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
Text Label 750  2900 0    60   ~ 0
ANALOG_GND
Text Label 8850 2800 0    60   ~ 0
GND
Text Notes 650  800  0    100  ~ 20
rescatAR\n
Text Label 5200 6950 0    60   ~ 0
I2C_SCL
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
Text Label 1300 2600 0    60   ~ 0
VCC_3.3V
Text Label 5200 6750 0    60   ~ 0
VCC_5V
$Comp
L CONN_8 P2
U 1 1 56167705
P 6050 7100
F 0 "P2" V 6000 7100 60  0000 C CNN
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
GND
Text Label 2300 4500 0    60   ~ 0
GND
Text Label 3100 3600 0    60   ~ 0
GND
Text Label 2300 3700 0    60   ~ 0
GND
Text Label 2300 3800 0    60   ~ 0
GND
Text Label 2300 3900 0    60   ~ 0
GND
Text Label 2300 4100 0    60   ~ 0
GND
Text Label 2300 4200 0    60   ~ 0
TEC_COL2
Text Label 2300 3500 0    60   ~ 0
GND
Text Label 2250 2800 0    60   ~ 0
WAKEUP
Text Label 2250 2700 0    60   ~ 0
GND
Text Label 2200 2600 0    60   ~ 0
VCC_5V
Text Label 8850 2900 0    60   ~ 0
GND
Text Label 8850 3000 0    60   ~ 0
GND
Text Label 8800 3100 0    60   ~ 0
ENET_RXD0
Text Label 8850 3200 0    60   ~ 0
GND
Text Label 8850 3300 0    60   ~ 0
GND
Text Label 8750 3400 0    60   ~ 0
ENET_REF_CLK
Text Label 8850 3500 0    60   ~ 0
GND
Text Label 8850 3700 0    60   ~ 0
SPI_MOSI
Text Label 8900 3800 0    60   ~ 0
LCD_EN
Text Label 8850 3900 0    60   ~ 0
GND
Text Label 8850 4000 0    60   ~ 0
GND
Text Label 8900 4100 0    60   ~ 0
GPIO0
Text Label 8900 4200 0    60   ~ 0
GPIO2
Text Label 8350 4300 0    60   ~ 0
GPIO4
Text Label 8850 4500 0    60   ~ 0
GND
Text Label 8850 4600 0    60   ~ 0
GND
Text Label 8350 4400 0    60   ~ 0
GPIO6
Text Label 10200 2700 0    60   ~ 0
VCC_5V
Text Label 9300 2700 0    60   ~ 0
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
Text Label 5850 3400 0    60   ~ 0
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
NoConn ~ 2900 2800
$Comp
L LED D1
U 1 1 5617B2D6
P 6000 5750
F 0 "D1" H 6000 5850 50  0000 C CNN
F 1 "LED" H 6000 5650 50  0000 C CNN
F 2 "~" H 6000 5750 60  0000 C CNN
F 3 "~" H 6000 5750 60  0000 C CNN
	1    6000 5750
	0    1    1    0   
$EndComp
Text Label 5800 6250 0    60   ~ 0
STATUS_LED
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
Text Notes 4800 2900 0    35   ~ 0
Rx de la edu-ciaa se conecta con\nRx del esquematico del GE864 Rx \ntambien (Lo determinamos por\nprueba y error)
$Comp
L VCC #PWR01
U 1 1 5630345C
P 3250 1100
F 0 "#PWR01" H 3250 1200 30  0001 C CNN
F 1 "VCC" H 3250 1200 30  0000 C CNN
F 2 "" H 3250 1100 60  0000 C CNN
F 3 "" H 3250 1100 60  0000 C CNN
	1    3250 1100
	1    0    0    -1  
$EndComp
Text Label 3450 1100 0    60   ~ 0
VCC_12V
Text Label 5900 2900 0    60   ~ 0
GND
Text Label 5900 3000 0    60   ~ 0
GND
Text Label 5900 3200 0    60   ~ 0
GND
Text Label 5900 3300 0    60   ~ 0
GND
Text Label 7200 2900 0    60   ~ 0
GND
Text Label 7200 3000 0    60   ~ 0
GND
Text Label 7250 3900 0    60   ~ 0
GND
Text Label 7200 3200 0    60   ~ 0
GND
Text Label 7200 3300 0    60   ~ 0
GND
Text Label 7250 4000 0    60   ~ 0
GND
Text Label 5900 3900 0    60   ~ 0
GND
Text Label 5900 4000 0    60   ~ 0
GND
Text Label 7250 4500 0    60   ~ 0
GND
Text Label 7250 4600 0    60   ~ 0
GND
Text Label 5900 4600 0    60   ~ 0
GND
Text Label 4750 4500 0    60   ~ 0
GND
Text Label 4750 4600 0    60   ~ 0
GND
Text Label 3450 4600 0    60   ~ 0
GND
Text Label 3450 3900 0    60   ~ 0
GND
Text Label 3450 4000 0    60   ~ 0
GND
Text Label 4750 3900 0    60   ~ 0
GND
Text Label 4750 4000 0    60   ~ 0
GND
Text Label 4750 3300 0    60   ~ 0
GND
Text Label 4750 3200 0    60   ~ 0
GND
Text Label 3500 3200 0    60   ~ 0
GND
Text Label 3500 3300 0    60   ~ 0
GND
Text Label 3450 2900 0    60   ~ 0
GND
NoConn ~ 5500 2750
Text Label 5250 6850 0    60   ~ 0
GND
Text Notes 3550 1600 0    60   ~ 0
Los "X" que no tienen comentarios\n son los que estan sin asignar en el\nesquematico del fabricante, o pines\nque no utilizamos\n
Text Label 5250 7350 0    60   ~ 0
GND
NoConn ~ 700  2900
Text Label 8750 4300 0    60   ~ 0
GE864_RESET
Text Label 8750 4400 0    60   ~ 0
GE864_ON_OFF
NoConn ~ 6350 3600
NoConn ~ 2150 2900
NoConn ~ 2150 3000
NoConn ~ 2150 3100
NoConn ~ 2150 3200
NoConn ~ 2150 3300
NoConn ~ 2150 3400
Text Notes 2200 3050 0    60   ~ 0
Estos son los\nAnalog_GND\nque no usamos
NoConn ~ 5000 7450
NoConn ~ 5000 7150
NoConn ~ 5000 7250
Text Label 8850 3600 0    60   ~ 0
GND
Text Label 2300 4000 0    60   ~ 0
GND
$Comp
L BAT_CONN BAT1
U 1 1 564115EC
P 4250 750
F 0 "BAT1" H 4250 900 50  0000 C CNN
F 1 "BAT_CONN" H 4250 1000 50  0000 C CNN
F 2 "~" H 4250 550 60  0000 C CNN
F 3 "~" H 4250 550 60  0000 C CNN
	1    4250 750 
	1    0    0    -1  
$EndComp
Text Label 4450 1100 0    60   ~ 0
GND
$Comp
L LM317T U1
U 1 1 565C63CE
P 7000 850
F 0 "U1" H 6800 1050 40  0000 C CNN
F 1 "LM317T" H 7000 1050 40  0000 L CNN
F 2 "TO-220" H 7000 950 30  0000 C CIN
F 3 "" H 7000 850 60  0000 C CNN
	1    7000 850 
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 565C63FB
P 7650 1100
F 0 "R5" V 7730 1100 40  0000 C CNN
F 1 "220" V 7657 1101 40  0000 C CNN
F 2 "~" V 7580 1100 30  0000 C CNN
F 3 "~" H 7650 1100 30  0000 C CNN
	1    7650 1100
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 565C6408
P 7000 1700
F 0 "R4" V 7080 1700 40  0000 C CNN
F 1 "470" V 7007 1701 40  0000 C CNN
F 2 "~" V 6930 1700 30  0000 C CNN
F 3 "~" H 7000 1700 30  0000 C CNN
	1    7000 1700
	1    0    0    -1  
$EndComp
Text Label 5950 2000 0    60   ~ 0
GND
Text Label 6150 800  0    60   ~ 0
VCC_12V
Text Label 8350 800  0    60   ~ 0
VCC_3.8V
$Comp
L CP1 C1
U 1 1 565C6973
P 8500 1250
F 0 "C1" H 8550 1350 50  0000 L CNN
F 1 "10uF" H 8550 1150 50  0000 L CNN
F 2 "~" H 8500 1250 60  0000 C CNN
F 3 "~" H 8500 1250 60  0000 C CNN
	1    8500 1250
	1    0    0    -1  
$EndComp
Text Label 9100 800  0    60   ~ 0
VCC_12V
$Comp
L CP1 C2
U 1 1 565C6DF9
P 10550 1250
F 0 "C2" H 10600 1350 50  0000 L CNN
F 1 "10uF" H 10600 1150 50  0000 L CNN
F 2 "~" H 10550 1250 60  0000 C CNN
F 3 "~" H 10550 1250 60  0000 C CNN
	1    10550 1250
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P1
U 1 1 565CADCA
P 11100 900
F 0 "P1" V 11050 900 40  0000 C CNN
F 1 "5V_OUT" V 11150 900 40  0000 C CNN
F 2 "" H 11100 900 60  0000 C CNN
F 3 "" H 11100 900 60  0000 C CNN
	1    11100 900 
	1    0    0    -1  
$EndComp
$Comp
L LM7805 U2
U 1 1 565DCE78
P 9900 850
F 0 "U2" H 10050 654 60  0000 C CNN
F 1 "LM7805" H 9900 1050 60  0000 C CNN
F 2 "" H 9900 850 60  0000 C CNN
F 3 "" H 9900 850 60  0000 C CNN
	1    9900 850 
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 565EEA3E
P 8100 1250
F 0 "C4" H 8100 1350 40  0000 L CNN
F 1 "0.1uF" H 8106 1165 40  0000 L CNN
F 2 "~" H 8138 1100 30  0000 C CNN
F 3 "~" H 8100 1250 60  0000 C CNN
	1    8100 1250
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 565EECEE
P 6400 1200
F 0 "C3" H 6400 1300 40  0000 L CNN
F 1 "0.1uF" H 6406 1115 40  0000 L CNN
F 2 "~" H 6438 1050 30  0000 C CNN
F 3 "~" H 6400 1200 60  0000 C CNN
	1    6400 1200
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 565EEF20
P 10300 1250
F 0 "C6" H 10300 1350 40  0000 L CNN
F 1 "0.1uF" H 10306 1165 40  0000 L CNN
F 2 "~" H 10338 1100 30  0000 C CNN
F 3 "~" H 10300 1250 60  0000 C CNN
	1    10300 1250
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 565EEF26
P 9400 1250
F 0 "C5" H 9400 1350 40  0000 L CNN
F 1 "0.1uF" H 9406 1165 40  0000 L CNN
F 2 "~" H 9438 1100 30  0000 C CNN
F 3 "~" H 9400 1250 60  0000 C CNN
	1    9400 1250
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
	8250 4400 9350 4400
Wire Wire Line
	8250 4300 9350 4300
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
	2150 3500 2900 3500
Wire Wire Line
	2150 3600 3900 3600
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
	4350 6750 5700 6750
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
	700  2800 1350 2800
Wire Wire Line
	700  2700 1350 2700
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
	2150 2700 2900 2700
Wire Wire Line
	2150 2800 2900 2800
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
	1250 2600 1350 2600
Wire Wire Line
	2250 2600 2150 2600
Wire Wire Line
	9250 2700 9350 2700
Wire Wire Line
	10250 2700 10150 2700
Wire Notes Line
	600  600  600  850 
Wire Wire Line
	3400 3500 3900 3500
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
	6000 4900 6000 4950
Wire Wire Line
	6000 5950 6000 6250
Wire Wire Line
	6350 3400 5800 3400
Wire Wire Line
	5800 3500 6350 3500
Wire Wire Line
	6000 4900 5700 4900
Wire Wire Line
	3250 1100 4100 1100
Wire Wire Line
	4100 1100 4100 950 
Wire Wire Line
	4400 950  4400 1100
Wire Wire Line
	4400 1100 4650 1100
Wire Wire Line
	7400 800  8600 800 
Wire Wire Line
	7650 800  7650 850 
Connection ~ 7650 800 
Wire Wire Line
	7000 1100 7000 1450
Wire Wire Line
	7000 2000 7000 1950
Wire Wire Line
	5900 2000 10750 2000
Wire Wire Line
	6050 800  6600 800 
Wire Wire Line
	7650 1350 7000 1350
Connection ~ 7000 1350
Connection ~ 7000 2000
Wire Wire Line
	9050 800  9500 800 
Wire Wire Line
	10550 1450 10550 2000
Wire Wire Line
	10300 800  10750 800 
Wire Wire Line
	10550 1050 10550 800 
Connection ~ 10550 800 
Wire Wire Line
	10750 2000 10750 1000
Wire Wire Line
	8500 2000 8500 1450
Connection ~ 8500 2000
Wire Wire Line
	5000 7350 5700 7350
Connection ~ 10550 2000
Wire Wire Line
	9900 1100 9900 2000
Connection ~ 9900 2000
Wire Wire Line
	8100 1050 8100 800 
Connection ~ 8100 800 
Wire Wire Line
	8100 1450 8100 2000
Connection ~ 8100 2000
Wire Wire Line
	6400 1400 6400 2000
Connection ~ 6400 2000
Wire Wire Line
	6400 1000 6400 800 
Connection ~ 6400 800 
Wire Wire Line
	9400 1050 9400 800 
Connection ~ 9400 800 
Wire Wire Line
	9400 1450 9400 2000
Connection ~ 9400 2000
Wire Wire Line
	10300 1050 10300 800 
Wire Wire Line
	10300 1450 10300 2000
Connection ~ 10300 2000
Wire Wire Line
	6000 6250 5800 6250
$Comp
L R R1
U 1 1 565EF363
P 6000 5200
F 0 "R1" V 6080 5200 40  0000 C CNN
F 1 "330" V 6007 5201 40  0000 C CNN
F 2 "~" V 5930 5200 30  0000 C CNN
F 3 "~" H 6000 5200 30  0000 C CNN
	1    6000 5200
	1    0    0    -1  
$EndComp
Text Label 5750 4900 0    60   ~ 0
VCC_3.8V
Wire Wire Line
	8500 1050 8500 800 
Connection ~ 8500 800 
Wire Wire Line
	6000 5450 6000 5550
$Comp
L SW_PUSH SW1
U 1 1 5660908B
P 1100 2200
F 0 "SW1" H 1250 2310 50  0000 C CNN
F 1 "Reset_ciaa" H 1100 2120 50  0000 C CNN
F 2 "~" H 1100 2200 60  0000 C CNN
F 3 "~" H 1100 2200 60  0000 C CNN
	1    1100 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	700  2700 700  2200
Wire Wire Line
	700  2200 800  2200
Wire Wire Line
	1400 2200 1950 2200
Text Label 1550 2200 0    60   ~ 0
GND
$Comp
L C C7
U 1 1 5660923F
P 4350 6950
F 0 "C7" H 4350 7050 40  0000 L CNN
F 1 "0.1uF" H 4356 6865 40  0000 L CNN
F 2 "~" H 4388 6800 30  0000 C CNN
F 3 "~" H 4350 6950 60  0000 C CNN
	1    4350 6950
	-1   0    0    1   
$EndComp
$Comp
L CP1 C8
U 1 1 5660924E
P 4650 6950
F 0 "C8" H 4700 7050 50  0000 L CNN
F 1 "10uF" H 4700 6850 50  0000 L CNN
F 2 "~" H 4650 6950 60  0000 C CNN
F 3 "~" H 4650 6950 60  0000 C CNN
	1    4650 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 7150 4050 7150
Text Label 4100 7150 0    60   ~ 0
GND
Connection ~ 4650 6750
Connection ~ 4350 7150
$EndSCHEMATC
