﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "matrizCCcpp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
     // Constructor
MatrizCC::MatrizCC() {
    df = 0;
    dc = 0;
    repe = 0;
    nt = 0;
    for (int k = 0; k < MAXs; k++) {
        VF[k] = 1;
    }
}

// Métodos
void MatrizCC::dimensionar(int nf, int nc) {
	df = nf;
	dc = nc;

	dimf=df;
	 dimc=dc;
}

int MatrizCC::dimension_Fila() {
    return df;
}

int MatrizCC::dimension_columna() {
    return dc;
}
int MatrizCC::Existe_Elemento(int f, int c) {
    // Verificar si existe elemento
    int Existe_lugar = 0;
    int lug_antes = 0;
    for (int i = 1; i < f; i++) {
        lug_antes += VF[i + 1] - VF[i];
    }
    for (int z = lug_antes+1; z < VF[f + 1]; z++) {
        if (VC[z] == c) {
            // Si encontramos la columna ocupada, devolvemos la posición
            return z;
        }
    }
    // Si no encontramos la columna ocupada, devolvemos 0
    return Existe_lugar;
}
   int MatrizCC::Donde_insertar(int f, int c) {
	// Contando los lugares por fila
    int lug_antes = 0;
    for (int i = 0; i < f - 1; i++) {
        lug_antes = lug_antes + (VF[i + 1] - VF[i]);
    }

    // Contando los lugares por columna
    int nuevo_lugar = lug_antes;
    int lugar = lug_antes;
    int max_elem_fila = (VF[f + 1] - VF[f]);
    for (int i = 0; i < max_elem_fila; i++) {
        lugar = lug_antes + i;
        if (c > VC[lugar]) {
            nuevo_lugar = lugar;
		}
	}
	nuevo_lugar = nuevo_lugar + 1;

	return nuevo_lugar;
}void MatrizCC::poner(int f, int c, int valor) {
	// El siguiente algoritmo no analiza si se coloca el “0”
	int Lugar = Existe_Elemento(f, c);
	if (Lugar != 0) {
		VD[Lugar] = valor;
	} else {
		// Calcula el lugar donde insertar el nuevo elemento
		int lug_antes = 0;
		for (int i = 1; i < f; i++) {
			lug_antes += VF[i + 1] - VF[i];
		}
		int max_elem_fila = VF[f + 1] - VF[f];
		int i;
        for (i = 1; i <= max_elem_fila && VC[lug_antes + i] < c; i++);
        Lugar = lug_antes + i;

        // Desplaza los elementos para hacer espacio para el nuevo elemento
        for (i = nt; i >= Lugar; i--) {
            VD[i + 1] = VD[i];
			VC[i + 1] = VC[i];
        }

        // Inserta el nuevo elemento
        VD[Lugar] = valor;
        VC[Lugar] = c;
        nt++;

        // Ajusta los valores del vector comprimido
		for (i = f + 1; i <= df + 1; i++) {
            VF[i]++;
        }
    }
}

void MatrizCC::poner2(int f, int c, int valor) {
	// El siguiente algoritmo no analiza si se coloca el “0”
	int Lugar = Existe_Elemento(f, c);
	if (Lugar != 0) {
		VD[Lugar] = valor;
	} else {
		// Calcula el lugar donde insertar el nuevo elemento
		int lug_antes = 0;
		for (int i = 1; i < f; i++) {
			lug_antes += VF[i + 1] - VF[i];
		}
		int max_elem_fila = VF[f + 1] - VF[f];
		int i;
        for (i = 1; i <= max_elem_fila && VC[lug_antes + i] < c; i++);
        Lugar = lug_antes + i;

        // Desplaza los elementos para hacer espacio para el nuevo elemento
        for (i = nt; i >= Lugar; i--) {
            VD[i + 1] = VD[i];
			VC[i + 1] = VC[i];
        }

        // Inserta el nuevo elemento
        VD[Lugar] = valor;
        VC[Lugar] = c;
        nt++;

        // Ajusta los valores del vector comprimido
		for (i = f + 1; i <= df + 1; i++) {
            VF[i]++;
        }
    }
}

