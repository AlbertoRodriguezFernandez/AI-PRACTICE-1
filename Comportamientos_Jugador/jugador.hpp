#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H


#include "comportamientos/comportamiento.hpp"
using namespace std;


// Estructura state
struct state {
 
  int fil;
  int col;
  Orientacion brujula;
  bool brujula_desconocida;
};


// Clase ComportamientoJugador
class ComportamientoJugador : public Comportamiento{


  public:

    static const int POS_DESCONOCIDA = -1; // Valor fuera de rango porque no se la pos
    static const int TAM_MAX_VECTOR_SENSORES_VISION = 16; // Valor que indica que el jugador tiene 16 casillas de vision
    static const int TAM_MIN_VECTOR_SENSORES_VISION = 1; // Valor que indica que el jugador siempre tiene la suya como minima

    // Constructor
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      
      last_action = actIDLE;
      current_state.fil = current_state.col = POS_DESCONOCIDA;  

      // NO inicializo current_state.brujula porque necesito el nivel y eso lo hare en el think  
      current_state.brujula_desconocida = true;
       
      casilla_posicionamiento = false;
      tengo_zapatillas = false;
      tengo_bikini = false;

      // Inicialización de matriz ultimas visitas
      vector<double> aux(size, 0.0);
      for (int i = 0; i < size; i++) {

        matriz_ultimas_visitas.push_back(aux);
      }

    }


    // Constructor de copia
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport) {

      last_action = comport.last_action;
      current_state = comport.current_state;
      casilla_posicionamiento = comport.casilla_posicionamiento;
      tengo_zapatillas = comport.tengo_zapatillas;
      tengo_bikini = comport.tengo_bikini;
      matriz_ultimas_visitas = comport.matriz_ultimas_visitas;
    }
    

    // Destructor
    ~ComportamientoJugador(){}


    // Método think --> describe comportamiento del agente
    Action think(Sensores sensores);


    // Método interact --> descibe como interacciona agente con otros agentes
    int interact(Action accion, int valor);


    // Método que guarda todos los couts de los sensores
    void valor_sensores(Sensores sensores);


    // Método que muestra el valor del current_state
    void valor_current_state();


    // Método que se encarga de colocar toda la info en sensor terreno
    void guardar_mapaResultado(const vector<unsigned char> &terreno);


  private:

    // Variables de estado de memoria del agente
    Action last_action;
    state current_state;

    // Necesitamos variables de estado ya que no hay sensor que detecte si el agente tiene zapatillas o bikini o casilla de posicionamiento
    bool tengo_zapatillas; 
    bool tengo_bikini;
    bool casilla_posicionamiento;

    vector<vector<double>> matriz_ultimas_visitas;
};

#endif