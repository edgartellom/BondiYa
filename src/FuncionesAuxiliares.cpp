

#include "FuncionesAuxiliares.h"


Lista<Parada*>* ordenarParadasPorDistancia(Lista<Parada*>* paradas,double coords[2]){

    int tamanio=paradas->getTamanio();
    Parada* paradaTemp;

    for (int i=2;i<=tamanio;i+=1){

        paradaTemp=paradas->obtener(i);
        int j=i-1;

        while(j>=1&&paradas->obtener(j)->getCoordenadas()->obtenerDistancia(coords)>paradaTemp->getCoordenadas()->obtenerDistancia(coords)){

            paradas->cambiar(paradas->obtener(j),j+1);
            j=j-1;
            }
        paradas->cambiar(paradaTemp,j+1);
    }

    return paradas;
    }
