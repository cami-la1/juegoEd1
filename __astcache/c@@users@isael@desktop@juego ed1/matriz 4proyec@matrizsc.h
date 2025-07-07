﻿//---------------------------------------------------------------------------

#ifndef matrizSCH
#define matrizSCH
 #define MAX 100
//---------------------------------------------------------------------------
class MatrizSC {
public:
   int rep;
	int dimf;
	int dimc;
    // Atributos
    int Vf[MAX]; // filas
    int VC[MAX]; // Columnas
    int VD[MAX]; // elementos
    int df, dc; // Dimensión
    int repe; // es el elemento que se repetirá en la matriz
    int nt;
    MatrizSC();
    // Métodos
    void Crear();
    void dimensionar(int df, int dc);
    int dimension_fila();
    int dimension_columna();
    void poner(int f, int c, int valor);
	int Elemento(int f, int c);
    void eliminarSiIgual(int valor) ;
	void Definir_valor_repetido(int valor);
	void imprimir(TColor FormColor, TCanvas *Canvas) ;
    void desplazar() ;
};
#endif
