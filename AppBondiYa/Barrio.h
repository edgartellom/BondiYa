#include "Parada.h"
#ifndef BARRIO_H_
#define BARRIO_H_

class Barrio {

private:
	std::string nombre;
	Lista<Parada*>* paradas;

public:
	/*
	 * pre: nombre tiene que ser distinto de vacío.
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
     * pre: 'parada' debe ser distinto de NULL.
     * post: agrega la parada pasada por parámetro a la lista de paradas.
     */
	void agregarParada(Parada* paradas);

	/*
	 * pre: -
	 * post: ordena las paradas por distancia de acuerdo a una ubicacion (coordenadas) pasada por parametro y devuelve una nueva lista.
	 */
	Lista<Parada*>* getParadasPorLinea(std::string linea);
	
};

#endif /* BARRIO_H_ */
