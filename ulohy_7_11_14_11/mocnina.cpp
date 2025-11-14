#include <iostream>
using namespace std;

int main(){
    int x,n;
    cout << "Zadej n: ";
    cin >> n;
    cout << "Zadej x: ";
    cin >> x;
    if(x < 0 || n < 0)
        cout << "Spatny vstup!";
    else{
        while(!(x % n))
            x /= n;
        cout << (x == 1 ? "Je mocnina" : "Neni mocnina");
    }
}