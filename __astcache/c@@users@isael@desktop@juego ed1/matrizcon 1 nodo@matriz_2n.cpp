//---------------------------------------------------------------------------

#pragma hdrstop
#include <vector>

#include "matriz_2N.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
	 MatrizDispersa2::MatrizDispersa2(CSmemoria* M) {
		Cm = M;
		PtrFil = NULO;
		dimf = 0;
		dimc = 0;
		rep = 0;
	}
		void MatrizDispersa2::dimensionar(int df, int dc) {
		dimf = df;
		dimc = dc;
	}

	int MatrizDispersa2:: dimension_Fila() {
		return dimf;
	}

	int MatrizDispersa2::dimension_columna() {
		return dimc;
	}

   int MatrizDispersa2::buscarF(int f) {
  int x = PtrFil;
    while (x != NULO) {
        if (Cm->obtenerDato(x, "->fila") == f) {
            return x;
        }
		x = Cm->obtenerDato(x, "->sigF");
	}
    return NULO; // Retorna NULO si no encuentra el nodo
}/*
 void MatrizDispersa2::Definir_valor_repetido(int valor){
	rep=valor;
}  */
void MatrizDispersa2::eliminarSiDiferente(int valor) {
    int dirF = PtrFil;
	int prevF = NULO;
	while (dirF != NULO) {
		int dirC = Cm->obtenerDato(dirF, "->ptrCol");
		int prevC = NULO;
		while (dirC != NULO) {
			if (Cm->obtenerDato(dirC, "->dato") == valor) {
                // Si el valor en la posición actual es diferente al valor de entrada
				int temp = Cm->obtenerDato(dirC, "->sigCol");
				if (prevC != NULO) {
                    // Actualizar el enlace del nodo anterior
					Cm->poner_dato(prevC, "->sigCol", temp);
				} else {
                    // Si el nodo eliminado era el primero de la fila, actualizar el enlace de la fila
					Cm->poner_dato(dirF, "->ptrCol", temp);
                }
				// Eliminar el nodo actual de la memoria
				Cm->Delete_espacio(dirC);
                // Continuar con el siguiente nodo
                dirC = temp;
            } else {
				prevC = dirC;
				dirC = Cm->obtenerDato(dirC, "->sigCol");
            }
        }
        // Si el último nodo de la fila ha sido eliminado, establecer el enlace de la fila en -1
		if (Cm->obtenerDato(dirF, "->ptrCol") == NULO) {
			if (prevF != NULO) {
                // Actualizar el enlace de la fila anterior
				Cm->poner_dato(prevF, "->sigF", Cm->obtenerDato(dirF, "->sigF"));
            } else {
                // Si la fila eliminada era la primera fila, actualizar el enlace de la matriz
				PtrFil = Cm->obtenerDato(dirF, "->sigF");
            }
            // Eliminar la fila actual de la memoria
            Cm->Delete_espacio(dirF);
            dirF = PtrFil; // Reiniciar la búsqueda desde el principio
        } else {
			prevF = dirF;
			dirF = Cm->obtenerDato(dirF, "->antF");
        }
    }
}

