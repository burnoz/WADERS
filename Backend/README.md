# WADERS
El desarrollo del proyecto fue dividido en tres etapas/componentes: 
* Aplicación web (Javascript)
* Placa de desarrollo (ESP32)
* Base de datos (MongoDB)

## Aplicación web
Para la creación de nuestra app utiilzamos Node.js, un entorno de ejecución de Javascript que destaca por su escalabilidad, alto rendimiento y facilidad de interacción con servicios externos. Cabe destacar además que esta es alojada en los servicios de la nube de Azure. El uso principal que se le dio en nuestro proyecto es la obtención de información de nuestra base de datos, para luego desplegarla en un dashboard amigable para el usuario.

## Placa de desarrollo (ESP32)
Para el funcionamiento de nuestras maquinas y la lectura de datos de los sensores, programamos una placa ESP32 a través de la IDE de Arduino, la cual tiene soporte para esta misma. Los datos recopilados son mostrado a través del monitor serial para verificar que todo esté funcionando correctamente y luego son enviados a la base de datos para su almacenamiento.

## Base de datos
Para el almacenamiento de la información utilizamos MongoBD, la cual, a pesar de no ser nativa de Azure (nuestro servicio de nube) como CosmosDB, permite una actualización rápida de los datos guardados, tiene una buena integración con Javascript y ofrece una gran capacidad de escalabilidad.

![image](https://user-images.githubusercontent.com/109123551/231694662-ead16cc7-bb61-4a9b-a8b8-e28fc346bb86.png)