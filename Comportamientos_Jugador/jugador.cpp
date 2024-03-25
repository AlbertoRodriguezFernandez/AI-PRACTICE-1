#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;


// Método valor_sensores
void ComportamientoJugador::valor_sensores(Sensores sensores) {

	// VALOR SENSORES 
	cout << "Posicion: fila " << sensores.posF << " columna " << sensores.posC;
	
	switch (sensores.sentido)
	{
		case norte:	  cout << " Norte\n";	    break;
		case noreste: cout << " Noreste\n";	    break;
		case este:    cout << " Este\n";	    break;
		case sureste: cout << " Sureste\n";	    break;
		case sur:     cout << " Sur\n";	        break;
		case suroeste:cout << " Suroeste\n";	break;
		case oeste:   cout << " Oeste\n";	    break;
		case noroeste:cout << " Noroeste\n";	break;
	}
	
	cout << "Terreno: ";
	for (int i=0; i<sensores.terreno.size(); i++)
		cout << sensores.terreno[i];

	cout << "  Agentes: ";
	for (int i=0; i<sensores.agentes.size(); i++)
		cout << sensores.agentes[i];

	cout << "\nColision: " << sensores.colision;
	cout << "  Reset: " << sensores.reset;
	cout << "  Vida: " << sensores.vida << endl<< endl;
}


// Método actualiza_juego
void ComportamientoJugador::actualiza_juego() {

	// Ultima accion --> actualización del mundo
	int nueva_orientacion; 

	switch(last_action)
	{
		case actWALK:   

			switch (current_state.brujula)
			{			
			case norte :   current_state.fil--;                      break;
			case noreste:  current_state.fil--; current_state.col++; break; 
			case este:     current_state.col++;                      break;
			case sureste:  current_state.fil++; current_state.col++; break;
			case sur:      current_state.fil++;                      break;
			case suroeste: current_state.fil++; current_state.col--; break;
			case oeste:    current_state.fil--;                      break;
			case noroeste: current_state.fil--; current_state.col--; break;
			}

		break; 

		case actRUN:      

			switch (current_state.brujula)
			{			
			case norte :   current_state.fil-=2;                        break;
			case noreste:  current_state.fil-=2; current_state.col+=2;  break; 
			case este:     current_state.col+=2;                        break;
			case sureste:  current_state.fil+=2; current_state.col+=2;  break;
			case sur:      current_state.fil+=2;                        break;
			case suroeste: current_state.fil+=2; current_state.col-=2;  break;
			case oeste:    current_state.fil-=2;                        break;
			case noroeste: current_state.fil-=2; current_state.col-=2;  break;
			}

		break;

		case actTURN_SR:  

			nueva_orientacion = current_state.brujula;
			nueva_orientacion = (nueva_orientacion + 1) % 8;
			current_state.brujula = static_cast<Orientacion>(nueva_orientacion);
			
		break;

		case actTURN_L: 

			nueva_orientacion = current_state.brujula;
			nueva_orientacion = (nueva_orientacion + 6) % 8;
			current_state.brujula = static_cast<Orientacion>(nueva_orientacion);

		break;	      
	}
}


/*
// Método PonerTerrenoEnMatriz
void PonerTerrenoEnMatriz(const vector<unsigned char> &terreno, const state &st, vector<vector<unsigned char>> &matriz) {

	matriz[st.fil][st.col] = terreno[0];

}
*/


// Método movimiento_agente
Action ComportamientoJugador::movimiento_agente(Sensores sensores, Action accion) {

	// Casilla de posicionamiento
	if (sensores.terreno[0] == 'G' && !bien_situado) {

		current_state.fil = sensores.posF;
		current_state.col = sensores.posC;
		current_state.brujula = sensores.sentido;
		bien_situado = true;
	}

	// 	TO-DO: en la matriz mapaResultado se ha de colocar lo que se descubre en el mapa	
	if (bien_situado) {

		mapaResultado[current_state.fil][current_state.col] = sensores.terreno[0];
		// PonerTerrenoEnMatriz(sensores.terreno, current_state, mapaResultado);
	}

	// Nueva accion
	if ((sensores.terreno[2] == 'T' || sensores.terreno[2] == 'S' || sensores.terreno[2] == 'G') && sensores.agentes[2] == '_') {

		accion = actWALK;
	
	} else if (!girar_derecha) {

		accion = actTURN_L;
		girar_derecha = (rand() % 2 == 0);
	
	} else {

		accion = actTURN_SR;
		girar_derecha = (rand() % 2 == 0);
	}

	return accion;
}


// Método think
Action ComportamientoJugador::think(Sensores sensores)
{
	Action accion = actIDLE;

	// LLamada a método valor_sensores
	this->valor_sensores(sensores);

	// LLamada a método actualiza_juego
	this->actualiza_juego();
	
	// LLamada a movimiento_agente
	accion = this->movimiento_agente(sensores, accion);

	// Devolver el valor de la accion
	last_action = accion;
	return accion;
}


// Método interact
int ComportamientoJugador::interact(Action accion, int valor)
{
	return false;
}