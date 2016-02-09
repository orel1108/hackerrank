#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    string s;
    while (t--)
    {
        cin >> s;
        
        const size_t n = s.length();
        if (n % 2 == 1)
        {
            cout << -1 << endl;
        }
        else
        {
            map<char, int> c1, c2;
            for (size_t i = 0; i < n / 2; i++)
            {
                auto p = c1.insert(make_pair(s[i], 1));
                if (!p.second)
                {
                    c1[s[i]]++;
                }
            }
            for (size_t i = n / 2; i < n; i++)
            {
                auto p = c2.insert(make_pair(s[i], 1));
                if (!p.second)
                {
                    c2[s[i]]++;
                }
            }
            
            for (auto p : c1)
            {
                if (c2.find(p.first) != c2.end())
                {
                    c1[p.first] -= c2[p.first];
                }
            }
            
            int pos = 0;
            int neg = 0;
            
            for (auto p : c1)
            {
                if (p.second < 0)
                {
                    neg += p.second;
                }
                else
                {
                    pos += p.second;
                }
            }
            
            int res = max(pos, abs(neg));
            cout << res << endl;
        }
    }
    return 0;
}

