#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, color, left = 0;
    cin >> n;
    
    map<int, int> counter;
    for (int c = 0; c < n; ++c)
    {
        cin >> color;
        counter[color]++;
    }
    
    for (map<int, int>::const_iterator it = counter.begin(); it != counter.end(); ++it)
    {
        left += it->second % 2;
    }
    
    cout << (n - left) / 2 << endl;
    
    return 0;
}

