//---------------------------------------------------------------------------

#pragma hdrstop

#include "UP_vectores.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
	pilav:: pilav(){
	   tope=0;
	}
	bool pilav::Vacia(){
     return (tope==0);
	}
	void pilav::Meter(int e){
	 if (tope<MAXXX) {
	   tope=tope+1;
       elementos[tope]=e;
	 }
	}
	void pilav::Sacar(int &e){
	 if (Vacia()==false) {
	  e=elementos[tope];
      tope--;
	 }
	}
	int pilav::cima(){
	 if (Vacia()==false) {
      return elementos[tope];
	 }
	}
    void pilav::imprimir(TColor FormColor, TCanvas *Canvas) {
	int TamanoCeldaX = 80;
    int TamanoCeldaY = 35;
    int posX = 800;
    int posY = 100;
    if (!Vacia()) {
        // Dibuja la cabecera de la pila
        TRect rect(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);
        Canvas->Brush->Color = FormColor;
        Canvas->FillRect(rect);
        Canvas->TextOutW(posX, posY, "Pila");
        posY += TamanoCeldaY;
        // Itera sobre los elementos de la pila y los imprime en el canvas
        for (int i = 1; i <= tope; i++) {
            TRect rect(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);
            Canvas->Brush->Color = clWhite;  // Color de fondo de las celdas
            Canvas->FillRect(rect);
            // Convierte el número a string y lo muestra
            Canvas->TextOutW(posX, posY, IntToStr(elementos[i]));
            posY += TamanoCeldaY;
        }
    } else {
        // Si la pila está vacía
        Canvas->TextOutW(posX, posY, "Pila vacía");
    }
}
