#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n, k, h, e, start;
    cin >> n >> k;
    vector<int> cloud(n);
    for (int pos = 0; pos < n; ++pos)
    {
       cin >> cloud[pos];
    }
    
    h = n / k;
    e = 100 - h;
    for (int pos = 1; pos <  h; ++pos)
    {
        e -= 2 * cloud[pos * k];
    }
    
    if (cloud[0])
    {
        e -= 2;
    }
    
    cout << e << endl;
    
    return 0;
}

