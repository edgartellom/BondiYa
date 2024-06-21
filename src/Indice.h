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

    //Recibe el nombre de barrio y numero de linea como string, y las coordenadas como tupla de doubles.
    //Funciona como hub para imprimir y una lista con las paradas de cierto barrio y cierta linea
    //ordenadas en distancia con respecto a una posicion ingresada.
	void imprimirParadasOrdenadas(std::string nombreBarrio, std::string nombreLinea, double coords[2]);


    //Se le ingresa el nombre de un barrio e itera sobre la lista de barrios.
    //Devuelve el objeto barrio que se corresponde con el nombre de barrio ingresado.
	Barrio* getBarrioPorNombre(std::string nombreBarrio);
};


//Funcion auxiliar. Recibe una lista de paradas y coordenadas en array de doubles.
//Devuelve la misma lista de paradas pero ordenada en base a distancia con las coordenadas ingresadas.
Lista<Parada*>*ordenarParadasPorDistancia(Lista<Parada*>* paradas, double coords[2]);


#endif /* INDICE_H_ */
