/*
 * menu.h
 *
 *  Created on: 16 jun. 2024
 *      Author: edgar
 */

void menu() {
	bool activo = true;
	int opcion;

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
		std::string barrio;
		std::string lineaDeColectivo;
		double coordenadaX;
		double coordenadaY;
		switch (opcion)
		{

		case 1:

			std::cout << std::endl;
			break;
		case 2:
			std::cout << std::endl;
			std::cout << "Ingrese una coordenada X: " << std::endl;
			std::cin >> coordenadaX;
			std::cout << coordenadaX << std::endl;
			std::cout << "Ingrese una coordenada Y: " << std::endl;
			std::cin >> coordenadaY;
			std::cout << coordenadaY << std::endl;
			coordenadaX = 0;
			coordenadaX = 0;
			break;
		case 3:
			std::cout << std::endl;
			std::cout << "Ingrese una linea de colectivo: ";
			std::cin >> lineaDeColectivo;
			std::cout << lineaDeColectivo << std::endl;
			lineaDeColectivo = "";
			std::cout << std::endl;
			break;
		case 4:
			std::cout << std::endl;
			std::cout << "Ingrese una linea de colectivo: ";
			std::cin >> lineaDeColectivo;
			std::cout << lineaDeColectivo << std::endl;
			lineaDeColectivo = "";
			std::cout << std::endl;
			break;
		case 5:
			std::cout << std::endl;
			std::cout << "Ingrese el barrio: ";
			std::cin >> barrio;
			std::cout << barrio << std::endl;
			std::cout << "Ingrese una linea de colectivo: ";
			std::cin >> lineaDeColectivo;
			std::cout << lineaDeColectivo << std::endl;
			barrio = "";
			lineaDeColectivo = "";
			std::cout << std::endl;
			break;
		case 6:
			activo = false;
			break;
		default:
			std::cout << std::endl << "La opción elegida no es válida." << std::endl << std::endl;
			break;
		}
	}
	std::cout << std::endl;
	std::cout << "¡Hasta luego!" << std::endl;
}


