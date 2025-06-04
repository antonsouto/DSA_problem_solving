#include <iostream>

using namespace std;

int closestNumber(int n, int m)
{
    int differencePos = 0;
    int differenceNeg = 0;
    int aux = n;
    while (aux % m != 0)
    {
        aux = aux + 1;
        differencePos += 1;
    }
    int aux2 = n;
    while (aux2 % m != 0)
    {
        aux2 = aux2 - 1;
        differenceNeg += 1;
    }
    if (differenceNeg < differencePos)
    {
        return aux;
    }
    else
        return aux2;
}