#include "LineaDeColectivos.h"

LineaDeColectivos::LineaDeColectivos(std::string numero) {
	if (numero.empty()) {
        throw "El número del colectivo no puede ser vacío.";
    }
	this->numero = numero;
	this->cantidadDeParadas = 1;
}

LineaDeColectivos::~LineaDeColectivos() {
}

std::string LineaDeColectivos::getNumero() {
	return this->numero;
}

void LineaDeColectivos::incrementarCantidadDeParadas(){
	this->cantidadDeParadas++;
}

int LineaDeColectivos::getCantidadDeParadas() {
    return this->cantidadDeParadas;
}