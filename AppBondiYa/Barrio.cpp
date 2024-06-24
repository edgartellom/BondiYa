#include "Barrio.h"

Barrio::Barrio(std::string nombre) {
	if (nombre.empty()) {
        throw "El nombre del barrio no puede ser vacío.";
    }
    this->nombre = nombre;
	this->paradas = new Lista<Parada*>();
}

Barrio::~Barrio() {
    this->paradas->iniciarCursor();
    while (this->paradas->avanzarCursor()) {
        delete this->paradas->obtenerCursor();
    }
    delete this->paradas;
}

std::string Barrio::getNombre() {
	return this->nombre;
}

Lista<Parada*>* Barrio::getParadas() {
	return this->paradas;
}

void Barrio::agregarParada(Parada* parada) {
	if (parada == NULL) {
        throw "No se puede agregar una parada nula.";
	}
	this->paradas->agregar(parada);
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

