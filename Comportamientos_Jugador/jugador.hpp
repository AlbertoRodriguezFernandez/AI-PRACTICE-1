#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"
using namespace std;

class ComportamientoJugador : public Comportamiento{

  public:

    // Constructor
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      
      // TO-DO: Dar el valor inicial a las variables de estado
    }

    // Constructor de copia
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    
    // Destructor
    ~ComportamientoJugador(){}

    // Método think --> describe comportamiento del agente
    Action think(Sensores sensores);

    // Método interact --> descibe como interacciona agente con otros agentes
    int interact(Action accion, int valor);

  private:
  
  // TO-DO: Declarar aquí las variables de estado que almacenan memoria sobre lo 
  // que lleva conocido el agente sobre el mundo
};

#endif