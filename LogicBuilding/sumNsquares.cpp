#include <iostream>

using namespace std;

int64_t sumNsquares(int n)
{
    if (n == 0)
    {
        return 0;
                
    }
    else
    {
         return (n * n + sumNsquares(n - 1));
        
    }
}
