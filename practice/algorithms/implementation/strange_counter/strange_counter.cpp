#include <iostream>

using namespace std;

int main()
{
    unsigned long long t, next_t = 3, add_t = 3;
    cin >> t;
    
    while (next_t < t)
    {
        add_t *= 2;
        next_t += add_t;
    }
    
    cout << (next_t - t + 1) << endl;
    
    return 0;
}

