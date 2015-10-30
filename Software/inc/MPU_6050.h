#ifndef _MPU_6050_H_
#define _MPU_6050_H_

/*==================[inclusions]=============================================*/
#include "ciaak.h"            /* <= ciaa kernel header (para los tipos de datos...:))*/
#include "os.h"               /* <= operating system header */

/*==================[macros]=================================================*/

#define MPU6050_ADDRESS 				0b1101000 // Address 7bits (for AD0 low)
#define MPU6050_RA_XG_OFFS_TC 			0x00 //[7] PWR_MODE, [6:1] XG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU6050_RA_YG_OFFS_TC 			0x01 //[7] PWR_MODE, [6:1] YG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU6050_RA_ZG_OFFS_TC 			0x02 //[7] PWR_MODE, [6:1] ZG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU6050_RA_X_FINE_GAIN 			0x03 //[7:0] X_FINE_GAIN
#define MPU6050_RA_Y_FINE_GAIN 			0x04 //[7:0] Y_FINE_GAIN
#define MPU6050_RA_Z_FINE_GAIN 			0x05 //[7:0] Z_FINE_GAIN
#define MPU6050_RA_XA_OFFS_H 			0x06 //[15:0] XA_OFFS
#define MPU6050_RA_XA_OFFS_L_TC 		0x07
#define MPU6050_RA_YA_OFFS_H 			0x08 //[15:0] YA_OFFS
#define MPU6050_RA_YA_OFFS_L_TC 		0x09
#define MPU6050_RA_ZA_OFFS_H	 		0x0A //[15:0] ZA_OFFS
#define MPU6050_RA_ZA_OFFS_L_TC 		0x0B
#define MPU6050_RA_XG_OFFS_USRH 		0x13 //[15:0] XG_OFFS_USR
#define MPU6050_RA_XG_OFFS_USRL 		0x14
#define MPU6050_RA_YG_OFFS_USRH 		0x15 //[15:0] YG_OFFS_USR
#define MPU6050_RA_YG_OFFS_USRL 		0x16
#define MPU6050_RA_ZG_OFFS_USRH 		0x17 //[15:0] ZG_OFFS_USR
#define MPU6050_RA_ZG_OFFS_USRL 		0x18
#define MPU6050_RA_SMPLRT_DIV 			0x19
#define MPU6050_RA_CONFIG				0x1A
#define MPU6050_RA_GYRO_CONFIG 			0x1B
#define MPU6050_RA_ACCEL_CONFIG			0x1C
#define MPU6050_RA_FF_THR				0x1D
#define MPU6050_RA_FF_DUR 				0x1E
#define MPU6050_RA_MOT_THR 				0x1F
#define MPU6050_RA_MOT_DUR 				0x20
#define MPU6050_RA_ZRMOT_THR 			0x21
#define MPU6050_RA_ZRMOT_DUR 			0x22
#define MPU6050_RA_FIFO_EN 				0x23
#define MPU6050_RA_I2C_MST_CTRL 		0x24
#define MPU6050_RA_I2C_SLV0_ADDR 		0x25
#define MPU6050_RA_I2C_SLV0_REG 		0x26
#define MPU6050_RA_I2C_SLV0_CTRL 		0x27
#define MPU6050_RA_I2C_SLV1_ADDR 		0x28
#define MPU6050_RA_I2C_SLV1_REG 		0x29
#define MPU6050_RA_I2C_SLV1_CTRL 		0x2A
#define MPU6050_RA_I2C_SLV2_ADDR 		0x2B
#define MPU6050_RA_I2C_SLV2_REG 		0x2C
#define MPU6050_RA_I2C_SLV2_CTRL 		0x2D
#define MPU6050_RA_I2C_SLV3_ADDR 		0x2E
#define MPU6050_RA_I2C_SLV3_REG 		0x2F
#define MPU6050_RA_I2C_SLV3_CTRL 		0x30
#define MPU6050_RA_I2C_SLV4_ADDR 		0x31
#define MPU6050_RA_I2C_SLV4_REG 		0x32
#define MPU6050_RA_I2C_SLV4_DO 			0x33
#define MPU6050_RA_I2C_SLV4_CTRL 		0x34
#define MPU6050_RA_I2C_SLV4_DI 			0x35
#define MPU6050_RA_I2C_MST_STATUS 		0x36
#define MPU6050_RA_INT_PIN_CFG 			0x37
#define MPU6050_RA_INT_ENABLE 			0x38
#define MPU6050_RA_DMP_INT_STATUS 		0x39
#define MPU6050_RA_INT_STATUS 			0x3A
#define MPU6050_RA_ACCEL_XOUT_H 		0x3B
#define MPU6050_RA_ACCEL_XOUT_L 		0x3C
#define MPU6050_RA_ACCEL_YOUT_H 		0x3D
#define MPU6050_RA_ACCEL_YOUT_L 		0x3E
#define MPU6050_RA_ACCEL_ZOUT_H 		0x3F
#define MPU6050_RA_ACCEL_ZOUT_L 		0x40
#define MPU6050_RA_TEMP_OUT_H 			0x41
#define MPU6050_RA_TEMP_OUT_L 			0x42
#define MPU6050_RA_GYRO_XOUT_H 			0x43
#define MPU6050_RA_GYRO_XOUT_L 			0x44
#define MPU6050_RA_GYRO_YOUT_H 			0x45
#define MPU6050_RA_GYRO_YOUT_L 			0x46
#define MPU6050_RA_GYRO_ZOUT_H 			0x47
#define MPU6050_RA_GYRO_ZOUT_L 			0x48
#define MPU6050_RA_EXT_SENS_DATA_00 	0x49
#define MPU6050_RA_EXT_SENS_DATA_01 	0x4A
#define MPU6050_RA_EXT_SENS_DATA_02 	0x4B
#define MPU6050_RA_EXT_SENS_DATA_03 	0x4C
#define MPU6050_RA_EXT_SENS_DATA_04 	0x4D
#define MPU6050_RA_EXT_SENS_DATA_05 	0x4E
#define MPU6050_RA_EXT_SENS_DATA_06 	0x4F
#define MPU6050_RA_EXT_SENS_DATA_07 	0x50
#define MPU6050_RA_EXT_SENS_DATA_08 	0x51
#define MPU6050_RA_EXT_SENS_DATA_09 	0x52
#define MPU6050_RA_EXT_SENS_DATA_10 	0x53
#define MPU6050_RA_EXT_SENS_DATA_11 	0x54
#define MPU6050_RA_EXT_SENS_DATA_12 	0x55
#define MPU6050_RA_EXT_SENS_DATA_13 	0x56
#define MPU6050_RA_EXT_SENS_DATA_14 	0x57
#define MPU6050_RA_EXT_SENS_DATA_15 	0x58
#define MPU6050_RA_EXT_SENS_DATA_16 	0x59
#define MPU6050_RA_EXT_SENS_DATA_17 	0x5A
#define MPU6050_RA_EXT_SENS_DATA_18 	0x5B
#define MPU6050_RA_EXT_SENS_DATA_19 	0x5C
#define MPU6050_RA_EXT_SENS_DATA_20 	0x5D
#define MPU6050_RA_EXT_SENS_DATA_21 	x5E
#define MPU6050_RA_EXT_SENS_DATA_22 	0x5F
#define MPU6050_RA_EXT_SENS_DATA_23 	0x60
#define MPU6050_RA_MOT_DETECT_STATUS 	0x61
#define MPU6050_RA_I2C_SLV0_DO 			0x63
#define MPU6050_RA_I2C_SLV1_DO 			0x64
#define MPU6050_RA_I2C_SLV2_DO 			0x65
#define MPU6050_RA_I2C_SLV3_DO 			0x66
#define MPU6050_RA_I2C_MST_DELAY_CTRL 	0x67
#define MPU6050_RA_SIGNAL_PATH_RESET 	0x68
#define MPU6050_RA_MOT_DETECT_CTRL 		0x69
#define MPU6050_RA_USER_CTRL 			0x6A
#define MPU6050_RA_PWR_MGMT_1 			0x6B
#define MPU6050_RA_PWR_MGMT_2 			0x6C
#define MPU6050_RA_BANK_SEL 			0x6D
#define MPU6050_RA_MEM_START_ADDR 		0x6E
#define MPU6050_RA_MEM_R_W 				0x6F
#define MPU6050_RA_DMP_CFG_1 			0x70
#define MPU6050_RA_DMP_CFG_2 			0x71
#define MPU6050_RA_FIFO_COUNTH 			0x72
#define MPU6050_RA_FIFO_COUNTL 			0x73
#define MPU6050_RA_FIFO_R_W 			0x74
#define MPU6050_RA_WHO_AM_I 			0x75
#define FS_SEL							250
#define AFS_SEL			    			2



