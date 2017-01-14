#include <iostream>

using namespace std;

typedef long long ll_t;
typedef pair<ll_t, ll_t> Complex;

Complex mult_complex_mod(Complex i_a, Complex i_b, ll_t i_m)
{
    ll_t x = (i_a.first * i_b.first - i_a.second * i_b.second) % i_m;
    ll_t y = (i_a.first * i_b.second + i_a.second * i_b.first) % i_m;
    x = x < 0 ? x + i_m : x;
    y = y < 0 ? y + i_m : y;
    return make_pair(x, y);
}

Complex pow_complex_mod(Complex i_a, ll_t i_deg, ll_t i_m)
{
    Complex res = make_pair(1, 0);
    while (i_deg)
    {
        if (i_deg & 1)
        {
            res = mult_complex_mod(res, i_a, i_m);
        }
        i_a = mult_complex_mod(i_a, i_a, i_m);
        i_deg >>= 1;
    }
    
    return res;
}

int main()
{
    int q;
    ll_t a, b, k, m;
    
    cin >> q;
    while (q--)
    {
        cin >> a >> b >> k >> m;
        Complex res = pow_complex_mod(make_pair(a, b), k, m);
        cout << res.first << " " << res.second << endl;
    }
    
    return 0;
}

