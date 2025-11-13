/*
Program pro urceni poctu cisel nesoudelnych s n z mnoziny {1,...,n}:

Pozn.:
    V matematice se tato funkce nazyva Eulerova funkce.
    V informatice je velmi dulezita napr. pro asymetricke sifrovani RSA
    Zajemcum doporucuji si tyto koncepty vyhledat na internetu.

Program se bude skladat ze dvou casti:
    1. Rozklad vstupniho cisla na prvocisla (nevybirejte prilis vysoke cislo, algoritmicky je to velmi narocne vypocitat, viz wiki)
        dulezita pro nas jsou unikatni prvocisla
    2. Vypocet samotne Eulerovy funkce
*/
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Zadej cislo: ";
    cin >> n;
    int out_n = n;
    float output = n;
    int divider = 2;
    bool used = false;
    while(n > 1 && divider * divider <= out_n){ 
        if(n % divider == 0){
            n /= divider;
            if(!used){
                output *= float(1 - (1/(float)divider));
                used = true;
            }
        }
        else{
            
            divider == 2 ? divider++ : divider+=2; //Vime ze prvni prvocislo je 2, ostatni jsou licha, proto pak uz staci mit krok 2
            used = false;
        }
    }
    cout << "Pocet cisel nesoudelnych s " << out_n << " je: " << output << endl;
}