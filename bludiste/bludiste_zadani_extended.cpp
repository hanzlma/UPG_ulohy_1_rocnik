#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

vector<vector<char> > ReadMap();
char GetMovementInput(vector<vector<char> > map);
bool CheckMovementDirection(vector<vector<char> > map, char move, bool* gameLoop);
void MovePlayerDirection(vector<vector<char> >* map, char move);
void PrintInfo(); 

// Definice, co který znak představuje v bludišti.
// Můžete libovolně upravit, musíte pak ale podle toho upravit i bludiště.
const char PLAYER_CHARACTER = 'P';
const char START_CHARACTER = 'S';
const char END_CHARACTER = 'K';
const char WALL_CHARACTER = 'X';
const char EMPTY_CHARACTER = ' ';

// Definice, který znak na vstupu představuje jaký pohyb
// Můžete libovolně upravit :)
const char MOVEMENT_UP = 'w';
const char MOVEMENT_DOWN = 's';
const char MOVEMENT_LEFT = 'a';
const char MOVEMENT_RIGHT = 'd';

enum Direction{
    //Tato struktura pro přehlednost umožňuje místo číselných hodnot používat námi určené názvy.
    UP,
    DOWN,
    LEFT,
    RIGHT
};
class Position{
    // Tato struktura zvyšuje přehlednost určení pozice na mapě. V podstatě jde o dva indexy.
    public:
        int line = 0;
        int column = 0;
};

int main(){
    vector<vector<char> > map = ReadMap(); // Načtení mapy ze zdrojového textového souboru.
    bool loop = true;
    while(loop){
        char move = GetMovementInput(map);
        if(CheckMovementDirection(map, move, &loop))
            MovePlayerDirection(&map, move);
    }
    cout << "Uspesne jsi prolezl bludiste!" << endl;
}
void PrintInfo(){
    /*
    Úkol: V této metodě implementujte výpis:
        1. Co jaký znak v bludišti představuje 
        2. Jak se bludiště ovládá
        Pozn.: K výpisu využívejte konstanty pro tyto účely definované na počátku souboru. (nepoužívejte přímo hodnoty, např. 'A')

    */
}
void PrintMap(vector<vector<char> > map){
    for(vector<char> line: map){
        for(char c: line){
            switch (c){
                case START_CHARACTER:
                    cout << "\033[32m"<< c << "\033[0m";
                    break;
                case END_CHARACTER:
                    cout << "\033[31m"<< c << "\033[0m";
                    break;
                case PLAYER_CHARACTER:
                    cout << "\033[34m"<< c << "\033[0m";
                    break;
                default:
                    cout << c;
                    break;
            }
        }
        cout << endl;
    }
}

char GetMovementInput(vector<vector<char> > map){
    #if _WIN32 || _WIN64 || __CYGWIN
        system("cls");
    #else
        system("clear");
    #endif
    PrintMap(map);
    cout << "Zadej pohyb: ";
    char move;
    cin >> move;
    return move;
}

vector<vector<char> > ReadMap(){
    /*
        Úkol (těžší):
            Zparametrizujte tuto metodu tak, aby uživatel mohl načíst libovolný textový soubor obsahující mapu.
            (abychom mohli mít více map, které si lze zahrát)
    */
    vector<vector<char> > map;
    string line;
    ifstream mapFile("./mapa.txt");
    while(getline(mapFile, line)){
        vector<char> row;
        for(char c: line){
            row.push_back(c);
        }
        map.push_back(row);
    }
    mapFile.close();
    return map;
}


Position GetPosition(vector<vector<char> > map, char type){
    Position position;
    bool brk = false;
    for(; position.line < map.size(); position.line++){
        position.column = 0;
        for(; position.column < map[position.line].size(); position.column++)
            if (map.at(position.line).at(position.column) == type){
                brk = true;
                break;
            }
        if (brk)
            break;
    }
    return position;
}
bool CheckPosition(vector<vector<char> > map,bool* gameLoop, Position position){
    if(map.at(position.line).at(position.column) == EMPTY_CHARACTER)
        return true;
    else if (map.at(position.line).at(position.column) == END_CHARACTER)
    {
        *gameLoop = false;
        return false;
    }
    else return false;
    
}
bool CheckMove(vector<vector<char> > map, bool* gameLoop, int direction){
    Position playerPosition = GetPosition(map, PLAYER_CHARACTER);
    Position movePosition = Position();
    /*
        Úkol:
            Implementujte switch, který přiřadí proměnné movePosition (definice na počátku souboru) pozici,
            kam se chce hráč přesunout.
    */
    return CheckPosition(map, gameLoop, movePosition);
}

bool CheckMovementDirection(vector<vector<char> > map, char move, bool* gameLoop){
    Direction direction;
    /*
        Úkol:
            Implementujte switch, ve kterém se proměnné direction (definice na počátku souboru) přiřadí směr
            podle zadaného znaku uživatelem.
    */
    return CheckMove(map, gameLoop, direction);
}
void MovePlayer(vector<vector<char> >* map, int direction){
    Position playerPosition = GetPosition(*map, PLAYER_CHARACTER);
    
    switch(direction){
        case 0:
            swap((*map).at(playerPosition.line).at(playerPosition.column), (*map).at(playerPosition.line - 1).at(playerPosition.column));
            break;
        case 1:
            swap((*map).at(playerPosition.line).at(playerPosition.column), (*map).at(playerPosition.line + 1).at(playerPosition.column));
            break;
        case 2:
            swap((*map).at(playerPosition.line).at(playerPosition.column), (*map).at(playerPosition.line).at(playerPosition.column - 1));
            break;
        case 3:
            swap((*map).at(playerPosition.line).at(playerPosition.column), (*map).at(playerPosition.line).at(playerPosition.column + 1));
            break;
        default:
            return;
    }
}
void MovePlayerDirection(vector<vector<char> >* map, char move){
    Direction direction;
    /*
        Úkol:
            Implementujte switch, ve kterém se proměnné direction (definice na počátku souboru) přiřadí směr
            podle zadaného znaku uživatelem.
    */
    MovePlayer(map, direction);
}