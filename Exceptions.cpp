#include "Exceptions.hh"
#include <iostream>

using namespace std;

void OutOfRangePlanszaException::Info()const{
	cout << "Warto�� spoza rozmiaru planszy!" << endl;
}

void FieldAlreadyUsedPlanszaException::Info()const{
	cout << "Pole jest ju� zaj�te!. Wybierz inne. " << endl;
}