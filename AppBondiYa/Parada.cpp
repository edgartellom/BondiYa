#include "Parada.h"

Parada::Parada(std::string direccion, Coordenadas* coordenadas) {
	this->direccion = direccion;
	this->coordenadas = coordenadas;
	this->lineasDeColectivos = new Lista<LineaDeColectivos*>();
}

Parada::~Parada() {
	// TODO Auto-generated destructor stub
}

std::string Parada::getDireccion() {
	return this->direccion;
}

Coordenadas* Parada::getCoordenadas() {
	return this->coordenadas;
}

void Parada::agregarLineaDeColectivos(LineaDeColectivos* lineaDeColectivos) {
	this->lineasDeColectivos->agregar(lineaDeColectivos);
}

bool Parada::tieneLinea(LineaDeColectivos* lineaDeColectivos) {
	this->lineasDeColectivos->iniciarCursor();
	while(this->lineasDeColectivos->avanzarCursor()) {
		LineaDeColectivos* linea = this->lineasDeColectivos->obtenerCursor();
		if (linea->getNumero() == lineaDeColectivos->getNumero()) {
			return true;
		}
	}
	return false;
}

