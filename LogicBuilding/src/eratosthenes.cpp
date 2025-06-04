#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
typedef vector<int> vec;

bool isPrime(int);
vec extractPrimes(vec);
vec includeNumbers(int);
void SieveOfEratosthenes(int);

int main()
{
    int n = 30;
    SieveOfEratosthenes(n);
    return 0;
}

void SieveOfEratosthenes(int n)
{
    vec total = includeNumbers(n);
    vec primos = extractPrimes(total);
    cout << "Los primos en los primeros " << n << " numeros son: ";
    for (const auto &a : primos)
    {
        cout << a << " ,";
    }
    cout << ".";
}

vec includeNumbers(int n)
{
    int aux = 2;
    vec vector;
    while (aux <= n)
        vector.push_back(aux++);
    return vector;
}

vec extractPrimes(vec total)
{
    int length = total.size();
    int maxIter = sqrt(length);
    int iter = 2;
    vec toCheck;

    // Primero introduzco todos los primos menores de raiz del total para eliminar los múlitplos luego
    for (int a = 2; a <= maxIter; a++)
    {
        if (isPrime(a))
            toCheck.push_back(a);
    }

    for (auto it = total.begin(); it != total.end();)
    {
        bool eliminar = false;

        // Solo elimio si el elemento no está en toCheck y es múltiplo de este
        for (auto &a : toCheck)
        {
            if (*it != a && *it % a == 0)
                eliminar = true;
        }

        if (eliminar)
        {
            it = total.erase(it); // al eliminar el elemento it apunta al siguiente, solo vale total.end() cuando se sale del vector tras evaluar el último elemento
        }
        else
        {
            it++;
        }
    }

    return total;
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}