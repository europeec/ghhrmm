// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>;
using namespace std;
const double d = 0.0254;
const double f = 12;
const double pb = 2.2;


int main()
{
	double ftheight, dheight, mass;
	cout << "please enter your height (ft) here : ";
	cin >> ftheight;
	cout << "please enter your height (d) here : ";
	cin >> dheight;
	cout << "please enter your mass (pb) here : ";
	cin >> mass;
	mass = mass / pb; // pb in kg
	ftheight = ftheight * f; // ft in d
	dheight = (dheight + ftheight) * d;
	double BMI = mass / (dheight*dheight);
	cout << BMI << endl;
	return 0;
}

