
#include <iostream>
using namespace std;
int main()
{
    // 1. inicializace prazdneho pole
    float lengths[10]{};

    //2. inicializace pole s hodnotami
    int coins[] = { 1, 2, 5, 10, 20, 50 }; // velikost pole 6

    //3. inicializace pole jen s nekterymi hodnotami
    int points[10] = { 100, 200, 500 }; // velikost pole 10

    //4. pristup k prvku
    cout << coins[2]; // vypise cislo 5 (3. prvek pole coins)
    cout << endl << endl;

    //5. prirazeni hodnoty
    points[3] = 50;
    points[0] += 100; // prvek funguje jako normalni promenna

    //6. pruchod prvku pole
    for (int i = 0; i < 6; i++) { // nastavenim pocatecniho a koncoveho indexu lze urcit ktere prvky projdu
        cout << coins[i] << endl;
    }
    cout << endl;
    //nebo
    for (int coin : coins) { // projde vzdy vsechny prvky pole
        cout << coin << endl;
    }
    cout << endl;
    //7. zjisteni velikosti pole
    cout << "Velikost pole coins: ";
    cout << (sizeof(coins) / sizeof(coins[0]));
}
 