#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> divisorGenerator(int i_n)
{
    vector<int> divisors;
    for (int d = 1; d < static_cast<int>(sqrt(i_n)) + 1; ++d)
    {
        if (i_n % d == 0)
        {
            divisors.push_back(d);
            if (d != (i_n / d))
            {
                divisors.insert(divisors.begin(), i_n / d);
            }
        }
    }
    
    return divisors;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> a[pos];
    }
    
    int max_size = accumulate(a.begin(), a.end(), 0);
    
    vector<int> divisors = divisorGenerator(max_size);
    
    vector<int> sizes;
    vector<int>::const_iterator it = divisors.begin();
    for (; it != divisors.end(); ++it)
    {
        int cnt = 0, curr_size = 0;
        while (cnt < n)
        {
            curr_size += a[cnt];
            cnt++;
            if (curr_size == *it)
            {
                curr_size = 0;
            }
            else if (curr_size > *it)
            {
                break;
            }
        }
        if ((cnt == n) && (curr_size == 0))
        {
            sizes.push_back(*it);
        }
    }
    
    sort(sizes.begin(), sizes.end());
    it = sizes.begin();
    for (; it != sizes.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}

