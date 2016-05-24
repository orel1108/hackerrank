#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> sieve(int i_n)
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
    
    vector<int> primes;
    for (int pos = 2; pos < i_n + 1; ++pos)
    {
        if (is_prime[pos])
        {
            primes.push_back(pos);
        }
    }
    
    return primes;
}

int main()
{
    int n, q;
    vector<int> primes = sieve(10000);
    
    cin >> n >> q;
    vector<int> a(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> a[pos];
    }
    
    stack<int> s, r;
    for (vector<int>::reverse_iterator rit = a.rbegin(); rit != a.rend(); ++rit)
    {
        s.push(*rit);
    }
    
    int cnt = 0;
    while (q--)
    {
        while (!s.empty())
        {
            int t = s.top();
            s.pop();
            if (t % primes[cnt] == 0)
            {
                cout << t << endl;
            }
            else
            {
                r.push(t);
            } 
        }
        
        s = r;
        r = stack<int>();
        cnt++;
    }
    
    while (!s.empty())
    {
        r.push(s.top());
        s.pop();
    }
    while (!r.empty())
    {
        cout << r.top() << endl;
        r.pop();
    }
    
    return 0;
}

