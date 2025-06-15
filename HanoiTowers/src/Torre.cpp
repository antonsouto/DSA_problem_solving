#include "Torre.h"
#include <iostream>


// Definición de variables estáticas, norma de C++
vector<int> Torre::numerosUsados; // define la variable estática


Torre::Torre(int numero)
{
    for (auto n : numerosUsados)
    {
        if (n == numero)
            throw std::invalid_argument("Ese número ya ha sido usado");
    }
    numerosUsados.push_back(numero);
    numeroTorre = numero;
    top = nullptr;
}

Torre::~Torre(){
    //No libero memoria porque uso punteros inteligentes
}

void Torre::push(pDisco d)
{
    pNodo nuevoTop = make_shared<Nodo>(d, top);
    top = nuevoTop;
    nNodos++;
}

pDisco Torre::pop()
{
    if (top)
    {

        auto it = top;
        top = it->siguiente;
        nNodos--;
        return it->disco;
    }else{
        return nullptr;
    }
}
pDisco Torre::peek() const
{
    return top->disco;
};
bool Torre::empty() const
{
    if (top)
    {
        return false;
    }
    else
    {
        return true;
    };
};
void Torre::print() const
{
    auto it = top;
    int i = 1;
    cout << "La torre numero " << numeroTorre << " contiene los discos: " << endl;
    while (it!=nullptr)
    {
        cout << "   - Disco " << i++ << " con tamaño " << it->disco->getTamaño() << endl;
        it = it->siguiente;
    }
};

int Torre::size()const{
    return nNodos;
}

/* void Torre::print() const
{
    auto it = top;
    while(it){
        it->disco->print();
        it = it->siguiente;
    }
} */

int Torre::getNumTorre() const
{
    return numeroTorre;
}

vector<int> Torre::getDiscos() const{
    vector<int> aux;
    auto it = top;
    while(it){
        aux.push_back(it->disco->getTamaño());
        it = it->siguiente;
    }
    return aux;
}