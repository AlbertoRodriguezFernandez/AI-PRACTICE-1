#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
#include <cassert>


using namespace std;


// Método valor_sensores  ---> TODO: hacerlo operador <<
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


// Método valor_current_state ---> TODO: hacerlo operador <<
void ComportamientoJugador::valor_current_state() {

	cout << "Current_State:";
	cout << " Fila: " << current_state.fil;
	cout << " Columna: " << current_state.col;
	cout << " Orientacion: ";
	if (current_state.brujula_desconocida) {cout << " Desconocida " << endl;}
	else cout << current_state.brujula << endl;
}


// Metodo guardar_mapaResultado
void ComportamientoJugador::guardar_mapaResultado(const vector<unsigned char> &terreno) {

	assert(current_state.fil != POS_DESCONOCIDA && current_state.col != POS_DESCONOCIDA); // Esto es porque la comprobacion se hace fuera antes de llamar al metodo

	mapaResultado[current_state.fil][current_state.col] = terreno[0]; // No necesito verificar porque es mi propia posicion y siempre la tengo

	// Comprobar brujula y comprobar tamaño de terreno
	if (!current_state.brujula_desconocida && terreno.size() > 15) {

		switch (current_state.brujula) {
	
			case norte:     

				mapaResultado[current_state.fil - 1][current_state.col -1]  = terreno[1];
				mapaResultado[current_state.fil - 1][current_state.col]     = terreno[2];
				mapaResultado[current_state.fil - 1][current_state.col + 1] = terreno[3];
				mapaResultado[current_state.fil - 2][current_state.col - 2] = terreno[4];
				mapaResultado[current_state.fil - 2][current_state.col - 1] = terreno[5];
				mapaResultado[current_state.fil - 2][current_state.col]     = terreno[6];
				mapaResultado[current_state.fil - 2][current_state.col + 1] = terreno[7];
				mapaResultado[current_state.fil - 2][current_state.col + 2] = terreno[8];
				mapaResultado[current_state.fil - 3][current_state.col - 3] = terreno[9];
				mapaResultado[current_state.fil - 3][current_state.col - 2] = terreno[10];
				mapaResultado[current_state.fil - 3][current_state.col - 1] = terreno[11];
				mapaResultado[current_state.fil - 3][current_state.col]     = terreno[12];
				mapaResultado[current_state.fil - 3][current_state.col + 1] = terreno[13];
				mapaResultado[current_state.fil - 3][current_state.col + 2] = terreno[14];
				mapaResultado[current_state.fil - 3][current_state.col + 3] = terreno[15];

				break;

			case noreste:     

				mapaResultado[current_state.fil - 1][current_state.col]     = terreno[1];
				mapaResultado[current_state.fil - 1][current_state.col + 1] = terreno[2];
				mapaResultado[current_state.fil][current_state.col + 1]     = terreno[3];
				mapaResultado[current_state.fil - 2][current_state.col]     = terreno[4];
				mapaResultado[current_state.fil - 2][current_state.col + 1] = terreno[5];
				mapaResultado[current_state.fil - 2][current_state.col + 2] = terreno[6];
				mapaResultado[current_state.fil - 1][current_state.col + 2] = terreno[7];
				mapaResultado[current_state.fil][current_state.col + 2]     = terreno[8];
				mapaResultado[current_state.fil - 3][current_state.col]     = terreno[9];
				mapaResultado[current_state.fil - 3][current_state.col + 1] = terreno[10];
				mapaResultado[current_state.fil - 3][current_state.col + 2] = terreno[11];
				mapaResultado[current_state.fil - 3][current_state.col + 3] = terreno[12];
				mapaResultado[current_state.fil - 2][current_state.col + 3] = terreno[13];
				mapaResultado[current_state.fil - 1][current_state.col + 3] = terreno[14];
				mapaResultado[current_state.fil][current_state.col + 3]     = terreno[15];

				break;

			case este:     

				mapaResultado[current_state.fil - 1][current_state.col + 1] = terreno[1];
				mapaResultado[current_state.fil    ][current_state.col + 1] = terreno[2];
				mapaResultado[current_state.fil + 1][current_state.col + 1] = terreno[3];
				mapaResultado[current_state.fil - 2][current_state.col + 2] = terreno[4];
				mapaResultado[current_state.fil - 1][current_state.col + 2] = terreno[5];
				mapaResultado[current_state.fil    ][current_state.col + 2] = terreno[6];
				mapaResultado[current_state.fil + 1][current_state.col + 2] = terreno[7];
				mapaResultado[current_state.fil + 2][current_state.col + 2] = terreno[8];
				mapaResultado[current_state.fil - 3][current_state.col + 3] = terreno[9];
				mapaResultado[current_state.fil - 2][current_state.col + 3] = terreno[10];
				mapaResultado[current_state.fil - 1][current_state.col + 3] = terreno[11];
				mapaResultado[current_state.fil    ][current_state.col + 3] = terreno[12];
				mapaResultado[current_state.fil + 1][current_state.col + 3] = terreno[13];
				mapaResultado[current_state.fil + 2][current_state.col + 3] = terreno[14];
				mapaResultado[current_state.fil + 3][current_state.col + 3] = terreno[15];

				break;

			case sureste:     

				mapaResultado[current_state.fil    ][current_state.col + 1] = terreno[1];
				mapaResultado[current_state.fil + 1][current_state.col + 1] = terreno[2];
				mapaResultado[current_state.fil + 1][current_state.col    ] = terreno[3];
				mapaResultado[current_state.fil    ][current_state.col + 2] = terreno[4];
				mapaResultado[current_state.fil + 1][current_state.col + 2] = terreno[5];
				mapaResultado[current_state.fil + 2][current_state.col + 2] = terreno[6];
				mapaResultado[current_state.fil + 2][current_state.col + 1] = terreno[7];
				mapaResultado[current_state.fil + 2][current_state.col    ] = terreno[8];
				mapaResultado[current_state.fil    ][current_state.col + 3] = terreno[9];
				mapaResultado[current_state.fil + 1][current_state.col + 3] = terreno[10];
				mapaResultado[current_state.fil + 2][current_state.col + 3] = terreno[11];
				mapaResultado[current_state.fil + 3][current_state.col + 3] = terreno[12];
				mapaResultado[current_state.fil + 2][current_state.col + 3] = terreno[13];
				mapaResultado[current_state.fil + 1][current_state.col + 3] = terreno[14];
				mapaResultado[current_state.fil    ][current_state.col + 3] = terreno[15];

				break;

			case sur:     

				mapaResultado[current_state.fil + 1][current_state.col + 1] = terreno[1];
				mapaResultado[current_state.fil + 1][current_state.col    ] = terreno[2];
				mapaResultado[current_state.fil + 1][current_state.col - 1] = terreno[3];
				mapaResultado[current_state.fil + 2][current_state.col + 2] = terreno[4];
				mapaResultado[current_state.fil + 2][current_state.col + 1] = terreno[5];
				mapaResultado[current_state.fil + 2][current_state.col    ] = terreno[6];
				mapaResultado[current_state.fil + 2][current_state.col - 1] = terreno[7];
				mapaResultado[current_state.fil + 2][current_state.col - 2] = terreno[8];
				mapaResultado[current_state.fil + 3][current_state.col + 3] = terreno[9];
				mapaResultado[current_state.fil + 3][current_state.col + 2] = terreno[10];
				mapaResultado[current_state.fil + 3][current_state.col + 1] = terreno[11];
				mapaResultado[current_state.fil + 3][current_state.col    ] = terreno[12];
				mapaResultado[current_state.fil + 3][current_state.col - 1] = terreno[13];
				mapaResultado[current_state.fil + 3][current_state.col - 2] = terreno[14];
				mapaResultado[current_state.fil + 3][current_state.col - 3] = terreno[15];

				break;

			case suroeste:     


				mapaResultado[current_state.fil + 1][current_state.col    ] = terreno[1];
				mapaResultado[current_state.fil + 1][current_state.col - 1] = terreno[2];
				mapaResultado[current_state.fil    ][current_state.col - 1] = terreno[3];
				mapaResultado[current_state.fil + 2][current_state.col    ] = terreno[4];
				mapaResultado[current_state.fil + 2][current_state.col - 1] = terreno[5];
				mapaResultado[current_state.fil + 2][current_state.col - 2] = terreno[6];
				mapaResultado[current_state.fil + 1][current_state.col - 2] = terreno[7];
				mapaResultado[current_state.fil    ][current_state.col - 2] = terreno[8];
				mapaResultado[current_state.fil + 3][current_state.col    ] = terreno[9];
				mapaResultado[current_state.fil + 3][current_state.col - 1] = terreno[10];
				mapaResultado[current_state.fil + 3][current_state.col - 2] = terreno[11];
				mapaResultado[current_state.fil + 3][current_state.col - 3] = terreno[12];
				mapaResultado[current_state.fil + 2][current_state.col - 3] = terreno[13];
				mapaResultado[current_state.fil + 1][current_state.col - 3] = terreno[14];
				mapaResultado[current_state.fil    ][current_state.col - 3] = terreno[15];

				break;

			case oeste:     

				mapaResultado[current_state.fil + 1][current_state.col - 1] = terreno[1];
				mapaResultado[current_state.fil    ][current_state.col - 1] = terreno[2];
				mapaResultado[current_state.fil - 1][current_state.col - 1] = terreno[3];
				mapaResultado[current_state.fil + 2][current_state.col - 2] = terreno[4];
				mapaResultado[current_state.fil + 1][current_state.col - 2] = terreno[5];
				mapaResultado[current_state.fil    ][current_state.col - 2] = terreno[6];
				mapaResultado[current_state.fil - 1][current_state.col - 2] = terreno[7];
				mapaResultado[current_state.fil - 2][current_state.col - 2] = terreno[8];
				mapaResultado[current_state.fil + 3][current_state.col - 3] = terreno[9];
				mapaResultado[current_state.fil + 2][current_state.col - 3] = terreno[10];
				mapaResultado[current_state.fil + 1][current_state.col - 3] = terreno[11];
				mapaResultado[current_state.fil    ][current_state.col - 3] = terreno[12];
				mapaResultado[current_state.fil - 1][current_state.col - 3] = terreno[13];
				mapaResultado[current_state.fil - 2][current_state.col - 3] = terreno[14];
				mapaResultado[current_state.fil - 3][current_state.col - 3] = terreno[15];

				break;

			case noroeste:     

				mapaResultado[current_state.fil    ][current_state.col - 1] = terreno[1];
				mapaResultado[current_state.fil - 1][current_state.col - 1] = terreno[2];
				mapaResultado[current_state.fil - 1][current_state.col    ] = terreno[3];
				mapaResultado[current_state.fil    ][current_state.col - 2] = terreno[4];
				mapaResultado[current_state.fil - 1][current_state.col - 2] = terreno[5];
				mapaResultado[current_state.fil - 2][current_state.col - 2] = terreno[6];
				mapaResultado[current_state.fil - 2][current_state.col - 1] = terreno[7];
				mapaResultado[current_state.fil - 2][current_state.col    ] = terreno[8];
				mapaResultado[current_state.fil    ][current_state.col - 3] = terreno[9];
				mapaResultado[current_state.fil - 1][current_state.col - 3] = terreno[10];
				mapaResultado[current_state.fil - 2][current_state.col - 3] = terreno[11];
				mapaResultado[current_state.fil - 3][current_state.col - 3] = terreno[12];
				mapaResultado[current_state.fil - 3][current_state.col - 2] = terreno[13];
				mapaResultado[current_state.fil - 3][current_state.col - 1] = terreno[14];
				mapaResultado[current_state.fil - 3][current_state.col    ] = terreno[15];

				break;
		}
	}
}


