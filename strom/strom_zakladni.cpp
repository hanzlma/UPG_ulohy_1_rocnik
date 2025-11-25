#include <iostream>
using namespace std;
int main()
{
    int K, L;
    cout << "Zadej K: ";
    cin >> K;
    cout << "Zadej L: ";
    cin >> L;
 
    for (int i = 1; i <= K; i++) {
        int tecky = K - i;
        int hvezdicky = 2 * i - 1;
        for (int j = 1; j <= tecky; j++)
            cout << ".";
        for (int j = 1; j <= hvezdicky; j++)
            cout << "*";
        for (int j = 1; j <= tecky; j++)
            cout << ".";
        cout << endl;
    }
    for (int i = 1; i <= L; i++) {
        int tecky = K - 1;
        for (int j = 1; j <= tecky; j++)
            cout << ".";
        cout << "*";
        for (int j = 1; j <= tecky; j++)
            cout << ".";
        cout << endl;
    }
}