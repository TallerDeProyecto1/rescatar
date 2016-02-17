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
#include "utime.h"	//no va creo


/*==================[macros and definitions]=================================*/
#define TEC1_MASK         0B0001
#define TEC2_MASK         0B0010
#define TEC3_MASK         0B0100
#define TEC4_MASK         0B1000
#define LEDS_RESET		  0B11100000
#define TICK			  10	//periodic task se ejecutara acada 10 milisegundos
#define X_ANGLEA_LARM	  45
#define Y_ANGLE_ALARM	  45
#define X_ACC_ALARM		  10
#define Y_ACC_ALARM		  10
#define TELIT_TIME_ON	  30



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
char message[120];
char message2[120];
char numEmerg[15]="2346514794";
char chNumEmerg[30];

/*luces*/
uint8 outputs;

char systemOn=255;

/*determina el estado de emergencia*/
char alarma=0;

/*TODO esta variable debera ser eliminada cuando se implemente la comunicacion
 * serie con el telit, ya que se usa para determinar cada cuanto tiempo se deberan
 * mostrar  por terminal los valores
 */
char countSerial=0;

/*1 para enviar un mensaje por serial, 0 para recibir un menaje por serial
 */
char serialSend=0;

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
static int32_t fd_uart1;					//borrar, ya que solo sirve para debugear

/** \brief File descriptor of the uart
 *
 * Device path /dev/serial/uart/2
 */