#define GRAV 		-9.81
#define PESO 		0.95
#define RADAGRA 	57.3   			// 180/pi
#define PHI 		3.141592


/*==================[typedef]================================================*/
typedef struct{
	float xgyro;
	float ygyro;
	float zgyro;
	float xacc;
	float yacc;
	float zacc;
} MPU_data_struct;

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/


/*
 * La siguiente funcion realiza la lectura del valor del registro "RegAddress" y almacena el valor
 * en la direccion de memoria pasada como parametro "*data"
 * Ademas la funcion devuelve el valor leido
 ** \param[in] fd_i2c Device path /dev/dio/in/0
 ** \param[in] RegAddress direccion del registro a leer
 ** \param[out] data buffer que contiene el valor del registro leido
 ** \return valor del registro leido
 */
uint8_t  MPU_6050_readReg(int32_t	fd_i2c,uint8_t RegAddress,uint8_t *data);

/*
 * La siguiente funcion realiza la escritura del valor "data" en el registro "RegAddress"
 * retorna 0 para decir que la operacion se realizo satisfactoriamente
 ** \param[in] fd_i2c Device path /dev/dio/in/0
 ** \param[in] RegAddress direccion del registro a escribir
 ** \param[out] data buffer que contiene el valor del registro a escribir
 ** \return 0 TODO quiza deba ser mejorado
 */