// Método think
Action ComportamientoJugador::think(Sensores sensores)
{
	
	// Termino de inicializar el constructor de ComportamientoJugador: comprobación de nivel en el momento inicial para completar la orientación
	if (sensores.tiempo == 0) {

		// SI se conoce la orientacion inicial
		if (sensores.nivel == 1 || sensores.nivel == 2) {

			current_state.brujula = norte;
			current_state.brujula_desconocida = false;
		} 

		// En el caso de que no se conozca brujula_desconocida seguirá a true
	}
	

	// Imprimo valor de los sensores para tener una mejor información del mapa
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

	// Imprimo el valor del estado actual para ver si hubo algun error
	valor_current_state();

	// Posicion actual
	switch(sensores.terreno[0]) {

		case 'D': tengo_zapatillas = true; break;
		case 'K': tengo_bikini = true;     break;
		

	}

	// Si conozco la pos guardo el INSTANTE en el que paso por la casilla que sea y Actualizo mapaResultado

	if (current_state.fil != POS_DESCONOCIDA && current_state.col != POS_DESCONOCIDA) {

		matriz_ultimas_visitas[current_state.fil][current_state.col] = sensores.tiempo;
		guardar_mapaResultado(sensores.terreno);
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

		2. información del momento que visito las casillas

			matriz_ultimas_visitas[fil][col] == sensores.tiempo

		3. sensores.terreno (1 de 16)  *
 
		4. sensores.agentes (1 de 16)  *

		5. sensores.bateria

		6. sensores.colision

		7. sensores.reset

		8. sensores.nivel
	*/

	

	// Mantenerse vivo: giro (¿Hacia Donde?) si la posicion que tengo delante no me permite avanzar o si esta ocupada por un intruso
	if (sensores.terreno[2] == 'P' or sensores.terreno[2] == 'M' or sensores.agentes[2] == 'a' or sensores.agentes[2] == 'l') {

		next_action = actTURN_L;
		cout << "next_action = actTURN_L" << endl << endl;
	
	// Avanzo si el terreno delante es favorable y posicion por delante esta libre y que no este visitada la posicion de delante
	} else if ((sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S' or sensores.terreno[2] == 'D' or sensores.terreno[2] == 'K' 
	            or sensores.terreno[2] == 'X' or sensores.terreno[2] == 'G') and sensores.agentes[2] == '_') {
		
		next_action = actWALK;
		cout << "next_action = actWALk" << endl << endl;
	
	// Avanzo al bosque si tengo las zapatillas y posicion por delante esta libre y no visitada
	} else if (sensores.terreno[2] == 'B' and tengo_zapatillas and sensores.agentes[2] == '_') {

		next_action = actWALK;
		cout << "next_action = actWALk" << endl << endl;

	// Avanzo al agua si tengo el bikini y posicion por delante esta libre
	} else if (sensores.terreno[2] == 'A' and tengo_bikini and sensores.agentes[2] == '_' ) {

		next_action = actWALK;
		cout << "next_action = actWALk" << endl << endl;

	// Giro (hacia donde) si el terreno que tengo delante es bosque y no tengo zapatillas
	} else if(sensores.terreno[2] == 'B' and !tengo_zapatillas and sensores.agentes[2] == '_') {

		next_action = actTURN_L;
		cout << "next_action = actTURN_L" << endl << endl;

	// Giro (hacia donde) si el terreno que tengo delante es agua y no tengo bikini
	} else if(sensores.terreno[2] == 'A' and !tengo_bikini and sensores.agentes[2] == '_') {

		next_action = actTURN_L;
		cout << "next_action = actTURN_L" << endl << endl;
	
	// En el caso de que no se produzca ninguna accion anterior, giro (hacia donde)
	} else {

		next_action = actTURN_SR;
		cout << "next_action = actTURN_SR" << endl << endl;
	}
	
	// Devolver el valor de la accion
	last_action = next_action;
	return next_action;
}


// Método interact --> No se implementa en esta practica
int ComportamientoJugador::interact(Action accion, int valor)
{
	return false;
}