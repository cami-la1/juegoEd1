	//---------------------------------------------------------------------------

	#pragma hdrstop

	#include "UP_memoria.h"
	//---------------------------------------------------------------------------
	#pragma package(smart_init)
	pilaM::pilaM() {
		 pe=-1;

	// Cm = new CSmemoria();
	}
	pilaM::pilaM(CSmemoria* m) {
	 pe=-1;
	 longitud=0;
	 Cm= m;
	}

	bool pilaM::Vacia(){
	return (longitud==0) ;
	}

	void pilaM ::Meter(dir e){
	int dir=Cm->new_espacio("elemento,sig");
	if (dir!=NULO) {
		 Cm->poner_dato(dir,elementNL ,e);
			 Cm->poner_dato(dir, sigNL ,pe) ;
		 pe=dir;

		longitud++;
	}
	}


	void pilaM::Sacar(dir& e){
		   if (Vacia()==false) {
		   int z=pe;
				e = Cm->obtenerDato(pe,elementNL) ;// Assigning the top element to e
		pe=Cm->obtenerDato(pe, sigNL); // Moving the top pointer to the next element
			Cm->Delete_espacio(z);  // Deleting the previous top element
		longitud--;
		   }

	}
	dir pilaM::cima() {
		if (Vacia()) {
			// Handle error: Stack is empty
			return -1;  // Return an error value or throw an exception
		} else {
			return Cm->obtenerDato(pe,elementNL); // Return the top element
		}
	}


	 void pilaM::imprimir(TColor FormColor, TCanvas *Canvas){
		 Cm->ImprimirPantalla2(FormColor, Canvas,1150,600);
	 }


	//--------------------------------
	//----------aplicacion1----------


	 float pilaM::Evalua(float Op1, char Operador, float Op2) {
		switch (Operador) {
			case '^': return pow(Op1, Op2);
			case '*': return Op1 * Op2;
			case '/': return Op1 / Op2;
			case '+': return Op1 + Op2;
			case '-': return Op1 - Op2;
			default:
				throw Exception("Operador desconocido");
		}
	}
	float pilaM::EvaluarPostfija(const String& ExpPostfija) {
		for (int i = 1; i <= ExpPostfija.Length(); ++i) {
			char ch = ExpPostfija[i];
			if (isdigit(ch)) { // Si es un operando
				Meter(ch - '0'); // Convertir char a int y meter en la pila
			} else { // Si es un operador
				dir Op2, Op1;
				Sacar(Op2);
				Sacar(Op1);
				float Z = Evalua(Op1, ch, Op2);
				Meter(Z);
			}
		}
		return cima(); // Resultado final de la evaluación
	}
