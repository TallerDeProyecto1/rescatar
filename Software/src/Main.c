/* Copyright 2015, Marcelo Minig Traverso
 * Copyright 2015, Manuel Garcia
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief i2c_MPU6050_Slave example source file
 **
 ** This is a mini example of the CIAA Firmware for use with a MPU-6050™ MotionTracking™ device
 **
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */
/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup i2c_MPU6050_Slave example source file
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * MaMT         Marcelo Minig Traverso
 * MaGa         Manuel Garcia
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20150921 v0.0.1   MaGa   first functional version
 *//*==================[inclusions]=============================================*/
#include "../inc/Main.h"    /* <= own header */

#include "os.h"               /* <= operating system header */
#include "ciaaI2CDevices.h"
#include "ciaaPOSIX_stdio.h"  /* <= device handler header */
#include "ciaaPOSIX_string.h" /* <= string header */
#include "ciaak.h"            /* <= ciaa kernel header */
#include "chip.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../../Rescatar/inc/MPU_6050.h"

/*==================[macros and definitions]=================================*/
#define TEC1_MASK         0B0001
#define TEC2_MASK         0B0010
#define TEC3_MASK         0B0100
#define TEC4_MASK         0B1000
#define LED_GREEN				(0x20)
#define LED_RED					(0x10)
#define LED_ORANGE				(0x08)
#define LED_BLUE_RGB			(0x04)
#define LED_GREEN_RGB			(0x02)
#define LED_RED_RGB				(0x01)
#define TEMP_GREA_30C			LED_RED
#define TEMP_LESS_20C_GREA_30C	LED_ORANGE
#define TEMP_LESS_20C			LED_BLUE_RGB
#define tick					10
#define xanglealarm				45
#define yanglealarm				45
#define xaccalarm				10
#define yaccalarm				10



/*==================[internal data declaration]==============================*/

/*en estas variables guardo las lecturas del MPU. tambien se guardan en la libreria del
 * mpu, decidir que conviene hacer
 */
float xgyro=0,ygyro=0,zgyro=0,xacc=0,yacc=0,zacc=0;

/* en num guardo el valor de los registros del giroscopio convertidos a string*/
char num[]="    ";

/*en message combino todos los strings generados en la lectura de los ejes x,y,z*/
char message[80];

uint8 outputs;

char alarma=0;

char countSerial=0,countAlarm=0;

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/** \brief File descriptor for digital output ports
 *
 * Device path /dev/dio/out/0
 */
static int32_t fd_out;

/** \brief File descriptor for digital inputs ports
 *
 * Device path /dev/dio/in/0
 */
static int32_t fd_in;

/** \brief File descriptor for I2C
 *
 * Device path /dev/i2c/0
 */
static int32_t fd_i2c;

/** \brief File descriptor of the USB uart
 *
 * Device path /dev/serial/uart/1
 */
static int32_t fd_uart1;


/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */
int main(void)
{
	/* Starts the operating system in the Application Mode 1 */
	/* This example has only one Application Mode */

	StartOS(AppMode1);

	/* StartOs shall never returns, but to avoid compiler warnings or errors
	 * 0 is returned */
	return 0;
}

/** \brief Error Hook function
 *
 * This fucntion is called from the os if an os interface (API) returns an
 * error. Is for debugging proposes. If called this function triggers a
 * ShutdownOs which ends in a while(1).
 *
 * The values:
 *    OSErrorGetServiceId
 *    OSErrorGetParam1
 *    OSErrorGetParam2
 *    OSErrorGetParam3
 *    OSErrorGetRet
 *
 * will provide you the interface, the input parameters and the returned value.
 * For more details see the OSEK specification:
 * http://portal.osek-vdx.org/files/pdf/specs/os223.pdf
 *
 */
void ErrorHook(void)
{
	ciaaPOSIX_printf("ErrorHook was called\n");
	ciaaPOSIX_printf("Service: %d, P1: %d, P2: %d, P3: %d, RET: %d\n", OSErrorGetServiceId(), OSErrorGetParam1(), OSErrorGetParam2(), OSErrorGetParam3(), OSErrorGetRet());
	ShutdownOS(0);
}

/** \brief Initial task
 *
 * This task is started automatically in the application mode 1.
 */
TASK(InitTask)
{
	/* init CIAA kernel and devices */
	ciaak_start();

	/* print message (only on x86) */
	ciaaPOSIX_printf("Init Task...\n");

	/* open UART connected to USB bridge (FT2232) */
	fd_uart1 = ciaaPOSIX_open("/dev/serial/uart/1", O_RDWR);

	/* change baud rate for uart usb */
	ciaaPOSIX_ioctl(fd_uart1, ciaaPOSIX_IOCTL_SET_BAUDRATE, (void *)ciaaBAUDRATE_115200);

	/* change FIFO TRIGGER LEVEL for uart usb */
	ciaaPOSIX_ioctl(fd_uart1, ciaaPOSIX_IOCTL_SET_FIFO_TRIGGER_LEVEL, (void *)ciaaFIFO_TRIGGER_LEVEL3);

	/*Abro la comunicacion i2c con el sensor:*/
	fd_i2c = MPU_6050_open(ciaaPOSIX_IOCTL_CLOCKRATE_400000);

	/* open CIAA digital outputs */
	fd_out = ciaaPOSIX_open("/dev/dio/out/0", O_RDWR);

	/* open CIAA digital inputs */
	fd_in = ciaaPOSIX_open("/dev/dio/in/0", O_RDWR);

	/*Setup MPU*/
	MPU_6050_setup(fd_i2c,tick);

	/* activate periodic task:
	 *  - for the first time after 350 ticks (350 ms)
	 *  - and then every 10 ticks (10 ms)
	 */
	SetRelAlarm(ActivatePeriodicTask, 350, tick);

	/* terminate task */
	TerminateTask();
}

