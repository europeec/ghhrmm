#include <iostream>
using namespace std;
int main(){
 int i,j;
    cout << "Введите размерность матрицы: ";
    cin >> i;
    j = i;
    int min_dia = INT_MAX;
    int* dia_str = new int [i];
    int* dia_stlb = new int [i];
    int* t_summ = new int[i];
    int* max_summ = new int [i];
    int** arr = new int*[i];
// СОБСНА ВВОД ЭЛЕМЕНТОВ
      for ( int c = 0; c < i; c++){
            arr[c] = new int[j];
                }
    for ( int str = 0; str < i; str ++){
      t_summ[str] = 0;
      max_summ[str] = 0;
        for ( int stlb = 0; stlb < j; stlb++ ){
            cout << "\nВведите элемент " << str + 1 << " строки и " << stlb + 1 << " столбца: ";
            cin >> arr[str][stlb];
            t_summ[str] += arr[str][stlb];
            max_summ[str] += abs(arr[str][stlb]);
      }
    }
    // CHECK
    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[0][2] = 3;
    arr[1][0] = 4;
    arr[1][1] = 5;
    arr[1][2] = 6;
    arr[2][0] = 7;
    arr[2][1] = 8;
    arr[2][2] = 9;
    cout << " \n\n\n\n\n\n\n\n\n\t\t\t\tIN PROCESSING..";
// ПРОВЕРКА СТРОКИ НА НАЛИЧИЕ ОТКРИЦАТЕЛЬНЫХ ЭЛЕМЕНТОВ И ВЫВОД
    int count_positive = 0;
    for ( int str = 0; str < i; str ++){
        if ( t_summ[str] == max_summ[str]) {
            cout << "\n\tСумма элементов в " << str + 1 << " строке = " << t_summ[str];
            count_positive++;
        }
    }
    if ( count_positive == 0 ){
        cout << "\n\t\t\tERROR";
        cout << "\n\tНе найдено строк, в которых не было бы отрицательных элементов :с ";
    }
// ПОДСЧЕТ СУММЫ НА ДИАГОНАЛЯХ
    for ( int k = 0; k < i; k++){
        int doubler = k;
        int temp = 0;
        dia_stlb[k] = dia_str[k] = 0;
        while ( doubler < i  ){
            dia_stlb[k] += arr[temp][doubler];
            dia_str[k] += arr[doubler][temp];
            temp++;
            doubler++;
        }
    }
 // ПОИСК НАИМЕНЬШЕГО СРЕДИ СУММ ДИАГОНАЛЕЙ
    for ( int k = 0; k < i-1; k ++){
        if ( dia_stlb[k] < dia_str[k]){
            if (dia_stlb[k] < min_dia){
                min_dia = dia_stlb[k];
            }
        } else {
            if (dia_str[k] < min_dia){
                min_dia = dia_str[k];
            }
        }
    }
    cout << "\n\tМинимамльная сумма элементов на диагонали = " << min_dia << endl;
    return 5; // <- оценка кста ))0))
}

