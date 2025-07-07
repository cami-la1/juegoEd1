//---------------------------------------------------------------------------

#ifndef UP_punteroH
#define UP_punteroH
//---------------------------------------------------------------------------

using namespace std;

//defino a direccionL como un struct
struct Nodop {
	int dato;
	Nodop* sig;
};

class ptr_pila{
	private:
	Nodop* ptrp;
	 ptr_pila();
	int cant;
	Nodop* localiza(int e);
	Nodop* anterior(Nodop *p);
	public:
      int  recupera(Nodop* d);
	void crear();
	 bool vacio();
	  Nodop* fin();
	Nodop* primero();
	 void Meter(int e);
  void Sacar(int &e);
  int cima();

	void imprimir(TColor FormColor, TCanvas *Canvas);
	 void Pintado(int posX, int posY, String cad, TColor color, TCanvas *Canvas);

};
#endif
