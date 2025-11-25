#include <iostream>
using namespace std;
int main()
{
    int k, l;
    cout << "Zadej k: ";
    cin >> k;
    cout << "Zadej l: ";
    cin >> l;
    string prvni_radek;
    for (int i = 1; i <= k; i++) {
        string tecky = "";
        for (int j = 0; j < (k - i); j++) {
            tecky += ".";
        }
        string hvezdicky = "*";
        for (int j = 1; j < i; j++)
            hvezdicky += "**";
        if (i == 1)
            prvni_radek = tecky + hvezdicky + tecky;
        cout << tecky << hvezdicky << tecky << endl;
    }
    for (int i = 1; i <= l; i++)
        cout << prvni_radek << endl;
}