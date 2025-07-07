//---------------------------------------------------------------------------

#pragma hdrstop

#include "UP_listas.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
		pilal::pilal(){
		//CSmemoria* M =new CSmemoria();;
			ls= new Lista();
//ls= new Vlista();
 // ptrlista* ls =new ptrlista();
		}
			pilal::pilal(CSmemoria* M){

	  //	ls= new Lista(M); //ver el constructor de la clase lista a usar

			}
bool pilal::Vacia(){
return ls->vacia();
}void pilal::Meter(int e){
ls->insertar(ls->primero(),e);
}
void pilal::Sacar(int &e){
ls->recupera(ls->primero());
ls->suprime(ls->primero() );

}
int pilal::cima(){

return ls->recupera(ls->primero());

}
 void pilal::imprimir(TColor FormColor, TCanvas *Canvas){

 ls->imprimir2(FormColor,Canvas,1150,800)   ;
 }
