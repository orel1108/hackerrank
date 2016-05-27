#include <vector>
#include <iostream>

using namespace std;

const long long MOD = 1000000000;

vector<vector<long long>> triangle(int i_n)
{
    vector<vector<long long>> pascal;
    pascal.push_back(vector<long long>(2, 1));
    
    for (int cnt = 0; cnt < i_n; ++cnt)
    {
        vector<long long> b(1, 1);
        vector<long long> last = pascal.back();
        for (int pos = 0; pos < last.size() - 1; ++pos)
        {
            long long d = last[pos] + last[pos + 1];
            d %= MOD;
            b.push_back(d);
        }
        b.push_back(1);
        
        pascal.push_back(b);
    }
    
    return pascal;
}

int main()
{
    int t, n, k;
    vector<vector<long long>> tr = triangle(2000);
    
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cout << tr[k + n - 2][n - 1] << endl;
    }
    return 0;
}

