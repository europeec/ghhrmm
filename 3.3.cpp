// ConsoleApplication16.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	double km, l;
	cout << "km: ";
	cin >> km;
	cout << "l: ";
	cin >> l;
	cout << "result: " << l/(km/100)<<endl ;
    return 0;
}

