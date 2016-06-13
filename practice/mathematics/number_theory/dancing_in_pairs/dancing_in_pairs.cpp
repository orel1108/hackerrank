#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int t;
    unsigned long long n, a;
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        a = static_cast<unsigned long long>(sqrt(n));
        if (a * a > n)
        {
            a--;
        }
        
        if (a % 2 == 0)
        {
            cout << "even" << endl;
        }
        else
        {
            cout << "odd" << endl;
        }
    }
    
    return 0;
}

