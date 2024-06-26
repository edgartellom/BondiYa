/*
 * Indice.cpp
 *
 *  Created on: 16 jun. 2024
 *      Author: edgar
 */

#include "Indice.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>

Indice::Indice() {
	this->barrios = new Lista<Barrio*>();
}

Indice::~Indice() {
	this->barrios->iniciarCursor();
	while (this->barrios->avanzarCursor()) {
		delete this->barrios->obtenerCursor();
	}
	delete this->barrios;
}

// Función para leer un campo del CSV teniendo en cuenta las comillas dobles
std::string leerCampo(std::stringstream& stream, char delimitador) {
    std::string campo;
    char c;
    bool enComillas = false;

    while (stream.get(c)) {
        if (c == '"') {
            enComillas = !enComillas;
        } else if (c == delimitador && !enComillas) {
            break;
        } else {
            campo += c;
        }
    }

    return campo;
}

void Indice::guardarInformacion(std::string rutaDeArchivo) {
    std::ifstream archivo;
    archivo.open(rutaDeArchivo.c_str());
    if(!archivo.is_open()) {
    	std::cout << "File "<< rutaDeArchivo <<" not found." << std::endl;
    }

    std::string linea;
    char delimitador = ',';
    // Leemos la primer línea para descartarla, pues es el encabezado
    std::getline(archivo, linea);

    // Leemos todas las líneas
    while(getline(archivo, linea)) {
    	std::stringstream stream(linea);
    	std::string calle, altPlano, direccion, x, y, comuna, barrio;
    	double coordX = 0, coordY = 0;

    	// Leer cada campo del CSV
    	calle = leerCampo(stream, delimitador);
    	altPlano = leerCampo(stream, delimitador);
    	direccion = leerCampo(stream, delimitador);
    	x = leerCampo(stream, delimitador);
    	y = leerCampo(stream, delimitador);

    	try {
    		coordX = std::stod(x);
    		coordY = std::stod(y);
    	} catch (...) {
    		std::cout << "Hubo un error de conversión" << std::endl;
    	}

    	comuna = leerCampo(stream, delimitador);
    	barrio = leerCampo(stream, delimitador);

    	Coordenadas* coordenadas = new Coordenadas(coordX, coordY);

    	// Buscar o crear el barrio
    	Barrio* barrioExistente = NULL;
    	this->barrios->iniciarCursor();
    	while(this->barrios->avanzarCursor()) {
    		Barrio* b = this->barrios->obtenerCursor();
    		if (b->getNombre() == barrio) {
    			barrioExistente = b;
    			break;
    		}
    	}
    	if (!barrioExistente) {
    		barrioExistente = new Barrio(barrio);
    		this->barrios->agregar(barrioExistente);
    	}

    	// Crear la parada y agregarla al barrio
    	Parada* parada = new Parada(direccion, coordenadas);

    	// Leer las líneas de colectivo
    	for (int i = 0; i < 6; i++) {
    		std::string lineaCampo = leerCampo(stream, delimitador);
    		std::string sentido = leerCampo(stream, delimitador);
    		if (!lineaCampo.empty()) {
    			LineaDeColectivos* linea = new LineaDeColectivos(lineaCampo);
    			parada->agregarLineaDeColectivos(linea);
    		}
    	}
    	barrioExistente->agregarParada(parada);
    }
    archivo.close();
}

void Indice::listarCantParadasPorBarrio() {
    this->barrios->iniciarCursor();
    while (this->barrios->avanzarCursor()) {
        Barrio* barrio = this->barrios->obtenerCursor();
        std::cout << "Barrio: " << barrio->getNombre() << ", Cantidad de paradas: " << barrio->getParadas()->getTamanio() << std::endl;
    }
}

void Indice::getParadaMasCercana(Coordenadas* ubicacion) {
	double menorDistancia = std::numeric_limits<double>::max();
	Parada* paradaMasCercana;

	this->barrios->iniciarCursor();
	while (this->barrios->avanzarCursor()) {
		Barrio* barrio = this->barrios->obtenerCursor();
		Lista<Parada*>* paradas = barrio->getParadas();
		paradas->iniciarCursor();
		while (paradas->avanzarCursor()) {
			Parada* parada = paradas->obtenerCursor();
			double distancia = ubicacion->obtenerDistancia(parada->getCoordenadas());
			if (distancia < menorDistancia) {
				menorDistancia = distancia;
				paradaMasCercana = parada;
			}
		}
	}

	if (paradaMasCercana) {
		std::cout << "La parada más cercana es: " << paradaMasCercana->getDireccion()
				<< " en " << menorDistancia << " unidades de distancia." << std::endl;
	} else {
		std::cout << "No se encontraron paradas cercanas." << std::endl;
	}
};

void Indice::listarParadas(LineaDeColectivos* lineaDeColectivos) {
	this->barrios->iniciarCursor();
	while (this->barrios->avanzarCursor()) {
		Barrio* barrio = this->barrios->obtenerCursor();
		Lista<Parada*>* paradas = barrio->getParadas();
		paradas->iniciarCursor();
		while (paradas->avanzarCursor()) {
			Parada* parada = paradas->obtenerCursor();
			if (parada->tieneLinea(lineaDeColectivos)) {
				std::cout << "Parada: " << parada->getDireccion() << std::endl;
			}
		}
	}
};

void Indice::listarCantParadasPorLineaDeColectivo() {

};

void Indice::getParadasOrdenadas(Barrio* barrio, LineaDeColectivos* lineaDeColectivos, Coordenadas* ubicacionActual) {

};