static int32_t fd_uart2;




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
	fd_uart1 = ciaaPOSIX_open("/dev/serial/uart/1", O_RDWR);				//borrar, sirve para debug
	/* open UART connected to RS232 */
	fd_uart2 = ciaaPOSIX_open("/dev/serial/uart/2", O_RDWR);

	//	/* change baud rate for uart usb */
	ciaaPOSIX_ioctl(fd_uart1, ciaaPOSIX_IOCTL_SET_BAUDRATE, (void *)ciaaBAUDRATE_115200);		//borrar, sirve para debug

	/* change baud rate for uart RS232  */
	ciaaPOSIX_ioctl(fd_uart2, ciaaPOSIX_IOCTL_SET_BAUDRATE, (void *)ciaaBAUDRATE_115200);

	//	/* change FIFO TRIGGER LEVEL for uart usb */
	ciaaPOSIX_ioctl(fd_uart1, ciaaPOSIX_IOCTL_SET_FIFO_TRIGGER_LEVEL, (void *)ciaaFIFO_TRIGGER_LEVEL3);						//borrar, sirve para debug

	/* change FIFO TRIGGER LEVEL for uart RS232 */
	ciaaPOSIX_ioctl(fd_uart2, ciaaPOSIX_IOCTL_SET_FIFO_TRIGGER_LEVEL, (void *)ciaaFIFO_TRIGGER_LEVEL3);

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


	Chip_SCU_PinMux(6,10,MD_PUP,FUNC0); /* GPIO3[6], GPIO6 , p6_10*/
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 3,(1<<6),1);	//seteo como salida
	Chip_GPIO_ClearValue(LPC_GPIO_PORT, 3,(1<<6));	//enciendo el telit


	/*se realizan las configuraciones iniciales del MPU*/
	MPU_6050_setup(fd_i2c,TICK);

	if(!MPU_6050_test(fd_i2c))
		ErrorHook();

	SetRelAlarm(ActivateTelitInitTask,1000, 1000);
	//	ActivateTask(TelitInitTask);


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


	/* activacion de la alarma si se supera (en modulo) en los ejes 'x' o 'y' a los
	 * valores maximos en cualquier sentido, si la aceleracion lateral supera (en modulo)
	 * los valores maximos o si se produce una desaceleracion brusca en el eje y. ademas
	 * se inicia countAlarm para realizar la cuenta regresiva antes de mandar el mensaje
	 * ademas el booleando serialSend se pone en 1 para indicar que se debe envia un mensaje
	 */
	if((((abs(MPU_data.xgyro)>X_ANGLEA_LARM)|(abs(MPU_data.ygyro)>Y_ANGLE_ALARM))|((MPU_data.yacc<-Y_ACC_ALARM)|(abs(MPU_data.xacc)>X_ACC_ALARM)))&&alarma!=1&&systemOn==255){
		alarma=1;
		countAlarm=0;
	}

	/*
	 * control de las luces y de la cuenta regresiva para mandar el mensaje
	 */
	if(alarma!=0){
		if((++countAlarm>(1000/TICK)) & (outputs!= 0x3f)){
			outputs=outputs | (outputs >> 1 ) ;
			countAlarm=0;
		}
		/* si se cumple este if, se llego al final de la cuenta y se debe mandar
		 * el mensaje de auxilio*/
		if(outputs== 255){
			CancelAlarm(ActivatePeriodicTask);
			CancelAlarm(ActivateKeysTask);
			serialSend=1;
			//			ActivateTask(SerialEchoTask);
			/*
			 * Aca debo configurar el mensaje a enviar por sms, y luego activar la
			 * serial task
			 */

			/* Activates the SerialEchoTask task */
			ActivateTask(TelitSMSTask);
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

	/* TEC2: boton de panico para activar la alarma
	 *  */
	if (TEC2_MASK & edgeUpKeys)
	{
		if(systemOn!=0){
			alarma=1;
			countAlarm=0;
			serialSend=1;
		}
	}

	/* TEC3: cambiar numero */
	if (TEC3_MASK & edgeUpKeys)
	{
		CancelAlarm(ActivatePeriodicTask);
		CancelAlarm(ActivateKeysTask);
		serialSend=0;
		outputs=0b11001000;
		ciaaPOSIX_write(fd_out, &outputs, 1);
		ActivateTask(TelitSMSTask);
	}

	/* TEC4: toogle systemOn */
	if (TEC4_MASK & edgeUpKeys)
	{
		systemOn=~systemOn;
		if(systemOn==0){
			outputs=0b11010000;
			ciaaPOSIX_write(fd_out, &outputs, 1);
		}else
			outputs =LEDS_RESET;
	}

	/* terminate task */
	TerminateTask();
}

TASK(ListenTelitTask){
	outputs=~outputs;
	ciaaPOSIX_write(fd_out, &outputs, 1);
	//Esta tarea se encarga de leer lo que envia el telit y activa eventos
	ciaaPOSIX_read(fd_uart2,message2, 50);
	strcat(message,message2);
	//ciaaPOSIX_write(fd_uart1, message, ciaaPOSIX_strlen(message));
	//	char str[15]=strstr(message,"CNE:")
	//	if((str!=NULL)){
	//		numEmerg=str
	//	}
	if((strstr(message,"OK")!=NULL)){
		CancelAlarm(ActivateListenTelitTask);
		TaskStateType state=4;
		GetTaskState(TelitSMSTask,&state);
		if(WAITING	== state){//Si TelitSMSTask esta en estado waiting entonces
			if(serialSend==0){//Si tenemos que leer los mensajes recibidos
				if(strstr(message,"CNE")!=NULL){//Si el msj contiene la palabra clave "CNE" se recibio un msj que pretende cambiar el numero
					int count=4,indice=strlen(message); //llendo desde el "OK hacia el inicio del mensaje deberian haber 4 /n, asi guardamos solo el mensaje y no todo el eco"
					while(count>0){
						if(message[--indice]=='\n'){
							--count;
						}
					}
					int i;
					indice++;
					for(i=indice;i<strlen(message);i++)
					{
						if(message[i]!='\r'){
							chNumEmerg[i-indice]=message[i];
						}else{
							chNumEmerg[i-indice]=0;
							break;
						}
					}
					SetEvent(TelitSMSTask,EventOK);
				}else{
					SetEvent(TelitSMSTask,EventErrorCode);
				}
			}else
				SetEvent(TelitSMSTask,EventOK);
		}else{
			SetEvent(TelitInitTask,EventOK);
		}
		memset(message, 0, sizeof(message));//Limpiar el msj total cuando encuentra la condicion
	}else if ((strstr(message,">")!=NULL)){
		memset(message, 0, sizeof(message));//Limpiar el msj total cuando encuentra la condicion
		CancelAlarm(ActivateListenTelitTask);
		SetEvent(TelitSMSTask,EventPromt);
	}else if ((strstr(message,"ERROR")!=NULL)){
		memset(message, 0, sizeof(message));//Limpiar el msj total cuando encuentra la condicion
		CancelAlarm(ActivateListenTelitTask);
		SetEvent(TelitSMSTask,EventErrorCode);
		//	}else if ((strstr(message,"CMGS:")!=NULL)){
		//		CancelAlarm(ActivateListenTelitTask);
		//		SetEvent(TelitSMSTask,EventSMSSend);
	}

	memset(message2, 0, sizeof(message2));
	ciaaPOSIX_write(fd_out, &outputs, 1);
	TerminateTask();
}

TASK(TelitInitTask)
{
	static char countTelit=TELIT_TIME_ON;

	outputs=~outputs;
	ciaaPOSIX_write(fd_out, &outputs, 1);
	if(countTelit--==0){
		ciaaPOSIX_write(fd_out, &outputs, 1);
		CancelAlarm(ActivateTelitInitTask);
		strcpy(message,"AT+CMGF=1\r\n");
		ciaaPOSIX_write(fd_uart2, message, ciaaPOSIX_strlen(message));
		memset(message, 0, sizeof(message));
		SetRelAlarm(ActivateListenTelitTask,999,500);
		WaitEvent(EventOK);
		ClearEvent(EventOK);
		strcpy(message,"AT+COPS=0\r\n");
		ciaaPOSIX_write(fd_uart2, message, ciaaPOSIX_strlen(message));
		memset(message, 0, sizeof(message));
		SetRelAlarm(ActivateListenTelitTask,1000,200);
		WaitEvent(EventOK);
		ClearEvent(EventOK);
		strcpy(message,"AT+FCLASS=0\r\n");
		ciaaPOSIX_write(fd_uart2, message, ciaaPOSIX_strlen(message));
		memset(message, 0, sizeof(message));
		SetRelAlarm(ActivateListenTelitTask,1000,500);
		WaitEvent(EventOK);
		ClearEvent(EventOK);
		strcpy(message,"AT+CMGD=1,4\r\n");									//borra sms en la sim
		ciaaPOSIX_write(fd_uart2, message, ciaaPOSIX_strlen(message));
		memset(message, 0, sizeof(message));
		SetRelAlarm(ActivateListenTelitTask,1000,500);
		WaitEvent(EventOK);
		ClearEvent(EventOK);
		/* activate periodic task:
		 *  - for the first time after 1000 ticks (1000 ms)
		 *  - and then every tick ticks (definido como macro)
		 */
		SetRelAlarm(ActivatePeriodicTask, 1000, TICK);
		SetRelAlarm(ActivateKeysTask, 50, 50);
		outputs=LEDS_RESET;
	}
	TerminateTask();
}


/*
 * Esto se usa para debuguear y ver los valores. se deberia implementar aca la
 * comunicacion serie con el modulo telit
 */
TASK(TelitSMSTask)
//Esta tarea se encarga de escribir en el telit y esperar por los eventos
{
	EventMaskType Events;
	if(serialSend==1){
		strcpy(message,"AT+CMGS=\"");
		strcat(message,numEmerg);
		strcat(message,"\"\r\n");
		ciaaPOSIX_write(fd_uart2, message, ciaaPOSIX_strlen(message));
		memset(message, 0, sizeof(message));
		SetRelAlarm(ActivateListenTelitTask,1000,500);
		WaitEvent(EventPromt);
		ClearEvent(EventPromt);
		char alarm[]="Rescatar\nHH:mm:SS\n-30.9064706\n-47.9420838";
		int leng=ciaaPOSIX_strlen(alarm);
		alarm[leng]=0x1A;
		alarm[leng+1]=0;
		ciaaPOSIX_write(fd_uart2, alarm, ciaaPOSIX_strlen(alarm));
		memset(message, 0, sizeof(message));
		SetRelAlarm(ActivateListenTelitTask,8000,1000);
		/*
		 * El problema esta aca, si lo hacemos con breakpoints funciona! :)
		 * POr eso lo dejamos que espere 8segundos
		 * */
		WaitEvent(EventOK);
		ClearEvent(EventOK);
		outputs=0b11010000;
		ciaaPOSIX_write(fd_out, &outputs, 1);
		alarma=0;
		systemOn=0;
	}else
		if(serialSend==0){
			strcpy(message,"AT+CMGR=1\r\n");//Para leer el primer mensaje
			ciaaPOSIX_write(fd_uart2, message, ciaaPOSIX_strlen(message));
			memset(message, 0, sizeof(message));
			SetRelAlarm(ActivateListenTelitTask,8000,1000);
			WaitEvent(EventOK | EventErrorCode);
			GetEvent(TelitSMSTask, &Events);
			ClearEvent(Events);
			if (Events & EventOK) {
				//ANALIZAR chNumEmerg
				//Tiene "CNE" hay que cambiarlo
				if((strstr(chNumEmerg,"CNE")!=NULL)){
					//Si cumple la condicion de la HASH
					int i=0;
					while (chNumEmerg[i]!=','){
						numEmerg[i]=chNumEmerg[i];//CAMBIAR numEmerg
						i++;
					}
				}
				outputs=LEDS_RESET;
			}
			else{
				outputs=0b11010000;
			}
			ciaaPOSIX_write(fd_out, &outputs, 1);

			/*
			 * FORMATO DEL MSJ RECIBIDO PARA CAMBIR EL NUMERO DE EMERGENCIA:
			 * "NNNNNNNNNN,PASSWORD,CNE" PASSWORD SERA UN NUMERO CALCULADO
			 *  MEDIANTE UNA FUNCION HASH DEPENDIENTE DE "NNNNNNNNNN" (NUMERO
			 *  QUE SE DESEA SETEAR)
			 */

			/*
			if(serialSend==0){
			strcpy(message2,"AT+CMGR=1\r\n");
			ciaaPOSIX_write(fd_uart2, message2, ciaaPOSIX_strlen(message2));
			memset(message, 0, sizeof(message));
			ciaaPOSIX_read(fd_uart2,message2, 180);
			ciaaPOSIX_write(fd_uart1, message, ciaaPOSIX_strlen(message));
			while((strstr(message2,"OK")==NULL) && (strstr(message2,"+CMS ERROR: 321")==NULL)){		//321 no hay mensajes recibidos
				memset(message, 0, sizeof(message));
				ciaaPOSIX_read(fd_uart2,message2, 180);
				ciaaPOSIX_write(fd_uart1, message, ciaaPOSIX_strlen(message));
			}
			 */


		}
	SetRelAlarm(ActivatePeriodicTask, 1000, TICK);
	SetRelAlarm(ActivateKeysTask, 50, 50);
	TerminateTask();
}


/*
 * PROBLEMAS
 * -- la calibracion deberia hacerse despues de 30 ms(pag * 12 del datashet)
 * -- el boton cancelar deberia llamar a una recalibracion? si cancelo con los angulos
 * de posicion superancdo los limites se va a volver a llamar la alarma
 */

