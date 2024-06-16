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
	Lista<Parada>* paradas;

public:
	Barrio();
	virtual ~Barrio();
	int getCantParadas();

};

#endif /* BARRIO_H_ */
