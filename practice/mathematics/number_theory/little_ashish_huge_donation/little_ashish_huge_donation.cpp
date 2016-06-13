#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    unsigned long long n, x;
    
    const unsigned long long MAX = 10000000000000001;
    
    vector<unsigned long long> v(1, 0);
    n = 1;
    while (n * (n + 1) * (2 * n + 1) / 6 < MAX)
    {
        v.push_back(v.back() + n * n);
        n++;
    }
    
    cin >> t;
    while (t--)
    {
        cin >> x;
        size_t d = distance(v.begin(), upper_bound(v.begin(), v.end(), x)) - 1;
        cout << d << endl;
    }
    
    return 0;
}

