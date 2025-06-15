#include "Disco.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Definición de variables estáticas, norma de C++
int Disco::count = 0;
vector<int> Disco::tamañosUsados; // define la variable estática


Disco::Disco(){
        
        tamaño = ++count;
        tamañosUsados.push_back(tamaño);
    }

Disco::~Disco(){
        count--;
        auto it = find(tamañosUsados.begin(),tamañosUsados.end(),tamaño);

        // Verificar si se encontró
         if (it != tamañosUsados.end())
            {
                 tamañosUsados.erase(it); // Eliminar el valor
                 std::cout << "Valor " << tamaño << " eliminado. Vector actualizado:\n";                
            }
            else
            {
                 std::cout << "Valor " << tamaño<< " no encontrado en el vector.\n";   
            }
    }

int Disco::getTamaño() const{
    return tamaño;
}

Disco::Disco(int tam)
{ // En principio esto solo se prevée para cargar partidas porque si no la lógica puede romperse

    auto it = find(tamañosUsados.begin(), tamañosUsados.end(), tam);
    if(it!=tamañosUsados.end()){
        throw invalid_argument("Este tamaño ya está siendo usado actualmente"); //No olvidarse de manejar esta excepción cuando se creen los discos
    }else{
        tamaño = tam;
        tamañosUsados.push_back(tamaño);
    }

}

void Disco::print()
{
    cout << "Disco de tamaño: " << tamaño << endl;
}