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
    //int numeroDeLinea = 1;
    // Leer todas las líneas de datos
    while (std::getline(archivo, linea)) {
        //std::cout << "LineaTexto " << numeroDeLinea++ << ": " << linea << std::endl;
        std::stringstream stream(linea);
        guardarCamposPrincipales(stream);
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
    if (siguiente == '"') {
        stream.get(); // Leer y descartar la comilla inicial
        campo += '"'; // Incluir la comilla inicial en el campo
        while (stream.get(siguiente) && siguiente != '"') {
            campo += siguiente;
        }
        if (siguiente == '"') {
            campo += '"'; // Incluir la comilla final en el campo
        }
        stream.get();
    } else if (siguiente == delimitador) {
        stream.get(); 
    } else {
        std::getline(stream, campo, delimitador); // Leer hasta el delimitador
    }
    //std::cout<<"Campo: "<<campo<<std::endl;
    return campo;
}

void Indice::guardarCamposPrincipales(std::stringstream& stream) {
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
    if (barrio.empty()) {
        barrio = "N.N(SinBarrio)";//agrega un nombre por defecto
    // Buscar o crear el barrio
    }
    Barrio* barrioEncontrado = obtenerBarrio(barrio);
        if (barrioEncontrado == NULL) {
            barrioEncontrado = new Barrio(barrio);
            barrios->agregar(barrioEncontrado);
        }
    // Crear la parada
    if (direccion.empty()) {
        direccion = calle + "," + altPlano;
    }
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
            LineaDeColectivos* lineaExistente = encontrarLinea(lineaCampo);
            if (lineaExistente == NULL) {
                LineaDeColectivos* linea = new LineaDeColectivos(lineaCampo);
                this->lineasDeColectivos->agregar(linea);
            } else {
                parada->agregarLineaDeColectivos(lineaExistente);
                lineaExistente->incrementarCantidadDeParadas();
            }
            std::string sentidoCampo;
            std::getline(stream, sentidoCampo, ',');
        } else {
            continuarLectura = false;
        }
    }
}

LineaDeColectivos* Indice::encontrarLinea(const std::string& linea) {
    if (linea.empty()){
        throw "la linea no puede ser vacío";
    }
    this->lineasDeColectivos->iniciarCursor();
    while (this->lineasDeColectivos->avanzarCursor()) {
        LineaDeColectivos* lineaExistente = this->lineasDeColectivos->obtenerCursor();
        if (lineaExistente->getNumero() == linea) {
            return lineaExistente;
        }
    }
    return NULL;
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
        std::cout <<"\n"<<"La parada más cercana es: " << paradaMasCercana->getDireccion()
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
            std::cout << "Parada" << ":" <<parada->getDireccion() << std::endl;
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
void Indice::imprimirParadasOrdenadas(std::string nombreBarrio, std::string linea, double coords[2]) {
    Barrio * barrioOrdenar=getBarrioPorNombre(nombreBarrio);
    Lista<Parada*>* paradasCoincidencia=barrioOrdenar->getParadasPorLinea(linea);
    paradasCoincidencia->iniciarCursor();
    paradasCoincidencia=ordenarParadasPorDistancia(paradasCoincidencia,coords);
    paradasCoincidencia->iniciarCursor();
    imprimirParadasConDistancia(paradasCoincidencia,coords);
    delete paradasCoincidencia;
}

Barrio* Indice::getBarrioPorNombre(std::string nombreBarrio){

    try{
        bool siguiente=true;
        this->barrios->iniciarCursor();
        Barrio * barrioActual;
        while(this->barrios->avanzarCursor()){
                barrioActual=this->barrios->obtenerCursor();
                if (nombreBarrio==barrioActual->getNombre()){
                    return barrioActual;
        }
    }

throw 125;
    }
    catch(int){
    std::cout<<"Barrio no encontrado"<<std::endl;
    return NULL;
    }
}
//potencialmente cambiar el sistema catch para que se siga ejecutando el menu luego de no encontrar barrio