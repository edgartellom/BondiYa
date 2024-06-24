#include <string>
#ifndef LINEADECOLECTIVOS_H_
#define LINEADECOLECTIVOS_H_

class LineaDeColectivos {

private:
	std::string numero;
	int cantidadDeParadas;

public:
	/*
	 * pre: El número del colectivo tiene que ser distinto de vacío.
	 * post: crea la linea de colectivo con su numero pasado por parametro, y se iniciliza la cantidad de paradas en 1(cantidad min).
	 */
	LineaDeColectivos(std::string numero);

	virtual ~LineaDeColectivos();

	/*
	 * pre: -
	 * post: devuelve el numero de la linea de colectivo.
	 */
	std::string getNumero();

	/*
	 * pre: -
	 * post: incrementa en uno la cantidad de paradas.
	 */
	void incrementarCantidadDeParadas();

	/*
	 * pre: -
	 * post: devuelve la cantidad de paradas.
	 */
	int getCantidadDeParadas();
};

#endif /* LINEADECOLECTIVOS_H_ */
