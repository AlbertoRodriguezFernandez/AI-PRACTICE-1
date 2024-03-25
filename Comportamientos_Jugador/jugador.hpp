#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H


#include "comportamientos/comportamiento.hpp"
using namespace std;


// Estructura state
struct state {
 
  int fil;
  int col;
  Orientacion brujula;
};


// Clase ComportamientoJugador
class ComportamientoJugador : public Comportamiento{


  public:

    // Constructor
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      
      // TO-DO: Dar el valor inicial a las variables de estado
      last_action = actIDLE;
      current_state.fil = current_state.col = 99;
      current_state.brujula = norte;      
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
  
  // TO-DO: Declarar aquí las variables de estado que almacenan memoria sobre lo que lleva conocido el agente sobre el mundo
  Action last_action;
  state current_state;
};

#endif