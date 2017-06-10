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
// IN: Symbol - wartoœæ inicjalizuj¹ca pole _Symbol
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

void Komputer::WykonajRuch(Plansza* Gameboard){
// Opis: Metoda obs³uguj¹ca ruch komputera
// IN: Brak.
// OUT: Wykonuje ruch komputera
	int MoveVal = -1000;
	int BestMoveVal = -1000;
	int alpha = 1000;
	int beta = -1000;
	int w = INT_MAX;
	int k = INT_MAX;
	for(int i = 0; i < Gameboard->GetSize(); ++i){
		for(int j = 0; j < Gameboard->GetSize(); ++j){
			if(Gameboard->GetGame()[i][j] == ' '){
				Gameboard->SetSymbolOnBoard(i, j, GetSymbol());
				MoveVal = MinIMax(Gameboard, 0, false, alpha, beta);
				Gameboard->SetSymbolOnBoard(i, j, ' ', true);
				if(MoveVal > BestMoveVal){
					w = i;
					k = j;
					BestMoveVal = MoveVal; // n
				}
			}
		}
	}
	Gameboard->SetSymbolOnBoard(w, k, GetSymbol());
}

void Komputer::PierwszyRuch(Plansza* Game)const{
// Opis: Metoda wykonuj¹ca ruch je¿eli Komputer gra jako pierwszy
// IN: Game - wskaŸnik na planszê, na której komputer wykonuje ruch
// OUT: Ruch wykonany na planszy.
	int w = (rand() % (Game->GetSize() - 5)) + 3;
	int k = (rand() % (Game->GetSize() - 5)) + 3;
	Game->SetSymbolOnBoard(w-1, k-1, Gracz::GetSymbol());
}

int Komputer::Ocen(Plansza* Gameboard, int Depth){
// Opis: Metoda oceniaj¹ca sytuacjê na planszy wywo³ywana przez algorytm minimax
// IN: Gameboard - Plansza z aktualn¹ sytuacj¹
// RETURN: -1/0/1 w zale¿noœci od tego ¿e pora¿ka/remis/zwyciêstwo
	Gracz* Winner = Gameboard->CheckForVictory();
	if(Winner == NULL) return 0;
	else if(Winner == this) return 100 - Depth;
	else return -100 - Depth;
}


int Komputer::MinIMax(Plansza* Gameboard, int Depth, bool IsMax, int& alpha, int& beta){
// Opis: Implementacja algorytmu MiniMax, sztucznej inteligencji odpowiedzialnej za rozgrywkê w trybie jednoosobowym
// IN: Gameboard - referencja do analizowanego stanu planszy w grze
// IN: Depth - g³êdokoœæ wywo³añ rekurencyjnych
// IsMax
// RETURN: 
	if(Depth == 11 - 6) return 0;
	int Score = Ocen(Gameboard, Depth);
	if(Score != 0) return Score;
	else if(Gameboard->IsFull()) return Score;//y;

	if(IsMax == true){
		int Maximum = -100;
		for(int i = 0; i < Gameboard->GetSize(); ++i){
			for(int j = 0; j < Gameboard->GetSize(); ++j){
				if(!(beta >= Score)){
					if(Gameboard->GetGame()[i][j] == ' '){
						Gameboard->SetSymbolOnBoard(i, j, GetSymbol());
						Maximum = max(Maximum, MinIMax(Gameboard, Depth + 1, false, alpha, beta));
						beta = Maximum;
						//Maximum += MinIMax(Gameboard, Depth + 1, false);
						Gameboard->SetSymbolOnBoard(i, j, ' ', true);
					}
				}
			}
		}
		return Maximum;
	}

	else{
		int Minimum = 100;
		char Symbol;
		Symbol = (Gameboard->GetOpponent(this)->GetSymbol());
		for(int i = 0; i < Gameboard->GetSize(); ++i){
			for(int j = 0; j < Gameboard->GetSize(); ++j){
				if(alpha > Score){
					if(Gameboard->GetGame()[i][j] == ' '){
						Gameboard->SetSymbolOnBoard(i, j, Symbol);
						Minimum = min(Minimum, MinIMax(Gameboard, Depth + 1, true, alpha, beta));
						//Minimum += MinIMax(Gameboard, Depth + 1, true);
						Gameboard->SetSymbolOnBoard(i, j, ' ', true);
					}
				}
			}
		}
		return Minimum;
	}
}
