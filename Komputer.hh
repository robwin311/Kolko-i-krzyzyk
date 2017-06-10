#pragma once

#include "Gracz.hh"
#include "Plansza.hh"

class Komputer : public Gracz{
public:
	/*- Konstruktory/Destruktory -*/
	Komputer(char Symbol);
	~Komputer();

	/*- Obs³uga -*/
	void WykonajRuch(Plansza* Game);
private:
	void PierwszyRuch(Plansza* Game)const;
	int MinIMax(Plansza* Gameboard, int Depth, bool IsMax, int& alpha, int& beta);
	int Ocen(Plansza* Gameboard, int Depth);
};
