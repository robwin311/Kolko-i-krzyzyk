#include "Plansza.hh"
#include <iostream>
#include "Exceptions.hh"

using namespace std;

/* ----------------------------------------------------------------------------------------- */
/* -------------------------------- Konstruktory/Destruktory ------------------------------- */
/* ----------------------------------------------------------------------------------------- */

Plansza::Plansza(int Size, int Row):_Size(Size), _Row(Row), _Player1(NULL), _Player2(NULL){
// Opis: Konstruktor klasy Plansza
// IN: Size - warto�� inicjalizuj�ca pole _Size
// IN: Row - warto�� inicjalizuj�ca pole _Row
// OUT: Dynamicznie alokuje pami�� na plansz� i przypisuje wska�nik na ni� do pola _Game;
  _Game = new char*[Size];          // alokacja pami�ci na _Game
	for(int i = 0; i < Size; ++i){
		_Game[i] = new char[Size];
	}
	for(int i = 0; i < Size; ++i){    // inicjalizacja _Game
		for(int j = 0; j < Size; ++j){
			_Game[i][j] = ' ';
		}
	}
}

Plansza::~Plansza(){
// Opis: Destruktor klasy Plansza
// IN: Brak.
// OUT: Dealokuje pami�� przydzielon� na plansz�
	for(int i = 0; i < _Size; ++i){
		delete [] _Game[i];
	}
	delete _Game;
}

/* ----------------------------------------------------------------------------------------- */
/* ------------------------------------ Getery/Setery -------------------------------------- */
/* ----------------------------------------------------------------------------------------- */

char** Plansza::GetGame()const{
// Opis: Geter pola _Game klasy Plansza
// IN: Brak.
// RETURN: Zwraca warto�� pola _Game obiektu klasy Plansza
	return _Game;
}

int Plansza::GetSize()const{
// Opis: Geter pola _Size klasy Plansza
// IN: Brak.
// OUT: Zwraca warto�� pola _Size obiektu klasy Plansza.
	return _Size;
}

/* ----------------------------------------------------------------------------------------- */
/* --------------------------------- Metody obs�ugi planszy -------------------------------- */
/* ----------------------------------------------------------------------------------------- */

void Plansza::SetPlayers(Gracz* Player1, Gracz* Player2){
// Opis: Metoda ustawiaj�ca zawodnik�w graj�cych na danej planszy
// IN: Player1 - Gracz 1;
// IN: Player2 - Gracz 2
// OUT: Pola _Player1 i _Player2 klasy s� skojarzone z obiektami graczy
	_Player1 = Player1;
	_Player2 = Player2;
}


void Plansza::Display()const{
// Opis: Metoda wy�wietlaj�ca plansz�.
// IN: Brak.
// OUT: Wy�wietla plansz� na standardowym wyj�ciu.
 cout << "    ";
	for(int i = 0; i < _Size; ++i){
		if(i < 9) cout  << " " << i+1 << " ";
		else if(i >= 9 && i < 99) cout << " " << i+1 << "";
		else if(i >= 99 && i < 999) cout << i + 1 << "";
	}
	cout << endl;

	for(int i = 0; i < _Size; ++i){
		if(i < 9) cout << "  " << i+1 << " ";
		else if(i >= 9 && i < 99) cout << " " << i+1 << " ";
		else if(i >= 99 && i < 999) cout << i+1 << " ";
		for(int j = 0; j < _Size; ++j){
			cout << "[" << _Game[i][j] << "]";
		}
		cout << endl;
	}
}

void Plansza::SetSymbolOnBoard(int w, int k, char Symbol, bool frce) throw(OutOfRangePlanszaException, FieldAlreadyUsedPlanszaException){
// Opis: Metoda ustawiaj�ca symbol na planszy
// IN: w - indeks wiersza, do kt�rego ustawiany jest symbol
// IN: k - indeks kolumny, do kt�rej ustawiany jest symbol
// IN: Symbol - rodzaj symbolu, kt�ry jest ustawiany.
	if(w >= 0 && w <= _Size-1 && k >= 0 && k <= _Size-1){
		if(_Game[w][k] == ' ' || frce == true){
			_Game[w][k] = Symbol;
		}
		else throw FieldAlreadyUsedPlanszaException();
	}
	else throw OutOfRangePlanszaException();
}