void MatrizDispersa2::Definir_valor_repetido(int valor){
 if (Cm->Espacio_ocupado()==0) {
	  rep=valor   ;
 }  else{


	// Recorrer todas las filas y columnas
	for (int i = 1; i <= dimf; i++) {
		for (int j = 1; j <= dimc; j++) {
			// Si el valor en la posición actual es diferente al nuevo valor repetido
			if (Elemento(i, j) ==rep) {
				// Guardar el valor en la memoria
				poner2(i, j, Elemento(i, j));
			}
		}
	}
		  eliminarSiDiferente(valor);
	rep = valor;}
}




 int MatrizDispersa2::buscarFila(int f) {
	int x = PtrFil;
	while (x != NULO) {
		if (Cm->obtenerDato(x, "->fila") == f) {
			return x;
		}
		x = Cm->obtenerDato(x, "->antF");
	}
	return NULO; // Retorna NULO si no encuentra el nodo
}
int MatrizDispersa2::buscarC(int f, int c) {

	// Primero obtenemos la dirección de la fila
	int dirF = buscarF(f);
	if (dirF != NULO) {
		// Si la fila existe, buscamos la columna
        int x = Cm->obtenerDato(dirF, "->ptrCol");
        while (x != NULO) {
            if (Cm->obtenerDato(x, "->col") == c) {
                return x;
            }
			x = Cm->obtenerDato(x, "->sigCol");
        }
    }
	return NULO; // Retorna NULO si no encuentra el nodo

// Retorna NULO si no encuentra el nodo
}
//void MatrizDispersa2::poner(int f, int c, int valor) {
// static int lastF = NULO;
//    // Buscar la fila
//	int dirF = buscarFila(f);
//    if (dirF == NULO) {
//        // Si la fila no existe, crear un nuevo nodo para la fila
//        dirF = Cm->new_espacio("fila,sigF,antF,ptrCol");
//        Cm->poner_dato(dirF, "->fila", f);
//		Cm->poner_dato(dirF, "->sigF", PtrFil);
//		  Cm->poner_dato(dirF, "->ptrCol", NULO);
//		   Cm->poner_dato(dirF, "->antF", lastF);
//		PtrFil = dirF;
//		   lastF = dirF; // Actualizar el puntero a la primera fila
//	}
//
//    // Buscar la columna en la fila
//	int dirC = buscarColumna(dirF, c);
//	if (dirC == NULO) {
//        // Si la columna no existe, crear un nuevo nodo para la columna
//        dirC = Cm->new_espacio("col,dato,sigCol");
//		Cm->poner_dato(dirC, "->col", c);
//          Cm->poner_dato(dirC, "->sigCol", NULO);
//        // Enlazar el nuevo nodo de columna en la lista de nodos de columna para esta fila
//		int x = Cm->obtenerDato(dirF, "->ptrCol");
//        if (x != NULO) {
//            Cm->poner_dato(dirC, "->sigCol", x);
//        }
//        Cm->poner_dato(dirF, "->ptrCol", dirC);
//    }
//
//    // Almacenar el valor en el nodo de la columna
//	Cm->poner_dato(dirC, "->dato", valor);
//}
void MatrizDispersa2::poner2(int f, int c, int valor) {
	// Buscar la fila


	int dirF = buscarFila(f);
	if (dirF == NULO) {
		// Si la fila no existe, crear un nuevo nodo para la fila
		dirF = Cm->new_espacio("fila,sigF,antF,ptrCol");
		Cm->poner_dato(dirF, "->fila", f);
		Cm->poner_dato(dirF, "->sigF", NULO);
		Cm->poner_dato(dirF, "->ptrCol", NULO);
		if (PtrFil != NULO) {
			Cm->poner_dato(PtrFil, "->sigF", dirF);
		}
		Cm->poner_dato(dirF, "->antF", PtrFil);
		PtrFil = dirF;
	}
	// Buscar la columna en la fila
	int dirC = buscarColumna(dirF, c);
    if (dirC == NULO) {
        // Si la columna no existe, crear un nuevo nodo para la columna
        dirC = Cm->new_espacio("col,dato,sigCol");
        Cm->poner_dato(dirC, "->col", c);
		Cm->poner_dato(dirC, "->sigCol", NULO);
        // Enlazar el nuevo nodo de columna en la lista de nodos de columna para esta fila
        int x = Cm->obtenerDato(dirF, "->ptrCol");
        if (x != NULO) {
            Cm->poner_dato(dirC, "->sigCol", x);
		}
        Cm->poner_dato(dirF, "->ptrCol", dirC);
    }
    // Almacenar el valor en el nodo de la columna
	Cm->poner_dato(dirC, "->dato", valor);
}


