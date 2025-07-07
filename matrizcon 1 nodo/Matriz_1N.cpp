//---------------------------------------------------------------------------

#pragma hdrstop
 #include <vector>
#include "Matriz_1N.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
	 MatrizDispersa::MatrizDispersa(CSmemoria* M) {
    Cm = M;
	PtrMatD = -1;
    dimf = 0;
	dimc = 0;
    rep = 0;
}

void MatrizDispersa::dimensionar(int df, int dc) {
    dimf = df;
	dimc = dc;
}
	int MatrizDispersa::dimension_Fila(){

	  return dimf;

	}
	int MatrizDispersa:: dimension_columna(){
       return dimc;
	}
   int MatrizDispersa::buscar(int f, int c) {
    int x = PtrMatD;
    while (x != NULO) {
        if (Cm->obtenerDato(x, "->fila") == f && Cm->obtenerDato(x, "->col") == c) {
            return x;
        }
		x = Cm->obtenerDato(x, "->sig");
    }
    return NULO; // Retorna NULO si no encuentra el nodo
}
 void MatrizDispersa::poner(int f, int c, int e) {
 if (e!=rep) {


	// Buscar si existe f,c en los nodos
	int dir = buscar(f, c);
	if (dir == NULO) {
		// Crear un nuevo espacio
		int x = Cm->new_espacio("fila,col,dato,sig");
		if (x != NULO) {
			// Poner los datos
			Cm->poner_dato(x, "->fila", f);
			Cm->poner_dato(x, "->col", c);
			Cm->poner_dato(x, "->dato", e);
            Cm->poner_dato(x, "->sig", PtrMatD);
            PtrMatD = x;
        } else {
            // Error: no hay espacio en la memoria
            // Manejar el error aquí
		}
    } else {
        // Poner el dato
        Cm->poner_dato(dir, "->dato", e);
        if (e == rep) {
            // Eliminar el nodo
			int temp = PtrMatD;
            // Si el nodo a eliminar es el primer nodo
            if (temp == dir) {
                PtrMatD = Cm->obtenerDato(dir, "->sig");
			} else {
                // Buscar el nodo anterior al nodo a eliminar
                while (Cm->obtenerDato(temp, "->sig") != dir) {
                    temp = Cm->obtenerDato(temp, "->sig");
                }
                // Cambiar el enlace del nodo anterior al nodo siguiente
                Cm->poner_dato(temp, "->sig", Cm->obtenerDato(dir, "->sig"));
            }
			// Liberar el espacio de memoria del nodo eliminado
            Cm->Delete_espacio(dir);
		}
	}
 }
}
 void MatrizDispersa::poner2(int f, int c, int e) {



	// Buscar si existe f,c en los nodos
	int dir = buscar(f, c);
	if (dir == NULO) {
		// Crear un nuevo espacio
		int x = Cm->new_espacio("fila,col,dato,sig");
		if (x != NULO) {
			// Poner los datos
			Cm->poner_dato(x, "->fila", f);
			Cm->poner_dato(x, "->col", c);
			Cm->poner_dato(x, "->dato", e);
            Cm->poner_dato(x, "->sig", PtrMatD);
            PtrMatD = x;
        } else {
            // Error: no hay espacio en la memoria
            // Manejar el error aquí
		}
    } else {
        // Poner el dato
        Cm->poner_dato(dir, "->dato", e);
        if (e == rep) {
            // Eliminar el nodo
			int temp = PtrMatD;
            // Si el nodo a eliminar es el primer nodo
            if (temp == dir) {
                PtrMatD = Cm->obtenerDato(dir, "->sig");
			} else {
                // Buscar el nodo anterior al nodo a eliminar
                while (Cm->obtenerDato(temp, "->sig") != dir) {
                    temp = Cm->obtenerDato(temp, "->sig");
                }
                // Cambiar el enlace del nodo anterior al nodo siguiente
                Cm->poner_dato(temp, "->sig", Cm->obtenerDato(dir, "->sig"));
            }
			// Liberar el espacio de memoria del nodo eliminado
            Cm->Delete_espacio(dir);
		}
	}
 }


