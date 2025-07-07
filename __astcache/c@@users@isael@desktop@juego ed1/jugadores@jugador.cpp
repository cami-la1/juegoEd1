//---------------------------------------------------------------------------
// jugador.cpp

#pragma hdrstop

#include "jugador.h"
#include <Vcl.h>     // Necesario para los códigos de teclas como VK_UP
#include <stdlib.h>  // Necesario para rand() para la fruta

//---------------------------------------------------------------------------
#pragma package(smart_init)

// --- Constructor ---
// Guarda los punteros a las estructuras de datos y inicializa las coordenadas.
ControlJuego::ControlJuego(MatrizCC* m, ColaPri* c, pilaM* p) {
	this->mapa = m;
    this->cola_de_turnos = c;
    this->pila_undo = p;
    // Se inicializan en -1 para saber que aún no las hemos localizado.
    this->p1_fila = -1;
    this->p1_col = -1;
    this->p2_fila = -1;
    this->p2_col = -1;
}

// --- Lógica de Inicialización ---
// Escanea el mapa al inicio para encontrar las posiciones (fila, columna)
// donde fueron colocados aleatoriamente los jugadores.
// jugador.cpp
void ControlJuego::encontrarPosicionInicialJugadores() {
    if (mapa == nullptr) return;
    for (int f = 1; f <= mapa->dimension_Fila(); f++) {
        for (int c = 1; c <= mapa->dimension_columna(); c++) {
            int val = mapa->Elemento(f, c);
            if (val == 5) { // <-- CAMBIO
                p1_fila = f;
                p1_col = c;
            } else if (val == 6) { // <-- CAMBIO
                p2_fila = f;
                p2_col = c;
            }
        }
    }
}

// La función devuelve 'true' si el movimiento fue exitoso y 'false' si no lo fue.
// Recibe como parámetros el jugador que se mueve (1 o 2) y las coordenadas de la nueva casilla (nF, nC).
// Reemplazar esta función completa en jugador.cpp

bool ControlJuego::intentarMover(int jugador, int nF, int nC) {
	int destino = mapa->Elemento(nF, nC);

	if (destino == 1 || (jugador == 1 && destino == 6) || (jugador == 2 && destino == 5)) {
		return false;
	}

	int id_jugador = (jugador == 1) ? 5 : 6;
	int fila_actual = (jugador == 1) ? p1_fila : p2_fila;
	int col_actual = (jugador == 1) ? p1_col : p2_col;

	// --- GUARDADO PARA LA FUNCIÓN DESHACER (UNDO) ---
	pila_undo->Meter(id_jugador);
	pila_undo->Meter(fila_actual);
	pila_undo->Meter(col_actual);
	pila_undo->Meter(destino);

	// --- ACTUALIZACIÓN DEL MAPA ---
	mapa->poner2(fila_actual, col_actual, 0);
	mapa->eliminarSiIgual(0);
    mapa->poner2(nF, nC, id_jugador);

    // --- ACTUALIZACIÓN DE ESTADO INTERNO ---
    if (jugador == 1) {
		p1_fila = nF;
        p1_col = nC;
    } else {
        p2_fila = nF;
        p2_col = nC;
    }

    // --- LÓGICA ESPECIAL AL COMER FRUTAS ---
    if (destino == 3 || destino == 4) {
        // 1. Aumentar frecuencia
        int prioridad_del_jugador = jugador - 1;
		int aumento = (destino == 3) ? 2 : 1;
		cola_de_turnos->aumentarFrecuencia(prioridad_del_jugador, aumento);

		// 2. Generar nueva fruta
		int f_rand, c_rand;
		do {
			f_rand = 2 + rand() % (mapa->dimension_Fila() - 2);
			c_rand = 2 + rand() % (mapa->dimension_columna() - 2);
		} while (mapa->Elemento(f_rand, c_rand) != 0);
		mapa->poner2(f_rand, c_rand, destino);

		// 3. --- NUEVO: GUARDAR COORDENADAS DE FRUTA NUEVA ---
		pila_undo->Meter(f_rand);
		pila_undo->Meter(c_rand);

	} else {
		// --- NUEVO: GUARDAR MARCADORES NULOS SI NO SE COME FRUTA ---
		// Esto mantiene el tamaño de la "trama" en la pila consistente.
		pila_undo->Meter(-1); // Marcador para f_rand
		pila_undo->Meter(-1); // Marcador para c_rand
	}

    return true;
}

void ControlJuego::deshacerMovimiento() {
    if (pila_undo->Vacia()) {
        return;
    }

    // 1. Sacamos los 6 datos de la pila
    int c_fruta_nueva, f_fruta_nueva;
	int valor_viejo_destino;
    int col_original;
    int fila_original;
    int id_jugador;

    pila_undo->Sacar(c_fruta_nueva);
    pila_undo->Sacar(f_fruta_nueva);
    pila_undo->Sacar(valor_viejo_destino);
    pila_undo->Sacar(col_original);
    pila_undo->Sacar(fila_original);
    pila_undo->Sacar(id_jugador);

    // 2. Obtenemos la posición actual y número del jugador
    int fila_actual, col_actual;
    int num_jugador;
    if (id_jugador == 5) {
        num_jugador = 1;
        fila_actual = p1_fila; col_actual = p1_col;
		p1_fila = fila_original; p1_col = col_original;
	} else {
		num_jugador = 2;
		fila_actual = p2_fila; col_actual = p2_col;
		p2_fila = fila_original; p2_col = col_original;
	}

	// 3. Restauramos el mapa
	mapa->poner2(fila_original, col_original, id_jugador);
	mapa->poner2(fila_actual, col_actual, valor_viejo_destino);
	if (valor_viejo_destino == 0) {
        mapa->eliminarSiIgual(0);
    }

    // 4. --- LÓGICA CORREGIDA PARA FRUTAS ---
    if (f_fruta_nueva != -1) { // Verificamos si se generó una fruta
        // a) Revertir el aumento de frecuencia (Arreglo anterior)
        int prioridad_del_jugador = num_jugador - 1;
        int reduccion = (valor_viejo_destino == 3) ? -2 : -1;
        cola_de_turnos->aumentarFrecuencia(prioridad_del_jugador, reduccion);

        // b) Eliminar la fruta duplicada (Nuevo arreglo)
		mapa->poner2(f_fruta_nueva, c_fruta_nueva, 0); // La reemplazamos por espacio vacío
        mapa->eliminarSiIgual(0); // Limpiamos el nodo
    }
}/*



 AQUÍ VA TU MÉTODO procesarInput QUE YA TIENES
 void ControlJuego::procesarInput(WORD tecla) { ... }
*/
// jugador.cpp

void ControlJuego::procesarInput(WORD tecla) {
	// Ya no necesitamos verificar el turno, solo ejecutar la acción de la tecla.
	switch (tecla) {
		// Acciones del Jugador 1
		case 'W': intentarMover(1, p1_fila - 1, p1_col); break;
		case 'S': intentarMover(1, p1_fila + 1, p1_col); break;
		case 'A': intentarMover(1, p1_fila, p1_col - 1); break;
		case 'D': intentarMover(1, p1_fila, p1_col + 1); break;

		// Acciones del Jugador 2
		case VK_UP:    intentarMover(2, p2_fila - 1, p2_col); break;
		case VK_DOWN:  intentarMover(2, p2_fila + 1, p2_col); break;
		case VK_LEFT:  intentarMover(2, p2_fila, p2_col - 1); break;
		case VK_RIGHT: intentarMover(2, p2_fila, p2_col + 1); break;
	}
}
