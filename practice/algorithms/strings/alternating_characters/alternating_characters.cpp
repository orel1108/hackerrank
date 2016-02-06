#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int t;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        const size_t len = s.length();
        
        auto it = unique(s.begin(), s.end());
        s.resize(distance(s.begin(), it));
        
        cout << (len - s.length()) << endl;
    }
    return 0;
}

