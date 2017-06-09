#pragma once

//#include "Plansza.hh"

extern class Plansza;

class Gracz{
public:
	/*- Konstruktory/Destruktory -*/
	Gracz(char Symbol);
	~Gracz();

	/*- Getery/Setery -*/
	char GetSymbol()const;
	void SetSymbol(char Symbol);
	
	/*- Obs³uga -*/
	virtual void WykonajRuch(Plansza* Game) = 0;
	
private:
	char _Symbol; // Symbol wpisywany na planszy
};