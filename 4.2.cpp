#include <iostream>
using namespace std;

struct CandyBar {
    string name;
    double mass;
    int kallories;
};
int main(){
    CandyBar snack;
    snack.name = " Mocha Muncha ";
    snack.mass = 2.3;
    snack.kallories = 350;
    cout << snack.name << endl;
    cout << "\t" << snack.mass << endl;
    cout << "\t\t" << snack.kallories << endl;
    return 5; // <-- оценочка 
}
