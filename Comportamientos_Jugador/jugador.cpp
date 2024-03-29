#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;


// Método valor_sensores
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
	cout << "  Vida: " << sensores.vida << endl<< endl;
}


/*
// Método PonerTerrenoEnMatriz
void PonerTerrenoEnMatriz(const vector<unsigned char> &terreno, const state &st, vector<vector<unsigned char>> &matriz) {

	matriz[st.fil][st.col] = terreno[0];

}
*/


// Método think
Action ComportamientoJugador::think(Sensores sensores)
{
	Action accion = actIDLE;
	int nueva_orientacion;

	// Imprimir valor de los sensores
	this->valor_sensores(sensores);

	// Actualización variables de estado
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
			case oeste:    current_state.col--;                      break;
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
			case oeste:    current_state.col-=2;                        break;
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

		case actIDLE:

			cout << "No se hace nada" << endl;

		break;   
	}

	// Accion
	/*
	TO-DO:
		Analizar que pasa lo de la primera posicion
		Analizar que hacer si caigo directamente en bosque, o en agua o justo al lado de un precipio
	*/
	
	/*
	if (sensores.terreno.size() != 0 && sensores.agentes.size() != 0) {
		
		// Casilla de posicionamiento
		if (sensores.terreno[0] == 'G' && !bien_situado) {

			current_state.fil = sensores.posF;
			current_state.col = sensores.posC;
			current_state.brujula = sensores.sentido;
			bien_situado = true;
		}

		// Zapatillas
		if (sensores.terreno[0] == 'D' && !tengo_zapatillas) {

			current_state.fil = sensores.posF;
			current_state.col = sensores.posC;
			current_state.brujula = sensores.sentido;
			tengo_zapatillas = true;
		}

		// Bikini
		if (sensores.terreno[0] == 'K' && !tengo_bikini) {

			current_state.fil = sensores.posF;
			current_state.col = sensores.posC;
			current_state.brujula = sensores.sentido;
			tengo_bikini = true;
		}
		
		
		if ((sensores.terreno[2] == 'T' || sensores.terreno[2] == 'S' || sensores.terreno[2] == 'G' || sensores.terreno[2] == 'D' || sensores.terreno[2] == 'K') && sensores.agentes[2] == '_') {

			accion = actWALK;
		
		} else if (tengo_bikini && sensores.terreno[2] == 'A') {

			accion = actWALK;

		} else if (tengo_zapatillas && sensores.terreno[2] == 'B') {

			accion = actWALK;

		} else if (!girar_derecha) {

			accion = actTURN_L;
			girar_derecha = (rand() % 2 == 0);
		
		} else {

			accion = actTURN_SR;
			girar_derecha = (rand() % 2 == 0);
		}

		// Guardar en mapaResultado
		if (bien_situado) {

			mapaResultado[current_state.fil][current_state.col] = sensores.terreno[0];
			// PonerTerrenoEnMatriz(sensores.terreno, current_state, mapaResultado);
		}
		

	} else {

		cerr << "Vectores vacios" << endl;
		accion = actIDLE;
	}
	*/

	// Devolver el valor de la accion
	last_action = accion;
	return accion;
}


// Método interact
int ComportamientoJugador::interact(Action accion, int valor)
{
	return false;
}