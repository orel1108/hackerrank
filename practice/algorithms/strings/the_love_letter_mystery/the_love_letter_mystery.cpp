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
        unsigned res = 0;
        const int len = s.length();
        const int n = len / 2;
        for (int i = 0; i < n; i++)
        {
            res += abs(static_cast<int>(s[i]) - static_cast<int>(s[len - 1 - i]));    
        }
        cout << res << endl;
    }
    return 0;
}

