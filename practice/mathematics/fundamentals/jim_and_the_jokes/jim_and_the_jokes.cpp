#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int dec_rep(int i_m, const string & i_d)
{
    vector<int> digits(i_d.size());
    transform(i_d.begin(), i_d.end(), digits.begin(), 
              [](char c)
              { 
                  return static_cast<int>(c - '0');
              });
    int base = i_m;
    
    if (*max_element(digits.begin(), digits.end()) >= base)
    {
        return -1;
    }
    
    int res = digits[0];
    if (digits.size() == 2)
    {
        res = base * res + digits[1];
    }
    
    return res;
}

int main()
{
    int n, m;
    string d;
    
    vector<long long> dates(366);
    
    cin >> n;
    while (n--)
    {
        cin >> m >> d;
        int pos = dec_rep(m, d);
        if (pos >= 0)
        {
            dates[pos]++;
        }
    }
    
    long long num_pairs = accumulate(dates.begin(), dates.end(), 0LL, 
                                     [](long long a, long long val)
                                     { 
                                         return a + val * (val - 1) / 2;
                                     });
    cout << num_pairs << endl;
    
    return 0;
}

