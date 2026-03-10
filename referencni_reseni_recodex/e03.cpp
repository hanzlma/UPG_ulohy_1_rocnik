#include <iostream>

int main(){
    int pocet_a, pocet_b;
    scanf("%d %d", &pocet_a, &pocet_b);
    if(pocet_a > 100 || pocet_b > 100){
        return 1;
    }
    int a[100] = {};
    int b[100] = {};
    int c[200] = {};
    for(int i = 0; i < pocet_a; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < pocet_b; i++){
        scanf("%d", &b[i]);
    }
    for(int i = 0, j = 0, k = 0; i < pocet_a + pocet_b; i++){
        if(k < pocet_b && (a[j] >= b[k] || j >= pocet_a)){
            c[i] = b[k];
            k++;
        }
        else{
            c[i] = a[j];
            j++;
        }
    }
    for(int i = 0; i < pocet_a + pocet_b; i++){
        printf("%d\n", c[i]);
    }
}