#include <iostream>
#include <iomanip>
#include <cmath>
constexpr double PI = 3.14159;

void zobrazMenu()
{
    std::cout << "--- GEOMETRICKA KALKULACKA ---\n1. Kruh\n2. Obdelnik\n3. Konec\nVyberte moznost: ";
}
double obvod(double r)
{
    return 2 * PI * r;
}
double obvod(double a, double b)
{
    return 2 * (a + b);
}
void obsah(double r, double &s)
{
    s = PI * r * r;
}
void obsah(double a, double b, double &s)
{
    s = a * b;
}
void calcSwitch(int &repeat)
{
    int option;
    std::cin >> option;
    double o, s;
    std::cout << std::fixed << std::setprecision(4);
    switch (option)
    {
    case 1:
        std::cout << "Zadejte polomer kruhu: ";
        double r;
        std::cin >> r;
        o = obvod(r);
        obsah(r, s);
        std::cout << "Obsah kruhu je: " << s << "\nObvod kruhu je: " << o << std::endl;
        break;
    case 2:
        std::cout << "Zadejte sirku obdelniku: ";
        double a, b;
        std::cin >> a;
        std::cout << "Zadejte vysku obdelniku: ";
        std::cin >> b;
        o = obvod(a, b);
        obsah(a, b, s);
        std::cout << "Obsah obdelniku je: " << s << "\nObvod obdelniku je: " << o << std::endl;

        break;
    case 3:
        repeat = 0;
        return;
    }
}
int main()
{
    int repeat = 1;
    do
    {
        zobrazMenu();
        calcSwitch(repeat);
    } while (repeat);
    std::cout << "Ukoncuji program..." << std::endl;
}