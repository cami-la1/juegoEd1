﻿//---------------------------------------------------------------------------
       #include "Umemoria.h"
#ifndef matriz_2NH
#define matriz_2NH
//---------------------------------------------------------------------------
struct NodoF {
    int Fila;
    int SigF; // Dirección del nodo que tiene la siguiente fila
    int AntF; // Dirección de nodo que tiene la anterior Fila
    int PtrCol; // Dirección que tiene los datos de la columna y elemento
};

struct NodoC {
    int Col; // Es el valor de la columna donde está el elemento
    int Dato; // Es el valor de elemento en la matriz
    int SigCol; // Dirección del próximo elemento para otra columna
};

class MatrizDispersa2 {
private:
	// Dirección
	int rep;
	int dimf;
    int dimc;
    CSmemoria* Cm; // Enlace a la memoria

public:
	MatrizDispersa2(CSmemoria* M) ;
   int PtrFil;
	void dimensionar(int df, int dc);
	int dimension_Fila() ;

	int dimension_columna();
	void eliminarSiDiferente(int valor) ;
	void poner(int f, int c, int e) ;
	void poner2(int f, int c, int e) ;
  int buscarC2(int dirF, int c) ;
	int Elemento(int f, int c);
	  int buscarF(int f) ;
	int buscarC(int f, int c) ;
	int buscarColumna(int dirF, int c);
	int buscarFila(int f) ;
	   void Definir_valor_repetido(int valor);
	void imprimir(TColor FormColor, TCanvas *Canvas) ;
	void eliminarElemento(int fila, int columna) ;
	void eliminarElementoInverso(int fila, int columna) ;
	 void imprimir2(TCanvas *Canvas, TColor fondo, int x, int y, int a, int b);
	 void imprimirEstructura(TCanvas* Canvas, TColor fondo, int x, int y) ;
};
#endif
