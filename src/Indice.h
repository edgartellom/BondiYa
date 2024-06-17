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
	Lista<Barrio*>* barrios;
public:
	Indice();

	virtual ~Indice();

	/*
	 * pre: -
	 * post: guarda la informacion proveniente del archivo csv cuya ruta es pasada por parametro.
	 */
	void guardarInformacion(std::string rutaDeArchivo);

	/*
	 * pre: -
	 * post: lista los barrios con la cantidad de paradas que tiene cada barrio.
	 */
	void listarCantParadasPorBarrio();

	/*
	 * pre: -
	 * post: imprime la parada mas cercana a las coordenadas pasadas por parametro.
	 */
	void getParadaMasCercana(Coordenadas* ubicacion);

	/*
	 * pre: -
	 * post: lista las paradas de una linea de colectivo pasada por parametro.
	 */
	void listarParadas(LineaDeColectivos* lineaDeColectivos);

	/*
	 * pre: -
	 * post: lista las lineas de colectivo con su respectiva cantidad de paradas.
	 */
	void listarCantParadasPorLineaDeColectivo();

	/*
	 * pre: -
	 * post: obtiene las paradas de un barrio de una linea de colectivo en orden de acuerdo a la distancia de una ubicacion pasados por parametro.
	 */
	void getParadasOrdenadas(Barrio* barrio, LineaDeColectivos* lineaDeColectivos, Coordenadas* ubicacionActual);
};

#endif /* INDICE_H_ */
