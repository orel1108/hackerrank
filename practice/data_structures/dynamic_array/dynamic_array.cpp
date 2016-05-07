#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, q;
    int a, x, y;
    int last = 0;
    
    cin >> n >> q;
    
    vector<vector<int>> seq(n, vector<int>());
    while (q--)
    {
        cin >> a >> x >> y;
        
        int pos = (x ^ last) % n;
        if (a == 1)
        {
            seq[pos].push_back(y);
        }
        else
        {
            last = seq[pos][y % seq[pos].size()];
            cout << last << endl;
        }
    }
    return 0;
}

