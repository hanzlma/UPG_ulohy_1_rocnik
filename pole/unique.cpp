#include <iostream>

int main(){
    int count;
    scanf("%d", &count);
    if(count > 100){
        return 1;
    }
    int a[100] = {};
    int b[100] = {};
    for(int i = 0; i < count; i++){
        scanf("%d", &a[i]);
    }
    int unique_count = 0;
    for(int i = 0; i < count; i++){
        bool add = true;
        for(int k = 0; k <= unique_count; k++){
            if(b[k] == a[i]){
                add = false;
                break;
            }
        }
        if(add){
            b[unique_count] = a[i];
            unique_count++;
        }
    }
    for(int i = 0; i < unique_count; i++){
        printf("%d\n", b[i]);
    }
    
}