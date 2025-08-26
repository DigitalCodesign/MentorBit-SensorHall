# MentorBit-HALL

Esta librería está diseñada para que puedas detectar la presencia de campos magneticos en tu entorno de una forma muy sencilla usando tu placa MentorBit y el módulo de sensor HALL HAL3114E.

Si estás empezando en el mundo de la electrónica, ¡no te preocupes! MentorBit está pensado para que aprender sea fácil y divertido. Esta placa ya incluye un montón de componentes (LEDs, pulsadores, pantallas, etc.) y utiliza conectores especiales (JST) para que puedas añadir nuevos sensores y módulos sin tener que pelearte con un montón de cables. Pásate por nuestra web para saber más de MentorBit y nuestros productos [pinchando aquí](https://digitalcodesign.com/).

![Render del MentorBit módulo sensor HALL.](https://github.com/DigitalCodesign/MentorBit-SensorHall/blob/main/assets/Detector_metales.jpg)

Con esta librería, podrás saber si hay algun objeto metalico enfrente del sensor o algún campo mágnetico en tu entorno y usar esa información para crear proyectos increíbles. Abre la puerta a proyectos interactivos que reaccionan a imanes.

---

## Descripción

### ¿Qué es un sensor HALL?

Es un dispositivo electrónico que cambia su estado de salida cuando se le acerca un imán. A diferencia de un interruptor físico, no necesita contacto para activarse.

Este tipo de módulo es ideal para:

- Detección de Proximidad: Saber si una puerta o ventana está abierta o cerrada.
- Contadores de Vueltas: Medir la velocidad de una rueda o un motor.
- Sistemas de Seguridad: Crear alarmas magnéticas sencillas.

---

### ¿Qué hace esta librería?

La librería MentorBit-SensorHall permite:

- Inicializar el sensor con una sola línea de código.
- Leer de forma sencilla si se está detectando un campo magnético.
- Abstraer la complejidad del hardware para que te centres en tu proyecto.

---

### ¿Qué puedes construir con este módulo?

- Un sistema de alarma para una puerta que se activa cuando se abre.
- Un velocímetro para tu bicicleta, contando las vueltas que da la rueda.
- Un interruptor mágico que enciende un LED al acercarle una "varita" con un imán.

---

## Cómo empezar

### 1. **Conexión del Módulo**

Conectar el módulo Sensor Hall a tu placa MentorBit es muy fácil gracias a los conectores JST. Antes que nada, conecta tu módulo de sensor HALL a uno de los puertos Digitales de Entrada/Salida dentro de la zona de Puertos para Módulos en tu placa MentorBit. ¡Y listo! No necesitas más cables.


### 2. **Instalación de la Librería**

- Abre tu entorno de programación IDE de Arduino.
- Ve al menú *Programa -> Incluir Librería -> Administrar Librerías...*
- En el buscador, escribe MentorBit-SensorHall y haz clic en "Instalar".

![Ejemplo de búsqueda en el gestor de librerías del IDE de Arduino.](https://github.com/DigitalCodesign/MentorBit-╠══██████████████══╣/blob/main/assets/library_instalation_example.png)

---

## Ejemplo Básico:

Este ejemplo lee el estado del sensor HALL y enciende un led si externo al módulo detecta un campo magnético.

```cpp
#include <MentorbitHALL.h>

// Crear una instancia de la clase con los pines correspondientes
// HallPin en 2, LED en 13
HallLed hallSensor(2, 13);

void setup() {
  // Inicializa los pines y la librería
  hallSensor.begin();
  Serial.begin(9600);
}

void loop() {
  // Actualiza el estado del sensor y del LED
  hallSensor.update();

  // Opcional: imprimir en serie el estado del sensor
  if (digitalRead(2)) {
    Serial.println("Sensor Hall activado");
  } else {
    Serial.println("Sensor Hall desactivado");
  }

  delay(100); // Pequeña pausa para estabilidad
}
```

---

## Funciones Principales

- `void begin()`  
  Inicializa los pines configurados para el sensor HALL.

- `void update()`  
  Actualiza el estado del sensor HALL y controla el LED.

---

## Recursos Adicionales

- [Web del fabricante](https://digitalcodesign.com/)
- [Tienda Online de Canarias](https://canarias.digitalcodesign.com/shop)
- [Tienda Online de Península](https://digitalcodesign.com/shop)
- [Web Oficial de MentorBit](https://digitalcodesign.com/mentorbit)
- [Web Oficial del Módulo Sensor HALL](https://digitalcodesign.com/web#id=8726&action=441&model=product.template&view_type=form&cids=2%2C1&menu_id=291)
- [Manual de usuario del Módulo](https://drive.google.com/drive/folders/1Od-UCIs65W1tSBUHtOhaoi7MCI4rnAiM)
- [Modelo 3D del Módulo en formato .STEP](https://drive.google.com/drive/folders/1Od-UCIs65W1tSBUHtOhaoi7MCI4rnAiM)
