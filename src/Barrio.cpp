/*
 * Barrio.cpp
 *
 *  Created on: 16 jun. 2024
 *      Author: edgar
 */

#include "Barrio.h"

Barrio::Barrio(std::string nombre) {
	this->nombre = nombre;
	this->paradas = new Lista<Parada*>();
}

Barrio::~Barrio() {
}

std::string Barrio::getNombre() {
	return this->nombre;
}

Lista<Parada*>* Barrio::getParadas() {
	return this->paradas;
}

void Barrio::agregarParada(Parada* parada) {
	this->paradas->agregar(parada);
}

Lista<Parada*>* Barrio::ordenarParadas(Coordenadas* ubicacion) {
	Lista<Parada*>* listaOrdenada = new Lista<Parada*>();
	this->paradas->iniciarCursor();
	while(this->paradas->avanzarCursor()) {
		Parada* parada = this->paradas->obtenerCursor();
		double distancia = parada->getCoordenadas()->obtenerDistancia(ubicacion);
		//logica para ordenar parada por distancia
		if (distancia){
		}
	}

	return listaOrdenada;
}


Lista<Parada*>* Barrio::getParadasPorLinea(std::string linea){

    Lista<Parada*>* paradasCoincidencia=new Lista<Parada*>();
    this->paradas->iniciarCursor();

    while(this->paradas->avanzarCursor()){
        Parada* paradaActual=this->paradas->obtenerCursor();

        if (paradaActual->tieneLinea(linea)){
            paradasCoincidencia->agregar(paradaActual);
        }
    }
    if (paradasCoincidencia->estaVacia()){
        std::cout<<"Esa linea no pasa por ese barrio"<<std::endl;
        }

    return paradasCoincidencia;

}


