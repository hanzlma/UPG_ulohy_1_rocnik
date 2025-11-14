#include <iostream>
using namespace std;

int main(){
    int veta;
    cout << "Vyber vetu o konstrukci trojuhelniku:\n1: SSS\n2: SUS\n3: USU\n4:SsU:\n-> ";
    cin >> veta;

    int a, b, c, alfa, beta;

    switch(veta){
        case 1:
        cout << "Zadej strany a, b, c:\na: ";
        cin >> a;
        cout << "b: ";
        cin >> b;
        cout << "c: ";
        cin >> c;

        if(a > 0 && b > 0 && c > 0 && a < b+c && b < a + c && c < a+b)
            cout << "Jde sestrojit";
        else cout << "Nejde sestrojit";
        break;
        
        case 2:
        cout << "Zadej stranu b, uhel alfa ve stupnich, stranu c:\nb: ";
        cin >> b;
        cout << "alfa: ";
        cin >> alfa;
        cout << "c: ";
        cin >> c;

        if(alfa > 0 && b > 0 && c > 0 && alfa < 180)
            cout << "Jde sestrojit";
        else cout << "Nejde sestrojit";
        break;

        case 3:
        cout << "Zadej uhel alfa ve stupnich, stranu c, uhel beta ve stupnich:\nalfa: ";
        cin >> alfa;
        cout << "c: ";
        cin >> c;
        cout << "beta: ";
        cin >> beta;

        if(alfa > 0 && beta > 0 && c > 0 && alfa + beta < 180)
            cout << "Jde sestrojit";
        else cout << "Nejde sestrojit";
        break;

        case 4:
        cout << "Zadej strany a, b, uhel alfa ve stupnich:\na: ";
        cin >> a;
        cout << "b: ";
        cin >> b;
        cout << "alfa: ";
        cin >> alfa;

        if(a > 0 && b > 0 && c > 0 && a > b && alfa < 180)
            cout << "Jde sestrojit";
        else cout << "Nejde sestrojit";
        break;

        default:
        cout << "Neplatny vstup";
    }
}