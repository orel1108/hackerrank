#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long long solve(long long i_n, const vector<long long> & i_pows10)
{
    for (int i = 1; i < 6000; ++i)
    {
        long long s = 0;
        for (int j = 0; j < 13; ++j)
        {
            long long tmp = (i & (1 << j)) > 0 ? 9 : 0;
            s += tmp * i_pows10[j];
        }
        if (s % i_n == 0)
        {
            return s;
        }
    }
    
    return 0;
}

int main()
{
    int t;
    long long n;
    
    vector<long long> pows10(13);
    for (int deg = 0; deg < 13; ++deg)
    {
        pows10[deg] = static_cast<long long>(pow(10, deg));
    }
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << solve(n, pows10) << endl;
    }
    
    return 0;
}

