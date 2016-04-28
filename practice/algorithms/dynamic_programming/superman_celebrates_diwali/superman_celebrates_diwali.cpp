#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int n, h, i;
    cin >> n >> h >> i;
    
    vector<vector<int>> t(h + i, vector<int>(n));
    vector<vector<int>> m(h, vector<int>(n));
    string s;
    getline(cin, s);
    for (int cnt = 0; cnt < n; ++cnt)
    {
        getline(cin, s);
        istringstream ss(s);
        
        vector<int> a;
        int val;
        while (ss >> val)
        {
            a.push_back(val);
        }
        
        const int sz = a[0];
        for (int k = 0; k < sz; ++k)
        {
            m[a[k + 1] - 1][cnt] += 1;
        }
    }
    
    vector<pair<int, int>> fmax(h + i);
    for (int f = h - 1; f >= 0; --f)
    {
        for (int b = 0; b < n; ++b)
        {
            if (b != fmax[f].first)
            {
                t[f][b] = m[f][b] + max(t[f + 1][b], fmax[f + i].second);
            }
            else
            {
                vector<int> tmp;
                for (int b1 = 0; b1 < n; ++b1)
                {
                    if (b1 != b)
                    {
                        tmp.push_back(t[f + i][b1]);
                    }
                }
                tmp.push_back(t[f + 1][b]);
                
                t[f][b] = m[f][b] + *max_element(tmp.begin(), tmp.end());
            }
            
            if (t[f][b] > fmax[f].second)
            {
                fmax[f].second = t[f][b];
                fmax[f].first = b;   
            }
        }
    }
    
    cout << *max_element(t[0].begin(), t[0].end()) << endl;
    
    return 0;
}

