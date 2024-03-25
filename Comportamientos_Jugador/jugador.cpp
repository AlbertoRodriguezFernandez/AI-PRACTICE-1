#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;


// Método think
Action ComportamientoJugador::think(Sensores sensores)
{

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
	
	// ----------------------------------------------------------------------------
	

	Action accion = actIDLE;
	int a;

	// Ultima accion --> actualización del mundo
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

			a = current_state.brujula;
			a = (a + 1) % 8;
			current_state.brujula = static_cast<Orientacion>(a);
			
		break;

		case actTURN_L: 

			a = current_state.brujula;
			a = (a + 7) % 8;
			current_state.brujula = static_cast<Orientacion>(a);

		break;	      
	}

	// Movimiento del agente
	if ((sensores.terreno[2] == 'T' || sensores.terreno[2] == 'S') && sensores.agentes[2] == '_') {

		accion = actWALK;
	
	} else if (!girar_derecha) {

		accion = actTURN_L;
		girar_derecha = (rand() % 2 == 0);
	
	} else {

		accion = actTURN_SR;
		girar_derecha = (rand() % 2 == 0);
	}

	/*
	TO-DO: en la matriz mapaResultado se ha de colocar lo que se descubre en el mapa	
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