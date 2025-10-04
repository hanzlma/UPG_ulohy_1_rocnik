#include <iostream>
using namespace std;

int main(){
    int a,b;

    cout << "Zadej 1. cislo: ";
    cin >> a;
    cout << "Zadej 2. cislo: ";
    cin >> b;

    if (a <= 0 || b <= 0){
        cout << "Musis zadat prirozena cisla!";
        return 1;
    }

    while(b){ //dokud b není 0, hodnota 0 je v logickém výrazu rovna false
        int r = a % b;
        a = b;
        b = r;
    }
    cout << "NSD je: " << a << endl;
}