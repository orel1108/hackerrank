#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
    int t;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> s;
        
        const size_t n = s.length();
        map<string, int> counter;
        
        for (size_t left = 0; left < n; left++)
        {
            for (size_t right = left + 1; right < n + 1; right++)
            {
                string ss(s.begin() + left, s.begin() + right);
                sort(ss.begin(), ss.end());
                
                auto p = counter.insert(make_pair(ss, 1));
                if (!p.second)
                {
                    counter[ss]++;
                }
            }
        }
        
        int r = 0;
        for (auto p : counter)
        {
            r += p.second * (p.second - 1) / 2;
        }
        cout << r << endl;
    }
    return 0;
}

