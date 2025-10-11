#include <iostream>
using namespace std;    

int main(){
    string s;
    cout << "Zadej retezec: ";
    getline(cin, s);
    string reversed = "";
    for (int i = s.length() - 1; i >= 0; --i)//otoceni znakoveho retezce
        reversed += s[i];
    s = reversed;
    for (int i = 0; i < s.length(); i++){ // Prochazime kazdy znak retezce
        if(!isalpha((unsigned char) s[i])) //pokud neni pismeno, preskocime
            continue;
        if (i%2 == 0)
            s[i] = toupper((unsigned char) s[i]); //prevedeni na velka pismena
        
        else
            s[i] = tolower((unsigned char) s[i]); //prevedeni na mala pismena
    }
    cout << "Vysledek: " << s << endl;
}