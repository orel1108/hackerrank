#include <vector>
#include <iostream>

using namespace std;

int solve(const vector<int> & i_c, int i_n, int i_pos)
{
    if (i_pos < i_n - 1)
    {
        int next_pos = i_pos + 1;
        if (i_pos < i_n - 2 && i_c[i_pos + 2] == 0)
        {
            next_pos++;
        }
        return 1 + solve(i_c, i_n, next_pos);
    }
    
    return 0;
}

int main()
{
    int n;
    cin >> n;
    vector<int> c(n);
    for (int pos = 0; pos < n; ++pos)
    {
       cin >> c[pos];
    }
    
    cout << solve(c, n, 0) << endl;
    
    return 0;
}

