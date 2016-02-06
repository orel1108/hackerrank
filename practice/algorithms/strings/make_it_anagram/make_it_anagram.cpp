#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

map<char, int> counter(const string & s)
{
    map<char, int> m;
    for (auto c : s)
    {
        auto ir = m.insert(make_pair(c, 1));
        if (!ir.second)
        {
            m[c]++;
        }
    }
    
    return m;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    
    map<char, int> count_1 = counter(s1);
    map<char, int> count_2 = counter(s2);
    
    int res = 0;
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (count_1.find(c) != count_1.end() && count_2.find(c) != count_2.end())
        {
            res += abs(count_1[c] - count_2[c]);
        }
        else if (count_1.find(c) != count_1.end())
        {
            res += count_1[c];
        }
        else if (count_2.find(c) != count_2.end())
        {
            res += count_2[c];
        }
    }
    
    cout << res << endl;
    
    return 0;
}

