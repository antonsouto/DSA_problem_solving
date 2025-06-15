#include "Juego.h"
#include <memory>
#include <algorithm>

Juego::Juego(int Ndiscos)
{
    numDiscos = Ndiscos;
    for (int i = 0; i < 3; i++)
    {
        misTorres[i] = make_shared<Torre>(i + 1); //Torre 1 ocupa la posicion 0 en el array de torres de mi juego
    }

    vector<shared_ptr<Disco>> discos;
    for (int i = 0; i < Ndiscos; i++)
    {
        discos.push_back(make_shared<Disco>());
    }
    for (int i = Ndiscos; i > 0; i--)
    {
        misTorres[0]->push(discos[i-1]);
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

        // Les doy la vuelta para que en el futuro se muestren mejor, librería algorithm. PODRÍA SOBRAR, AHORA SE MUESTRAN DEL SUPERIOR AL INFERIOR, LO COMENTO POR SI ACASO
        //std::reverse(discos.begin(), discos.end());

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

bool Juego::esMovimientoValido(const Torre &origen, const Torre &destino) const 
{
    if (origen.empty()) return false;
    if (destino.empty()) return true;
    return origen.peek()->getTamaño() < destino.peek()->getTamaño();

}

bool Juego::moverDisco(Torre& origen, Torre& destino){
    if(esMovimientoValido(origen, destino)){
        auto discOrigen = origen.pop();
        destino.push(discOrigen);
        actualizarEstado();
        movimientosCounter++;
        return true;
    }else{
        return false;
    }
}

bool Juego::juegoTerminado()const{
    return misTorres[0]->empty() && (misTorres[1]->empty() || misTorres[2]->empty());
}

estado const& Juego::getEstado() const{
    return estadoActual;
}

void Juego::reiniciar(){

    int nDiscosTotales = 0;
    for(auto torre: misTorres){
        nDiscosTotales += torre->size();
        while(!torre->empty()){
            torre->pop();
        }
    }

    vector<shared_ptr<Disco>> discos;
    for (int i = 0; i < nDiscosTotales; i++)
    {
        discos.push_back(make_shared<Disco>());
    }
    for (int i = nDiscosTotales -1; i >= 0; i--)
    {
        misTorres[0]->push(discos[i]);
    }
    // Tengo que inicializar este atributo para poder visualizar

    actualizarEstado();
}


Torre& Juego::getTorre(int id) const{
    return *misTorres[id-1];
}