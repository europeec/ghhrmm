#include <iostream>
#include <algorithm>
using namespace std;
const int counter = 3;
    struct PRICE{
    int price;
    string name_product;
    string name_shop;
    };
int main(){
    PRICE product[counter];
    for ( int k = 0; k < counter; k++){
        cin.clear();
        cout << "Введите стоимость продукта - ";
        cin >> product[k].price;
        cin.get();
        cout << "Введите название продукта - ";
        getline(cin,product[k].name_product);
        cout << "Введите название магазина - ";
        getline(cin,product[k].name_shop);
    }
    // SORT
    for ( int i = 0; i < counter; i++){
        string min = product[0].name_shop;
        int min_num = -1;
        for (int p = i; p < counter; p ++) {
            if (product[p].name_shop < min){
                min = product[p].name_shop;
                min_num = p;
            }
            if ( min_num == -1){
                min_num = i;
            }
        }
        string temp = product[i].name_shop;
        product[i].name_shop = min;
        product[min_num].name_shop = temp;
        string temp2 = product[i].name_product;
        product[i].name_product = product[min_num].name_product;
        product[min_num].name_product = temp2;
        int temp3 = product[i].price;
        product[i].price = product[min_num].price;
        product[min_num].price = temp3;
    }
    cout << "СПИСОК МАГАЗИНОВ" << endl;
     for ( int i = 0; i < counter; i ++ ){
            cout << "\t" << product[i].name_shop << endl;
    }
    cout << "Какой магазин нужно найти? - ";
    string chose;
    getline(cin,chose);
    int otchet = 0;
    for ( int i = 0; i < counter; i ++ ){
        if ( chose == product[i].name_shop){
            cout << "\tНазвание продукта - " << product[i].name_product << endl;
            cout << "\tСтоимость продукта - "<< product[i].price << endl;
            otchet++;
        }
    }
    if (otchet == 0){
        cout << "\nТакой магазин не найден" << endl;
    }
}
