#include "Disco.h"


int Disco::count = 0;

Disco::Disco(){
        tamaño = ++count;
    }

Disco::~Disco(){
        count--;
    }

int Disco::getTamaño() const{
    return tamaño;
}

