//Priklad registracniho formulare
//Uzivatel musi opakovat pokus o registraci tolikrat nez splni vsechny pozadavky.
#include <iostream>
#include <string>
using namespace std;

int main(){
    string username, firstPassword, secondPassword;
    
    while(true){
        cout << "Zadej uzivatelske jmeno: ";
        cin >> username;
        cout << "Zadej heslo poprve: ";
        cin >> firstPassword;
        cout << "Zadej heslo podruhe: ";
        cin >> secondPassword;

        if(firstPassword != secondPassword)
            cout << "Hesla se musi shodovat!" << endl;
        else if(firstPassword.length() < 8)
            cout << "Heslo musi mit minimalne 8 znaku!" << endl;
        else if(username.find(firstPassword) != string::npos)
            cout << "Uzivatelske jmeno nesmi obsahovat heslo!" << endl;
        else if(firstPassword.find(username) != string::npos)
            cout << "Heslo nesmi obsahovat uzivatelske jmeno!" << endl;
        else break;
    }
    cout << "Uzivatel uspesne vytvoren!" << endl;
    
}