float pilaM::EvaluarPostfija2(const String& ExpPostfija,TColor FormColor, TCanvas *Canvas) {
	String numero = "";  // Para acumular caracteres de números de varios dígitos
	for (int i = 1; i <= ExpPostfija.Length(); ++i) {
		char ch = ExpPostfija[i];
		if (isdigit(ch) || ch == '.') {  // Acumula el número (incluye punto decimal para floats)
			numero += ch;
		} else if (ch == ' ' && !numero.IsEmpty()) {  // Fin de un número
			Meter(StrToFloat(numero));  // Convertir el número a float y meter en la pila
			Cm->ImprimirPantalla(FormColor, Canvas);  // Muestra la memoria después de la inserción
			ShowMessage("Número insertado en la pila: " + numero + ". Presiona Enter para continuar...");
			numero = "";  // Reiniciar acumulador de números
		} else if (strchr("+-*/^", ch)) {  // Si es un operador
			dir Op2, Op1;
			Sacar(Op2);  // Sacar el segundo operando
			Cm->ImprimirPantalla(FormColor, Canvas);  // Muestra la memoria después de sacar el segundo operando
			ShowMessage("Sacar el segundo operando: " + UnicodeString(Op2) + ". Presiona Enter para continuar...");
			Sacar(Op1);  // Sacar el primer operando
			Cm->ImprimirPantalla(FormColor, Canvas);  // Muestra la memoria después de sacar el primer operando
			ShowMessage("Sacar el primer operando: " + UnicodeString(Op1) + ". Presiona Enter para continuar...");
			float Z = Evalua(Op1, ch, Op2);  // Realizar operación
			Meter(Z);  // Meter resultado en la pila
			Cm->ImprimirPantalla(FormColor, Canvas);  // Muestra la memoria después de meter el resultado
			ShowMessage("Resultado de la operación " + UnicodeString(ch) + ": " + UnicodeString(Z) + ". Presiona Enter para continuar...");
		}
	}
	// Obtener el resultado final en la cima de la pila
	Cm->ImprimirPantalla(clWhite, Canvas);  // Muestra la memoria con el resultado final en la cima
	ShowMessage("Resultado final en la cima de la pila. Presiona Enter para continuar...");
	return cima();
}
String pilaM::InfijaToPostfija2(const String& Infija,TColor FormColor, TCanvas *Canvas) {
	String Postfija = "";
	String numero = "";  // Acumula dígitos para números de varios dígitos
	for (int i = 1; i <= Infija.Length(); ++i) {
		char ch = Infija[i];
		if (isdigit(ch)) {  // Si es un dígito, acumulamos en numero
            numero += ch;
        } else {
			if (!numero.IsEmpty()) {  // Si tenemos un número acumulado, lo agregamos
				Postfija += numero + " ";
				Cm->ImprimirPantalla(FormColor, Canvas);  // Muestra la memoria después de agregar un número
                ShowMessage("Número agregado a la expresión postfija: " + numero + ". Presiona Enter para continuar...");
                numero = "";
            }
			if (ch == '(') {  // Si es un paréntesis izquierdo
                Meter(ch);
				Cm->ImprimirPantalla(FormColor, Canvas);  // Muestra la memoria después de insertar un paréntesis
                ShowMessage("Paréntesis izquierdo insertado en la pila: " + UnicodeString(ch) + ". Presiona Enter para continuar...");
            } else if (ch == ')') {  // Si es un paréntesis derecho
                char aux;
                while (true) {
                    Sacar(aux);
                    if (aux == '(') break;
					Postfija += aux;
				}
				Cm->ImprimirPantalla(FormColor, Canvas);  // Muestra la memoria después de procesar paréntesis derecho
                ShowMessage("Paréntesis derecho procesado en la pila. Presiona Enter para continuar...");
            } else {  // Si es un operador
                bool salir = false;
                while (!salir) {
                    if (Vacia() || PrioridadInfija(ch) > PrioridadPila(cima())) {
                        Meter(ch);
                        salir = true;
						Cm->ImprimirPantalla(FormColor, Canvas);  // Muestra la memoria después de insertar un operador
						ShowMessage("Operador insertado en la pila: " + UnicodeString(ch) + ". Presiona Enter para continuar...");
                    } else {
                        char aux;
                        Sacar(aux);
                        Postfija += aux;
						Cm->ImprimirPantalla(FormColor, Canvas);  // Muestra la memoria después de sacar un operador
						ShowMessage("Operador sacado de la pila: " + UnicodeString(aux) + ". Presiona Enter para continuar...");
                    }
                }
            }
        }
	}
    // Si queda algún número pendiente, lo agregamos
    if (!numero.IsEmpty()) {
        Postfija += numero + " ";
		Cm->ImprimirPantalla(FormColor, Canvas);  // Muestra la memoria después de agregar el número pendiente
        ShowMessage("Número agregado a la expresión postfija: " + numero + ". Presiona Enter para continuar...");
    }
	// Vaciamos la pila al final
    while (!Vacia()) {
        char aux;
        Sacar(aux);
		Postfija += aux;
		Cm->ImprimirPantalla(clWhite, Canvas);  // Muestra la memoria después de vaciar la pila
		ShowMessage("Operador sacado de la pila al vaciarla: " + UnicodeString(aux) + ". Presiona Enter para continuar...");
	}
	return Postfija;
}

int pilaM::PrioridadInfija(char c) {
	switch (c) {
		case '^': return 4;
		case '*': return 2;
		case '/': return 2;
		case '+': return 1;
		case '-': return 1;
		case '(': return 5;
		default: return 0;
	}
}
int pilaM::PrioridadPila(char c) {
	switch (c) {
		case '^': return 3;
		case '*': return 2;
		case '/': return 2;
		case '+': return 1;
		case '-': return 1;
        case '(': return 0;
		default: return 0;
	}
}
