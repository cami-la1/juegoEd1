﻿//---------------------------------------------------------------------------

#ifndef matrizCCcppH
#define matrizCCcppH
 #define MAXs 1000
//---------------------------------------------------------------------------
class MatrizCC {
private:
	int VF[MAXs]; // filas
	int VC[MAXs]; // columnas
	int VD[MAXs]; // elementos
    int df; // dimensión fila
    int dc; // dimensión columna
    int repe; // elemento repetido
	//int nt; // número de términos

    int Existe_Elemento(int f, int c); // busca en vd,vc y vf si existe el elemento
    int Donde_insertar(int f, int c); // determina donde insertar en vd,vc y vf

public:
 int rep;
	int dimf;
	int dimc;
int nt;
    MatrizCC(); // constructor
	void dimensionar(int df, int dc); // dimensionar la matriz
	int dimension_Fila(); // obtener la dimensión de la fila
	int dimension_columna(); // obtener la dimensión de la columna
	void eliminarSiIgual(int valor) ;
	void poner(int f, int c, int valor);	void poner2(int f, int c, int valor); // poner un elemento en la matriz
    int Elemento(int f, int c); // obtener un elemento de la matriz
	void Definir_valor_repetido(int valor); // definir el valor repetido
		void imprimir(TColor FormColor, TCanvas *Canvas) ;
        void DibujarVectores(TCanvas *Canvas, int x, int y);
};

#endif
