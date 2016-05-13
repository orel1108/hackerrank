#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

const int MAXN = 1000000;

vector<bool> sieve(int i_n)
{
    vector<bool> is_prime(i_n + 1, true);
    int i = 2;
    while (i * i <= i_n)
    {
        if (is_prime[i])
        {
            int j = i * i;
            while (j <= i_n)
            {
                is_prime[j] = false;
                j += i;
            }
        }
        i++;
    }
    
    return is_prime;
}

int solve(int i_n, const vector<bool> & i_isprime)
{
    vector<int> res(MAXN + 1, MAXN);
    vector<bool> inq(MAXN + 1, false);
    res[i_n] = 0;
    inq[i_n] = true;
    
    queue<int> q;
    q.push(i_n);
    
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        
        inq[p] = false;
        
        if (p > 0)
        {
            res[p - 1] = min(res[p - 1], res[p] + 1);
            if (!inq[p - 1])
            {
                q.push(p - 1);   
                inq[p - 1] = true;
            }

            if (!i_isprime[p])
            {
                for (int d = 2; d < int(sqrt(p)) + 1; ++d)
                {
                    if (p % d == 0)
                    {
                        int a = p / d;
                        res[a] = min(res[a], res[p] + 1);
                        if (!inq[a])
                        {
                            q.push(a);
                            inq[a] = true;
                        }
                    }
                }
            }   
        }
        else
        {
            return res[p];
        }
    }
    
    return 1;
}

int main()
{
    vector<bool> is_prime = sieve(MAXN);
    
    int q, n;
    cin >> q;
    while (q--)
    {
        cin >> n;
        cout << solve(n, is_prime) << endl;
    }
    
    return 0;
}

