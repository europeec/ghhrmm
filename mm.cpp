#include <iostream>
#include <fstream>
#include <string>

using namespace std;
char iToupper(char ch)
{
    return toupper(static_cast<unsigned char>(ch));
}
int main(){
    int i = 0;
    char search[70];
    char temp[70] = "";
    char txt[701] = "";
    fstream fs;
    fs.open("text.txt", fstream :: in | fstream :: out );
    if (!fs.is_open()){
        cout << "Ошибка чтения файла!";
    } else
    {
        while (!fs.eof()) {
            fs.get(txt[i]);
            i++;
            }
        } // весь текст находится в txt[]
        cout << txt << endl;
    cout << "Какое слово вы хотели бы выделить? - ";
    cin >> search;
    int counter = 0;
    int lcounter = 0;
    for ( counter = 0; counter < i; counter++){
        if ( txt[counter] != ' '){
            temp[lcounter] = txt[counter];
            lcounter++;
        } else {
            string word = (string)temp;
            string poisk = (string)search;
            if (poisk == word){
                for ( int k = 0; k < lcounter; k++){
                    temp[k] = iToupper(temp[k]);
                    txt[counter-lcounter+k] = temp[k];
                }
                
            }
            lcounter = 0;
            for (int p = 0; p < 70; p++){
                temp[p] = NULL;
            }
            
        }
         
    }
    cout << txt;
}
