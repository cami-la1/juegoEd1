//---------------------------------------------------------------------------

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

bool ColaPri::sacar(int& e) {
    int intentos = 0;  // Evita bucle infinito
    while (intentos < MAXP) {
        if (!vc[colaAct].vacia()) {
            if (cant < vf[colaAct]) {
                cant++;
                vc[colaAct].Sacar(e);
                if (cant == vf[colaAct]) {
                    colaAct = (colaAct + 1) % MAXP;  // avanzar circularmente
                    cant = 0;
                }
                return true;
            }
        } else {
            colaAct = (colaAct + 1) % MAXP;
            cant = 0;
        }
        intentos++;
    }

    return false;  // si no encontró ningún elemento después de MAXP intentos
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
