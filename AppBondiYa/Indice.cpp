#include "Indice.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <limits>

Indice::Indice() {
	this->barrios = new Lista<Barrio*>();
    this->lineasDeColectivos = new Lista<LineaDeColectivos*>();
}

Indice::~Indice() {
    this->barrios->iniciarCursor();
    while (this->barrios->avanzarCursor()) {
        delete this->barrios->obtenerCursor();
    }
    delete this->barrios;

    this->lineasDeColectivos->iniciarCursor();
    while (this->lineasDeColectivos->avanzarCursor()) {
        delete this->lineasDeColectivos->obtenerCursor();
    }
    delete this->lineasDeColectivos;
}

void Indice::guardarInformacion(std::string rutaDeArchivo) {
    std::ifstream archivo;
    archivo.open(rutaDeArchivo.c_str());
    if (!archivo.is_open() || rutaDeArchivo.empty()) {
        throw "No se pudo abrir el archivo por estar dañado o por ruta incorrecta.";
    }
    std::string linea;
    // Leer la primera línea para descartarla, ya que es el encabezado
    std::getline(archivo, linea);
    // Leer todas las líneas de datos
    while (std::getline(archivo, linea)) {
        std::stringstream stream(linea);
        guardar_campos_principales(stream);
    }
    archivo.close();
}

std::string Indice::leerCampo(std::stringstream& stream, char delimitador) {
    if (!stream.good()) {
        throw "Stream no está en un estado válido.";
    }
    if (delimitador == '\0') {
        throw "Delimitador no válido.";
    }
    std::string campo;
    char siguiente = stream.peek();
    // Verificar si el siguiente caracter es una comilla
    if (siguiente == '"') {
        //stream.get(); // Consumir la comilla inicial
        while (stream.get(siguiente) && siguiente != '"') {
            campo += siguiente;
        }
        campo += siguiente;
        stream.get();
    } else if (siguiente == delimitador) {
        stream.get(); 
    } else {
        std::getline(stream, campo, delimitador); // Leer hasta el delimitador
    }
    return campo;
}

void Indice::guardar_campos_principales(std::stringstream& stream) {
    if (!stream.good()) {
        throw "Error: el stream no está en un estado válido.";
    }
    std::string x, y;
    std::string calle, altPlano, direccion, comuna, barrio;
	char delimitador = ',';
    // Leer cada campo del CSV utilizando leerCampo
    calle = leerCampo(stream, delimitador);
    altPlano = leerCampo(stream, delimitador);
    direccion = leerCampo(stream, delimitador);
    x = leerCampo(stream, delimitador);
    y = leerCampo(stream, delimitador);
    comuna = leerCampo(stream, delimitador);
    barrio = leerCampo(stream, delimitador);
    // Crear coordenada
    Coordenadas* coordenadas = crearCoordenadas(x, y);
    // Buscar o crear el barrio
    Barrio* barrioEncontrado = obtenerBarrio(barrio);
        if (barrioEncontrado == NULL) {
            barrioEncontrado = new Barrio(barrio);
            barrios->agregar(barrioEncontrado);
        }
    // Crear la parada
    Parada* parada = new Parada(direccion, coordenadas);
    // Leer las líneas de colectivo
    leerLineasDeColectivos(stream, parada);
    // Agregar la parada al barrio
    barrioEncontrado->agregarParada(parada);
}

void Indice::leerLineasDeColectivos(std::stringstream& stream, Parada* parada) {
    if (!stream.good()) {
        throw "Error: el stream no está en un estado válido.";
    }
    if(parada == NULL) {
        throw "parada no puede ser NULL";
    }
    bool continuarLectura = true;
    while (continuarLectura) {
        std::string lineaCampo;
        std::getline(stream, lineaCampo, ',');
        if (!lineaCampo.empty() && lineaCampo != ",") {
            LineaDeColectivos* linea = new LineaDeColectivos(lineaCampo);
            if (agregarSiNoExiste(linea)) {
                linea->incrementarCantidadDeParadas(); // Incrementar el contador de paradas
            }
            parada->agregarLineaDeColectivos(linea);
            std::string sentidoCampo;
            std::getline(stream, sentidoCampo, ',');
        } else {
            continuarLectura = false;
        }
    }
}

bool Indice::agregarSiNoExiste(LineaDeColectivos* linea) {
    if(linea == NULL){
        throw "linea no puede ser NULL";
    }
    this->lineasDeColectivos->iniciarCursor();
    while (this->lineasDeColectivos->avanzarCursor()) {
        LineaDeColectivos* lineaExistente = this->lineasDeColectivos->obtenerCursor();
        if (lineaExistente->getNumero() == linea->getNumero()) {
            delete linea; // Liberar la memoria de la línea que no se va a usar
            return false;
        }
    }
    this->lineasDeColectivos->agregar(linea);
    return true;
}

Lista<LineaDeColectivos*>* Indice::getLineasDeColectivos() {
    return this->lineasDeColectivos;
}