uint8_t  MPU_6050_writeReg(int32_t	fd_i2c,uint8_t RegAddress,uint8_t data);

/*
 * Esta funcion prueba que funciona realizando la lectura de un registro del MPU6050 que
 * segun el fabricante siempre retorna "0x68". Si la lectura da "0x68" entonces la funcion
 * retorna 1, en caso contrario devolvera 0
 ** \param[in] fd_i2c Device path /dev/dio/in/0
 ** \return
 ** 		1 si pasa el test
 ** 		0 si no lo pasa
 */
uint8_t  MPU_6050_test(int32_t fd_i2c);

/*
 * La siguiente funcion realiza la calibracion del sensor, calculando los offset correspondientes a cada eje
 ** \param[in] fd_i2c Device path /dev/dio/in/0
 ** \return 1 TODO quiza deba ser mejorado
 */
uint8_t  MPU_6050_calibrate(int32_t	fd_i2c);


/*
 * La siguiente funcion realiza la configuracion inicial del sensor
 ** \param[in] fd_i2c Device path /dev/dio/in/0
 ** \param[in] tick delta tiempo (en ms) segun el cual se toman las muestras
 ** \return 1 TODO quiza deba ser mejorado
 */
uint8_t  MPU_6050_setup(int32_t	fd_i2c,uint16 tick);


/*
 * La siguiente funcion actualiza el valor de las medidas del giroscopio y
 * acelerometro
 ** \param[in] fd_i2c Device path /dev/dio/in/0
 ** \param[out] estructura con las variables a actualizar
 ** \return
 ** 		1 si se habian tomado los samples
 ** 		0 si no se habian tomado los samples
 */
uint8_t  MPU_6050_update(int32_t	fd_i2c,MPU_data_struct *datos);

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */

/*==================[end of file]============================================*/
#endif /* #ifndef _BLINKING_H_ */