Gracz* Plansza::CheckForVictory()const{
// Opis: Metoda sprawdzaj�ca, czy kto� wygra�
// IN: a - pierwszy gracz
// IN: b - drugi gracz
// RETURN: Gracz kt�ry wygra�, lub NULL je�eli �aden nie wygra�
	char aSymb = _Player1->GetSymbol();
	char bSymb = _Player2->GetSymbol();

	int aLicznik = 0;
	int bLicznik = 0;
	int adLicznik = 0;
	int bdLicznik = 0;

	for(int i = 0; i < _Size; ++i){           // Sprawdzenie zwyci�stwa w poziomie
		for(int j = 0; j < _Size; ++j){
			if(_Game[i][j] == aSymb){
				bLicznik = 0;
				++aLicznik;
			}
			else if(_Game[i][j] == bSymb){
				aLicznik = 0;
				++bLicznik;
			}
			else{
				aLicznik = 0;
				bLicznik = 0;
			}
			if(aLicznik >= _Row) return _Player1;
			if(bLicznik >= _Row) return _Player2;
		}
		aLicznik = 0;
		bLicznik = 0;
	}
	aLicznik = 0;
	bLicznik = 0;
	
	for(int i = 0; i < _Size; ++i){            // Sprawdzenie zwyci�stwa w pionie
		for(int j = 0; j < _Size; ++j){
			if(_Game[j][i] == aSymb){
				bLicznik = 0;
				++aLicznik;
			}
			else if(_Game[j][i] == bSymb){
				aLicznik = 0;
				++bLicznik;
			}
			else{
				aLicznik = 0;
				bLicznik = 0;
			}
			if(aLicznik >= _Row) return _Player1;
			if(bLicznik >= _Row) return _Player2;
		}
		aLicznik = 0;
		bLicznik = 0;
	}
	aLicznik = 0;
	bLicznik = 0;

	for(int i = _Size-1; i >= 0 ; --i){              // Sprawdzenie zwyci�stwa po przek�tnej
		for(int j = 0; j <= _Size-1-i; ++j){
			if(_Game[i+j][j] == aSymb){
				bLicznik = 0;
				++aLicznik;
			}
			else if(_Game[i+j][j] == bSymb){
				aLicznik = 0;
				++bLicznik;
			}
			else{
				aLicznik = 0;
				bLicznik = 0;
			}

			if(_Game[_Size - 1 - i - j][_Size - 1 - j] == aSymb){
				bdLicznik = 0;
				++adLicznik;
			}
			else if(_Game[_Size - 1 - i - j][_Size - 1 - j] == bSymb){
				adLicznik = 0;
				++bdLicznik;
			}
			else{
				adLicznik = 0;
				bdLicznik = 0;
			}
			if(aLicznik >= _Row || adLicznik >= _Row) return _Player1;
			if(bLicznik >= _Row || bdLicznik >= _Row) return _Player2;
		}
		aLicznik = 0;
		bLicznik = 0;
		adLicznik = 0;
		bdLicznik = 0;
	}
	aLicznik = 0;
	bLicznik = 0;
	adLicznik = 0;
	bdLicznik = 0;

	for(int i = 0; i < _Size; ++i){            // Sprawdzenie zwyci�stwa w pionie
		for(int j = 0; j <= i; ++j){
			if(_Game[i-j][j] == aSymb){
				bLicznik = 0;
				++aLicznik;
			}
			else if(_Game[i-j][j] == bSymb){
				aLicznik = 0;
				++bLicznik;
			}
			else{
				aLicznik = 0;
				bLicznik = 0;
			}
			
			if(_Game[_Size - 1 - i + j][_Size - 1 - j] == aSymb){
				bdLicznik = 0;
				++adLicznik;
			}
			else if(_Game[_Size - 1 - i + j][_Size - 1 - j] == bSymb){
				adLicznik = 0;
				++bdLicznik;
			}
			else{
				adLicznik = 0;
				bdLicznik = 0;
			}
			if(aLicznik >= _Row || adLicznik >= _Row) return _Player1;
			if(bLicznik >= _Row || bdLicznik >= _Row) return _Player2;
		}
		aLicznik = 0;
		bLicznik = 0;
		adLicznik = 0;
		bdLicznik = 0;
	}
	return NULL;
}

bool Plansza::IsEmpty()const{
// Opis: Metoda sprawdzaj�ca czy plansza jest pusta.
// IN: Brak.
// RETURN Zwraca true/false je�eli plansza jest pusta/s� na niej symbole
	for(int i = 0; i < _Size; ++i){
		for(int j = 0; j < _Size; ++j){
			if(_Game[i][j] != ' ') return false;
		}
	}
	return true;
}

bool Plansza::IsFull()const{
// Opis: Metoda sprawdzaj�ca czy plansza jest pe�na.
// IN: Brak.
// RETURN Zwraca true/false je�eli plansza jest pe�na/niepe�na
	for(int i = 0; i < _Size; ++i){
		for(int j = 0; j < _Size; ++j){
			if(_Game[i][j] == ' ') return false;
		}
	}
	return true;
}

Gracz* Plansza::GetOpponent(Gracz* Player)const{
// Opis: Metoda zwracaj�ca przeciwnika gracza Player
// IN: Player - gracz znany
// RETURN: Zwraca wska�nik na przeciwnika
	if(Player == _Player1) return _Player2;
	else if(Player == _Player2) return _Player1;
	else return NULL;
}