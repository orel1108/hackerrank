#include <iostream>

using namespace std;

int main()
{
    long n, k, b, total = 0, c;
    cin >> n >> k;
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> c;
        if (pos != k)
        {
            total += c;
        }
    }
    
    cin >> b;
    
    if (total >= 2 * b)
    {
        cout << "Bon Appetit" << endl;
    }
    else
    {
        cout << (b - total / 2) << endl;
    }
    
    return 0;
}