void MatrizDispersa2::poner(int f, int c, int valor) {
	// Buscar la fila


	int dirF = buscarFila(f);
	if (dirF == NULO) {
		// Si la fila no existe, crear un nuevo nodo para la fila
		dirF = Cm->new_espacio("fila,sigF,antF,ptrCol");
		Cm->poner_dato(dirF, "->fila", f);
		Cm->poner_dato(dirF, "->sigF", NULO);
		Cm->poner_dato(dirF, "->ptrCol", NULO);
		if (PtrFil != NULO) {
			Cm->poner_dato(PtrFil, "->sigF", dirF);
		}
		Cm->poner_dato(dirF, "->antF", PtrFil);
		PtrFil = dirF;
	}
	// Buscar la columna en la fila
	int dirC = buscarColumna(dirF, c);
    if (dirC == NULO) {
        // Si la columna no existe, crear un nuevo nodo para la columna
        dirC = Cm->new_espacio("col,dato,sigCol");
		Cm->poner_dato(dirC, "->col", c);
		Cm->poner_dato(dirC, "->sigCol", NULO);
		// Enlazar el nuevo nodo de columna en la lista de nodos de columna para esta fila
        int x = Cm->obtenerDato(dirF, "->ptrCol");
        if (x != NULO) {
            Cm->poner_dato(dirC, "->sigCol", x);
		}
        Cm->poner_dato(dirF, "->ptrCol", dirC);
    }
	// Almacenar el valor en el nodo de la columna
	Cm->poner_dato(dirC, "->dato", valor);

 eliminarSiDiferente(rep);
	}






 int MatrizDispersa2::buscarC2(int dirF, int c) {
	if (dirF != NULO) {
		int x = Cm->obtenerDato(dirF, "->PtrCol");
		while (x != NULO) {
			if (Cm->obtenerDato(x, "->Col") == c) {
				return x;
			}
			x = Cm->obtenerDato(x, "->SigCol");
		}
	}
	return NULO; // Retorna NULO si no encuentra el nodo
}
int MatrizDispersa2::buscarColumna(int dirF, int c) {
    if (dirF != NULO) {
		int x = Cm->obtenerDato(dirF, "->ptrCol");
        while (x != NULO) {
            if (Cm->obtenerDato(x, "->col") == c) {
                return x;
            }
            int next = Cm->obtenerDato(x, "->sigCol");
            if (next == x) {  // Evitar bucles infinitos
                break;
            }
            x = next;
		}
    }
    return NULO;  // Retorna NULO si no encuentra el nodo
}


int MatrizDispersa2::Elemento(int f, int c) {
    // Buscar el nodo correspondiente a la fila y columna
int dirF = buscarFila(f);
    if (dirF == NULO) {
		// Si la fila no existe, devolver el valor de rep
        return rep;
    }

	int dirC = buscarColumna(dirF, c);
    if (dirC == NULO) {
        // Si la columna no existe, devolver el valor de rep
        return rep;
    }

	// Si el nodo existe, devolver su valor
	return Cm->obtenerDato(dirC, "->dato");
}





