#include <iostream>
#include <fstream>

using namespace std;

struct NOTEBOOK{
    struct clisp_res{
    int х;//горизонаталь
    int у;//vertical
    };
    int f; //частота
    char d[5] = ""; // диагональ
    char hdd[6]= ""; // объем памяти
    char model[21] = ""; // наименование
    char price[5] = "";
    char mass[4] = "";
    char gab[14] = "";
    char hz[4] = "";
    char ozu[3] = "";
    char video[2] = "";
    char x[5] = "";
    char y[5] = "";
    char video_hz[3] = "";
    int cost;
    int iHz;
    
};

int main(){
    string path = "test.txt";
    fstream fin;
    char count[3];
    int MAX = 0;
    char space;
    fin.open(path, fstream :: in | fstream :: out);
    if (fin.is_open()){
        count[0] = fin.get();
        //count[1] = fin.get();
        MAX = atoi(count);
        if (!fin.eof()){
            //получение числа строк
            NOTEBOOK* note = new NOTEBOOK[MAX];
            NOTEBOOK copy;
            int num;
            for (num = 0; num < MAX; num++){
                for ( int p = 0; p < 20; p++){
                    note[num].model[p] = fin.get();
                    }
                for ( int p = 0; p < 4; p++ ){
                    note[num].price[p] = fin.get();
                    }
                note[num].cost = atoi(note[num].price);
                    space = fin.get();
                for (int p = 0; p < 3; p++){//!!
                    note[num].mass[p] = fin.get();
                    }
                    space = fin.get();
                for( int p = 0; p < 14; p++){
                    note[num].gab[p] = fin.get();
                    }
                    space = fin.get();
                for ( int p = 0; p < 3; p++ ){// !!
                    note[num].hz[p] = fin.get();
                    }
                note[num].iHz = atoi(note[num].hz);
                    space = fin.get();
                for ( int p = 0; p < 2; p++){
                    note[num].ozu[p] = fin.get();
                    }
                    space = fin.get();
                for ( int p = 0; p < 4; p++){
                    note[num].d[p] = fin.get();
                    }
                    space = fin.get();
                for ( int p = 0; p < 1; p++){
                    note[num].video[p] = fin.get();
                    }
                    space = fin.get();
                for ( int p = 0; p < 4; p++ ){
                    note[num].x[p] = fin.get();
                    }
                    space = fin.get();
                for ( int p = 0; p < 4; p++ ){
                    note[num].y[p] = fin.get();
                    }
                    space = fin.get();
                for ( int p = 0; p < 2; p++){
                    note[num].video_hz[p] = fin.get();
                    }
                    space = fin.get();
                for ( int p = 0; p < 5; p++){
                    note[num].hdd[p] = fin.get();
                    }
                space = fin.get();
    } // все считано
           for(int i = 0; i < MAX-1; i++)
            {
                for(int j = 0; j < MAX-1; j++)
                {
                    if (note[j].cost > note[j+1].cost)
                    {
                        copy = note[j+1];
                        note[j+1] = note[j];
                        note[j] = copy;
                }
                }
            }
            fin << "------------- sort" << endl;
            for ( int p = 0; p < MAX; p++){
            if (note[p].iHz > 120){
                fin << note[p].model << " " << note[p].price << " " << note[p].mass << " " << note[p].gab << " " << note[p].hz << " "<< note[p].ozu<< " " << note[p].d << " "<< note[p].video << " "<< note[p].x << " "<< note[p].y << " "<< note[p].video_hz << " "<< note[p].hdd << endl;
            }
        }
        
    }
    }
}
