#include <iostream>
#include <fstream>
#include <sstream>
#include "Indice.h"
#include <iostream>
#include <string>
#define NOMBRE_ARCHIVO "paradas_de_colectivo.csv"
using namespace std;

void mostrarMenu() {
    std::cout << "Menu de Opciones:\n";
    std::cout << "1) Listado de cantidad de paradas por barrio\n";
    std::cout << "2) Parada más cercana a una coordenada ingresada por teclado\n";
    std::cout << "3) Listado de paradas de una línea de colectivo\n";
    std::cout << "4) Listado de cantidad de paradas por linea de colectivo\n";
    std::cout << "5) Dado un barrio y una línea de colectivo, imprimir las paradas ordenadas por distancia\n";
    std::cout << "6) Salir\n";
    std::cout << "Elija una opción [1-6]: ";
}


int main() {
    Indice* indice = new Indice();
    try{
	    indice->guardarInformacion(NOMBRE_ARCHIVO);
        int opcion;
        std::cout << "¡Bienvenido al sistema BondiYa!" << std::endl;
	    std::cout << std::endl;
        do {
            mostrarMenu();
            std::cin >> opcion;
    
            switch (opcion) {
                case 1: {
                    indice->listarCantParadasPorBarrio();
                    break;
                }
                case 2: {
                    double coordX, coordY;
                    std::cout << "Ingrese la coordenada X: ";
                    std::cin >> coordX;
                    std::cout << "Ingrese la coordenada Y: ";
                    std::cin >> coordY;
                    Coordenadas* ubicacion = new Coordenadas(coordX, coordY);
                    indice->getParadaMasCercana(ubicacion);
                    delete ubicacion;
                    break;
                }
                case 3: {
                    std::string numeroLinea;
                    std::cout << "Ingrese el número de línea de colectivo: ";
                    std::cin >> numeroLinea;
                    LineaDeColectivos* linea = new LineaDeColectivos(numeroLinea);
                    indice->listarParadas(linea);
                    delete linea;
                    break;
                }
                case 4: {
                    indice->listarCantParadasPorLineaDeColectivo();
                    break;
                }
                case 5: {
                    std::string nombreBarrio, numeroLinea;
                    std::cout << "Ingrese el nombre del barrio: ";
                    std::cin.ignore();
                    std::getline(std::cin, nombreBarrio);
                    std::cout << "Ingrese el número de línea de colectivo: ";
                    std::cin >> numeroLinea;
                    Barrio* barrio = new Barrio(nombreBarrio);
                    LineaDeColectivos* linea = new LineaDeColectivos(numeroLinea);
                    Coordenadas* ubicacionActual = new Coordenadas(0, 0); // Colocar la ubicación actual
                    indice->getParadasOrdenadas(barrio, linea, ubicacionActual);
                    delete barrio;
                    delete linea;
                    delete ubicacionActual;
                    break;
                }
                case 6: {
                    std::cout << "Saliendo del programa..." << std::endl;
                    break;
                }
                default: {
                    std::cout << "Opción inválida. Intente nuevamente." << std::endl;
                    break;
                }
            }
        } while (opcion != 6);
	    std::cout << "¡Gracias por su preferencia!" << std::endl;
    } catch (const char* s) {
        std::cout << "Error:"<< s << std::endl;
    } catch(...){
        std::cout << "Error inesperado"<< std::endl;
    }
	delete indice;
	return 0;
}
