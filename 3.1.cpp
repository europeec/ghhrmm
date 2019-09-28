// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>;
using namespace std;
const double d = 2.54;
const double f = 30.48;


int main()
{
	int ent;
	cout << "please enter here : _ ";
	cin >> ent;
	cout << "your height is " << ent << " d. or " << ent/f << " f. " << endl;
		return 0;
}

