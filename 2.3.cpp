// ConsoleApplication6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>;
using namespace std;
void first_second() {
	cout << "Three blind mice\n";
}
void three_four() {
	cout << "See how they run\n";
}

int main()
{
	first_second();
	first_second();
	three_four();
	three_four();
	return 0;
}

