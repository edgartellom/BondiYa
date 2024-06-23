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
    if (coordenadas == NULL) {
        throw "No se puede calcular la distancia a coordenadas nulas.";
    }
    double dx = this->coordenadaX - coordenadas->getCoordenadaX();
    double dy = this->coordenadaY - coordenadas->getCoordenadaY();
    return std::sqrt(dx * dx + dy * dy);
}
