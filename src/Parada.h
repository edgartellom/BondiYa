/*
 * Parada.h
 *
 *  Created on: 16 jun. 2024
 *      Author: edgar
 */
#include "Lista.h"
#ifndef PARADA_H_
#define PARADA_H_

struct Coordenadas {
	double coordenadaX;
	double coordenadaY;
};

class Parada {
public:
	std::string direccion;
	Coordenadas coordenadas;
	Lista<unsigned int>* lineaDeColectivos;

	Parada();
	virtual ~Parada();
	std::string getDireccion();
	Coordenadas getCoordenadas();
};

#endif /* PARADA_H_ */
