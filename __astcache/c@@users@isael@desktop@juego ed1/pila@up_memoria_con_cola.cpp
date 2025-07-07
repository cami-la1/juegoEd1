#pragma hdrstop
#include "UP_memoria_con_cola.h"
#pragma package(smart_init)

pilaMC::pilaMC() {
    c = nullptr;
}

pilaMC::pilaMC(colaM* cola) {
    c = cola;
}

bool pilaMC::Vacia() {
    return c->vacia();
}

void pilaMC::Meter(int e) {
    c->MeterAlPrincipio(e);
}

void pilaMC::Sacar(int &e) {
    c->Sacar(e);
}

int pilaMC::cima() {
    return c->colaprimero();  // o c->ultimoElemento() dependiendo del comportamiento deseado
}

void pilaMC::imprimir(TColor FormColor, TCanvas *Canvas) {
    c->imprimir(FormColor, Canvas);
}

