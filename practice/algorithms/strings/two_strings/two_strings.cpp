#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main()
{
    int t;
    cin >> t;
    string s1, s2;
    set<char> x, y;
    for (int i = 0; i < t; i++)
    {
        cin >> s1 >> s2;
        
        vector<char> v;
        x = set<char>(s1.begin(), s1.end());
        y = set<char>(s2.begin(), s2.end());
        
        set_intersection(x.begin(), x.end(), y.begin(), y.end(), back_inserter(v));
        if (v.size() > 0)
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

