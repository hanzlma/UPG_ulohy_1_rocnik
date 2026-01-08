#include <iostream>

int main()
{
    int dayCount;
    scanf("%d", &dayCount);
    if (dayCount < 28 || dayCount > 31) {
        printf("Error - days");
        return 1;
    }
    float temperatures[31]{};
    for (int i = dayCount - 1; i >= 0; i--) {
        scanf("%f", &temperatures[i]);
        if (temperatures[i] < 150 || temperatures[i] > 350) {
            printf("Error - temperature");
            return 2;
        }
        temperatures[i] -= 273.15f;
    }
    for (int i = 0; i < dayCount; i++) {
        printf("%.2f\n", temperatures[i]);
    }
}