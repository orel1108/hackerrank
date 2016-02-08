#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_palindrome(const string & s)
{
    const size_t n = s.length();
    size_t pos = 0;
    while (pos < n / 2 && s[pos] == s[n - pos - 1])
    {
        pos++;
    }
    if (pos == n / 2)
    {
        return true;
    }
    return false;
}

int main() {
    
    int t;
    cin >> t;
    
    string s;
    for (int i = 0; i < t; i++)
    {
        cin >> s;
        const size_t n = s.length();
        size_t pos = 0;
        while (pos < n / 2 && s[pos] == s[n - pos - 1])
        {
            pos++;
        }
        if (pos == n / 2)
        {
            cout << -1 << endl;
        }
        else
        {
            string s1;
            for (size_t opos = 0; opos < n; opos++)
            {
                if (opos != pos)
                {
                    s1 += s[opos];
                }
            }
            if (is_palindrome(s1))
            {
                cout << pos << endl;
            }
            else
            {
                cout << (n - pos - 1) << endl;
            }
        }
    }
    return 0;
}

