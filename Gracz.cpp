#include "Gracz.hh"

/* --------------------------------------------------------------------------------- */
/* --------------------------- Konstruktory/Destruktory ---------------------------- */
/* --------------------------------------------------------------------------------- */

Gracz::Gracz(char Symbol):_Symbol(Symbol){
// Opis: Konstruktor klasy abstrakcyjnej Gracz
// IN: Symbol - wartoœæ inicjalizuj¹ca pole _Symbol
// OUT: Tworzy obiekt klasy Gracz
}

Gracz::~Gracz(){
// Opis: Destruktor klasy Gracz
// IN: Brak.
// OUT: Usuwa obiekt klasy Gracz
}

/* --------------------------------------------------------------------------------- */
/* -------------------------------- Getery/Setery ---------------------------------- */
/* --------------------------------------------------------------------------------- */

char Gracz::GetSymbol()const{
// Opis: Geter pola _Symbol klasy Gracz
// IN: Brak.
// RETURN:: Zwraca wartoœæ pola _Symbol klasy Gracz
	return _Symbol;
}

void Gracz::SetSymbol(char Symbol){
// Opis: Seter pola _Symbol klasy Gracz
// IN: Symbol - wartoœæ wstawiana do pola _Symbol obiektu klasy Gracz
// OUT: Zmieniona wartoœæ pola _Symbol w obiekcie klasy Gracz
	_Symbol = Symbol;
}