void MatrizDispersa::eliminarElementoInverso(int f, int c) {
	int dir = PtrMatD;
	int prev = NULO;

	// Recorrer la lista de nodos para encontrar el nodo con la fila y columna especificadas
	while (dir != NULO) {
		if (Cm->obtenerDato(dir, "->fila") == f && Cm->obtenerDato(dir, "->col") == c) {
			// Nodo encontrado, proceder con la eliminación
			int siguiente = Cm->obtenerDato(dir, "->sig");

			if (prev != NULO) {
				// Si el nodo no es el primero, actualizar el enlace del nodo anterior
				Cm->poner_dato(prev, "->sig", siguiente);
			} else {
				// Si el nodo es el primero, actualizar el puntero principal de la matriz
				PtrMatD = siguiente;
			}

			// Eliminar el nodo de la memoria
            Cm->Delete_espacio(dir);
            return; // Salir después de eliminar el nodo
        } else {
            // Continuar con el siguiente nodo
            prev = dir;
            dir = Cm->obtenerDato(dir, "->sig");
        }
    }
}






void MatrizDispersa::eliminarSiIgual(int valor) {
    int prev = NULO;
    int dir = PtrMatD;
    while (dir != NULO) {
        if (Cm->obtenerDato(dir, "->dato") == valor) {
            int temp = Cm->obtenerDato(dir, "->sig");
            if (prev != NULO) {
                Cm->poner_dato(prev, "->sig", temp);
            } else {
                PtrMatD = temp;
            }
            Cm->Delete_espacio(dir);
            dir = temp;
        } else {
            prev = dir;
            dir = Cm->obtenerDato(dir, "->sig");
        }
    }
}












void MatrizDispersa::Definir_valor_repetido(int valor){
	if (Cm->Espacio_ocupado()==0) {
		rep=valor;
	} else {
		std::vector<int> nodosAEliminar;
		 int p= Elemento(1, 1);    int a= Elemento(1, 1);
        // Recorrer todas las filas y columnas
        for (int i = 1; i <= dimf; i++) {
            for (int j = 1; j <= dimc; j++) {
				// Si el valor en la posición actual es igual al nuevo valor repetido
				if (Elemento(i, j) == rep) {
                    // Añadir la dirección del nodo a la lista de nodos a eliminar
				  int z= Elemento(i, j);// nodosAEliminar.push_back(buscar(i, j));
				   poner(i,j,Elemento(i,j));
				}
			}
		}
		eliminarSiIgual(valor);
		rep = valor;
	}
}


	int MatrizDispersa::Elemento(int f, int c) {
	if (f >= 1 && f <= dimf && c >= 1 && c <= dimc) {
		// Buscar si existe f,c en los nodos
		int dir = buscar(f, c);
		if (dir != NULO) {
            // Si el nodo existe, retornar el dato
			return Cm->obtenerDato(dir, "->dato");
        } else {
            // Si el nodo no existe, retornar el valor repetido
            return rep;
		}
	}
	// Retornar un valor por defecto si f o c están fuera de los límites
	// Puedes ajustar este valor según tus necesidades
	  return rep;
}



void MatrizDispersa::imprimir(TColor FormColor, TCanvas *Canvas) {
	// Obtén las dimensiones del Canvas
	int canvasWidth = Canvas->ClipRect.Width();
	int canvasHeight = Canvas->ClipRect.Height();

	// Calcula el tamaño de cada celda de la matriz en el Canvas
	int cellWidth = 40; // Ahora la matriz ocupará 1/3 del ancho del Canvas
	int cellHeight = 30;

	// Asegúrate de que el Canvas esté limpio


	// Cambia el color del pincel para dibujar la matriz
	Canvas->Pen->Color = clBlack; // Solo cambia el color del lápiz, no el del pincel

	// Calcula el desplazamiento para centrar la matriz en el Canvas
	int offsetX = (canvasWidth - dimc * cellWidth) / 2;
	int offsetY = (canvasHeight - dimf * cellHeight) / 2;

	// Recorre la matriz y dibuja cada celda
	for (int i = 0; i < dimf; i++) {
		for (int j = 0; j < dimc; j++) {
			// Calcula la posición de esta celda en el Canvas
			int x = offsetX + j * cellWidth;
			int y = offsetY + i * cellHeight;

            // Dibuja la celda
			Canvas->Rectangle(x, y, x + cellWidth, y + cellHeight);

			// Dibuja el valor de la celda
            int valor = Elemento(i+1, j+1); // Asume que los índices de la matriz comienzan en 1
			Canvas->Font->Color = clBlack; // Cambia el color del texto a negro
			Canvas->TextOutW(x + cellWidth / 2, y-10+ cellHeight / 2, IntToStr(valor));
		}
	}
}

