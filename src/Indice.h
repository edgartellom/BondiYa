/*
 * Indice.h
 *
 *  Created on: 16 jun. 2024
 *      Author: edgar
 */
#include "Barrio.h"
#ifndef INDICE_H_
#define INDICE_H_

class Indice {
private:
	Lista<Barrio*> barrios;
public:
	Indice();
	virtual ~Indice();
	void listarCantParadasPorBarrio();
	void getParadaMasCercana(Coordenadas);
	void listarParadas(unsigned int lineaDeColectivo);
	void listarCantParadasPorLineaDeColectivo();
	void getParadasOrdenadas(std::string nombreBarrio, unsigned lineaColectivos);
};

#endif /* INDICE_H_ */
