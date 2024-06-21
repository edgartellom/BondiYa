/*
 * Barrio.h
 *
 *  Created on: 16 jun. 2024
 *      Author: edgar
 */
#include "Parada.h"
#ifndef BARRIO_H_
#define BARRIO_H_

class Barrio {

private:
	std::string nombre;
	Lista<Parada*>* paradas;

public:
	/*
	 * pre: -
	 * post: crea un barrio con un nombre pasado por parametro.
	 */
	Barrio(std::string nombre);

	virtual ~Barrio();

	/*
	 * pre: -
	 * post: obtiene el nombre del barrio.
	 */
	std::string getNombre();

	/*
	 * pre: -
	 * post: obtiene la lista de paradas.
	 */
	Lista<Parada*>* getParadas();

	/*
	 * pre: -
	 * post: guarda una parada pasada por parametro en la lista de paradas.
	 */
	void agregarParada(Parada* paradas);

	/*
	 * pre: -
	 * post: ordena las paradas por distancia de acuerdo a una ubicacion (coordenadas) pasada por parametro y devuelve una nueva lista.
	 */
	Lista<Parada*>* ordenarParadas(Coordenadas* ubicacion);



	//Recibe como string un numero de linea y devuelve una lista
	//con las paradas que incluyen la linea de ese nombre.

	Lista<Parada*>* getParadasPorLinea(std::string linea);

};


#endif /* BARRIO_H_ */
