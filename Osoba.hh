#pragma once

#include "Plansza.hh"
#include "Gracz.hh"

class Osoba: public Gracz{
public:
	/*- Konstruktory/Destruktory -*/
	Osoba(char Symbol);
	~Osoba();

	/*- Obs³uga -*/
	virtual void WykonajRuch(Plansza* Game);

private:
	void ZczytajPole(int& w, int& k, int Size)const;
};