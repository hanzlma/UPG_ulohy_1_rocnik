#include <string>
#include <iostream>

bool IsPerfect(const int &cislo)
{
    int sum = 0;
    for (int i = 1; i < cislo; i++)
    {
        sum += (cislo % i == 0) ? i : 0;
    }
    return sum == cislo;
}

bool IsSquare(const int &cislo)
{
    for (int i = 1; i * i <= cislo; i++)
    {
        if (i * i == cislo)
        {
            return true;
        }
    }
    return false;
}

bool IsQube(const int &cislo)
{
    for (int i = 1; i * i * i <= cislo; i++)
    {
        if (i * i * i == cislo)
        {
            return true;
        }
    }
    return false;
}

std::string GetPerfectString(const int &cislo)
{
    std::string result = "";
    if (IsPerfect(cislo))
        result += 'P';
    if (IsSquare(cislo))
        result += 'C';
    if (IsQube(cislo))
        result += 'K';
    return result;
}

int main()
{
    int x;
    std::cin >> x;
    std::cout << GetPerfectString(x) << std::endl;
}