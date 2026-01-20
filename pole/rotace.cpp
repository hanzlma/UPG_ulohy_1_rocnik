#include <iostream>
using namespace std;
int main(){
    int count, rotation;
    scanf("%d", &count);
    if (count > 100 || count < 1){
        return 1;
    }
    int vals[100]={};
    for(int i = 0; i < count; i++){
        scanf("%d", &vals[i]);
    }
    scanf("%d", &rotation);
    rotation %= count;
    if (rotation < 0){
        for(int i = -1; i >= rotation; i--){
            int x = vals[count - 1];
            vals[count - 1] = vals[0];
            vals[0] = x;
            for(int j = 0; j < count -2 ; j++){
                int y = vals[j];
                vals[j] = vals[j+1];
                vals[j+1] = y;
            }
        }
    }
    else if (rotation > 0)
    {
        for(int i = 1; i <= rotation; i++){
            int x = vals[count - 1];
            vals[count - 1] = vals[0];
            vals[0] = x;
            for(int j = count - 2; j > 0; j--){
                int y = vals[j];
                vals[j] = vals[j+1];
                vals[j+1] = y;
            }
        }
    }
    
    
    for(int i = 0; i < count; i++){
        printf("%d\n", vals[i]);
    }
}