int MatrizCC::Elemento(int f, int c) {
	if (!(f >= 1 && f <= df && c >= 1 && c <= dc)) {
		std::cerr << "Error: Los índices están fuera de rango." << std::endl;
		return -1;
	}

	int lug_antes = 0;
	for (int i = 1; i < f; i++) {
		lug_antes += VF[i + 1] - VF[i];
	}

	int max_elem_fila = VF[f + 1] - VF[f];

	for (int i = 1; i <= max_elem_fila; i++) {
		if (VC[lug_antes + i] == c) {
			return VD[lug_antes + i];
		}
	}

	return repe;
}
void MatrizCC::eliminarSiIgual(int valor) {
	bool encontrado = false;
	// Buscamos y eliminamos todos los elementos que coinciden con el valor especificado
	for (int i = 1; i <= nt; i++) {
		if (VD[i] == valor) {
			encontrado = true;
			// Busca la fila correspondiente al elemento
			int fila = 1;
			while (i >= VF[fila + 1]) {
				fila++;
			}
			// Elimina el elemento
			for (int j = i; j < nt; j++) {
				VD[j] = VD[j + 1];
				VC[j] = VC[j + 1];
			}
			nt--;
			// Actualiza los valores del vector comprimido para reflejar la eliminación
            for (int j = fila; j <= df; j++) {
                VF[j + 1]--;
            }
            // Continuamos buscando más elementos que coincidan
            i--;
        }
    }
}
void MatrizCC::Definir_valor_repetido(int valor) {
	if (nt == 0) {
		repe = valor;  rep=repe;
    } else {
		for (int i = 1; i <= df; i++) {
		for (int j = 1; j <= dc; j++) {
			int val = Elemento(i, j);
			if (val==repe) {
				poner(i,j,val);
			}
		}
	}
	eliminarSiIgual(valor);
	}
	eliminarSiIgual(valor);
	repe = valor;
	rep=repe;
}
  void MatrizCC::imprimir(TColor FormColor, TCanvas *Canvas) {
    // Obtén las dimensiones del Canvas
    int canvasWidth = Canvas->ClipRect.Width();
    int canvasHeight = Canvas->ClipRect.Height();

    // Calcula el tamaño de cada celda de la matriz en el Canvas
    int cellWidth = 40;
    int cellHeight = 30;

    // Calcula el desplazamiento para centrar la matriz en el Canvas
    int offsetX = (canvasWidth - dc * cellWidth) / 2;
	int offsetY = (canvasHeight - df * cellHeight) / 2;

    // Asegúrate de que el Canvas esté limpio
    Canvas->Brush->Color = FormColor;
    Canvas->FillRect(TRect(0, 0, canvasWidth, canvasHeight));

    // Cambia el color del pincel para dibujar la matriz
    Canvas->Pen->Color = clBlack; // Solo cambia el color del lápiz, no el del pincel

    // Recorre la matriz y dibuja cada celda
	for (int i = 1; i <= df; i++) {
		for (int j = 1; j <= dc; j++) {
			// Calcula la posición de la celda
			int x = offsetX + (j - 1) * cellWidth;
			int y = offsetY + (i - 1) * cellHeight;

			// Dibuja el recuadro de la celda
			Canvas->Rectangle(x, y, x + cellWidth, y + cellHeight);

			// Dibuja el valor de la celda
			int valor = Elemento(i, j);
			Canvas->Font->Color = clBlack; // Cambia el color del texto a negro
			Canvas->TextOutW(x + cellWidth / 2, y -10+ cellHeight / 2, IntToStr(valor));
		}
	}
}
void MatrizCC::DibujarVectores(TCanvas *Canvas, int x, int y) {
    Canvas->TextOut(x, y, "VD:");
    for (int i = 1; i <= nt; i++) {
        Canvas->TextOut(x + i * 20, y, IntToStr(VD[i]));
    }
    // Dibuja el vector VC (elementos como texto)
    Canvas->TextOut(x, y + 20, "VC:");
    for (int i = 1; i <= nt; i++) {
        Canvas->TextOut(x + i * 20, y + 20, IntToStr(VC[i]));
    }
    // Dibuja el vector VF (elementos como texto)
    Canvas->TextOut(x, y + 40, "VF:");
    for (int i = 1; i <= df + 1; i++) {
        Canvas->TextOut(x + i * 20, y + 40, IntToStr(VF[i]));
    }// Supongo que VF[0] contiene la longitud del vector VF
}
