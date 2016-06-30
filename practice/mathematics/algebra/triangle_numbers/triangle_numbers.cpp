#include <iostream>

using namespace std;

int main()
{
    int t, n;
    
    cin >> t;
    while (t--)
    {    
        cin >> n;
        if (n % 2 == 1)
        {
            cout << 2 << endl;
        }
        else if(n % 4 == 0)
        {
            cout << 3 << endl;
        }
        else
        {
            cout << 4 << endl;
        }
    }

    return 0;
}

