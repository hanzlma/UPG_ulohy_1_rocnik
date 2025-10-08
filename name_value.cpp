//Program pro výpočet celkové "hodnoty" jména a průměrné hodnoty na znak

#include <iostream>

using namespace std;

int main(){
    string name;
    int value = 0;

    cout << "Zadej jmeno: ";
    cin >> name;
    
    for(char c: name){
        c = toupper((unsigned char) c); // Pro konzistenci prevedeme všechna písmena na velká
        value += int(c);
    }
    cout << "Celkova hodnota jmena "<< name <<" je: " << value << endl;
    cout << "Prumerna hodnota znaku v tomto jmene je: " << (float)(value / name.length()) << endl;
}