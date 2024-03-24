#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;


// Método think
Action ComportamientoJugador::think(Sensores sensores)
{

	Action accion = actIDLE;

	// Mostrar el valor de los sensores
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

	// Ultima accion --> actualización del mundo
	switch(last_action)
	{
		case actWALK:      //.............
		case actRUN:       //.............
		case actTURN_SR:   //.............
		case actTURN_L:    //.............
		case actIDLE:      //.............
	}

	// Brujula --> siguiente acción a realizar
	if (brujula == norte) {

		//...................


	} else if (brujula == noreste) {

		//..................


	} else if (brujula == este) {

		//...................


	} else if (brujula == sureste) {

		//....................


	} else if (brujula == sur) {

		//..................


	} else if (brujula == suroeste) { 

		//................


	} else if (brujula == oeste) {

		//..................


	} else { // brujula == noroeste

		//.................

	}
	last_action = accion;


	/*
	TO-DO: en la matriz mapaResultado se ha de colocar lo que se descubre en el mapa	
	*/


	// Determinar el efecto de la ultima accion enviada y devolverla
	return accion;
}


// Método interact
int ComportamientoJugador::interact(Action accion, int valor)
{
	return false;
}