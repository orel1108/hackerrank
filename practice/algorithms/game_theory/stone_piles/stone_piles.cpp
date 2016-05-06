#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>

using namespace std;

map<int, set<set<int>>> find_decomp(int i_n)
{
    map<int, set<set<int>>> d;
    set<int> x;
    x.insert(1);
    d[1].insert(x);
    for (int val = 2; val < i_n + 1; ++val)
    {
        x.clear();
        x.insert(val);
        d[val].insert(x);
        for (int k = 1; k < (val + 1) / 2; ++k)
        {
            x.clear();
            x.insert(k);
            x.insert(val - k);
            
            set<set<int>>::iterator L, R;
            L = d[k].begin();
            for (; L != d[k].end(); ++L)
            {
                R = d[val - k].begin();
                for (; R != d[val - k].end(); ++R)
                {
                    x.clear();
                    set_union(L->begin(), L->end(), R->begin(), R->end(), inserter(x, x.begin()));
                    int s = accumulate(x.begin(), x.end(), 0);
                    if (s == val)
                    {
                        d[val].insert(x);
                    }
                }
            }
        }
    }
    
    return d;
}

vector<int> grundy(int i_n, const map<int, set<set<int>>> & i_decomp)
{
    vector<int> res(i_n + 1);
    for (int val = 3; val < i_n + 1; ++val)
    {
        set<int> s;
        set<set<int>>::const_iterator it = i_decomp.at(val).begin();
        for (; it != i_decomp.at(val).end(); ++it)
        {
            if (it->size() > 1)
            {
                int x = 0;
                set<int>::const_iterator sit = it->begin();
                for (; sit != it->end(); ++sit)
                {
                    x ^= res[*sit];
                }
                s.insert(x);
            }
        }
        while (s.find(res[val]) != s.end())
        {
            res[val]++;
        }
    }
    
    return res;
}

int main()
{
    const int maxn = 50;
    map<int, set<set<int>>> decomp = find_decomp(maxn);
    vector<int> gr = grundy(maxn, decomp);
    
    int t, n;
    cin >> t;
    
    while (t--)
    {
        cin >> n;
        
        vector<int> a(n);
        for (int pos = 0; pos < n; ++pos)
        {
            cin >> a[pos];
        }
        
        int x = accumulate(a.begin(), a.end(), 0, [&gr](int v, int w) { return v ^ gr[w]; });
        if (x == 0)
        {
            cout << "BOB" << endl;
        }
        else
        {
            cout << "ALICE" << endl;
        }
    }
    
    return 0;
}

