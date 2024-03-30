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

	/* 
	
	----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	SECUENCIA DE ACCIONES

	1º: Comprobar SENSORES DE VISIÓN para saber en que nivel estoy y saber si conozco posición o no.

	2º: MATRIZ DE VISIÓN 
		
			2.1 Ver lo que tengo delante y guardar en MATRIZ DE VISIÓN (pensar también si estoy pegado a los precipicios)

				2.1.1 Si lo que tengo delante SÍ es interesante: ZAPATILLA, BIKINI, RECARGA o CASILLA POSICIONAMIENTO --> ir hacia alli y guardarmelo

					¿Como voy?
						Si a donde quiero ir está a mi izquierda: me muevo por filas y luego por columnas (avanzo, giro 90ª izquierda y avanzo)
						Si a donde quiero ir está a mi derecha: miro diagonal (fila - columna = 0) y si no está, avanzo hacia delante y vuelvo a mirar diagonal
					
					Caso especial
						Si el coste de ir a la recarga es mayor que lo que da la recarga de bateria (10) no merece la pena ir. En caso contrario si

				2.1.2 Si lo que tengo delante NO es interesante: 

					2.1.2.1 Si estoy en agua o bosque sin bikini o zapatillas: 
						2.1.2.1.1 Busco en las casillas de delante si puedo irme a tierra que tienen coste menor.
						2.1.2.1.2 Giro 90º a la izquierda y repetir paso 2.1


	3º: MATRIZ DE YA VISITADAS

		Ir guardando las casillas visitadas como elemento[i][j] = true y así no volver a visitarlas

	4º: MATRIZ MAPA RESULTADO

		Nivel 0: nada mas pisar puedo empezar a guardar en mapaResultado.
		Nivel 1,2,3: hasta que no este en casilla de posicionamiento no puedo empezar a guardar en mapaResultado.
	
		// Método PonerTerrenoEnMatriz
		void PonerTerrenoEnMatriz(const vector<unsigned char> &terreno, const state &st, vector<vector<unsigned char>> &matriz) {

			matriz[st.fil][st.col] = terreno[0];
		}
		

	-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
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

		if ((sensores.terreno[2] == 'T' || sensores.terreno[2] == 'S' || sensores.terreno[2] == 'G' || sensores.terreno[2] == 'D' || sensores.terreno[2] == 'K' || sensores.terreno[2] == 'X') && sensores.agentes[2] == '_' ) {

			accion = actWALK;

		// Agua
		} else if (tengo_bikini && sensores.terreno[2] == 'A') {

			accion = actWALK;

		// Bikini
		} else if (tengo_zapatillas && sensores.terreno[2] == 'B') {

			accion = actWALK;

		// Bateria
		} else if (sensores.terreno[2] == 'X' && sensores.bateria <= 4990) {

			sensores.bateria += 10;

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