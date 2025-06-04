#include "Disco.h"
#include <memory>
#include <vector>

struct Nodo; //Predeclaración para que se se pueda usar

//ALIAS****************************************************************************************
typedef shared_ptr<Nodo> pNodo;
typedef shared_ptr<Disco> pDisco;

//ESTRUCTURAS DE DATOS*************************************************************************
struct Nodo{
    pDisco disco;
    pNodo siguiente;
    Nodo(pDisco d, pNodo s = nullptr):disco(d), siguiente(s){}
};


class Torre{

    private:
    pNodo top;
    int nNodos = 0;
    int numeroTorre;
    vector<int> numerosUsados;

    public:
    Torre(int);
    ~Torre();
    void push(pDisco d);
    pDisco pop();
    pDisco peek() const;
    bool empty() const;
    void print() const;
    int size() const;

};