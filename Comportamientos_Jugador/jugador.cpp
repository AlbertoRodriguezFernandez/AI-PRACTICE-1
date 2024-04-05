#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;


// Método valor_sensores

// TODO: ostream
void ComportamientoJugador::valor_sensores(Sensores sensores) {

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
	cout << "  Vida: " << sensores.vida;
	cout << " Tiempo: " << sensores.tiempo << endl << endl;
}


// Método valor_current_state
void ComportamientoJugador::valor_current_state() {

	cout << "Current_State:";
	cout << " Fila: " << current_state.fil;
	cout << " Columna: " << current_state.col;
	cout << " Orientacion: ";
	if (current_state.brujula_desconocida) {cout << " Desconocida " << endl;}
	else cout << current_state.brujula << endl;
}


// Método think
Action ComportamientoJugador::think(Sensores sensores)
{
	// Comprobación de nivel en el momento inicial para completar la inicialización del objeto
	if (sensores.tiempo == 0) {

		// SI se conoce la orientacion inicial
		if (sensores.nivel == 1 || sensores.nivel == 2) {

			current_state.brujula = norte;
			current_state.brujula_desconocida = false;
		} 
	}
	


	// Imprimir valor de los sensores
	valor_sensores(sensores);
	



	// OBSERVACION y actualización variables de estado: posibilidad de que sea sensores o a través de la ultima accion

	// 1. Sensores
	if (sensores.posF != POS_DESCONOCIDA && sensores.posC != POS_DESCONOCIDA) {

		current_state.fil = sensores.posF;
		current_state.col = sensores.posC;
		current_state.brujula = sensores.sentido;
		current_state.brujula_desconocida = false;
	
	} else {

		// 2. Ultima accion
		switch(last_action)
		{
			case actWALK:   

				if (!current_state.brujula_desconocida && current_state.fil != POS_DESCONOCIDA && current_state.col != POS_DESCONOCIDA) {

					switch (current_state.brujula)
					{			
					case norte :   current_state.fil--;                      break;
					case noreste:  current_state.fil--; current_state.col++; break; 
					case este:     current_state.col++;                      break;
					case sureste:  current_state.fil++; current_state.col++; break;
					case sur:      current_state.fil++;                      break;
					case suroeste: current_state.fil++; current_state.col--; break;
					case oeste:    current_state.col--;                      break;
					case noroeste: current_state.fil--; current_state.col--; break;
					}

				}

			break; 

			case actRUN:     

				if (!current_state.brujula_desconocida && current_state.fil != POS_DESCONOCIDA && current_state.col != POS_DESCONOCIDA) {

					switch (current_state.brujula)
					{			
					case norte :   current_state.fil-=2;                        break;
					case noreste:  current_state.fil-=2; current_state.col+=2;  break; 
					case este:     current_state.col+=2;                        break;
					case sureste:  current_state.fil+=2; current_state.col+=2;  break;
					case sur:      current_state.fil+=2;                        break;
					case suroeste: current_state.fil+=2; current_state.col-=2;  break;
					case oeste:    current_state.col-=2;                        break;
					case noroeste: current_state.fil-=2; current_state.col-=2;  break;
					}
				}

			break;

			case actTURN_SR:  

				if (!current_state.brujula_desconocida) {

					int nueva_orientacion = current_state.brujula;
					nueva_orientacion = (nueva_orientacion + 1) % 8;
					current_state.brujula = static_cast<Orientacion>(nueva_orientacion);
				}
				
			break;

			case actTURN_L: 

				if (!current_state.brujula_desconocida) {

					int nueva_orientacion = current_state.brujula;
					nueva_orientacion = (nueva_orientacion + 6) % 8;
					current_state.brujula = static_cast<Orientacion>(nueva_orientacion);
				}

			break;	   
		}

	}

	// Imprimir valor de current_state
	valor_current_state();


	// Si conozco la pos guardo el INSTANTE en el que paso por la casilla que sea
	if (current_state.fil != POS_DESCONOCIDA && current_state.col != POS_DESCONOCIDA) {

		matriz_ultimas_visitas[current_state.fil][current_state.col] = sensores.tiempo;

	}
	

	
	// DECISION
	Action next_action = actIDLE;

	/* 
	INFO CON LA QUE CUENTO

		1. current_state

			a. pos / orientacion conocida    --> if (current_state.fil/col != POS_DESCONOCIDA && !brujula_desconocida)
												 Si puedo actualizar y usar matriz visitas

			b. pos / orientacion desconocida --> else 
												 No puedo actualizar ni usar la matriz visitas

	INFO DE ULTIMAS VISITAS

		matriz_ultimas_visitas[fil][col] == sensores.tiempo
	
	*/
	
	

	if ((sensores.terreno.size() > 2 && sensores.agentes.size() > 2) and (sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S') and sensores.agentes[2] == '_'){
		
		next_action = actWALK;
		cout << "next_action = actWALk" << endl << endl;
	
	} else{
		
		next_action = actTURN_L;
		cout << "next_action = actTURN_L" << endl << endl;
	}
	



	// Devolver el valor de la accion
	last_action = next_action;
	return next_action;
}


// Método interact
int ComportamientoJugador::interact(Action accion, int valor)
{
	return false;
}