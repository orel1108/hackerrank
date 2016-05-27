#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n, x, y, q;
    
    cin >> n;
    
    vector<int> a(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> a[pos];
    }
    
    cin >> q;
    while (q--)
    {
        cin >> x >> y;
        if (x == y)
        {
            if (a[x - 1] % 2 == 1)
            {
                cout << "Odd" << endl;
            }
            else
            {
                cout << "Even" << endl;
            }
        }
        else
        {
            if (a[x - 1] % 2 == 0 && a[x] != 0)
            {
                cout << "Even" << endl;
            }
            else
            {
                cout << "Odd" << endl;
            }
        }
    }
    
    return 0;
}

