// ConsoleApplication9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	double cels, fahr;
	cout << "Please enter a celsius value: ";
	cin >> cels;
	cout << cels << " degreees Celsius is " << (cels * 1.8 + 32.0) << " degrees Fahrenheit\n";
	return 0;
}

