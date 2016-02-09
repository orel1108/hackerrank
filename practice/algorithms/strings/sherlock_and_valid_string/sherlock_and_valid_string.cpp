#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    map<char, int> counter;
    for (auto c : s)
    {
        auto p = counter.insert(make_pair(c, 1));
        if (!p.second)
        {
            counter[c]++;
        }
    }
    
    vector<int> freq;
    set<int> f;
    for (auto p : counter)
    {
        freq.push_back(p.second);
        f.insert(p.second);
    }
    
    if (f.size() == 1)
    {
        cout << "YES" << endl;
    }
    else if (f.size() > 2)
    {
        cout << "NO" << endl;
    }
    else
    {
        sort(freq.begin(), freq.end());
        const size_t n = freq.size();
        if (freq[n - 1] - freq[n - 2] == 1)
        {
            cout << "YES" << endl;
        }
        else if (freq[0] == 1 && freq[1] > 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    
    
    return 0;
}

