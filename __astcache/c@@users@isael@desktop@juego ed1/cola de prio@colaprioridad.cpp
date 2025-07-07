﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaPrioridad.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ColaPri::ColaPri() {
    colaAct = 0;
    cant = 0;
	for (int i = 0; i < MAXP; i++) {
        vf[i] = 1;  // Frecuencia por defecto
    }
}
bool ColaPri::vacia() {
    for (int i = 0; i < MAXP; i++) {
		if (!vc[i].vacia()) return false;
    }
    return true;
}
int ColaPri::primero() {
    for (int i = 0; i < MAXP; i++) {
        if (!vc[i].vacia()) return vc[i].primero();
    }
    return -1;
}
void ColaPri::poner(int e, int prioridad) {
    if (prioridad >= 0 && prioridad < MAXP) {
		vc[prioridad].Meter(e);
    }
}
void ColaPri::asignarFrecuenciaPrioridad(int frec, int prioridad) {
    if (prioridad >= 0 && prioridad < MAXP) {
        vf[prioridad] = frec;
    }
}
// ColaPrioridad.cpp -> Versión Mejorada de sacar()

// ColaPrioridad.cpp -> Versión Mejorada de sacar()
 void ColaPri::aumentarFrecuencia(int prioridad, int cantidad) {
	// Nos aseguramos de que la prioridad sea válida
    if (prioridad >= 0 && prioridad < MAXP) {
        vf[prioridad] += cantidad; // Incrementamos el valor en el vector de frecuencias
    }
}
bool ColaPri::sacar(int& e) {
    int intentos = 0;
    while (intentos < MAXP) {
        // CONDICIÓN PARA AVANZAR: La cola activa está vacía O ya cumplió su frecuencia.
        if (vc[colaAct].vacia() || cant >= vf[colaAct]) {
            colaAct = (colaAct + 1) % MAXP;
            cant = 0;
            intentos++;
            continue; // Intenta de nuevo con la siguiente cola.
        }

        // Si estamos aquí, la cola es válida para servir un turno.
        vc[colaAct].Sacar(e);
        cant++;
        // Si justo ahora cumplimos la frecuencia, nos preparamos para la siguiente vuelta.
        if (cant >= vf[colaAct]) {
            colaAct = (colaAct + 1) % MAXP;
            cant = 0;
        }
        return true;
    }
    return false;
}

void ColaPri::imprimir(TColor FormColor, TCanvas* Canvas) {
	int x = 600; // posición inicial en X
    int y = 100; // posición inicial en Y
    Canvas->Font->Color = clBlack;
    Canvas->Brush->Color = FormColor;

	for (int i = 0; i < MAXP; i++) {
        String linea = "Prioridad " + IntToStr(i) + ": ";

        if (vc[i].vacia()) {
            linea += "[vacía]";
        } else {
            linea += "[";
			for (int j = vc[i].ini; j <= vc[i].fin; j++) {
			linea += IntToStr(vc[i].V[j]);
				if (j < vc[i].fin) linea += ", ";
            }
            linea += "]";
        }

        linea += " | Frec: " + IntToStr(vf[i]);
        if (i == colaAct) linea += "  <-- Activa";

        Canvas->TextOutW(x, y, linea);
        y += 20; // mover abajo para la siguiente línea
    }
}

int ColaPri::verProximoTurno() {
    if (vacia()) {
        return -1; // Retorna -1 si no hay turnos en ninguna cola
    }
    // Hacemos una búsqueda temporal para no alterar el estado real de la cola
    int tempColaAct = colaAct;
    for (int i = 0; i < MAXP; i++) {
        if (!vc[tempColaAct].vacia()) {
            // Encontramos una cola con turnos, devolvemos el primero de esa cola.
            return vc[tempColaAct].primero();
        }
        // Si la cola activa temporal está vacía, pasamos a la siguiente
        tempColaAct = (tempColaAct + 1) % MAXP;
    }
    return -1; // No debería llegar aquí si vacia() es false, pero es una seguridad
}
int ColaPri::obtenerFrecuencia(int prioridad) {
    // Verificamos que la prioridad esté dentro del rango del array.
    if (prioridad >= 0 && prioridad < MAXP) {
        return vf[prioridad]; // Devolvemos el valor guardado.
    }
    // Si la prioridad no es válida, devolvemos -1 para indicar un error.
    return -1;
}
