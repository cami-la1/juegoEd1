//---------------------------------------------------------------------------

#ifndef UPlistaH
#define UPlistaH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <iomanip>
#include <Graphics.hpp>

struct Nodolista{
	int elemento;
	Nodolista* sig;
};
//defino a direccionL como un struct


class ptrlista{
	private:



	//	direccion   x();

	int longitud;
	public:   	Nodolista* ptrelemento;
	ptrlista();
    Nodolista* fin();
	Nodolista* primero();
	Nodolista* siguiente(Nodolista* direccion);
	Nodolista* anterior(Nodolista* direccion);
	bool vacia();
	int recupera(Nodolista* d);
	int getlongitud();
    int sumarPares();
     void elimLista();
    void insertar(Nodolista* direccion, int ele);
	void inserta_primero(int ele);
	void inserta_ultimo(int ele);
	void suprime(Nodolista* d);
	void modifica(Nodolista* d,int ele);
	void imprimir(TColor FormColor, TCanvas *Canvas);
	void imprimir2(TColor FormColor, TCanvas *Canvas,int posX,int posY);
	Nodolista* localiza(int ele);
	void eliminardato(int ele);
    void anular();
};

#endif
