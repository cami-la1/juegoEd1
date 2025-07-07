//---------------------------------------------------------------------------

#ifndef UVListaH
#define UVListaH
//---------------------------------------------------------------------------
#include <iostream>
#include <tchar.h>
#include <string>
#include <iomanip>
#include <Graphics.hpp>
using namespace std;

class Vlista{
	private:

    static const int MAX = 100;
	static const int NULO = -1;
	typedef int Direccion;

	int elementos[MAX];

	public: 	int longitud;
	Vlista();
	int fin();
	int primero();
	int siguiente(int d);
	int anterior(int d);
	bool vacia();
	int recupera(int dirección);
	int getlongitud();
	void insertar( int dirección,int elemento);
	void inserta_primero(int elemento);
	void inserta_ultimo(int elemento);
	void suprime(int dirección);
	void modifica(int dirección,int elemento);
	void imprimir(TColor FormColor, TCanvas *Canvas);

};


#endif
