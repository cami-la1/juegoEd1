//---------------------------------------------------------------------------

#ifndef UP_punteroH
#define UP_punteroH
//---------------------------------------------------------------------------

using namespace std;

//defino a direccionL como un struct
struct Nodopil {
	int dato;
	Nodopil* sig;
};

class ptr_pila{
	private:
	Nodopil* ptrp;
	 ptr_pila();
	int cant;
	Nodopil* localiza(int e);
	Nodopil* anterior(Nodopil *p);
	public:
	  int  recupera(Nodopil* d);
	void crear();
	 bool vacio();
	  Nodopil* fin();
	Nodopil* primero();
	 void Meter(int e);
  void Sacar(int &e);
  int cima();

	void imprimir(TColor FormColor, TCanvas *Canvas);
	 void Pintado(int posX, int posY, String cad, TColor color, TCanvas *Canvas);

};
#endif
