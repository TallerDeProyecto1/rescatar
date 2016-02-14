///*==================[inclusions]=============================================*/
#include "../../Rescatar/inc/GE_864.h"

/*==================[macros]=================================================*/

/*==================[internal data declaration]==============================*/

/*==================[external functions definition]==========================*/

uint8_t  GE_864_test(int32_t fd_rs232,int32_t fd_uart2){
	char message[80];
	strcat(message,"AT");
	ciaaPOSIX_write(fd_rs232,message,ciaaPOSIX_strlen(message));
	int ret=ciaaPOSIX_read(fd_rs232,message,4);
	while(ret<4)
		ret=ciaaPOSIX_read(fd_rs232,message,2);
	ciaaPOSIX_write(fd_uart2, message, ciaaPOSIX_strlen(message));
	return 0;

}
uint8_t  GE_864_turnOn(int32_t	fd_rs232){
	//TODO
	return 0;
}
uint8_t  GE_864_setup(int32_t	fd_rs232,uint16 param2){
	//TODO
	return 0;
}
