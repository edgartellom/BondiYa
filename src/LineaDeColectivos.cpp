/*
 * LineaDeColectivos.cpp
 *
 *  Created on: 16 jun. 2024
 *      Author: edgar
 */

#include "LineaDeColectivos.h"

LineaDeColectivos::LineaDeColectivos(std::string numero) {
	this->numero = numero;
}

LineaDeColectivos::~LineaDeColectivos() {
	// TODO Auto-generated destructor stub
}

std::string LineaDeColectivos::getNumero() {
	return this->numero;
}

