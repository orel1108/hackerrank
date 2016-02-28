#include <iostream>

using namespace std;

const unsigned M = (1ll << 31) - 1;
const int MAX = 1 << 26;
const int K = 16;
const int MSK = (1 << K) - 1;

int kb[1 << K];
unsigned f[MAX];

int main()
{

    int n;
    cin >> n;
    unsigned s, p, q;
    cin >> s >> p >> q;

    f[s >> 5] |= 1u << (s & 31);
    for (int i = 1; i < n; i++)
    {
        s = (s * p + q) & M;
        f[s >> 5] |= 1u << (s & 31);
    }

    for (int i = 0; i < (1 << K); i++)
    {
        kb[i] = kb[i >> 1] + (i & 1);
    }

    int res = 0;
    for (int i = 0; i < MAX; i++)
    {
        res += kb[f[i] >> 16] + kb[f[i] & MSK];
    }
    
    cout << res << endl;
    return 0;
}

