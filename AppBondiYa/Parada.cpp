#include "Parada.h"

Parada::Parada(std::string direccion, Coordenadas* coordenadas) {
	if(direccion.empty()){
		throw "La direccion no puede ser vacío.";
	}
	this->direccion = direccion;
	this->coordenadas = coordenadas;
	this->lineasDeColectivos = new Lista<LineaDeColectivos*>();
}

Parada::~Parada() {
	this->lineasDeColectivos->iniciarCursor();
    while (this->lineasDeColectivos->avanzarCursor()) {
        delete this->lineasDeColectivos->obtenerCursor();
    }
    delete this->lineasDeColectivos;
	delete this->coordenadas;
}

std::string Parada::getDireccion() {
	return this->direccion;
}

Coordenadas* Parada::getCoordenadas() {
	return this->coordenadas;
}

void Parada::agregarLineaDeColectivos(LineaDeColectivos* lineaDeColectivos) {
	if(lineaDeColectivos == NULL){
		throw "lineaDeColectivos no puede ser NULL.";
	}
	this->lineasDeColectivos->agregar(lineaDeColectivos);
}

bool Parada::tieneLinea(LineaDeColectivos* lineaDeColectivos) {
	if(lineaDeColectivos == NULL){
		throw "lineaDeColectivos no puede ser NULL.";
	}
	this->lineasDeColectivos->iniciarCursor();
	while(this->lineasDeColectivos->avanzarCursor()) {
		LineaDeColectivos* linea = this->lineasDeColectivos->obtenerCursor();
		//std::cout << "linea: " << linea->getNumero() << std::endl;
		if (linea->getNumero() == lineaDeColectivos->getNumero()) {
			return true;
		}
	}
	return false;
}

bool Parada::tieneLinea(std::string nombreLinea){

    this->lineasDeColectivos->iniciarCursor();

    while(this->lineasDeColectivos->avanzarCursor()) {
            LineaDeColectivos* lineaRevisada = this->lineasDeColectivos->obtenerCursor();
            if (lineaRevisada->getNumero()==nombreLinea){
                return true;
            }
    }
    return false;

}
