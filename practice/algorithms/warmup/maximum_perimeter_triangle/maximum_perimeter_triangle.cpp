#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct TriangleSides
{
    unsigned l1, l2, l3;
};

int main()
{
    int n;
    cin >> n;
    
    vector<unsigned> l(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> l[pos];
    }
    
    sort(l.begin(), l.end(), greater<unsigned>());
    
    bool found_triangle = false;
    TriangleSides res;
    for (int pos = 0; pos < n - 2; ++pos)
    {
        if (l[pos] < (l[pos + 1] + l[pos + 2]))
        {
            found_triangle = true;
            res.l1 = l[pos + 2];
            res.l2 = l[pos + 1];
            res.l3 = l[pos];
            break;
        }
    }
    
    if (found_triangle)
    {
        cout << res.l1 << " " << res.l2 << " " << res.l3 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    
    return 0;
}

