#include <iostream>

using namespace std;

int main()
{
    unsigned long long n, k = 0;
    cin >> n;
    
    while (n)
    {
        if ((n & 1) == 0)
        {
            k++;
        }
        n >>= 1;
    }
    
    cout << (1ULL << k) << endl;
    
    return 0;
}

