#include "Juego.h"
#include <memory>
#include <algorithm>

Juego::Juego(int Ndiscos)
{
    numDiscos = Ndiscos;
    for (int i = 0; i < 3; i++)
    {
        misTorres[i] = make_shared<Torre>(i + 1);
    }

    vector<shared_ptr<Disco>> discos;
    for (int i = 0; i < Ndiscos; i++)
    {
        discos.push_back(make_shared<Disco>());
    }
    for (int i = Ndiscos; i > 0; i--)
    {
        misTorres[0]->push(discos[i]);
    }
    // Tengo que inicializar este atributo para poder visualizar

    actualizarEstado();
}

Juego::~Juego()
{
}

void Juego::actualizarEstado()
{
    for (int torre = 0; torre < 3; torre++)
    {
        // Recorro cada una de las torres extrayendo los discos en forma de vector de int, esto será más complejo en un futuro.
        vector<int> discos = misTorres[torre]->getDiscos();

        // Les doy la vuelta para que en el futuro se muestren mejor, librería algorithm
        std::reverse(discos.begin(), discos.end());

        // Asigno cada vector de int a las casillas de la matriz de estado
        estadoActual[torre] = discos;
    }
}

void Juego::imprimirEstado() const
{
    for (auto t : misTorres)
    {
        t->print();
    }
}