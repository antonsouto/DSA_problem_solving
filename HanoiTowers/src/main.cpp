#include <iostream>
#include <unistd.h>
#include "Juego.h"

using namespace std;

int main()
{
    int ndiscos = 0;

    cout << "Ingrese el número de discos con los que quiere jugar a las Torres de Hanoi: ";
    cin >> ndiscos;

    Juego mijuego(ndiscos);

    cout << "[DEBUG] Juego creado correctamente con " << ndiscos << " discos." << endl;

    while (!mijuego.juegoTerminado())
    {
        int id_origen = 0, id_destino = 0;

        cout << "\nNúmero de movimientos actualmente hechos: " << mijuego.getNMovimientos() << endl;
        mijuego.imprimirEstado();

        // Selección de torres
        while (true)
        {
            cout << "Escoja la torre de origen (1,2,3): ";
            cin >> id_origen;

            cout << "Escoja la torre de destino (1,2,3): ";
            cin >> id_destino;

            if (id_origen == id_destino)
            {
                cout << "Las torres deben ser distintas. Intenta de nuevo.\n";
                continue;
            }

            if (id_origen < 1 || id_origen > 3 || id_destino < 1 || id_destino > 3)
            {
                cout << "Índice fuera de rango. Intenta de nuevo.\n";
                continue;
            }

            break;
        }

        Torre &origen = mijuego.getTorre(id_origen);
        Torre &destino = mijuego.getTorre(id_destino);

        // Movimiento
        if (!mijuego.moverDisco(origen, destino))
        {
            cout << "Movimiento inválido. Recuerda que no puedes colocar un disco grande sobre uno pequeño.\n";
            sleep(2); // Espera de 2 segundos
        }

        // Limpieza visual entre turnos
        system("clear"); // Descomenta en Unix si deseas limpiar la pantalla entre turnos
    }

    // Mensaje de victoria
    cout << "\n¡Enhorabuena! Has resuelto el juego en " << mijuego.getNMovimientos() << " movimientos." << endl;

    return 0;
}
