#include <iostream>
#include "Plansza.hh"
#include "Osoba.hh"
#include "Gracz.hh"
#include "Komputer.hh"

using namespace std;

int main(){
	Plansza p(5, 3);
	Osoba o1('X');
	Komputer o2('O');
	p.SetPlayers(&o1, &o2);
	char tm;
	for(int i = 0; i < 10; ++i){
		o1.WykonajRuch(&p);
		p.Display();
		if(p.CheckForVictory() != NULL)
			if(p.CheckForVictory() == &o1){
				system("cls");
				cout << "Gracz a" << endl;
				break;
			}
			else{
				system("cls");
				cout << "Gracz b" << endl;
				break;
			}
		//system("pause");
		o2.WykonajRuch(&p);
		p.Display();
		system("pause");
		if(p.CheckForVictory()!=NULL)
			if(p.CheckForVictory() == &o1){
				system("cls");
				cout << "Gracz a" << endl;
				break;
			}
			else{
				system("cls");
				cout << "Gracz b" << endl;
				break;
			}
	}

	system("pause");
}