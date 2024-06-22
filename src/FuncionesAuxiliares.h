
#include "Barrio.h"
#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

	/*
     *Recibe una lista de punteros de paradas. Retorna esa misma lista
	 *ordenada en base a la distancia con las coordenadas ingresadas.
     *
	 * pre: -
	 * post:Retorna la lista ingresada ordenada en base a las coordenadas.
	 */
Lista<Parada*>* ordenarParadasPorDistancia(Lista<Parada*>* paradas, double coords[2]);

	/*
	 * pre: paradas debe apuntar a una lista valida
	 * post:Imprime la lista y junto a la distancia
	 * con el punto ingresado
	 */
void imprimirParadasConDistancia(Lista<Parada*>* paradas, double coords[2]);

#endif
