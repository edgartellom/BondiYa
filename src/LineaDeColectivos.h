/*
 * LineaDeColectivos.h
 *
 *  Created on: 16 jun. 2024
 *      Author: edgar
 */
#include <string>
#ifndef LINEADECOLECTIVOS_H_
#define LINEADECOLECTIVOS_H_

class LineaDeColectivos {

private:
	std::string numero;

public:
	/*
	 * pre: -
	 * post: crea la linea de colectivo con su numero pasado por parametro.
	 */
	LineaDeColectivos(std::string numero);

	virtual ~LineaDeColectivos();

	/*
	 * pre: -
	 * post: obtiene el numero de la linea de colectivo.
	 */
	std::string getNumero();
};

#endif /* LINEADECOLECTIVOS_H_ */
