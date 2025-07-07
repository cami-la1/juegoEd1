// mapa.cpp
#pragma hdrstop

#include "mapa.h"
#include <stdlib.h> // Para rand() y srand()
#include <time.h>   // Para time()

//---------------------------------------------------------------------------
#pragma package(smart_init)

Mapa::Mapa() {
    // Inicializar la semilla del generador de números aleatorios
    // para que el mapa sea diferente cada vez que se juega.
    srand(time(NULL));
}

// mapa.cpp

void Mapa::cargarMapaInicial(MatrizCC* matriz, int filas, int columnas) {
    matriz->dimensionar(filas, columnas);

    // Poner los muros en los bordes
    for (int f = 1; f <= filas; f++) {
        for (int c = 1; c <= columnas; c++) {
            if (f == 1 || f == filas || c == 1 || c == columnas) {
                matriz->poner2(f, c, 1);
            }
        }
    }

    int f_rand, c_rand;

    // Poner Jugador 1 (nuevo ID 5)
    do {
        f_rand = 2 + rand() % (filas - 2);
        c_rand = 2 + rand() % (columnas - 2);
    } while (matriz->Elemento(f_rand, c_rand) != 0);
    matriz->poner2(f_rand, c_rand, 5); // <--- CAMBIO

    // Poner Jugador 2 (nuevo ID 6)
    do {
        f_rand = 2 + rand() % (filas - 2);
        c_rand = 2 + rand() % (columnas - 2);
    } while (matriz->Elemento(f_rand, c_rand) != 0);
    matriz->poner2(f_rand, c_rand, 6); // <--- CAMBIO

    // Poner Manzana (valor 4)
    do {
        f_rand = 2 + rand() % (filas - 2);
        c_rand = 2 + rand() % (columnas - 2);
    } while (matriz->Elemento(f_rand, c_rand) != 0);
    matriz->poner2(f_rand, c_rand, 4);

    // Poner Pera (nuevo valor 3)
    do {
        f_rand = 2 + rand() % (filas - 2);
        c_rand = 2 + rand() % (columnas - 2);
    } while (matriz->Elemento(f_rand, c_rand) != 0);
    matriz->poner2(f_rand, c_rand, 3); // <--- AÑADIDO
}
