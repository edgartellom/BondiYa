#include "Barrio.h"
#include "FuncionesAuxiliares.h"
#ifndef INDICE_H_
#define INDICE_H_

class Indice {
private:
	Lista<Barrio*>* barrios;
	Lista<LineaDeColectivos*>* lineasDeColectivos;

	/*
     * pre: stream debe estar en un estado válido.
     * post: guarda los campos principales de una línea del archivo CSV en el índice.
     */
	void guardarCamposPrincipales(std::stringstream& stream);

	/*
     * pre: linea no puede ser vacio.
     * post: agrega la línea de colectivos al índice si no existe.
     */
	LineaDeColectivos* encontrarLinea(const std::string& lineaColectivo);

	/*
     * pre: stream debe estar en un estado válido. parada no puede ser NULL.
     * post: lee las líneas de colectivos de una parada desde el archivo CSV.
     */
    void leerLineasDeColectivos(std::stringstream& stream, Parada* parada);
    
	/*
     * pre: x y y no pueden ser vacíos.
     * post: crea y devuelve un objeto Coordenadas con los valores proporcionados.
     */
	Coordenadas* crearCoordenadas(std::string x, std::string y);

	/*
     * pre: -
     * post: devuelve la lista de líneas de colectivos del índice.
     */
	Lista<LineaDeColectivos*>* getLineasDeColectivos(); 

	/*
     * pre: stream debe estar en un estado válido.
     * post: lee un campo del stream hasta encontrar el delimitador y lo devuelve.
     */
	std::string leerCampo(std::stringstream& stream, char delimitador);

	/*
     * pre: el nombre del barrio no puede estar vacío.
     * post: devuelve el barrio correspondiente al nombre dado, o NULL si no se encuentra.
     */
	Barrio* obtenerBarrio(const std::string& nombre);

	/*
     * pre: paradas, ubicacion y menorDistancia no pueden ser NULL.
     * post: devuelve la parada más cercana a la ubicación proporcionada.
     */	
	Parada* paradaCercana(Lista<Parada*>* paradas, Coordenadas* ubicacion, double& menorDistancia);
	
	/*
     * pre: barrio y lineaDeColectivos no pueden ser NULL.
     * post: muestra las paradas del barrio que tienen la línea de colectivos dada.
     */
	void mostrarParadas(Barrio* barrio, LineaDeColectivos* lineaDeColectivos);
public:
	Indice();

	virtual ~Indice();
	
	/*
	 * pre: ruta del archivo tiene que ser distinto de vacío.
	 * post: guarda la informacion proveniente del archivo csv cuya ruta es pasada por parametro.
	 */
	void guardarInformacion(std::string rutaDeArchivo);

	/*
	 * pre: -
	 * post: lista los barrios con la cantidad de paradas que tiene cada barrio.
	 */
	void listarCantParadasPorBarrio();

	/*
	 * pre: ubicación tiene que ser distinto de NULL.
	 * post: imprime la parada mas cercana a las coordenadas pasadas por parametro.
	 */
	void getParadaMasCercana(Coordenadas* ubicacion);

	/*
	 * pre: lineaDeColectivo tiene que ser distinto de NULL.
	 * post: lista las paradas de una linea de colectivo pasada por parametro.
	 */
	void listarParadas(LineaDeColectivos* lineaDeColectivos);

	/*
	 * pre: -
	 * post: lista las lineas de colectivo con su respectiva cantidad de paradas.
	 */
	void listarCantParadasPorLineaDeColectivo();

	/*
	 * pre: barrio, lineaDeColestivos y ubicacionActual tienen que ser distinto de NULL.
	 * post: obtiene las paradas de un barrio de una linea de colectivo en orden de acuerdo a la distancia de una ubicacion pasados por parametro.
	 */
	void getParadasOrdenadas(Barrio* barrio, LineaDeColectivos* lineaDeColectivos, Coordenadas* ubicacionActual);

	/*
	 * pre: -
	 * post: Imprime las paradas del barrio y linea especificados ordenados
	 * segun la distancia con la ubicacion ingresada.
	 */
	void imprimirParadasOrdenadas(std::string nombreBarrio, std::string nombreLinea, double coords[2]);


	/*
	 * pre: -
	 * post: Devuelve el barrio cuyo nombre coincida con el string ingresado.
	 * Si no se encuentra un barrio que coincida, imprime que la funcion no lo encontro.
	 */
	Barrio* getBarrioPorNombre(std::string nombreBarrio);
};

#endif /* INDICE_H_ */
