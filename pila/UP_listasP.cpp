//---------------------------------------------------------------------------

#pragma hdrstop

#include "UP_listasP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
		pilal_P::pilal_P(){
	   ptrpi=NULL;
		}
bool pilal_P ::Vacia(){
return cant==0;
}void pilal_P ::Meter(int e){
Nodopi* dir=new Nodopi;
if (dir!=NULL) {
	 dir->dato=e;
	 dir->sig=ptrpi;
	 ptrpi=dir;
	 cant++;
}
}
void pilal_P::Sacar(int &e){
       Nodopi* temp = ptrpi;
        e = temp->dato;  // Assigning the top element to e
        ptrpi = temp->sig;  // Moving the top pointer to the next element
        delete temp;  // Deleting the previous top element
        cant--;
}
int pilal_P::cima() {
    if (Vacia()) {
        // Handle error: Stack is empty
        return -1;  // Return an error value or throw an exception
    } else {
        return ptrpi->dato;  // Return the top element
    }
}

void Pintado(int posX, int posY, String cad, TColor color, TCanvas *Canvas){
int TamanoCelda = 35;
int TamanoCeldaX = 80;
int TamanoCeldaY = 35;
	//           x1  y1    x2                   y2
	TRect rect(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->Brush->Color = color;
	Canvas->FillRect(rect);

	Canvas->TextOutW(posX,posY+3,cad);

}
void pilal_P::imprimir(TColor FormColor, TCanvas *Canvas){
int TamanoCelda = 35;
int TamanoCeldaX = 80;
int TamanoCeldaY = 35;

int	posX = 1150;
int	posY = 800;
int auxX = posX;
int auxY = posY;

	if (!Vacia()) {

			//DIBUJAMOS CABECERA
			Pintado(posX,posY,"Lista",FormColor,Canvas);
			posX= auxX;
			posY+= TamanoCeldaY;

			Nodopi* x = ptrpi;
			Pintado(posX,posY,"< ",FormColor,Canvas);
			posX+=40;
			while (x != nullptr){
			Pintado(posX,posY,IntToStr(x->dato),FormColor,Canvas);
			posX+=80;
			x = x->sig;
				if (x != nullptr) {
				Pintado(posX,posY,",",FormColor,Canvas);
				posX+=40;
				}

			}
			Pintado(posX,posY,">",FormColor,Canvas);
			posX+=40;
	}else{
    Pintado(posX,posY,"Lista Vacia",FormColor,Canvas);
			posX= auxX;
			posY+= TamanoCeldaY;
	}

}
