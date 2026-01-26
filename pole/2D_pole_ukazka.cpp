#include <iostream>

static bool Hit(bool* space) {
    if (*space) {
        *space = false;
        return true;
    }
    return false;
}
static bool CheckNeighbors(bool map[4][4], int x, int y) {
    if (x < 3 && map[x + 1][y])
        return false;
    if (y < 3 && map[x][y + 1])
        return false;
    if (x > 0 && map[x - 1][y])
        return false;
    if (y > 0 && map[x][y - 1])
        return false;
    return true;
}
int main()
{
    bool lode[4][4] = { 
        {true, false, false, true},
        {true, true, false, false},
        {false, false, false, true},
        {true, true, true, false}
    };
    int shipCount = 8;
    while (shipCount > 0) {
        printf("Zadej souradnice (ve formatu \"Radek Sloupec\"): ");
        int x, y;
        scanf_s("%d %d", &x, &y);
        if (Hit(&lode[--x][--y])) {
            printf("Zasah!\n");
            shipCount--;
            if (CheckNeighbors(lode, x, y))
                printf("Potopena!\n");
        }
        else {
            printf("Vedle!\n");
        }
        printf("\n");
    }
}
 