#include <iostream>
#include <vector>
#include "Torre.h"


using namespace std;

//CREACION DE ALIAS ****************************************************************************************
using torres = array<shared_ptr<Torre>, 3>; //OJO Me he dado cuenta que typedef no deja plantillas, hay que usar using
using estado = array<vector<int>,3>; //Vector de N filas y 3 columnas, que representan las torres
//ESTRUCTURAS***********************************************************************************************


class Juego {

    private:
    torres misTorres;
    int numDiscos;
    int movimientosCounter = 0;
    estado estadoActual;

    public:
    Juego(int);
    Juego(); // Inicializa 3 discos (Juego clasico)
    ~Juego();
    bool moverDisco(Torre&, Torre&);
    bool esMovimientoValido(Torre const&, Torre const&) const;
    bool juegoTerminado() const;
    void imprimirEstado() const;
    void actualizarEstado();
    int getNMovimientos(){return movimientosCounter;}

    //Métodos auxiliares para funcionalidades especiales
    Torre& getTorre(int index) const;
    void reiniciar();

    //Metodo de prevision para Raylib
    estado const& getEstado()const;

};