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

    // Constructor
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      
      last_action = actIDLE;
      current_state.fil = current_state.col = POS_DESCONOCIDA;  

      // Deliberadamente no inicializado current_state.brujula porque necesito el nivel y eso lo hare en el think  
      current_state.brujula_desconocida = true;
       
      bien_situado = false;
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
      bien_situado = comport.bien_situado;
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
    void PonerTerrenoEnMatriz(const vector<unsigned char> &terreno, const state &st, vector<vector<unsigned char>> &matriz);


  private:

    // Variables de estado de memoria del agente
    Action last_action;
    state current_state;
    bool bien_situado;
    bool tengo_zapatillas;
    bool tengo_bikini;
    vector<vector<double>> matriz_ultimas_visitas;
};

#endif