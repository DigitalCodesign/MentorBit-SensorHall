/*

            ██████╗    ██╗    ██████╗    ██╗   ████████╗    █████╗    ██╗               
            ██╔══██╗   ██║   ██╔════╝    ██║   ╚══██╔══╝   ██╔══██╗   ██║               
            ██║  ██║   ██║   ██║  ███╗   ██║      ██║      ███████║   ██║               
            ██║  ██║   ██║   ██║   ██║   ██║      ██║      ██╔══██║   ██║               
            ██████╔╝   ██║   ╚██████╔╝   ██║      ██║      ██║  ██║   ███████╗          
            ╚═════╝    ╚═╝    ╚═════╝    ╚═╝      ╚═╝      ╚═╝  ╚═╝   ╚══════╝          
                                                                                        
     ██████╗    ██████╗    ██████╗    ███████╗   ███████╗   ██╗    ██████╗    ███╗   ██╗
    ██╔════╝   ██╔═══██╗   ██╔══██╗   ██╔════╝   ██╔════╝   ██║   ██╔════╝    ████╗  ██║
    ██║        ██║   ██║   ██║  ██║   █████╗     ███████╗   ██║   ██║  ███╗   ██╔██╗ ██║
    ██║        ██║   ██║   ██║  ██║   ██╔══╝     ╚════██║   ██║   ██║   ██║   ██║╚██╗██║
    ╚██████╗   ╚██████╔╝   ██████╔╝   ███████╗   ███████║   ██║   ╚██████╔╝   ██║ ╚████║
     ╚═════╝    ╚═════╝    ╚═════╝    ╚══════╝   ╚══════╝   ╚═╝    ╚═════╝    ╚═╝  ╚═══╝ 
        

    Autor: Digital Codesign
    Version: 1.0.1
    Fecha de creación: Agosto de 2025
    Fecha de version: Agosto de 2025
    Repositorio: https://github.com/DigitalCodesign/MentorBit-HALL
    Descripcion: 
        Esta libreria esta especificamente diseñada para ser utilizada junto con 
        el modulo MentorBit HALL
    Metodos principales:
        HallLed   -> constructor de la clase
        begin     -> inicializador, debe colocarse en el setup
        update    -> actualizar medida
        confiPort -> configuracion de pines MentorBit

*/

#include "MentorbitHALL.h"

HallLed::HallLed(uint8_t hallPin, uint8_t ledPin) {
  _port.gpios[1] = hallPin;
  _ledPin = ledPin;
  _confi = false;
}

HallLed::HallLed(uint8_t hallPin) {
  _port.gpios[1] = hallPin;
  _confi = true;
}

void HallLed::begin() {
  if (_confi == false){
    pinMode(_ledPin, OUTPUT);
    digitalWrite(_ledPin, LOW);
  }
  _sensorState = false;
}

void HallLed::update() {
  // Lee el estado del sensor Hall
  _sensorState = digitalRead(_port.gpios[1]);

  // Controla el LED según el estado del sensor
  if (_sensorState) {
    digitalWrite(_ledPin, HIGH);
  } else {
    digitalWrite(_ledPin, LOW);
  }
}

void HallLed::configPort(const Port& port) {

  _port.type = port.type;
  _port.location = port.location;
  _port.gpios[1] = port.gpios[1];

}
