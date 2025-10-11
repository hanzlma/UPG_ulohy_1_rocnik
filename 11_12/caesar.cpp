#include <iostream>
using namespace std;

int main(){
    string text = "YRC DFJBW FCNZIGHW HIHC GWTFI NWGYO XSRBWQYI NO DFOQW J VCRWBS";
    
    for (int i = 1; i < 26; i++){
        for(char &c: text){
            if(c >= 'A' && c <= 'Z'){
                c = (c - 'A' - i + 26) % 26 + 'A'; // posunuti znaku o i zpet, +26 zajisti spravny vysledek i pro i > posunuti
            }
        }
        cout << "Posun o " << i << ": " << text << endl;
        text = "YRC DFJBW FCNZIGHW HIHC GWTFI NWGYO XSRBWQYI NO DFOQW J VCRWBS"; // reset textu
    }
}