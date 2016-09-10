#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int count_less_then(const vector<int> & i_q)
{
    int res = 0;
    for (int pos = i_q.size() - 1; pos >= 0; --pos)
    {
        if (i_q[pos] - 1 - pos > 2)
        {
            return -1;
        }
        for (int opos = max(0, i_q[pos] - 2); opos < pos; ++opos)
        {
            if (i_q[pos] < i_q[opos])
            {
                res++;
            }
        }
    }
    
    return res;
}

int main()
{
    int t, n, res;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> q(n);
        for (int pos = 0; pos < n; ++pos)
        {
           cin >> q[pos];
        }
        
        res = count_less_then(q);
        if (res >= 0)
        {
            cout << res << endl;
        }
        else
        {
            cout << "Too chaotic" << endl;    
        }
        
    }
    
    return 0;
}

