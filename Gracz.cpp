#include "Gracz.hh"

/* --------------------------------------------------------------------------------- */
/* --------------------------- Konstruktory/Destruktory ---------------------------- */
/* --------------------------------------------------------------------------------- */

Gracz::Gracz(char Symbol):_Symbol(Symbol){
// Opis: Konstruktor klasy abstrakcyjnej Gracz
// IN: Symbol - warto�� inicjalizuj�ca pole _Symbol
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
// RETURN:: Zwraca warto�� pola _Symbol klasy Gracz
	return _Symbol;
}

void Gracz::SetSymbol(char Symbol){
// Opis: Seter pola _Symbol klasy Gracz
// IN: Symbol - warto�� wstawiana do pola _Symbol obiektu klasy Gracz
// OUT: Zmieniona warto�� pola _Symbol w obiekcie klasy Gracz
	_Symbol = Symbol;
}