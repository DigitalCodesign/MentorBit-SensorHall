#include <MentorBitHALL.h>

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