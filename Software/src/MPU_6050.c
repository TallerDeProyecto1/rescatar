///*==================[inclusions]=============================================*/
#include "../../Rescatar/inc/MPU_6050.h"

#include "ciaak.h"            /* <= ciaa kernel header */
#include <math.h>			//para arcotg en filtro

/*==================[macros]=================================================*/

#define GRAV 		-9.81
#define PESO 		0.95
#define RADAGRA 	57.3   			// 180/pi
#define PHI 		3.141592

/*==================[internal data declaration]==============================*/

/*en esta estructura guardo los offset luego de la calibracion*/
static MPU_data_struct MPU_data_offset;
/*dt almacena el delta tiempo (en ms) segun el cual se toman las muestras*/
static float dt;
/* en esta estructura guardo las lecturas del MPU*/
static MPU_data_struct MPU_data;



/*==================[external functions definition]==========================*/


uint8_t  MPU_6050_readReg(int32_t	fd_i2c,uint8_t RegAddress,uint8_t *data){
	ciaaPOSIX_write(fd_i2c,&RegAddress,1);/*
	 * Escribir Register Address de donde queremos leer, tener en
	 * cuenta que el metodo "ciaaPOSIX_write" ya de por si realiza
	 * una escritura en el bus de la add del slave. (Ver secuencia en pagina 36/52 del datasheet del MPU6050)
	 * */
	ciaaPOSIX_read(fd_i2c,data,1);/*Leer el dato :)*/
	return *data;
}

uint8_t  MPU_6050_writeReg(int32_t	fd_i2c,uint8_t RegAddress,uint8_t data){
	uint8_t datos[]={RegAddress,data};//Cargar arreglo con direccion y dato a escribir
	ciaaPOSIX_write(fd_i2c,datos,2);//LLamar a escribir, tener en cuenta que lo hace en dos pasos,(Ver secuencia en pagina 36/52 del datasheet del MPU6050)
	return 0;
}

uint8_t  MPU_6050_test(int32_t fd_i2c){
	/*sirve para almacenar temporalmente los valores de los registros que contienen
	 *datos de 8bits
	 */
	uint8_t data;

	MPU_6050_readReg (fd_i2c,MPU6050_RA_WHO_AM_I,&data);
	if(data!=0x68)
		return (0);
	return 1;
}


uint8_t  MPU_6050_update(int32_t	fd_i2c,MPU_data_struct *datos){
	/*sirve para almacenar temporalmente los valores de los registros que contienen
	 *datos de 16bits
	 */
	int16_t data_word;

	/*sirve para almacenar temporalmente los valores de los registros que contienen
	 *datos de 8bits
	 */
	uint8_t data_byte;

	/*sirve para almacenar temporalmente las direcciones a pasar como parametro de los
	 * registros que deberan ser leidos
	 */
	uint8_t regAdress;

	regAdress=MPU6050_RA_INT_STATUS;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	if((data_byte & 0b00000001) ==1){
		/*
		 * lectura y escalamiento del registro x del acelerometro
		 */
		regAdress=MPU6050_RA_ACCEL_XOUT_H;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=(int16_t)((data_byte<<8)&0xff00);
		++regAdress;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=((data_word | data_byte)+MPU_data_offset.xacc);
		MPU_data.xacc=((float)data_word)/(INT16_MAX/AFS_SEL);
		MPU_data.xacc=MPU_data.xacc*GRAV;

		/*
		 * lectura y escalamiento del registro y del acelerometro
		 */
		regAdress=MPU6050_RA_ACCEL_YOUT_H;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=(int16_t)((data_byte<<8)&0xff00);
		++regAdress;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=((data_word | data_byte)+MPU_data_offset.yacc);
		MPU_data.yacc=((float)data_word)/(INT16_MAX/AFS_SEL);
		MPU_data.yacc=MPU_data.yacc*GRAV;

		/*
		 * lectura y escalamiento del registro z del acelerometro
		 */
		regAdress=MPU6050_RA_ACCEL_ZOUT_H;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=(int16_t)((data_byte<<8)&0xff00);
		++regAdress;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=((data_word | data_byte)+MPU_data_offset.zacc);
		MPU_data.zacc=((float)data_word)/(INT16_MAX/AFS_SEL);
		MPU_data.zacc=(MPU_data.zacc)*GRAV;

		/*
		 * lectura del registro x del giroscopio
		 */
		regAdress=MPU6050_RA_GYRO_XOUT_H;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=(int16_t)((data_byte<<8)&0xff00);
		++regAdress;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=(data_word | data_byte)+MPU_data_offset.xgyro;

		//filtro y escalamiento del registro x del giroscopio

		MPU_data.xgyro=PESO*((((float)data_word/(INT16_MAX/FS_SEL)))*dt+MPU_data.xgyro)+(1-PESO)*atan(MPU_data.yacc/(sqrt(pow(MPU_data.xacc,2)+pow(MPU_data.zacc,2))))*(float)RADAGRA;

		/*
		 * lectura del registro y del giroscopio
		 */
		regAdress=MPU6050_RA_GYRO_YOUT_H;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=(int16_t)((data_byte<<8)&0xff00);
		++regAdress;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=(data_word | data_byte)+MPU_data_offset.ygyro;

		//filtro y escalamiento del registro y del giroscopio
		MPU_data.ygyro=PESO*((((float)data_word/(INT16_MAX/FS_SEL)))*dt+MPU_data.ygyro)-(1-PESO)*atan(MPU_data.xacc/(sqrt(pow(MPU_data.yacc,2)+pow(MPU_data.zacc,2))))*(float)RADAGRA;

		/*
		 * lectura y escalamiento del registro z del giroscopio
		 */
		regAdress=MPU6050_RA_GYRO_ZOUT_H;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=(int16_t)((data_byte<<8)&0xff00);
		++regAdress;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=(data_word | data_byte)+MPU_data_offset.zgyro;
		MPU_data.zgyro+=(((float)data_word/(INT16_MAX/FS_SEL)))*dt;

		//filtro registro z debe ser implementado de otra forma

		*datos=MPU_data;
		return 1;
	}
	return 0;
}

