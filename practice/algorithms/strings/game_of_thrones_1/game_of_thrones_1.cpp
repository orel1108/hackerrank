#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {
   
    string s;
    cin >> s;
    
    map<char, int> counter;
    for (const auto & c : s)
    {
        if (counter.find(c) == counter.end())
        {
            counter.insert(make_pair(c, 1));
        }
        else
        {
            counter[c]++;
        }
    }
    
    int k = 0;
    for (const auto & p : counter)
    {
        if (p.second % 2 == 1)
        {
            k++;
        }
    }
    
    if (k > 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    
    return 0;
}

