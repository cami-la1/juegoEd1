//---------------------------------------------------------------------------


  #include "UCSLista.h"

#ifndef UP_listasH
#define UP_listasH
	#include "Umemoria.h"
    #include "UPlista.h"
//---------------------------------------------------------------------------

class pilal {
private:
// Lista* ls;
    ptrlista* ls;
//Vlista* ls;

public:
	pilal();
   pilal(CSmemoria* M);

  bool Vacia();
  void Meter(int e);
  void Sacar(int &e);
  int cima();
 void imprimir(TColor FormColor, TCanvas *Canvas);
};
	 #endif