void MatrizDispersa2::imprimir(TColor FormColor, TCanvas *Canvas) {
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
   // Canvas->Brush->Color = FormColor;
   // Canvas->FillRect(TRect(0, 0, canvasWidth, canvasHeight));

	// Cambia el color del pincel para dibujar la matriz
	Canvas->Pen->Color = clBlack; // Solo cambia el color del lápiz, no el del pincel

	// Recorre la matriz y dibuja cada celda
	for (int i = 1; i <= dimf; i++) {
		for (int j = 1; j <= dimc; j++) {
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


void MatrizDispersa2::eliminarElemento(int fila, int columna) {
    int dirF = buscarFila(fila); // Buscar la fila especificada
    if (dirF == NULO) {
        return; // La fila no existe, no hay nada que eliminar
    }

    int dirC = Cm->obtenerDato(dirF, "->ptrCol");
    int prevC = NULO;

    // Buscar la columna especificada dentro de la fila
    while (dirC != NULO) {
        if (Cm->obtenerDato(dirC, "->col") == columna) {
            // Nodo encontrado, eliminarlo de la memoria y actualizar enlaces

            int temp = Cm->obtenerDato(dirC, "->sigCol"); // Obtener el siguiente nodo de la columna

            if (prevC != NULO) {
                // Actualizar el enlace del nodo anterior de la columna
                Cm->poner_dato(prevC, "->sigCol", temp);
            } else {
                // Si el nodo eliminado era el primero de la fila, actualizar el puntero de la fila
                Cm->poner_dato(dirF, "->ptrCol", temp);
            }

            // Eliminar el nodo de la columna de la memoria
            Cm->Delete_espacio(dirC);

            // Verificar si la fila queda vacía y eliminarla si es necesario
            if (Cm->obtenerDato(dirF, "->ptrCol") == NULO) {
                int prevF = NULO;
                int currentF = PtrFil;

                // Buscar el nodo de fila y su anterior
                while (currentF != dirF) {
                    prevF = currentF;
                    currentF = Cm->obtenerDato(currentF, "->sigF");
                }

                if (prevF != NULO) {
                    // Actualizar el enlace del nodo de fila anterior
                    Cm->poner_dato(prevF, "->sigF", Cm->obtenerDato(dirF, "->sigF"));
                } else {
                    // Si la fila eliminada es la primera, actualizar el puntero principal de la matriz
                    PtrFil = Cm->obtenerDato(dirF, "->sigF");
                }

                // Eliminar el nodo de la fila de la memoria
                Cm->Delete_espacio(dirF);
            }
            return; // Salir después de eliminar el nodo especificado
        } else {
            // Avanzar en la lista de columnas
            prevC = dirC;
            dirC = Cm->obtenerDato(dirC, "->sigCol");
        }
    }
}


void MatrizDispersa2::eliminarElementoInverso(int fila, int columna) {
	int dirF = buscarFila(fila); // Encontrar la fila específica
	if (dirF == NULO) {
		return; // La fila no existe, no hay nada que eliminar
	}

	int dirC = Cm->obtenerDato(dirF, "->ptrCol");
	int prevC = NULO;

	// Buscar la columna específica de derecha a izquierda (moviéndose en el sentido inverso)
	while (dirC != NULO) {
		if (Cm->obtenerDato(dirC, "->col") == columna) {
            // Nodo encontrado, eliminarlo y actualizar los enlaces

            int temp = Cm->obtenerDato(dirC, "->sigCol"); // Siguiente nodo en la columna

            if (prevC != NULO) {
                // Actualizar el enlace del nodo anterior en la columna
				Cm->poner_dato(prevC, "->sigCol", temp);
            } else {
                // Si el nodo es el primero en la fila, actualizar el puntero de columna en la fila
                Cm->poner_dato(dirF, "->ptrCol", temp);
            }

            // Eliminar el nodo de la columna de la memoria
            Cm->Delete_espacio(dirC);

			// Verificar si la fila queda vacía y, si es así, eliminarla
            if (Cm->obtenerDato(dirF, "->ptrCol") == NULO) {
                int nextF = Cm->obtenerDato(dirF, "->sigF");
                int prevF = Cm->obtenerDato(dirF, "->antF");

                if (prevF != NULO) {
                    // Si hay un nodo de fila anterior, actualizar su enlace siguiente
                    Cm->poner_dato(prevF, "->sigF", nextF);
                } else {
					// Si la fila eliminada es la primera, actualizar el puntero principal de la matriz
                    PtrFil = nextF;
                }

                if (nextF != NULO) {
                    // Si hay un nodo de fila siguiente, actualizar su enlace anterior
                    Cm->poner_dato(nextF, "->antF", prevF);
                }

				// Eliminar el nodo de la fila de la memoria
                Cm->Delete_espacio(dirF);
            }
            return; // Salir después de eliminar el nodo especificado
        } else {
            // Avanzar en la lista de columnas en sentido inverso
            prevC = dirC;
            dirC = Cm->obtenerDato(dirC, "->sigCol");
        }
	}
}



  void MatrizDispersa2::imprimir2(TCanvas *Canvas, TColor fondo, int x, int y, int a, int b)
{
	// Validar que x <= a y y <= b
	if (x > a || y > b) {
		ShowMessage("Error: La fila/columna inicial debe ser menor o igual a la final.");
		return;
	}



	int filas = a - x + 1;
	int columnas = b - y + 1;

	// Coordenadas absolutas internas (fijas)
	int posX = 700;
	int posY = 300;

	// Área de dibujo
	int anchoTotal = 300;
	int altoTotal = 300;

	// Tamaño de cada celda
	int anchoCelda = anchoTotal / columnas;
	int altoCelda = altoTotal / filas;

	// Guardar configuración original del canvas
	TFont *oldFont = new TFont();
	oldFont->Assign(Canvas->Font);

	// Ajustar fuente base
	int fontSize = altoCelda - 4;
	if (fontSize > anchoCelda - 4)
		fontSize = anchoCelda - 4;
	if (fontSize < 6)
		fontSize = 6;

	Canvas->Font->Size = fontSize;
	Canvas->Brush->Color = fondo;
	Canvas->Brush->Style = bsSolid;

	// Dibujar celdas
	for (int f = x; f <= a; ++f) {
		for (int c = y; c <= b; ++c) {
			int valor = Elemento(f, c);

			// Coordenadas absolutas de la celda
			int filaIdx = f - x;
			int colIdx = c - y;

			int x1 = posX + colIdx * anchoCelda;
			int y1 = posY + filaIdx * altoCelda;
			int x2 = x1 + anchoCelda;
			int y2 = y1 + altoCelda;

			// Fondo
			Canvas->FillRect(TRect(x1, y1, x2, y2));

			// Borde
			Canvas->Pen->Color = clBlack;
			Canvas->Rectangle(x1, y1, x2, y2);

			// Texto centrado
			UnicodeString texto = IntToStr(valor);
			TSize sizeTexto = Canvas->TextExtent(texto);

			while ((sizeTexto.cx > anchoCelda - 4 || sizeTexto.cy > altoCelda - 4) && Canvas->Font->Size > 6) {
				Canvas->Font->Size--;
				sizeTexto = Canvas->TextExtent(texto);
			}

			int textX = x1 + (anchoCelda - sizeTexto.cx) / 2;
			int textY = y1 + (altoCelda - sizeTexto.cy) / 2;

			Canvas->TextOut(textX, textY, texto);

			// Restaurar fuente base
			Canvas->Font->Size = fontSize;
		}
	}

	Canvas->Font->Assign(oldFont);
	delete oldFont;
}










	/*

void MatrizDispersa2::imprimir2(TCanvas *Canvas, TColor fondo, int x, int y, int a, int b)
{
    int filas = dimension_Fila();
    int columnas = dimension_columna();

    // Ancho total y alto total
    int anchoTotal = a - x;
	int altoTotal = b - y;

    // Calcular tamaño de cada celda
    int anchoCelda = anchoTotal / columnas;
    int altoCelda = altoTotal / filas;

    // Guardar configuración original del canvas
    TFont *oldFont = new TFont();
    oldFont->Assign(Canvas->Font);

	// Ajustar tamaño de fuente inicial (que quepa en celda rectangular)
    int fontSize = altoCelda - 4;
    if (fontSize > anchoCelda - 4)
        fontSize = anchoCelda - 4;
    if (fontSize < 6)
        fontSize = 6;

    Canvas->Font->Size = fontSize;

	Canvas->Brush->Color = fondo;
    Canvas->Brush->Style = bsSolid;

    // Dibujar celdas
    for (int f = 0; f < filas; ++f)
    {
        for (int c = 0; c < columnas; ++c)
        {
            int valor = Elemento(f, c);

            // Coordenadas de la celda
			int x1 = x + c * anchoCelda;
            int y1 = y + f * altoCelda;
            int x2 = x1 + anchoCelda;
            int y2 = y1 + altoCelda;

            // Dibujar fondo de celda
            Canvas->FillRect(TRect(x1, y1, x2, y2));

            // Dibujar borde de celda
            Canvas->Pen->Color = clBlack;
            Canvas->Rectangle(x1, y1, x2, y2);

            // Ajustar fuente para cada texto
            UnicodeString texto = IntToStr(valor);
            TSize sizeTexto = Canvas->TextExtent(texto);

            // Si no cabe, reducir tamaño de fuente solo para este texto
            while ((sizeTexto.cx > anchoCelda - 4 || sizeTexto.cy > altoCelda - 4) && Canvas->Font->Size > 6)
            {
                Canvas->Font->Size--;
                sizeTexto = Canvas->TextExtent(texto);
            }

            // Dibujar texto centrado
            int textX = x1 + (anchoCelda - sizeTexto.cx) / 2;
            int textY = y1 + (altoCelda - sizeTexto.cy) / 2;

			Canvas->TextOut(textX, textY, texto);

			// Restaurar tamaño de fuente base para siguiente celda
			Canvas->Font->Size = fontSize;
		}
	}

	// Restaurar la fuente original
	Canvas->Font->Assign(oldFont);
	delete oldFont;
}
   */
void MatrizDispersa2::imprimirEstructura(TCanvas* Canvas, TColor fondo, int x, int y) {
	const int anchoCelda = 90;
	const int altoCelda = 45;
	const int espacioX = 130;
	const int espacioY = 80;

	Canvas->Font->Size = 7;

	int dirF = PtrFil;
	int fila = 0;

	while (dirF != NULO) {
		int filaY = y + fila * espacioY;

		// --- Nodo Fila ---
		Canvas->Brush->Color = clWhite;
		TRect rectFila(x, filaY, x + anchoCelda, filaY+10 + altoCelda);
		Canvas->Rectangle(rectFila);

		int numFila = Cm->obtenerDato(dirF, "->fila");
		int ptrCol = Cm->obtenerDato(dirF, "->ptrCol");

		Canvas->TextOutW(x + 3, filaY + 3, "F: " + IntToStr(numFila));
		Canvas->TextOutW(x + 3, filaY + 15, "ptrCol: " + IntToStr(ptrCol));
		Canvas->TextOutW(x + 3, filaY + 35, "sigF ↓");

		// Flecha al nodo anterior (antF visual abajo)
		int antF = Cm->obtenerDato(dirF, "->antF");
		if (antF != NULO) {
			int fx = x + anchoCelda / 2;
			int fy1 = filaY + altoCelda;
			int fy2 = fy1 + (espacioY - altoCelda);
			Canvas->MoveTo(fx, fy1);
			Canvas->LineTo(fx, fy2);
			Canvas->Ellipse(fx - 2, fy2 - 2, fx + 2, fy2 + 2); // punta
		}

		// --- Nodos columna ---
		int dirC = ptrCol;
		int col = 0;

		while (dirC != NULO) {
			int colX = x + (col + 1) * espacioX;

			TRect rectCol(colX, filaY, colX + anchoCelda, filaY + altoCelda);
			Canvas->Brush->Color = clYellow;
			Canvas->Rectangle(rectCol);

			int numCol = Cm->obtenerDato(dirC, "->col");
			int dato = Cm->obtenerDato(dirC, "->dato");
			int sigCol = Cm->obtenerDato(dirC, "->sigCol");

			Canvas->TextOutW(colX + 3, filaY + 3, "C: " + IntToStr(numCol));
			Canvas->TextOutW(colX + 3, filaY + 15, "D: " + IntToStr(dato));
			Canvas->TextOutW(colX + 3, filaY + 27, "sig →");

			// Flecha a sigCol (derecha)
			if (sigCol != NULO) {
				int cy = filaY + altoCelda / 2;
				int cx1 = colX + anchoCelda;
				int cx2 = colX + espacioX;
				Canvas->MoveTo(cx1, cy);
				Canvas->LineTo(cx2, cy);
				Canvas->Ellipse(cx2 - 2, cy - 2, cx2 + 2, cy + 2); // punta flecha
			}

			dirC = sigCol;
			col++;
		}

		dirF = Cm->obtenerDato(dirF, "->antF");
		fila++;
	}
}

