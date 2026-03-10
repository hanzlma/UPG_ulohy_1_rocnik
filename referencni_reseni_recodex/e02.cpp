#include <iostream>

int main() {
    int max1 = 0;
    int max2 = 0;
    int val = 0;
    int prev = 0;
    int counter = 0;
    

    while (val != -1) {
        if (counter == 0) {
            std::cin >> val;
            max1 = val;
            prev = val;
            counter++;
            continue;
        }
        
        if (counter == 1) {
            while (prev == val) {
                std::cin >> val;
                if (val > max1) {
                    max2 = max1;
                    max1 = val;
                } else if (val < max1) {
                    max2 = val;
                }
            }
            counter++;
            prev = val;
            continue;
        }
        
        std::cin >> val;
        
        if (val == -1) {
            break;
        }
        
        if (val > max1) {
            max2 = max1;
            max1 = val;
        } else if (val > max2 && val != max1) {
            max2 = val;
        }
    }

    std::cout << max2 << std::endl;

    return 0;
}