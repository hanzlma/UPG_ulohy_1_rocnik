#include <iostream>
#include <stdio.h>
int main(){
    int N, new_val;
    int values[100] = {};
    scanf("%d", &N);
    if(N > 99 || N < 1){
        return 1;
    }
    for(int i = 0; i < N; i++){
        scanf("%d", &values[i]);
    }
    scanf("%d", &new_val);
    bool found = false;
    for(int i = 0; i < N; i++){
        if(found){
            int x = values[i];
            values[i] = new_val;
            new_val = x;
        }
        if(values[i] <= new_val && values[i+1] >= new_val)
            found = true;
    }
    values[N] = new_val;
    for(int i = 0; i <= N; i++){
        printf("%d\n", values[i]);
    }
}