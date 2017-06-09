#include "Gracz.hh"
#include "Komputer.hh"
#include "stdlib.h"
#include "time.h"
#include <iostream>
#include <algorithm>

using namespace std;

/* --------------------------------------------------------------------------------- */
/* --------------------------- Konstruktory/Destruktory ---------------------------- */
/* --------------------------------------------------------------------------------- */

Komputer::Komputer(char Symbol) : Gracz::Gracz(Symbol){
// Opis: Konstruktor klasy Komputer
// IN: Symbol - warto�� inicjalizuj�ca pole _Symbol
// OUT: Tworzy obiekt klasy Komputer
}

Komputer::~Komputer(){
// Opis: Destruktor klasy Komputer
// IN: Brak.
// OUT: Usuwa obiekt klasy Komputer
}

/* --------------------------------------------------------------------------------- */
/* -------------------------------- Getery/Setery ---------------------------------- */
/* --------------------------------------------------------------------------------- */

void Komputer::WykonajRuch(Plansza* Board){
// Opis: Metoda obs�uguj�ca ruch komputera
// IN: Brak.
// OUT: Wykonuje ruch komputera
	int MoveVal = -1;
	int BestMoveVal = -1;
	int w = INT_MAX;
	int k = INT_MAX;
	for(int i = 0; i < Board->GetSize(); ++i){
		for(int j = 0; j < Board->GetSize(); ++j){
			if(Board->GetGame()[i][j] == ' '){
				Board->SetSymbolOnBoard(i, j, GetSymbol());
				MoveVal = MinIMax(Board, 0, false);
				Board->SetSymbolOnBoard(i, j, ' ', true);
				if(MoveVal > BestMoveVal){
					w = i;
					k = j;
					BestMoveVal = MoveVal; // n
				}
			}
		}
	}
	Board->SetSymbolOnBoard(w, k, GetSymbol());
}

void Komputer::PierwszyRuch(Plansza* Game)const{
// Opis: Metoda wykonuj�ca ruch je�eli Komputer gra jako pierwszy
// IN: Game - wska�nik na plansz�, na kt�rej komputer wykonuje ruch
// OUT: Ruch wykonany na planszy.
	int w = (rand() % (Game->GetSize() - 5)) + 3;
	int k = (rand() % (Game->GetSize() - 5)) + 3;
	Game->SetSymbolOnBoard(w-1, k-1, Gracz::GetSymbol());
}

int Komputer::Ocen(Plansza* Board){
// Opis: Metoda oceniaj�ca sytuacj� na planszy wywo�ywana przez algorytm minimax
// IN: Board - Plansza z aktualn� sytuacj�
// RETURN: -1/0/1 w zale�no�ci od tego �e pora�ka/remis/zwyci�stwo
	Gracz* Winner = Board->CheckForVictory();
	if(Winner == NULL) return 0;
	else if(Winner == this) return 1;
	else return -1;
}


int Komputer::MinIMax(Plansza* Board, int Depth, bool IsMax){
// Opis: Implementacja algorytmu MiniMax, sztucznej inteligencji odpowiedzialnej za rozgrywk� w trybie jednoosobowym
// IN: Board - referencja do analizowanego stanu planszy w grze
// IN: Depth - g��doko�� wywo�a� rekurencyjnych
// IsMax
// RETURN: 
	if(Depth == 10) return 0;
	if(Board->IsFull()){
		return Ocen(Board);
	}

	if(IsMax == true){
		int Maximum = -1;
		for(int i = 0; i < Board->GetSize(); ++i){
			for(int j = 0; j < Board->GetSize(); ++j){
				if(Board->GetGame()[i][j] == ' '){
					Board->SetSymbolOnBoard(i, j, GetSymbol());
					Maximum = max(Maximum, MinIMax(Board, Depth + 1, false));
					Board->SetSymbolOnBoard(i, j, ' ', true);
				}
			}
		}
		return Maximum;
	}

	else{
		int Minimum = 1;
		char Symbol;
		Symbol = (Board->GetOpponent(this)->GetSymbol());
		for(int i = 0; i < Board->GetSize(); ++i){
			for(int j = 0; j < Board->GetSize(); ++j){
				if(Board->GetGame()[i][j] == ' '){
					Board->SetSymbolOnBoard(i, j, Symbol);
					Minimum = min(Minimum, MinIMax(Board, Depth + 1, true));
					Board->SetSymbolOnBoard(i, j, ' ', true);
				}
			}
		}
		return Minimum;
	}
}
