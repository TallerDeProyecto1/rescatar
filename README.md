# rescatAR
El presente proyecto pretende contribuir a disminuir la fatalidad en las rutas argentinas, mediante la integración de la tecnología GSM/GPRS, sensores de aceleración, giroscopios y la Computadora Industrial Abierta Argentina,  en un dispositivo capaz de determinar cuándo se produce un siniestro automovilístico que requiera la intervención de los servicios de asistencia médica y ser capaz de enviar un pedido de socorro.

##Objetivos
El objetivo primario del proyecto consiste en lograr que la CIAA recoja y analice datos de un acelerómetro para detectar colisiones automovilísticas,utilizando un módulo GSM/GPRS para poder reportar las mismas a los servicios de asistencia, contando con un conjunto de teclas y luces para la interacción con el usuario(como por ejemplo un botón de pánico y un botón para cancelar la alerta).
Paralelamente, se desarrolló una aplicación android que instalada en el teléfono que recibe el mensaje SMS de socorro muestra en un mapa interactivo la ubicación del accidente.
Al no poder disponer de un dispositivo GPS, se recurrió a simular  mediante coordenadas arbitrarias la ubicación del pedido de ayuda. No obstante, se pretende seguir avanzando con el proyecto y realizar las modificaciones necesarias para la incorporación de un módulo GPS que permita determinar con precisión la locación del siniestro automovilístico.

## Uso

El proyecto esta dividicdo en distintos modulos organizado en carpetas: 
* [Hardware](https://github.com/TallerDeProyecto1/rescatar/tree/master/Hardware)
* [Software](https://github.com/TallerDeProyecto1/rescatar/tree/master/Software)
* [Aplicacion Android](https://github.com/TallerDeProyecto1/rescatar/tree/master/RescatarApp) 


Cada modulo como se indica a continuacion se desarrolla con diferentes herramientas:

**Hardware**: Abarca los circuitos diseñados para regular la tension de alimentacion de los dispositivos para lo cual utilizo [KiCad](http://kicad-pcb.org/) en su version: (2013-jul-07)-stable


**Software**: El desarrollo del software que corre la edu-ciaa se se realizo utilizando la implementacion de OSEK del _proyecto ciaa_, cabe aclarar que se utilizo la version del firmware que reside en el branch [I2C](https://github.com/ciaa/Firmware/tree/i2c) de repositorio oficial del [proyecto-ciaa](http://www.proyecto-ciaa.com.ar/) debido a la utilizacion de este protocolo. 


**Aplicacion Android**:Se desarrollo con Android Studio version 1.5.0.


## Integrantes del grupo

Minig Traverso Marcelo

Garcia Manuel
