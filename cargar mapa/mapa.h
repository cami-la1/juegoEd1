//---------------------------------------------------------------------------

#ifndef mapaH
#define mapaH
//---------------------------------------------------------------------------
 #include "matrizCCcpp.h"
#include "Matriz_1N.h"// La clase Mapa necesita saber qu� es una MatrizDispersa
class Mapa {
public:
    // Constructor (no necesita hacer nada)
    Mapa();
    // M�todo principal para configurar el tablero
	void cargarMapaInicial(MatrizCC* matriz, int filas, int columnas);
};
//---------------------------------------------------------------------------

#endif
