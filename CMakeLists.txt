cmake_minimum_required(VERSION 3.24)
project(BondiYa)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(BondiYa
        src/Barrio.cpp
        src/Barrio.h
        src/Coordenadas.cpp
        src/Coordenadas.h
        src/Indice.cpp
        src/Indice.h
        src/LineaDeColectivos.cpp
        src/LineaDeColectivos.h
        src/Lista.h
        src/main.cpp
        src/menu.h
        src/Nodo.h
        src/Parada.cpp
        src/Parada.h)
