/*
 * Parada.h
 *
 *  Created on: 16 jun. 2024
 *      Author: edgar
 */
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
	 * pre: -
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
	 * pre: -
	 * post: guarda la linea de colectivos pasada por parametro.
	 */
	void agregarLineaDeColectivos(LineaDeColectivos* lineaDeColectivos);

	/*
	 * pre: -
	 * post: validar si una linea de colectivo pasada por parametro esta dentro de la lista.
	 */
	bool tieneLinea(LineaDeColectivos* lineaDeColectivos);

	//Sobrecarga de tieneLinea. Revisa si una linea especifica esta dentro de la lista.
	//El parametro de referencia es el numero de la linea ingresado como string.

	bool tieneLinea(std::string nombreLinea);

};

#endif /* PARADA_H_ */
