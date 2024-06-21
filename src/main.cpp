//============================================================================
// Name        : main.cpp
// Author      : Edgar Tello
// Version     :
// Copyright   : Your copyright notice
// Description : BondiYa (TP2) in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include "Indice.h"
#define NOMBRE_ARCHIVO "paradas_de_colectivo.csv"
using namespace std;



int main() {
	bool activo = true;
	int opcion;

	Indice* indice = new Indice();
	indice->guardarInformacion(NOMBRE_ARCHIVO);


	std::cout << "¡Bienvenido al sistema BondiYa!" << std::endl;
	std::cout << std::endl;
	while(activo) {
		std::cout << "Menú de opciones:" << std::endl;
		std::cout << "-----------------" << std::endl;
		std::cout << "[1] Listar la cantidad de paradas por barrio." << std::endl;
		std::cout << "[2] Encontrar la parada más cercana." << std::endl;
		std::cout << "[3] Listar paradas." << std::endl;
		std::cout << "[4] Listar cantidad de paradas por linea de colectivo." << std::endl;
		std::cout << "[5] Listar paradas ordenadas por distancia (mas cercanas primero)." << std::endl;
		std::cout << "[6] Salir." << std::endl;
		std::cout << "Elija una opción [1-6]: ";
		std::cin >> opcion;
		std::cin.ignore();
		std::string barrio;
		std::string lineaDeColectivo;
		double coordenadaX;
		double coordenadaY;
		double coords[2];
		switch (opcion)
		{

		case 1: {
			std::cout << std::endl;
			indice->listarCantParadasPorBarrio();
			std::cout << std::endl;
			break;
		}
		case 2: {
            std::cout << std::endl;
			std::cout << "Ingrese una coordenada X: ";
			std::cin >> coordenadaX;
			std::cout << "Ingrese una coordenada Y: ";
			std::cin >> coordenadaY;
			Coordenadas* coordenadas = new Coordenadas(coordenadaX, coordenadaY);
			indice->getParadaMasCercana(coordenadas);
			std::cout << std::endl;
			delete coordenadas;
			break;

		}
		case 3: {
			std::cout << std::endl;
			std::cout << "Ingrese una linea de colectivo: ";
			std::cin >> lineaDeColectivo;
			LineaDeColectivos * linea = new LineaDeColectivos(lineaDeColectivo);
			indice->listarParadas(linea);
			std::cout << std::endl;
			delete linea;
			break;
		}
		case 4: {
			std::cout << std::endl;
			indice->listarCantParadasPorLineaDeColectivo();
			std::cout << std::endl;
			break;
		}
		case 5: {

			std::cout << std::endl;
			std::cout << "Ingrese el barrio: "<<std::endl;
			std::getline(std::cin,barrio);
			std::cout << "Ingrese una linea de colectivo: ";
			std::cin >> lineaDeColectivo;
			std::cout << "Ingrese una coordenada X: ";
			std::cin >> coords[0];
			std::cout << "Ingrese una coordenada Y: ";
			std::cin.ignore();
			std::cin >> coords[1];
            //REVISAR: Funcion no soporta input no numerico en ingreso de coordenadas. Programa loopea indefinidamente.

			indice->getParadasOrdenadas(barrio, lineaDeColectivo, coords);
			std::cout << std::endl;
			//delete nuevoBarrio;
			//delete lineaNueva;
			//delete ubicacionActual;
			break;
		}
		case 6: {
			activo = false;
			break;
		}
		default: {
			std::cout << std::endl << "La opción elegida no es válida." << std::endl << std::endl;
			break;
		}
		}
	}
	std::cout << std::endl;
	std::cout << "¡Hasta luego!" << std::endl;
	delete indice;
	return 0;
}
