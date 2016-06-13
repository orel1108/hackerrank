#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

long long count(long long i_n, long long i_k)
{
    long long k = 0;
    vector<long long> vals;
    
    while (k < i_k)
    {
        vals.push_back((i_n + k) / i_k);
        k++;
    }
    
    long long d = i_n / i_k, r = i_n % i_k;
    if (r > 0)
    {
        r--;
    }
    
    long long res = accumulate(vals.begin(), vals.end(), 0) * d + accumulate(vals.begin(), vals.begin() + r, 0);
    if (i_k % 2 == 0)
    {
        res -= d;
    }
    if (i_n % i_k == 0)
    {
        res -= d;
    }
    if (r > i_k / 2)
    {
        res += 2;
    }
    
    return res / 2;
}

int main()
{
    int t;
    long long n, k;
    
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cout << count(n, k) << endl;
    }
    
    return 0;
}