Coordenadas* Indice::crearCoordenadas(std::string x, std::string y) {
    if(x.empty() || y.empty()){
        throw "las coordenadas x e y no pueden ser vacíos";
    }
    double coordX, coordY;
    try {
        coordX = std::atof(x.c_str());
        coordY = std::atof(y.c_str());
    } catch (...) {
        std::cout << "Hubo un error en la conversión de coordenadas." << std::endl;
        return NULL;
    }
    return new Coordenadas(coordX, coordY);
}

Barrio* Indice::obtenerBarrio(const std::string& nombre){
    if (nombre.empty()) {
        throw "Error: el nombre del barrio no puede estar vacío.";
    }
    this->barrios->iniciarCursor();
    while (this->barrios->avanzarCursor()) {
        Barrio* barrio = this->barrios->obtenerCursor();
        if (barrio->getNombre() == nombre) {
            return barrio;
        }
    }
    return NULL;
}

void Indice::listarCantParadasPorBarrio() {
    this->barrios->iniciarCursor();
    while (this->barrios->avanzarCursor()) {
        Barrio* barrio = this->barrios->obtenerCursor();
        std::cout << "Barrio: " << barrio->getNombre() << ", Cantidad de paradas: " << barrio->getParadas()->getTamanio() << std::endl;
    }
}

// Método auxiliar para encontrar la parada más cercana en una lista de paradas
Parada* Indice::paradaCercana(Lista<Parada*>* paradas, Coordenadas* ubicacion, double& menorDistancia){
    if (paradas == NULL || ubicacion == NULL) {
        throw "Error: la lista de paradas o la ubicación no pueden ser NULL.";
    }
    Parada* paradaMasCercana = NULL;
    paradas->iniciarCursor();
    while (paradas->avanzarCursor()) {
        Parada* parada = paradas->obtenerCursor();
        double distancia = ubicacion->obtenerDistancia(parada->getCoordenadas());
        if (distancia < menorDistancia) {
            menorDistancia = distancia;
            paradaMasCercana = parada;
        }
    }
    return paradaMasCercana;
}

// Método principal para obtener la parada más cercana
void Indice::getParadaMasCercana(Coordenadas* ubicacion) {
    if(ubicacion == NULL){
        throw "ubicación tiene que ser distinto de NULL";
    }
    double menorDistancia = std::numeric_limits<double>::max();
    Parada* paradaMasCercana = NULL;
    this->barrios->iniciarCursor();
    while (this->barrios->avanzarCursor()) {
        Barrio* barrio = this->barrios->obtenerCursor();
        Lista<Parada*>* paradas = barrio->getParadas();
        Parada* paradaCercanaEnBarrio = paradaCercana(paradas, ubicacion, menorDistancia);

        if (paradaCercanaEnBarrio != NULL) {
            paradaMasCercana = paradaCercanaEnBarrio;
        }
    }
    if (paradaMasCercana) {
        std::cout << "La parada más cercana es: " << paradaMasCercana->getDireccion()
                << " en " << menorDistancia << " unidades de distancia." << std::endl;
    } else {
        std::cout << "No se encontraron paradas cercanas." << std::endl;
    }
}

void Indice::mostrarParadas(Barrio* barrio, LineaDeColectivos* lineaDeColectivos) {
    if(barrio == NULL || lineaDeColectivos == NULL){
        throw "barrio y linea de colectivos tienen que ser distintos de NULL.";
    }
    Lista<Parada*>* paradas = barrio->getParadas();
    paradas->iniciarCursor();
    while (paradas->avanzarCursor()) {
        Parada* parada = paradas->obtenerCursor();
        if (parada->tieneLinea(lineaDeColectivos)) {
            std::cout << "Parada: " << parada->getDireccion() << std::endl;
        }
    }
}

void Indice::listarParadas(LineaDeColectivos* lineaDeColectivos) {
    if(lineaDeColectivos == NULL){
        throw "linea de colectivos tienen que ser distinto de NULL.";
    }
    this->barrios->iniciarCursor();
    while (this->barrios->avanzarCursor()) {
        Barrio* barrio = this->barrios->obtenerCursor();
        mostrarParadas(barrio, lineaDeColectivos);
    }
}

void Indice::listarCantParadasPorLineaDeColectivo() {
    Lista<LineaDeColectivos*>* todasLasLineas = getLineasDeColectivos();
    todasLasLineas->iniciarCursor();
    while (todasLasLineas->avanzarCursor()) {
        LineaDeColectivos* linea = todasLasLineas->obtenerCursor();
        std::cout << "Línea " << linea->getNumero() << ": " << linea->getCantidadDeParadas() << " paradas." << std::endl;
    }
}
void Indice::getParadasOrdenadas(Barrio* barrio, LineaDeColectivos* lineaDeColectivos, Coordenadas* ubicacionActual) {
    if(barrio == NULL || lineaDeColectivos == NULL || ubicacionActual == NULL){
        throw "barrio, línea de colectivos y ubicación actual tienen que ser distintos de NULL.";
    }
    std::cout<<"Falta"<< std::endl;
};
