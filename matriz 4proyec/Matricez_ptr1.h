//---------------------------------------------------------------------------

#ifndef Matricez_ptr1H
#define Matricez_ptr1H
//---------------------------------------------------------------------------
// Definici�n del tipo de dato Nodo
struct Nodomp {
    int Fila;
    int Col;
    int dato;
	Nodomp* Sig;  // Puntero al siguiente Nodo
};

// Definici�n de la clase MatrizDispersa
class MatrizDispersaptr {
private:
	Nodomp* PtrMatD;  // Direcci�n a tipo Nodo
   
public:    int rep;
    int dimf;
	int dimc;
Nodomp* buscar(int f, int c) ;
	MatrizDispersaptr();  // Constructor
	void dimensionar(int df, int dc);  // Dimensionar la matriz
    int dimension_Fila();  // Obtener la dimensi�n de la fila
    int dimension_columna();  // Obtener la dimensi�n de la columna
    void poner(int f, int c, int valor);  // Poner un elemento en la matriz
    int Elemento(int f, int c);  // Obtener un elemento de la matriz
	void Definir_valor_repetido(int valor);  // Definir el valor repetido
    void eliminarSiIgual(int valor) ;
    void imprimir(TColor FormColor, TCanvas *Canvas) ;
};

#endif
