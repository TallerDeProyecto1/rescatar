///*==================[inclusions]=============================================*/
#include "../../Rescatar/inc/MPU_6050.h"

#include "ciaak.h"            /* <= ciaa kernel header */
#include <math.h>

#define grav -9.81
#define peso 0.95
#define radagra 57.3   // 180/pi
#define phi 3.141592


int16_t x_gyro_offset,y_gyro_offset,z_gyro_offset,x_accel_offset,y_accel_offset,z_accel_offset;
uint8_t regAdress,data_byte;
int16_t data_word;
float dt;
static float xgyro=0,ygyro=0,zgyro=0,xacc=0,yacc=0,zacc=0;

int32_t  MPU_6050_open(uint32_t  clockRate){
	int32_t	fd_i2c = ciaaPOSIX_open("/dev/i2c/0", O_RDWR);//Abrimos el file descriptor para i2c (I2C0)
	ciaaPOSIX_ioctl(fd_i2c, ciaaPOSIX_IOCTL_SET_CLOCKRATE, (void *)clockRate);//Configuramos el clockrate
	ciaaPOSIX_ioctl(fd_i2c, ciaaPOSIX_IOCTL_SET_SLAVEADD, (void *)MPU6050_ADDRESS);//Configuramos la direccion del esclavo
	return fd_i2c;
}

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
	uint8_t data;
	MPU_6050_readReg (fd_i2c,MPU6050_RA_WHO_AM_I,&data);
	if(data!=0x68)
		return (1==0);
	MPU_6050_readReg (fd_i2c,MPU6050_RA_GYRO_CONFIG,&data);
	if(data&&0b00011000!=0)
		return (1==0);
	return (1==1);
}



//	*reg=floorf(*reg * 10) / 10;

/*
 * filtro
 */
//	switch (add){
//	case MPU6050_RA_GYRO_XOUT_H:
//		float pitchAcc = atan2f((float)accData[1], (float)accData[2]) * 180 / M_PI;
//		*reg = *reg * 0.98 + pitchAcc * 0.02;
//		break;
//		//		case MPU6050_RA_GYRO_YOUT_H:data_word=(data_word | data_byte)+y_gyro_offset;break;
//		//		case MPU6050_RA_GYRO_ZOUT_H:data_word=(data_word | data_byte)+z_gyro_offset;break;
//	}


uint8_t  MPU_6050_readData(int32_t	fd_i2c,float *xg,float *yg,float *zg,float *xa,float *ya,float *za){
	regAdress=MPU6050_RA_INT_STATUS;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	if((data_byte & 0b00000001) ==1){
		/*
		 * accel registro x
		 */
		regAdress=MPU6050_RA_ACCEL_XOUT_H;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=(int16_t)((data_byte<<8)&0xff00);
		++regAdress;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=((data_word | data_byte)+x_accel_offset);
		*xa=((float)data_word)/(INT16_MAX/AFS_SEL);
		*xa=(*xa)*grav;
		/*
		 * accel registro y
		 */
		regAdress=MPU6050_RA_ACCEL_YOUT_H;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=(int16_t)((data_byte<<8)&0xff00);
		++regAdress;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=((data_word | data_byte)+y_accel_offset);
		*ya=((float)data_word)/(INT16_MAX/AFS_SEL);
		*ya=(*ya)*grav;
		/*
		 * accel registro z
		 */
		regAdress=MPU6050_RA_ACCEL_ZOUT_H;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=(int16_t)((data_byte<<8)&0xff00);
		++regAdress;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=((data_word | data_byte)+z_accel_offset);
		*za=((float)data_word)/(INT16_MAX/AFS_SEL);
		*za=(*za)*grav;
		/*
		 * gyro registro x
		 */
		regAdress=MPU6050_RA_GYRO_XOUT_H;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=(int16_t)((data_byte<<8)&0xff00);
		++regAdress;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=(data_word | data_byte)+x_gyro_offset;

		//filtro registro x

		*xg=peso*((((float)data_word/(INT16_MAX/FS_SEL)))*dt+*xg)+(1-peso)*atan(*ya/(sqrt(pow(*xa,2)+pow(*za,2))))*(float)radagra;

		/*
		 * gyro registro y
		 */
		regAdress=MPU6050_RA_GYRO_YOUT_H;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=(int16_t)((data_byte<<8)&0xff00);
		++regAdress;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=(data_word | data_byte)+y_gyro_offset;

		//filtro registro y
		*yg=peso*((((float)data_word/(INT16_MAX/FS_SEL)))*dt+*yg)-(1-peso)*atan(*xa/(sqrt(pow(*ya,2)+pow(*za,2))))*(float)radagra;

		/*
		 * gyro registro z
		 */
		regAdress=MPU6050_RA_GYRO_ZOUT_H;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=(int16_t)((data_byte<<8)&0xff00);
		++regAdress;
		MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
		data_word=(data_word | data_byte)+z_gyro_offset;
		*zg+=(((float)data_word/(INT16_MAX/FS_SEL)))*dt;
		//filtro registro z debe ser implementado de otra forma

		//*zg=peso*((((float)data_word/(INT16_MAX/FS_SEL)))*dt+*zg)+(1-peso)*atan2f(*xa,*ya)*(float)radagra;

		/*
		 * no se si son necesarias
		 */
		xgyro=*xg;
		ygyro=*yg;
		zgyro=*zg;
		xacc=*xa;
		yacc=*ya;
		zacc=*za;
		/*
		 *
		 */

		return 1;
	}
	return 0;
}

