/*==================[inclusions]=============================================*/
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
#define LEDS_RESET		  0B11000000
#define TICK			  10
#define X_ANGLEA_LARM	  45
#define Y_ANGLE_ALARM	  45
#define X_ACC_ALARM		  10
#define Y_ACC_ALARM		  10



/*==================[internal data declaration]==============================*/

/* en esta estructura guardo las lecturas del MPU*/
MPU_data_struct MPU_data;

/* TODO reemplazar o reutilizar para cuando se implemente el telit
 * en num guardo el valor de los registros del giroscopio convertidos a string
 */
char num[]="    ";

/*TODO idem anterior. en message combino todos los strings generados en la lectura
 * de los ejes x,y,z
 */
char message[80];

/*luces*/
uint8 outputs;

/*determina el estado de emergencia*/
char alarma=0;

/*TODO esta variable debera ser eliminada cuando se implemente la comunicacion
 * serie con el telit, ya que se usa para determinar cada cuanto tiempo se deberan
 * mostrar  por terminal los valores
 */
char countSerial=0;

/*Se utiliza para llevar la cuenta regresiva ants de mandar el sms*/
char countAlarm=0;




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

	/* open UART connected to USB bridge (FT2232) */
	fd_uart1 = ciaaPOSIX_open("/dev/serial/uart/1", O_RDWR);

	/* change baud rate for uart usb */
	ciaaPOSIX_ioctl(fd_uart1, ciaaPOSIX_IOCTL_SET_BAUDRATE, (void *)ciaaBAUDRATE_115200);

	/* change FIFO TRIGGER LEVEL for uart usb */
	ciaaPOSIX_ioctl(fd_uart1, ciaaPOSIX_IOCTL_SET_FIFO_TRIGGER_LEVEL, (void *)ciaaFIFO_TRIGGER_LEVEL3);

	/* Abro la comunicacion i2c (I2C0)*/
	fd_i2c = ciaaPOSIX_open("/dev/i2c/0", O_RDWR);

	/* seteamos el clockrate*/
	ciaaPOSIX_ioctl(fd_i2c, ciaaPOSIX_IOCTL_SET_CLOCKRATE, (void *)ciaaPOSIX_IOCTL_CLOCKRATE_400000);

	/* Configuramos la direccion del esclavo*/
	ciaaPOSIX_ioctl(fd_i2c, ciaaPOSIX_IOCTL_SET_SLAVEADD, (void *)MPU6050_ADDRESS);

	/* open CIAA digital outputs */
	fd_out = ciaaPOSIX_open("/dev/dio/out/0", O_RDWR);

	/* open CIAA digital inputs */
	fd_in = ciaaPOSIX_open("/dev/dio/in/0", O_RDWR);

	/*se realizan las configuraciones iniciales del MPU*/
	MPU_6050_setup(fd_i2c,TICK);

	/*
	 * Compruebo que el sensor funciona correctamente
	 */
	if(!MPU_6050_test(fd_i2c))
		ErrorHook();

	/* activate periodic task:
	 *  - for the first time after 350 ticks (350 ms)
	 *  - and then every tick ticks (definido como macro)
	 */
	SetRelAlarm(ActivatePeriodicTask, 350, TICK);

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
	/* actualizo los angulos de posicion y las aceleraciones*/
	MPU_6050_update(fd_i2c,&MPU_data);

	/* Envio el mensaje completo a transmitir por serie cada 1 seg
	 * Esto se usa para ver los valores por la terminal, debera ser eliminado
	 * cuando se implemente el codigo para enviar el sms*/
	if(++countSerial>(1000/TICK)){
		/* Activates the SerialEchoTask task */
		ActivateTask(SerialEchoTask);
		countSerial=0;
	}

	/* activacion de la alarma si se supera (en modulo) en los ejes 'x' o 'y' a los
	 * valores maximos en cualquier sentido, si la aceleracion lateral supera (en modulo)
	 * los valores maximos o si se produce una desaceleracion brusca en el eje y. ademas
	 * se inicia countAlarm para realizar la cuenta regresiva antes de mandar el mensaje
	 */
	if((((abs(MPU_data.xgyro)>X_ANGLEA_LARM)|(abs(MPU_data.ygyro)>Y_ANGLE_ALARM))|((MPU_data.yacc<-Y_ACC_ALARM)|(abs(MPU_data.xacc)>X_ACC_ALARM)))&&alarma!=1){
		alarma=1;
		countAlarm=0;
	}

	/*
	 * control de las luces y de la cuenta regresiva para mandar el mensaje
	 */
	if(alarma==0){
		outputs =LEDS_RESET;
	}else{
		if((++countAlarm>(1000/TICK)) & (outputs!= 0x3f)){
			outputs=outputs | (outputs >> 1 ) ;
			countAlarm=0;
		}
		/* si se cumple este if, se llego al final de la cuenta y se debe mandar
		 * el mensaje de auxilio*/
		if(outputs== 0x3f){
			/*
			 * Aca debo configurar el mensaje a enviar por sms, y luego activar la
			 * serial task
			 */

			/* Activates the SerialEchoTask task */
					//ActivateTask(SerialEchoTask);
		}
	}
	ciaaPOSIX_write(fd_out, &outputs, 1);
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
		outputs =LEDS_RESET;
		ciaaPOSIX_write(fd_out, &outputs, 1);
	}

	/* TEC2: boton de panico para activar la alarma */
	if (TEC2_MASK & edgeUpKeys)
	{
		alarma=1;
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
 * Esto se usa para debuguear y ver los valores. se deberia implementar aca la
 * comunicacion serie con el modulo telit
 */
TASK(SerialEchoTask)
{
	itoa((int)MPU_data.xgyro, num, 10);
	strcpy(message,"X=");
	strcat(message,num);
	strcat(message,"º\r\n");
	itoa((int)MPU_data.ygyro, num, 10);
	strcat(message,"Y=");
	strcat(message,num);
	strcat(message,"º\r\n");
	itoa((int)MPU_data.zgyro, num, 10);
	strcat(message,"Z=");
	strcat(message,num);
	strcat(message,"º\r\n");
	itoa((int)MPU_data.xacc, num, 10);
	strcat(message,"X=");
	strcat(message,num);
	strcat(message,"m/s\r\n");
	itoa((int)MPU_data.yacc, num, 10);
	strcat(message,"Y=");
	strcat(message,num);
	strcat(message,"m/s\r\n");
	itoa((int)MPU_data.zacc, num, 10);
	strcat(message,"Z=");
	strcat(message,num);
	strcat(message,"m/s\r\n");
	ciaaPOSIX_write(fd_uart1, message, ciaaPOSIX_strlen(message));
	TerminateTask();
}


/*
 * PROBLEMAS
 * -- la calibracion deberia hacerse despues de 30 ms(pag * 12 del datashet)
 * -- el boton cancelar deberia llamar a una recalibracion? si cancelo con los angulos
 * de posicion superancdo los limites se va a volver a llamar la alarma
 */

