#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    long long n;
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long k = (long long)sqrt(2 * n);
        while (k * (k + 1) < 2 * n)
        {
            k++;
        }
        if (k * (k + 1) == 2 * n)
        {
            cout << "Go On Bob " << k << endl;
        }
        else
        {
            cout << "Better Luck Next Time" << endl;   
        }
    }
    
    return 0;
}

