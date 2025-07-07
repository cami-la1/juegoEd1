// jugador.h
#ifndef jugadorH
#define jugadorH
//---------------------------------------------------------------------------
#include "Matriz_1N.h"
#include "ColaPrioridad.h"
#include "UP_memoria.h"
 #include "matrizCCcpp.h"
class ControlJuego {
private:
    // --- ATRIBUTOS ---
	MatrizCC* mapa;
    ColaPri* cola_de_turnos;
    pilaM* pila_undo;

    int p1_fila, p1_col;
    int p2_fila, p2_col;

    // --- MÉTODOS PRIVADOS ---
    // La declaración ahora coincide con la implementación en el .cpp
    bool intentarMover(int jugador, int nueva_fila, int nueva_col); // <-- ¡CAMBIO REALIZADO AQUÍ!

public:
    // --- MÉTODOS PÚBLICOS ---
	ControlJuego(MatrizCC* m, ColaPri* c, pilaM* p);
    void encontrarPosicionInicialJugadores();
    void procesarInput(WORD tecla);
    void deshacerMovimiento();
};
//---------------------------------------------------------------------------
#endif
