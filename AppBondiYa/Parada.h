#include "Lista.h"
#include "Coordenadas.h"
#include "LineaDeColectivos.h"
#include <string>
#ifndef PARADA_H_
#define PARADA_H_

class Parada {
public:
	std::string direccion;
	Coordenadas* coordenadas;
	Lista<LineaDeColectivos*>* lineasDeColectivos;

	/*
	 * pre: dirección no puede ser cadena vacía y coordenadas no puede ser NULL.
	 * post: crea una parada con una direccion y coordenadas pasadas por parametro.
	 */
	Parada(std::string direccion, Coordenadas* coordenadas);

	virtual ~Parada();
	/*
	 * pre: -
	 * post: obtiene la direccion de la parada.
	 */
	std::string getDireccion();

	/*
	 * pre: -
	 * post: obtiene las coordenadas de la parada.
	 */
	Coordenadas* getCoordenadas();

	/*
	 * pre: linea de colectivos tiene que ser distinto de NULL.
	 * post: guarda la linea de colectivos pasada por parametro.
	 */
	void agregarLineaDeColectivos(LineaDeColectivos* lineaDeColectivos);

	/*
	 * pre: linea de colectivos tiene que ser distinto de NULL.
	 * post: validar si una linea de colectivo pasada por parametro esta dentro de la lista.
	 */
	bool tieneLinea(LineaDeColectivos* lineaDeColectivos);

	/*
	 *Sobrecarga de tieneLinea. Se utiliza el nombre de la linea como parametro.
	 *pre: -
	 *post: validar si una linea de colectivo pasada por parametro esta dentro de la lista.
	 */

	bool tieneLinea(std::string nombreLinea);

};

#endif /* PARADA_H_ */