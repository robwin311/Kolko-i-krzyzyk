#include "Gracz.hh" 
#include "Osoba.hh"
#include "Plansza.hh" 
#include <iostream>
/**/ #include "Exceptions.hh" /**/
/* ---------------------------- Konstruktory/Destruktory --------------------------- */
/* --------------------------------------------------------------------------------- */
using namespace std;
Osoba::Osoba(char Symbol):Gracz::Gracz(Symbol){
// Opis: Konstruktor klasy Osoba
// IN: Symbol - warto�� inicjalizuj�ca pole _Symbol obiektu klasy Osoba
// OUT: Tworzy instancj� klasy Osoba. 
}

Osoba::~Osoba(){
// Opis: Destruktor klasy Osoba
// IN: Brak.
// OUT: Usuwa obiekt klasy Osoba 
}


/* --------------------------------------------------------------------------------- */
/* --------------------------- Metody obs�ugi planszy ------------------------------ */
/* --------------------------------------------------------------------------------- */


void Osoba::ZczytajPole(int& w, int& k, int Size)const{
// Opis: Metoda obs�uguj�ca zczytanie pola, do kt�rego symbol wpisuje osoba.
// IN: w - indeks wiersza.
// IN: k - indeks kolumny.
// IN: Size - rozmiar planszy.
// OUT: Argumenty w,k zawieraj� indeksy pola na planszy

	cout << "Gdzie chcia�by� postawi� " << Gracz::GetSymbol() << " ?" << endl;

	cout << "Wprowadz numer wiersza: ";
	cin >> w;
	cout << endl;
	while(w <= 0 || w > Size){
		cout << "Wprowadzono niepoprawny numer wiersza." << endl;
		cout << "Wprowadz poprawny numer wiersza: ";
		cin >> w;
		cout << endl;
	}

	cout << "Wprowadz numer kolumny: ";
	cin >> k;
	cout << endl;
	while(k <= 0 || k > Size){
		cout << "Wprowadzono niepoprawny numer kolumny." << endl;
		cout << "Wprowadz poprawny numer kolumny: ";
		cin >> k;
		cout << endl;
	}
}

void Osoba::WykonajRuch(Plansza* Game){
// Opis: Metoda wykonuje ruch osoby
// IN: Game - plansza, na kt�rej wykonywany jest ruch
// OUT: Wykonany ruch przez osob�
	int w = 0;
	int k = 0;
	ZczytajPole(w, k, Game->GetSize());
	try{
		Game->SetSymbolOnBoard(w - 1, k - 1, Gracz::GetSymbol());
	}
	catch(OutOfRangePlanszaException& Exception){
		Exception.Info();
	}
	catch(FieldAlreadyUsedPlanszaException& Exception){
		Exception.Info();
		WykonajRuch(Game);
	}
}