uint8_t  MPU_6050_calibrate(int32_t	fd_i2c){
	/*sirve para almacenar temporalmente los valores de los registros que contienen
	 *datos de 16bits
	 */
	int16_t data_word;

	/*sirve para almacenar temporalmente los valores de los registros que contienen
	 *datos de 8bits
	 */

	uint8_t data_byte;
	/*sirve para almacenar temporalmente las direcciones a pasar como parametro de los
	 * registros que deberan ser leidos
	 */
	uint8_t regAdress;

	/*calcular offset del registro x del acelerometro*/
	regAdress=MPU6050_RA_ACCEL_XOUT_H;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(int16_t)((data_byte<<8)&0xff00);
	++regAdress;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(data_word | data_byte);
	MPU_data_offset.xacc=-data_word;

	/*calcular offset del registro y del acelerometro*/
	regAdress=MPU6050_RA_ACCEL_YOUT_H;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(int16_t)((data_byte<<8)&0xff00);
	++regAdress;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(data_word | data_byte);
	MPU_data_offset.yacc=-data_word;

	/*calcular offset del registro z del acelerometro*/
	regAdress=MPU6050_RA_ACCEL_ZOUT_H;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(int16_t)((data_byte<<8)&0xff00);
	++regAdress;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(data_word | data_byte);
	MPU_data_offset.zacc=((float)INT16_MAX/AFS_SEL)-data_word;

	/*calcular offset del registro x del giroscopio*/
	regAdress=MPU6050_RA_GYRO_XOUT_H;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(int16_t)((data_byte<<8)&0xff00);
	++regAdress;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(data_word | data_byte);
	MPU_data_offset.xgyro=-data_word;

	/*calcular offset del registro y del giroscopio*/
	regAdress=MPU6050_RA_GYRO_YOUT_H;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(int16_t)((data_byte<<8)&0xff00);
	++regAdress;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(data_word | data_byte);
	MPU_data_offset.ygyro=-data_word;

	/*calcular offset del registro z del giroscopio*/
	regAdress=MPU6050_RA_GYRO_ZOUT_H;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(int16_t)((data_byte<<8)&0xff00);
	++regAdress;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(data_word | data_byte);
	MPU_data_offset.zgyro=-data_word;
	return 1;
}

uint8_t  MPU_6050_setup(int32_t	fd_i2c,uint16 tick){
	dt=((float)tick)/1000;
	//La siguiente funcion despierta al MPU que por defecto esta durmiendo.
	MPU_6050_writeReg(fd_i2c,MPU6050_RA_PWR_MGMT_1,0);

	//la siguiente es para habilitar las interrupcionescuando la data este lista
	MPU_6050_writeReg(fd_i2c,MPU6050_RA_INT_ENABLE,1);

	//la siguiente linea es para seleccionar la escala del gyroscopio +-250º/s
	//MPU_6050_writeReg(fd_i2c,MPU6050_RA_GYRO_CONFIG,0);

	//TODO ver si la siguiente es para habilitar el filtro
	MPU_6050_writeReg(fd_i2c,MPU6050_RA_CONFIG,6);

	/*
	 * TODO esta funcion deberia llamarse luego de 30 ms
	 * Calibrate sensor
	 */
	MPU_6050_calibrate(fd_i2c);

	return 1;
}
