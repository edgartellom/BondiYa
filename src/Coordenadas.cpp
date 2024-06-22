/*
 * Coordenadas.cpp
 *
 *  Created on: 16 jun. 2024
 *      Author: edgar
 */

#include "Coordenadas.h"
#include <cmath>

Coordenadas::Coordenadas() {
	this->coordenadaX = 0;
	this->coordenadaY = 0;
}

Coordenadas::Coordenadas(double coordenadaX, double coordenadaY) {
	this->coordenadaX = coordenadaX;
	this->coordenadaY = coordenadaY;
}

Coordenadas::~Coordenadas() {
}

double Coordenadas::getCoordenadaX() {
	return this->coordenadaX;
}

double Coordenadas::getCoordenadaY() {
	return this->coordenadaY;
}

double Coordenadas::obtenerDistancia(Coordenadas* coordenadas) {
    double dx = this->coordenadaX - coordenadas->getCoordenadaX();
    double dy = this->coordenadaY - coordenadas->getCoordenadaY();
    return std::sqrt(dx * dx + dy * dy);
}



double Coordenadas::obtenerDistancia(double coordenadas[2]){
    const double A_RADIANES=M_PI/180;
    const double RADIO_TIERRA=6371000;


    double dx = (coordenadas[0]-this->coordenadaX)*A_RADIANES;
    double dy = (coordenadas[1] - this->coordenadaY)*A_RADIANES;

    return std::sqrt(dx*dx+dy*dy)*RADIO_TIERRA;

}
