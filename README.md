# StreamMOCK
Libreria para el manejo de MOCKs de objetos Stream, especialmente para usar como un MOCK del puerto serie en pruebas unitarias

###Crear MOCK:
```cpp
StreamMOCK fakeSerial; 		/*Nuevo MOCK*/
```

###Obtención de datos de utilidad
```cpp
/*	Lectura del Buffer de escritura, este guarda los bytes escritos por medio
*	StreamMOCK::write()*/
byte datoEscrito = fakeSerial.writeBuffer[0];

/*	Simulación de lectura de datos en buffer de entrada*/
fakeSerial.readBuffer[0] = 'A';
faKeSerial.availableBytes = 1;

byte datoLectura = fakeSerial.read(); /*ahora datoLectura = 'A' y fakeSerial.availableBytes = 0*/

/*	Lectura de llamadas a métodos de StreamMOCK*/
fakeSerial.availableCalls(); /*Regresa el numero de ejecuciones de fakeSerial.avilable()*/
fakeSerial.readCalls(); /*Regresa el numero de ejecuciones de fakeSerial.read()*/
fakeSerial.writeCalls(); /*Regresa el numero de ejecuciones de fakeSerial.write()*/
fakeSerial.flushCalls(); /*Regresa el numero de ejecuciones de fakeSerial.flush()*/

```
