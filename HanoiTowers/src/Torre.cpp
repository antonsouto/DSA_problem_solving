#include "Torre.h"
#include <iostream>

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
    if (top == nullptr)
        top = make_shared<Nodo>(d);
    return;
    auto it = top;
    while (it->siguiente != nullptr)
    {
        it = it->siguiente;
    }
    it->siguiente = make_shared<Nodo>(d);
    nNodos++;
}
pDisco Torre::pop()
{
    auto it = top;
    top = it->siguiente;
    nNodos--;
    return it->disco;
}
pDisco Torre::peek() const
{
    return top->disco;
};
bool Torre::empty() const
{
    if (top)
    {
        return true;
    }
    else
    {
        return false;
    };
};
void Torre::print() const
{
    auto it = top;
    int i = 1;
    cout << "La torre numero " << numeroTorre << " contiene los discos: " << endl;
    while (it!=nullptr)
    {
        cout << "Disco " << i++ << " con tamaño " << it->disco->getTamaño() << endl;
    }
};

int Torre::size()const{
    return nNodos;
}
