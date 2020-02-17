#include <iostream>
//#include <algorithm>
using namespace std;


//MARK: - car
class car
{
public:
    friend class police;
    friend bool checkPos(car &one);
    friend class cam;
    friend void workCam(car&bip);
    car(string mark, string num, int x){
        this -> mark = mark;
        this -> num = num;
        this -> x = x;
    }
    string mark;
    string num;
    void motion(){
        if (timeStop == 0){
        this -> spd = 51 + rand()%16;
        this -> x = this -> x + spd;
        }else {
            this -> spd = 0;
            timeStop--;
        }
    }
    void showX(){
        cout << this -> x << " ";
    }
    int counter = 0;
private:
    int spd;
    int x;
    int checkCam = -1; // проверка от повторного штрафа
    int spamCam = -1; // Проверка от спама принадлжености к области действия камеры
    int spamPolice = -1; // Проверка от спама принедлежности к области действия сотрудника
    int stoped = -1; // номер сотрудника, останивившего автомобиль
    int timeStop = 0;
};


//MARK: - police
class police{
    friend class cam;
    friend void workCam(car &bip);
public:
    police(int x, int num){
        this -> x = x;
        this -> num = num;
    }
    bool checkPos ( car &bip ){
        if (( bip.x > this -> x - 100)&&(bip.x < this -> x + 100 )){
            return true;
        }else {
            return false;
        }
    }
    void work(car &bip){
        if (checkPos(bip)){
            if (bip.spamPolice != this -> num){
            cout << "Автомобиль марки " << bip.mark << " находится в зоне видимости сотрудника полиции ["<< num << "]." << endl;
                bip.spamPolice = this -> num;
            }
            if ((bip.counter != 0)&&(bip.x > this -> x - 40 && bip.x < this -> x + 40)){
                // если есть штраф = останавливаем
                if(bip.stoped != this -> num){
                bip.x = this -> x;
                cout << "Автомобиль с гос.номером " << bip.num << " был остановлен сотрудиком полиции [" << this -> num << "]" << endl;
                bip.timeStop = 10;
                bip.spd = 0;
                bip.stoped = this -> num;
               }
             }
            if (bip.stoped == num && bip.spd != 0){
                cout << "Сотрудник полиции [" << this -> num << "] отпустил автомобиль марки " << bip.mark << endl;
            }
        }
    }
private:
    int x;
    int num;
    
};


//MARK: - cam
class cam : public police{
public:
    cam(int x, int y, int lim) : police (x, y){
        this -> lim = lim;
    }
    void workCam(car &bip){
        if (checkPos(bip)){
            if (bip.spamCam != this -> num){
                cout << "Автомобиль марки " << bip.mark << " находится в зоне видимости камеры под номером "  << this -> num << endl;
            }
            if ( bip.spd > this -> lim){
            if (bip.checkCam != this -> num){
                bip.counter++;
                bip.checkCam = num;
                cout << "На номер " << bip.num << " был выписан штраф. Скорость т/с "  << bip.spd << " км/ч.Разрешенная скорость " << this -> lim << " км/ч" << endl;
            } else {
                cout << "На номер " << bip.num << " уже был выписан штраф" << endl;
            }
            }
        }
    }
private:
    int lim;
};

bool operator < (const car &bmw, const car &lada){
    return bmw.counter < lada.counter;
}
bool operator == ( const car &bmw, const car &lada){
    return bmw.counter == lada.counter;
}
int operator + ( const car &one, const car &two){
    return one.counter + two.counter;
}

//MARK: - main  
int main(){
    police Vitalii(300, 15);
    cam photo(2,4,44);
    cam street(200, 13,60);
    cam Most(1,228,60);
    car carFirst("BMW", "B868PY",0);
    car carSecond("Lada", "A987BA",184);
    for ( int i = 0; i < 60; i++ ){
        carFirst.motion();
        //carFirst.showX();
        carSecond.motion();
        Most.workCam(carFirst);
        Most.workCam(carSecond);
        Vitalii.work(carSecond);
        Vitalii.work(carFirst);
    }
    if (carFirst == carSecond){
        cout << "Количество штрафов у " << carFirst.mark << " и у " << carSecond.mark << " одинаково."  << endl;
    } else {
        if ( carFirst < carSecond){
            cout << "В этот раз водитель "  << carFirst.mark << " нарушил ПДД меньше, чем водитель " << carSecond.mark << endl;
        } else {
            cout << "В этот раз водитель "  << carSecond.mark << " нарушил ПДД меньше, чем водитель " << carFirst.mark << endl;

        }
    }
    cout << "Общее количество штрафов = " << carFirst + carSecond << endl;
}
