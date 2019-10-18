#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
struct information{
    string name;
    double diametr;
    double mass;
};
string input_name(){
    string name;
    cout << "Введите название пиццы:" << endl;
    getline(cin,name);
    return name;
}
double input_diameter(){
    double diametr;
    cout << "Введите диаметр пиццы: " << endl;
    cin >> diametr;
    return diametr;
}
double input_mass(){
    double mass;
    cout << "Введите вес пиццы: " << endl;
    cin >> mass;
    return mass;
}
int main(){
    int i, count;
    cin >> count;
    ++count;
    information pizza[count];
    // input information
    for (i = 0; i < count; i++ ){
        pizza[i].name = input_name(); // ????? почему первый getline скипается?
        // getline(cin,pizza[i].name);
    }
    for (i = 1; i < count; i++ ){
        cout << "Введите данные для " <<pizza[i].name << endl;
        pizza[i].diametr = input_diameter();
        pizza[i].mass = input_mass();
        
    }
    // output information
    cout << " INFORMATION ==========================" << endl;
    for ( i = 1; i < count; i++ ){
        cout << i  << ": " << pizza[i].name << endl;
        cout << "Вес: " << pizza[i].mass << " | ";
        cout << "Диаметр: " << pizza[i].diametr << endl;
    }
     
    return 5; 
}

