#include <string>
#include <iostream>

using namespace std;

int main()
{
    int n, res = 0;
    cin >> n;
    string b;
    cin >> b;
    
    if (n > 2)
    {
        for (int pos = 0; pos < n - 2; ++pos)
        {
            if (b[pos] == '0'     &&
                b[pos + 1] == '1' &&
                b[pos + 2] == '0')
            {
                b[pos + 2] = '1';
                res++;
            }
        }
    }
    
    cout << res << endl;
    
    return 0;
}

