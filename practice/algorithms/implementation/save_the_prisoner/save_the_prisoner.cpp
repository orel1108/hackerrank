#include <iostream>

using namespace std;

int main()
{
    int t;
    unsigned n, m, s, r;
    
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> s;
        r = (m + s - 1) % n;
        cout << (r == 0 ? n : r) << endl;
    }
    
    return 0;
}

