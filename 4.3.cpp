#include <iostream>
using namespace std;

struct CandyBar{
    string name;
    double mass;
    int kalories;
};
string input_name(){
    string name;
    cout << "Введите имя: ";
    cin >> name;
    return name;
}
double input_mass(){
    double mass;
    cout << "Введите массу: ";
    cin >> mass;
    return mass;
}
int input_kalories(){
    int kalories;
    cout << "Введите калории: ";
    cin >> kalories;
    return kalories;
}
int main(){
    CandyBar product1;
    CandyBar product2;
    CandyBar product3;
        product1.name = input_name();
        product1.mass = input_mass();
        product1.kalories = input_kalories();
        // input product 2
        product2.name = input_name();
        product2.mass = input_mass();
        product2.kalories = input_kalories();
        // input product 3
        product3.name = input_name();
        product3.mass = input_mass();
        product3.kalories = input_kalories();
        // output
    cout << " OUTPUT PRODUCTS: "<< endl;
    cout << " \tnum " << "\t\t\tINFORMATION" << endl;
    cout << "1 product: " <<  product1.name << " | mass:" << product1.mass << " | kalories: " << product1.kalories;
    cout << endl;
    cout << "2 product: " <<  product2.name << " | mass:" << product2.mass << " | kalories: " << product2.kalories;
    cout << endl;
    cout << "3 product: " <<  product3.name << " | mass:" << product3.mass << " | kalories: " << product3.kalories;
    cout << endl;
    return 5;
}
