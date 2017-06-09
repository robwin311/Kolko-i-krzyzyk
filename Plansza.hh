#pragma once
/*
  //#include <iostream>

  //using namespace std;
  //int GetSize()const;
	//void 
	*/

#include "Exceptions.hh"
#include "Gracz.hh"

class Plansza{
public:
	/*- Konstruktory/Destruktory -*/
	Plansza(int Size, int Row);
	~Plansza();

	/*- Getery/Setery -*/
	char** GetGame()const;
	int GetSize()const;

	/*- Metody obs³ugi planszy -*/
	bool IsEmpty()const;
	bool IsFull()const;
	void SetPlayers(Gracz* Player1, Gracz* Player2);
	void Display()const;
	void SetSymbolOnBoard(int w, int k, char Symbol, bool frce = false) throw(OutOfRangePlanszaException, FieldAlreadyUsedPlanszaException);
	Gracz* CheckForVictory()const;
	Gracz* Plansza::GetOpponent(Gracz* Player)const;

private:
	int _Size;     // Rozmiar planszy
	int _Row;      // Liczba symboli w rzêdzie do wygrania
	char** _Game;  // Plansza
	Gracz* _Player1; // Gracz 1
	Gracz* _Player2; // Gracz 2
};