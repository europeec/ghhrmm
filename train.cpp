#include <iostream>
#include <iostream>

using namespace std;

struct station{
    int num;
    char station[30];
    int hour;
    int min;
};

int main(){
    station train[INT_MAX];
    int answer = 0;
    cout << " Команда стоп - 3" << endl;
    int count = 0;
    while ( answer != 3) {
        cout << "Хотите добавить поезд ( 1 - да/ 0 - нет / 3 - завершить )" << endl;
        cin >> answer;
    if (answer == 1){
        count ++;
        cout << "Введите номер поезда -  ";
        cin >> train[count-1].num;
        cout << "Введите станцию назначения поезда -  ";
        cin >> train[count-1].station;
        cout << "Введите время отправления поезда ( час*пробел*минуты) -  ";
        cin >> train[count-1].hour >> train[count-1].min;
    } else
    {
        if ( answer == 0 ){
            cout << " 0 - завершить " << endl;
            cout << " 1 - вывести список" << endl;
            cout << " 2 - найти поезд по номеру "<< endl;
            cout << " 3 - найти поезда по станции"  << endl;
            int p;
            cin >> p;
            if (p == 1){
                for ( int i = 0; i < count; i++){
                    cout << "Номер поезда - " <<  train[i].num  << " | Станция назначения - " << train[i].station <<
                    " | Время отправления - " << train[i].hour << ":" << train[i].min << endl;
                }
            }
            else {
                if ( p == 2 ){
                    int nomer;
                    cout << "Введите номер интересующего вас поезда - " << endl;
                    cin >> nomer;
                    for ( int i = 0; i < count; i ++) {
                    if ( train[i].num == nomer){
                    cout << " Станция назначения - " << train[i].station  << " | Время отправления - " << train[i].hour << ":" << train[i].min << endl;
                    }
                    }
                } else
                {
                if (p == 3){
                    char searh[30];
                    cout << "Какую станцию хотели бы найти? - ";
                    cin >> searh;
                    string ssearch = (string)searh;
                    for ( int i = 0; i < count; i ++) {
                        string sstation = "";
                        sstation = (string)train[i].station;
                        if ( sstation == ssearch){
                        cout << "Номер поезда - " <<  train[i].num  << " | Время отправления - " << train[i].hour << ":" << train[i].min << endl;
                        }
                    }
                } else {
                    if ( p == 0) {
                        answer = 3;
                    }
                }
                }
            }
        }
    }
    }
    cout << "end" << endl;
    return 5;
}

