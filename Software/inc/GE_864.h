#ifndef _GE_864_H_
#define _GE_864_H_

/*==================[inclusions]=============================================*/
#include "ciaak.h"            /* <= ciaa kernel header (para los tipos de datos...:))*/
#include "os.h"               /* <= operating system header */

/*==================[macros]=================================================*/

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

/*
 * Esta funcion prueba que funciona escribiendo el comando "AT" y esperando un
 * "OK" como respuesta, si la lectura da "OK" entonces la funcion retorna 1,en
 *  caso contrario devolvera 0
 ** \param[in] fd_i2c Device path XXXXXXXXXX
 ** \return
 ** 		1 si pasa el test
 ** 		0 si no lo pasa
 */
uint8_t  GE_864_test(int32_t fd_i2c,int32_t fd_uart2);

/*
 * La siguiente funcion debe iniciar el modulo para que no haya necesidad de
 * apretar el boton ON (debemos mantener en bajo algun pin conectado a el pin
 * ON del modulo GE864, durante un segundo)
 ** \param[in] fd_i2c Device path XXXXXXXXXX
 ** \return 1 TODO quiza deba ser mejorado
 */
uint8_t  GE_864_turnOn(int32_t	fd_i2c);


/*
 * La siguiente funcion realiza la configuracion inicial del modulo
 * >Secuencia de comandos para que quede listo para mandar SMSs
 ** \param[in]
 ** \param[in]
 ** \return 1 TODO quiza deba ser mejorado
 */
uint8_t  GE_864_setup(int32_t	param1,uint16 param2);

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */

/*==================[end of file]============================================*/
#endif /* #ifndef _GE_864_H_ */

