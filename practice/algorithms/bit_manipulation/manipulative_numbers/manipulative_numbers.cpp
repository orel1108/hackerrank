#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<unsigned> arr(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> arr[pos];
    }
    
    int k;
    for (int bit = 31; bit >= 0; --bit)
    {
        map<unsigned, unsigned> d;
        for (int pos = 0; pos < n; ++pos)
        {
            unsigned h = arr[pos] >> bit;
            d[h]++;
        }
        
        bool is_valid = true;
        map<unsigned, unsigned>::iterator it = d.begin();
        for (; it != d.end(); ++it)
        {
            if (it->second > n / 2)
            {
                is_valid = false;
                break;
            }
        }
        
        if (is_valid)
        {
            k = bit;
            break;
        }
    }
    
    cout << k << endl;
    
    return 0;
}

