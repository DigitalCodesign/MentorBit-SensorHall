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

#ifndef MentorbitHALL_h
#define MentorbitHALL_h

#include "Arduino.h"
#include <MentorPort.h>

class HallLed : public MentorPort {
  public:
    // Constructor: recibe los pines del sensor Hall y del LED
    HallLed(uint8_t hallPin = 0, uint8_t ledPin = 0);

    // Constructor: recibe el pin del sensor Hall
    HallLed(uint8_t hallPin = 0);
    
    // Inicializa los pines
    void begin();

    // Actualiza el estado y controla el LED
    void update();

    void configPort(const Port& port) override;

  private:

    Port _port;
    uint8_t _ledPin;
    bool _sensorState; // Estado actual del sensor
    bool _confi = false;

};

#endif
