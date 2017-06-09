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
	int MinIMax(Plansza* Board, int Depth, bool IsMax);
	int Ocen(Plansza* Board);
};
