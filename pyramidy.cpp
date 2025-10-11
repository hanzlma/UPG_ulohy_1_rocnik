//Program pro výpočet potřebných kostek pro n pater 2D/3D pyramidy.
//n-té patro má hranu o délce n kostek

#include <iostream>
using namespace std;

int main(){
    int n, d, total; // n = počet pater, d = dimenze (očekáváme pouze 2 nebo 3, zbytek chybný vstup), total = výsledný počet kostek
    cout << "Zadej pocet dimenzi (2 nebo 3): ";
    cin >> d;
    if(d != 2 && d != 3){
        cout << "Nespravny vstup pro pocet dimenzi!";
        return 1;
    }
    cout << "Zadej pocet pater pyramidy: ";
    cin >> n;
    total = 0;
    if(n < 0){
        cout << "Nelze mit zaporny pocet pater!";
        return 2;
    }
    else if (n)
        for(int i = 1; i <= n; i++)
            total += pow(i, d-1);
        
    cout << "Potrebny pocet kostek pro " << d << "D pyramidu o " << n << " patrech je: " << total << endl;
}