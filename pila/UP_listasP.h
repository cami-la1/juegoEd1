//---------------------------------------------------------------------------

#ifndef UP_listasPH
#define UP_listasPH
#include "UPlista.h"
//---------------------------------------------------------------------------
 struct Nodopi{
	int dato;
	Nodopi* sig;
};



class pilal_P {
private:
	Nodopi* ptrpi;

public:
pilal_P();

   int cant;
  bool Vacia();
  void Meter(int e);
  void Sacar(int &e);
  int cima();
 void imprimir(TColor FormColor, TCanvas *Canvas);
};
	 #endif
