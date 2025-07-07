﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "Matricez_ptr1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
  // Constructor
MatrizDispersaptr::MatrizDispersaptr() {
	PtrMatD = nullptr;
    dimf = 0;
    dimc = 0;
    rep = 0;
}

// Métodos
void MatrizDispersaptr::dimensionar(int nf, int nc) {
    dimf = nf;
    dimc = nc;
}

int MatrizDispersaptr::dimension_Fila() {
    return dimf;
}

int MatrizDispersaptr::dimension_columna() {
    return dimc;
}

 Nodomp* MatrizDispersaptr::buscar(int f, int c) {
	Nodomp* ptr = PtrMatD;
    while (ptr != nullptr) {
        if (ptr->Fila == f && ptr->Col == c) {
			return ptr;
        }
        ptr = ptr->Sig;
    }
    return nullptr;  // Retorna nullptr si no se encuentra el nodo
}

  void MatrizDispersaptr::poner(int f, int c, int valor) {
    // Buscar si existe f,c en los nodos
	Nodomp* dir = buscar(f, c);
    if (dir == nullptr) {
		Nodomp* x = new Nodomp;
        if (x != nullptr) {
            x->Fila = f;
            x->Col = c;
            x->dato = valor;
            x->Sig = PtrMatD;
            PtrMatD = x;

        } else {
            // Error no existe espacio memoria
            std::cerr << "Error: No hay suficiente espacio de memoria." << std::endl;
        }
    } else {
        dir->dato = valor;
        if (valor == rep) {
            // Eliminar nodo
		delete(dir);

        }
    }
}
 int MatrizDispersaptr::Elemento(int f, int c) {
    if (f >= 1 && f <= dimf && c >= 1 && c <= dimc) {
        Nodomp* dir = buscar(f, c);
        if (dir != nullptr) {
            return dir->dato;
        } else {
            return rep;
        }
    } else {
        std::cerr << "Error: Los índices están fuera de rango." << std::endl;
        return -1;
    }
}
  void MatrizDispersaptr::eliminarSiIgual(int valor) {
    Nodomp* prev = nullptr;
    Nodomp* dir = PtrMatD;
    while (dir != nullptr) {
        if (dir->dato == valor) {
            if (prev != nullptr) {
                prev->Sig = dir->Sig;
            } else {
                PtrMatD = dir->Sig;
            }
            Nodomp* temp = dir;
            dir = dir->Sig;
            delete temp;
        } else {
            prev = dir;
            dir = dir->Sig;
        }
    }
}

void MatrizDispersaptr::Definir_valor_repetido(int valor) {
  if (PtrMatD==nullptr) {
		  rep=valor    ;
  } else{
for (int i = 1; i <= dimf; i++) {
		for (int j = 1; j <= dimc; j++) {
			// Calcula la posición de la celda


			// Dibuja el valor de la celda si existe, de lo contrario dibuja el valor de 'rep'
			Nodomp* ptr = buscar(i, j);
			int z = (ptr != nullptr) ? ptr->dato : rep;
			if (z!=valor) {
				poner(i,j,z);
			}
			}
	}
     eliminarSiIgual(valor);
  rep=valor;
  }


}void MatrizDispersaptr::imprimir(TColor FormColor, TCanvas *Canvas) {
    // Obtén las dimensiones del Canvas
    int canvasWidth = Canvas->ClipRect.Width();
    int canvasHeight = Canvas->ClipRect.Height();

    // Calcula el tamaño de cada celda de la matriz en el Canvas
    int cellWidth = 40;
    int cellHeight = 30;

    // Calcula el desplazamiento para centrar la matriz en el Canvas
    int offsetX = (canvasWidth - dimc * cellWidth) / 2;
    int offsetY = (canvasHeight - dimf * cellHeight) / 2;

    // Asegúrate de que el Canvas esté limpio
    Canvas->Brush->Color = FormColor;
    Canvas->FillRect(TRect(0, 0, canvasWidth, canvasHeight));

    // Cambia el color del pincel para dibujar la matriz
    Canvas->Pen->Color = clBlack; // Solo cambia el color del lápiz, no el del pincel

    // Recorre todas las celdas de la matriz
	for (int i = 1; i <= dimf; i++) {
		for (int j = 1; j <= dimc; j++) {
			// Calcula la posición de la celda
			int x = offsetX + (j - 1) * cellWidth;
			int y = offsetY + (i - 1) * cellHeight;

			// Dibuja el recuadro de la celda
			Canvas->Rectangle(x, y, x + cellWidth, y + cellHeight);

			// Dibuja el valor de la celda si existe, de lo contrario dibuja el valor de 'rep'
			Nodomp* ptr = buscar(i, j);
			int valor = (ptr != nullptr) ? ptr->dato : rep;
			Canvas->Font->Color = clBlack; // Cambia el color del texto a negro
			Canvas->TextOutW(x + cellWidth / 2, y -10+ cellHeight / 2, IntToStr(valor));
		}
	}
}

