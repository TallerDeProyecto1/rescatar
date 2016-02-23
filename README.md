# rescatAR
El presente proyecto pretende contribuir a disminuir la fatalidad en las rutas argentinas, mediante la integración de la tecnología GSM/GPRS, sensores de aceleración, giroscopios y la Computadora Industrial Abierta Argentina,  en un dispositivo capaz de determinar cuándo se produce un siniestro automovilístico que requiera la intervención de los servicios de asistencia médica y ser capaz de enviar un pedido de socorro.

##Objetivos
El objetivo primario del proyecto consiste en lograr que la CIAA recoja y analice datos de un acelerómetro para detectar colisiones automovilísticas,utilizando un módulo GSM/GPRS para poder reportar las mismas a los servicios de asistencia, contando con un conjunto de teclas y luces para la interacción con el usuario(como por ejemplo un botón de pánico y un botón para cancelar la alerta).
Paralelamente, se desarrolló una aplicación android que instalada en el teléfono que recibe el mensaje SMS de socorro muestra en un mapa interactivo la ubicación del accidente.
Al no poder disponer de un dispositivo GPS, se recurrió a simular  mediante coordenadas arbitrarias la ubicación del pedido de ayuda. No obstante, se pretende seguir avanzando con el proyecto y realizar las modificaciones necesarias para la incorporación de un módulo GPS que permita determinar con precisión la locación del siniestro automovilístico.
