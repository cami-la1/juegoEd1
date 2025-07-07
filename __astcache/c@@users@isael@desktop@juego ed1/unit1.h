//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

// --- IMPLEMENTACIONES DE MATRICES DISPERSAS ---
#include "Matriz_1N.h"      // Matriz COO con CSMemoria (1 Nodo)
#include "matriz_2N.h"      // Matriz LIL con CSMemoria (2 Nodos)
#include "Matricez_ptr1.h"  // Matriz COO con punteros
#include "Matricez_ptr2.h"  // Matriz LIL con punteros
#include "matrizCCcpp.h"    // Matriz con Filas Comprimidas (CSR)
// --- IMPLEMENTACIONES DE PILAS (STACKS) ---
#include "UP_memoria.h"             // Pila con CSMemoria (pilaM)
#include "pila_para_infija.h"       // Pila con CSMemoria para debug (pilaMM)
#include "UP_vectores.h"            // Pila con Vector (pilav)
#include "UP_listasP.h"             // Pila con Lista y Punteros (pilal_P)
#include "UP_puntero.h"             // Pila con Punteros (ptr_pila)
#include "UP_listas.h"              // Pila como adaptador de Lista (pilal)
#include "UP_memoria_con_cola.h"    // Pila como adaptador de Cola (pilaMC)
// --- IMPLEMENTACIONES DE COLAS ---
#include "UC_vectores.h"      // Cola con Vector (colaV1, usada por ColaPri)
#include "ColaPrioridad.h"    // La cola de prioridad para turnos
// --- CLASES DE LÓGICA DEL JUEGO (LAS CREAREMOS) ---
#include "jugador.h"
#include "mapa.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TTimer *Timer1;
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormPaint(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations

// --- VARIABLES PRINCIPALES DEL JUEGO ---

    // --- Gestor de Memoria (solo hay una implementación) ---
    CSmemoria* memoria_principal;
	// --- Matriz del Mapa (Solo descomentar UNA opción) ---
  //	MatrizDispersa* matriz_juego;   // Opción 1: Matriz con CSMemoria (Recomendada para empezar)
	// MatrizDispersa2* matriz_juego;  // Opción 2: Matriz LIL con CSMemoria
	// MatrizDispersaptr* matriz_juego;// Opción 3: Matriz COO con punteros
	// Matrizptr2* matriz_juego;      // Opción 4: Matriz LIL con punteros
   	MatrizCC * matriz_juego;        // Opción 5: Matriz CSR con vectores
	// --- Pila de Movimientos para Deshacer (Solo descomentar UNA opción) ---
    pilaM* pila_movimientos;        // Opción 1: Pila con CSMemoria (Recomendada)
    // pilaMM* pila_movimientos;     // Opción 2: Pila con CSMemoria (versión debug)
    // pilav* pila_movimientos;       // Opción 3: Pila con vector
    // pilal_P* pila_movimientos;    // Opción 4: Pila con lista y punteros
    // ptr_pila* pila_movimientos;   // Opción 5: Otra pila con punteros
    // pilal* pila_movimientos;      // Opción 6: Pila sobre lista
    // pilaMC* pila_movimientos;     // Opción 7: Pila sobre cola
       colaV1* cola_de_teclas;
	// --- Cola de Turnos (solo hay una implementación) ---
	ColaPri* cola_turnos;
	// --- Controladores de Lógica (solo hay una implementación de cada uno) ---
	ControlJuego* control_juego;
	//Mapa* mapa_creator;



public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
