#include <iostream>
#include <cmath>
using namespace std;

struct bod{
    double x;
    double y;
};

double euklidovskaVzdalenost(const bod& A, const bod& B){
    return sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
}

bod stredUsecky(const bod& A, const bod& B){
    bod C;
    C.x = (A.x + B.x) / 2;
    C.y = (A.y + B.y) / 2;
    return C;
}

int main(){
    bod A,B;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cout << euklidovskaVzdalenost(A, B) << endl;
    bod C = stredUsecky(A, B);
    cout << C.x << " " << C.y << endl;
}