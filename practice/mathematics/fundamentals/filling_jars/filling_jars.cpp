#include <iostream>

using namespace std;

int main()
{
    int n, m;
    unsigned long long a, b, k, r;
    
    cin >> n >> m;
    r = 0;
    while (m--)
    {
        cin >> a >> b >> k;
        r += (b - a + 1) * k;
    }
    
    r /= n;
    
    cout << r << endl;
    
    return 0;
}

