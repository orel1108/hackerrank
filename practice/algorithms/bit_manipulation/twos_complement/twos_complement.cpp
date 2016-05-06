#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> int2bin(int i_val)
{
    vector<int> res;
    while (i_val)
    {
        res.push_back(i_val & 1);
        i_val /= 2;
    }
    reverse(res.begin(), res.end());
    
    return res;
}

int bin2int(vector<int>::iterator i_begin,  vector<int>::iterator i_end)
{
    int res = 0;
    for (; i_begin != i_end; ++i_begin)
    {
        res = 2 * res + *i_begin;
    }
    return res;
}

unsigned long long num_bits(long long i_val)
{
    if (i_val == 0 || i_val == 1)
    {
        return i_val;
    }
    
    vector<int> bits = int2bin(i_val);
    const int n = bits.size();
    
    unsigned long long cnt = 0;
    for (int pos = 0; pos < n - 1; ++pos)
    {
        if (bits[pos] == 1)
        {
            cnt += (n - pos - 1) * pow(2ULL, n - pos - 2) + bin2int(bits.begin() + pos + 1, bits.end()) + 1;
        }
    }
    if (bits.back() == 1)
    {
        cnt++;
    }
    
    return cnt;
}

unsigned long long num_bits_neg(long long i_val)
{
    return 32ULL * abs(i_val) - num_bits(abs(i_val) - 1);
}

int main()
{
    int t, a, b;
    cin >> t;
    
    while (t--)
    {
        cin >> a >> b;
        if (a >= 1)
        {
            cout << (num_bits(b) - num_bits(a - 1)) << endl;
        }
        else if (a == 0)
        {
            cout << num_bits(b) << endl;
        }
        else if (b >= 0)
        {
            cout << (num_bits(b) + num_bits_neg(a)) << endl;
        }
        else if (b < -1)
        {
            cout << (num_bits_neg(a) - num_bits_neg(b + 1)) << endl;
        }
        else
        {
            cout << num_bits_neg(a) << endl;
        }
    }
    
    return 0;
}

