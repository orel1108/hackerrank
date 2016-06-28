#include <cmath>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int num_digits(unsigned long long i_value)
{
    if (i_value == 0)
    {
        return 1;
    }
    return static_cast<int>(log10(i_value)) + 1;
}

vector<unsigned long long> strange_values()
{
    set<unsigned long long> strange;
    set<unsigned long long> curr;
    
    strange.insert(0);
    for (unsigned long long v = 1; v < 10; ++v)
    {
        strange.insert(v);
        curr.insert(v);
    }
    
    while (!curr.empty() && (*curr.begin() < 1000000000000000000ULL))
    {
        set<unsigned long long> new_curr;
        set<unsigned long long>::iterator it = curr.begin();
        for (; it != curr.end(); ++it)
        {
            int n = num_digits(*it);
            unsigned long long d = *it * n;
            if (d != *it && num_digits(d) == n)
            {
                new_curr.insert(d);
            }
            
            d = *it * (n + 1);
            if (num_digits(d) == n + 1)
            {
                new_curr.insert(d);
            }
            
            d = *it * (n + 2);
            if (num_digits(d) == n + 2)
            {
                new_curr.insert(d);
            }
        }
        
        curr = new_curr;
        it = curr.begin();
        for (; it != curr.end(); ++it)
        {
            strange.insert(*it);
        }
    }
    
    return vector<unsigned long long>(strange.begin(), strange.end());
}

int main()
{
    int t;
    unsigned long long L, R, l, r;
    
    vector<unsigned long long> strange = strange_values();
    
    cin >> t;
    while (t--)
    {
        cin >> L >> R;
        
        l = 0;
        while (l < strange.size() && L > strange[l])
        {
            l++;
        }
        
        r = 0;
        while (r < strange.size() && R >= strange[r])
        {
            r++;
        }
        
        cout << (r - l) << endl;
    }
    
    return 0;
}

