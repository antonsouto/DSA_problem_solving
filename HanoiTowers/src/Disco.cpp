#include "Disco.h"
#include <iostream>



int Disco::count = 0;

Disco::Disco(){
        
        tamaño = ++count;
        tamañosUsados.push_back(tamaño);
    }

Disco::~Disco(){
        count--;
    }

int Disco::getTamaño() const{
    return tamaño;
}

Disco::Disco(int tam)
{ // En principio esto solo se prevée para cargar partidas porque si no la lógica puede romperse
    tamaño = tam;
    tamañosUsados.push_back(tamaño);
}

void Disco::print()
{
    cout << "Disco de tamaño: " << tamaño << endl;
}