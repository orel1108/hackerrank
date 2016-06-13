#include <vector>
#include <iostream>

using namespace std;

vector<vector<long long>> matrix_pow(vector<vector<long long>> i_a, long long i_n)
{
    vector<vector<long long>> r(2, vector<long long>(2, 0));
    r[0][0] = r[1][1] = 1;
    
    if (i_n == 0)
    {
        return r; 
    }
    
    if (i_n == 1)
    {
        return i_a;
    }
    
    while (i_n > 0)
    {
        if (i_n & 1 == 1)
        {
            long long r00 = r[0][0] * i_a[0][0] + r[0][1] * i_a[1][0];
            long long r01 = r[0][0] * i_a[0][1] + r[0][1] * i_a[1][1];
            long long r10 = r[1][0] * i_a[0][0] + r[1][1] * i_a[1][0];
            long long r11 = r[1][0] * i_a[0][1] + r[1][1] * i_a[1][1];
            
            r[0][0] = r00 % 1000000007;
            r[0][1] = r01 % 1000000007;
            r[1][0] = r10 % 1000000007;
            r[1][1] = r11 % 1000000007;
        }
        long long a00 = i_a[0][0] * i_a[0][0] + i_a[0][1] * i_a[1][0];
        long long a01 = i_a[0][0] * i_a[0][1] + i_a[0][1] * i_a[1][1];
        long long a10 = i_a[1][0] * i_a[0][0] + i_a[1][1] * i_a[1][0];
        long long a11 = i_a[1][0] * i_a[0][1] + i_a[1][1] * i_a[1][1];
            
        i_a[0][0] = a00 % 1000000007;
        i_a[0][1] = a01 % 1000000007;
        i_a[1][0] = a10 % 1000000007;
        i_a[1][1] = a11 % 1000000007;
        i_n /= 2;
    }
    
    return r;
}

long long fib(long long i_n, long long i_a, long long i_b)
{
    vector<vector<long long>> r(2, vector<long long>(2, 0));
    r[0][0] = r[0][1] = r[1][0] = 1;
    
    vector<vector<long long>> m = matrix_pow(r, i_n);
    
    return (m[1][0] * i_b + m[1][1] * i_a) % 1000000007;
}

int main()
{
    int t;
    long long a, b, n;
    
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> n;
        cout << fib(n, a, b) << endl;
    }
    
    return 0;
}

