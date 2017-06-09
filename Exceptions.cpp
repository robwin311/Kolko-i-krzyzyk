#include "Exceptions.hh"
#include <iostream>

using namespace std;

void OutOfRangePlanszaException::Info()const{
	cout << "Wartoœæ spoza rozmiaru planszy!" << endl;
}

void FieldAlreadyUsedPlanszaException::Info()const{
	cout << "Pole jest ju¿ zajête!. Wybierz inne. " << endl;
}