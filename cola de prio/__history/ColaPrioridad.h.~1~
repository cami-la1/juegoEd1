//---------------------------------------------------------------------------

#ifndef ColaPrioridadH
#define ColaPrioridadH
//---------------------------------------------------------------------------
#include "UC_vectores.h" // Suponiendo que ColaV es una clase Cola con vector normal

const int MAXP = 10;

class ColaPri {
private:
	colaV1 vc[MAXP]; // Arreglo de colas por prioridad
	int vf[MAXP];   // Frecuencia máxima por prioridad
    int colaAct;             // Prioridad actualmente activa
    int cant;                // Cantidad actual servida de la prioridad activa

public:
    ColaPri();
    bool vacia();
    int primero();
    void poner(int elemento, int prioridad);
    void asignarFrecuenciaPrioridad(int frec, int prioridad);
	bool sacar(int &elemento);
	void imprimir(TColor FormColor, TCanvas* Canvas) ;
};

#endif
