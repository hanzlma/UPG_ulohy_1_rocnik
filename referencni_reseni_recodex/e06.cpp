#include <iostream>
using namespace std;

bool readMatrix(int rows, int cols, int matrix[100][100]){
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if (!(cin >> matrix[i][j])) return false;
    return true;
}
int main(){
    int matrix1[100][100]={};
    int matrix2[100][100]={};
    int matrix3[100][100]={};
    int r1, c1, r2, c2;

    if (!(cin >> r1 >> c1)) return 1;
    if (c1 > 100 || r1 > 100) return 1;
    readMatrix(r1, c1, matrix1);
    
    if (!(cin >> r2 >> c2)) return 1;
    if (c2 > 100 || r2 > 100) return 1;
    if (c1 != r2) {
        cout << "nelze" << endl;
        return 2;
    }
    readMatrix(r2, c2, matrix2);

    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            int sum = 0;
            for(int k = 0; k < c1; k++){
                sum += matrix1[i][k] * matrix2[k][j];
            }
            matrix3[i][j] = sum;
        }
    }
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++)
            cout << matrix3[i][j] << (j == c2 - 1 ? "" : " ");
        cout << endl;
    }
}