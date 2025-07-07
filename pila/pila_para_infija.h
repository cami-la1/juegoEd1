//---------------------------------------------------------------------------

#ifndef pila_para_infijaH
#define pila_para_infijaH
	#include "Umemoria.h"
//---------------------------------------------------------------------------


typedef int dirr;
//typedef float dirr;
 //typedef char dirr;

	//static const int MAX= 20;
   //	static const int NULO = -1;
class pilaMM{

	private:

	dirr pe;
	CSmemoria* Cm;
	public: 	int longitud;
pilaMM();
	pilaMM(CSmemoria* m);
	 bool Vacia();
	 void Meter(dirr e);

       // En UP_memoria.h
CSmemoria* obtenerMemoria() {
    return Cm;
}
    	const string datoNL = "elemento,sig";
	const string elementNL = "->elemento";
	const string sigNL = "->sig";
  void Sacar(dirr &e);
  dirr cima();
 void imprimir(TColor FormColor, TCanvas *Canvas);
     float EvaluarPostfija(const String& ExpPostfija);
 float Evalua(float Op1, char Operador, float Op2) ;
	  int PrioridadInfija(char c) ;
	  int PrioridadPila(char c) ;
String InfijaToPostfija2(const String& Infija,TColor FormColor, TCanvas *Canvas) ;
	float EvaluarPostfija2(const String& ExpPostfija,TColor FormColor, TCanvas *Canvas);
 bool ParentesisOk(const String& Expresion) ;
};
#endif
