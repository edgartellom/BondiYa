#ifndef COORDENADAS_H_
#define COORDENADAS_H_

class Coordenadas {

private:
	double coordenadaX;
	double coordenadaY;

public:
	/*
	 * pre: -
	 * post: crea coordenadas por defecto en 0 y 0.
	 */
	Coordenadas();

	/*
	 * pre: -
	 * post: crea las coordenadas pasandolas por parametro.
	 */
	Coordenadas(double coordenadaX, double coordenadaY);

	virtual ~Coordenadas();

	/*
	 * pre: -
	 * post: obtiene la coordenada X.
	 */
	double getCoordenadaX();

	/*
	 * pre: -
	 * post: obtiene la coordenada Y.
	 */
	double getCoordenadaY();

	/*
     * pre: 'coordenadas' no debe ser NULL.
     * post: calcula la distancia a otras coordenadas pasadas por parámetro.
     */
	double obtenerDistancia(Coordenadas* coordenadas);
};

#endif /* COORDENADAS_H_ */
