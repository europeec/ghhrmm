// num 1 v19
#include "stdafx.h"
#include "iostream"
#include "locale.h"
using namespace std;
double input() {
	setlocale(LC_ALL, "RUS");
	double x;
	cout << "Введите значение переменной: ";
	cin >> x;
	return x;
}
double func(double a, double b, double c, double d, double x) {
	if ((x < 5) && (b != 0)) {
		return (a*(x + 7)*(x + 7) - b);
	}
	else {
		if (b == 0) {
			return x / c;
		}
	}
	if ((x > 5) && (b == 0)) {
		return ((x - c*d) / a*x);
	}
	else {
		if (b != 0) {
			return x / c;
		}
	}

}
int main() {
	double a, b, c, d, x;
	int ac, bc, cc;
	int F_int;
	double F_double;
	double left, right;
	cout << "left point -  ";
	cin >> left;
	cout << "right point - ";
	cin >> right;
	double dX;
	// input [ left .. right .. dX << a b c d ]
	cout << "dX - ";
	cin >> dX;
	a = input();
	b = input();
	c = input();
	d = input();
	ac = a / 1;
	bc = b / 1;
	cc = c / 1;
	for (x = left; x < right; x += dX) {
		if (((ac ^ bc) || (ac ^ cc)) != 0) {
			F_double = func(a, b, c, d, x);
			cout << F_double;
		}
		else {
			F_int = func(a, b, c, d, x);
			cout << F_int;
		}
	}
}