uint8_t  MPU_6050_calibrate(int32_t	fd_i2c){
	char count=0;
	while(count<150)
		count++;
	regAdress=MPU6050_RA_ACCEL_XOUT_H;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(int16_t)((data_byte<<8)&0xff00);
	++regAdress;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(data_word | data_byte);
	x_accel_offset=-data_word;
	regAdress=MPU6050_RA_ACCEL_YOUT_H;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(int16_t)((data_byte<<8)&0xff00);
	++regAdress;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(data_word | data_byte);
	y_accel_offset=-data_word;
	regAdress=MPU6050_RA_ACCEL_ZOUT_H;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(int16_t)((data_byte<<8)&0xff00);
	++regAdress;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(data_word | data_byte);
	z_accel_offset=((float)INT16_MAX/AFS_SEL)-data_word;
	//
	regAdress=MPU6050_RA_GYRO_XOUT_H;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(int16_t)((data_byte<<8)&0xff00);
	++regAdress;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(data_word | data_byte);
	x_gyro_offset=-data_word;
	regAdress=MPU6050_RA_GYRO_YOUT_H;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(int16_t)((data_byte<<8)&0xff00);
	++regAdress;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(data_word | data_byte);
	y_gyro_offset=-data_word;
	regAdress=MPU6050_RA_GYRO_ZOUT_H;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(int16_t)((data_byte<<8)&0xff00);
	++regAdress;
	MPU_6050_readReg(fd_i2c,regAdress,&data_byte);
	data_word=(data_word | data_byte);
	z_gyro_offset=-data_word;
	return UINT8_MAX;
}

uint8_t  MPU_6050_setup(int32_t	fd_i2c,uint16 tick){
	dt=((float)tick)/1000;
	//La siguiente funcion despierta al MPU que por defecto esta durmiendo.
	MPU_6050_writeReg(fd_i2c,MPU6050_RA_PWR_MGMT_1,0);

	//la siguiente es para habilitar las interrupcionescuando la data este lista
	MPU_6050_writeReg(fd_i2c,MPU6050_RA_INT_ENABLE,1);

	//la siguiente linea es para seleccionar la escala del gyroscopio +-250º/s
	//MPU_6050_writeReg(fd_i2c,MPU6050_RA_GYRO_CONFIG,0);

	//filtro
	MPU_6050_writeReg(fd_i2c,MPU6050_RA_CONFIG,6);

	/*
	 * Calibrate sensor
	 */
	MPU_6050_calibrate(fd_i2c);

	/*
	 * Compruebo que el sensor funciona correctamente
	 */
	if(MPU_6050_test(fd_i2c)==1)
		return 1;
	return 0;
}


//
//	/*
//	 * Para probar si hay esclavos...
//	 * PROBAR ESCLAVOS
//	 */
//	//      		int i;
//	//      			uint8_t ch;
//	//
//	//      			for (i = 0; i <= 0x7F; i++) {
//	//
//	//      				if (Chip_I2C_MasterRead(I2C0, i, &ch, 1 ) > 0) {
//	//      					ciaaPOSIX_printf("NO anda!!!\n");//Aca poner un breakpoint y ver cuando para que valor tiene ch
//	//      				}
//	//
//	//      			}
//	//