/** \brief Periodic Task
 *
 * This task is started automatically every time that the alarm
 * ActivatePeriodicTask expires.
 *
 */
TASK(PeriodicTask)
{
	/*cargo los angulos de posicion y las aceleraciones*/
	MPU_6050_readData(fd_i2c,&xgyro,&ygyro,&zgyro,&xacc,&yacc,&zacc);

	/* Envio el mensaje completo a transmitir por serie cada 1 seg*/
	if(++countSerial>(1000/tick)){
		/* Activates the SerialEchoTask task */
		ActivateTask(SerialEchoTask);
		countSerial=0;
	}

	/*activacion de la alarma si se supera en cualquier eje los 45º*/
	if((((abs(xgyro)>xanglealarm)|(abs(ygyro)>yanglealarm))|((xacc<-xaccalarm)|(abs(yacc)>yaccalarm)))&&alarma!=1){
		alarma=1;
		//para las luces
		outputs=0b00000111;
		countAlarm=0;
	}

	/*
	 * Esto prende y apaga las luces,pero aca se deberia llamar a la funcion
	 * que envia el mensaje de ayuda. se deberia implementar un contador para dar tiempo
	 * a cancelar en caso de que se dispare la alerta de forma erronea
	 */
	if(alarma==0){
		outputs =0x00;
		ciaaPOSIX_write(fd_out, &outputs, 1);
	}else{
		if((++countAlarm>(1000/tick)) & (outputs!= 0x3f)){
			outputs=outputs | (outputs << 1 ) ;
			countAlarm=0;
		}
		//ciaaPOSIX_read(fd_out, &outputs, 1);
		//outputs ^= 0x3f;
		ciaaPOSIX_write(fd_out, &outputs, 1);
	}
	TerminateTask();
}

/** \brief Keys Task
 *
 * This task is started automatically every time that the alarm
 * ActivateKeysTask expires.
 *
 */
TASK(KeysTask)
{
	static uint8_t stateKeys;
	uint8_t inputs;
	uint8_t edgeUpKeys;

	/* read input keys */
	ciaaPOSIX_read(fd_in, &inputs, 1);

	/* detects edges*/
	edgeUpKeys = (inputs ^ stateKeys) & inputs;

	/* save new state of keys */
	stateKeys = inputs;

	/* TEC1: Boton para cancelar la alarma*/
	if (TEC1_MASK & edgeUpKeys)
	{
		alarma=0;
		outputs =0x00;
		ciaaPOSIX_write(fd_out, &outputs, 1);
	}

	/* TEC2: boton de panico para activar la alarma */
	if (TEC2_MASK & edgeUpKeys)
	{
		alarma=1;
		//para las luces
		outputs=0b00000111;
		countAlarm=0;

	}

	/*
	 * quedan dos botones(TEC3 y TEC4_MASK) para utilizar y darle mas funcionalidad
	 */

	//	/* TEC3: decrease period */
	//	if (TEC3_MASK & edgeUpKeys)
	//	{
	//		ledMask = 0x10;
	//	}
	//
	//	/* TEC3: increment period */
	//	if (TEC4_MASK & edgeUpKeys)
	//	{
	//		ledMask = 0x20;
	//	}

	/* terminate task */
	TerminateTask();
}


/*
 * Esto se usa para debuguear y ver los valores. quizas se deberia implementar aca la
 * comunicacion serie con el modulo telit
 */
TASK(SerialEchoTask)
{
	itoa((int)xgyro, num, 10);
	strcpy(message,"X=");
	strcat(message,num);
	strcat(message,"º\r\n");
	itoa((int)ygyro, num, 10);
	strcat(message,"Y=");
	strcat(message,num);
	strcat(message,"º\r\n");
	itoa((int)zgyro, num, 10);
	strcat(message,"Z=");
	strcat(message,num);
	strcat(message,"º\r\n");
	itoa((int)xacc, num, 10);
	strcat(message,"X=");
	strcat(message,num);
	strcat(message,"m/s\r\n");
	itoa((int)yacc, num, 10);
	strcat(message,"Y=");
	strcat(message,num);
	strcat(message,"m/s\r\n");
	itoa((int)zacc, num, 10);
	strcat(message,"Z=");
	strcat(message,num);
	strcat(message,"m/s\r\n");
	ciaaPOSIX_write(fd_uart1, message, ciaaPOSIX_strlen(message));
	TerminateTask();
}


/*
 * PROBLEMAS
 * --Se debe hacer el filtro para las medidas del giroscopio.
 * --la calibracion deberia hacerse despues de 30 ms(pag * 12 del datashet)
 * --la alarma deberia llamarse mediante una funcion y quedar registrada en una variable,
 *    no depender directamente de los valores del gyroscopio/acelerometro
 *-- se deben quitar variables y codigo redundante
 *-- el boton de panico y el de cancelar deberian trabajar sobre la variable
 *   alarma/funcion no implementada todavia
 *-- preguntar como se deben tratar las pequeñas variaciones-> creo q el dt q estoy
 *   tomando no es correcto:yo toy tomando los tick del osek, pero capaz q hay q
 *   hacerlo con el samplerate del mpu
 * -- el boton cancelar deberia llamar a una recalibracion? si cancelo con los angulos
 * de posicion superancdo los limites se va a volver a llamar la alarma
 */

