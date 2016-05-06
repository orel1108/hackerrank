#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<long long> POWS;

void fill_pows()
{
    for (int POW = 0; POW < 33; ++POW)
    {
        POWS.push_back(1LL << POW);
    }
}

int main()
{
    int t;
    cin >> t;
    
    fill_pows();
    
    long long a, b, c;
    while (t--)
    {
        cin >> a >> b;
        
        c = b - a + 1;
        if (c == 1 || c == 2)
        {
            cout << (a & b) << endl;
        }
        else
        {
            int pos = 0;
            while (c > POWS[pos])
            {
                pos++;
            }
            a /= POWS[pos];
            b /= POWS[pos];
            
            long long r = 0xFFFFFFFF;
            while (a <= b)
            {
                r &= a;
                a++;
            }
            cout << (r * POWS[pos]) << endl;
        }
    }
    return 0;
}

