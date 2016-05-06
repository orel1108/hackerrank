#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<unsigned long long> POWS;

void fill_pows()
{
    for (int POW = 0; POW < 64; ++POW)
    {
        POWS.push_back((1ULL << POW) - 1LL);
    }
    POWS.push_back(0xFFFFFFFFFFFFFFFFULL);
}

unsigned long long num_steps(unsigned long long i_n)
{
    unsigned long long steps = 0;
    while (true)
    {
        int pos = 0;
        while (pos < POWS.size())
        {
            if (POWS[pos] == i_n - 1)
            {
                steps += pos + 1;
                return steps;
            }
            if (POWS[pos] >= i_n)
            {
                unsigned long long k = i_n / (POWS[pos - 1] + 1);
                i_n -= k * (POWS[pos - 1] + 1);
                steps += k;
                break;
            }
            pos++;
        }
    }
    
    return steps;
}

int main()
{
    int t;
    cin >> t;
    
    unsigned long long n, d;
    
    fill_pows();
    
    while (t--)
    {
        cin >> n;
        d = num_steps(n);
        if (d % 2 == 1)
        {
            cout << "Richard" << endl;
        }
        else
        {
            cout << "Louise" << endl;
        }
    }
    return 0;
}

