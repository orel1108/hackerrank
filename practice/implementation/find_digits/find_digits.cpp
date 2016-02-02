#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> digits(int n)
{
    vector<int> res;
    while (n > 0)
    {
        res.push_back(n % 10);
        n /= 10;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        
        vector<int> d = digits(n);
        int cnt = count_if(d.cbegin(), d.cend(), 
                           [n](int digit) 
                           { 
                               return digit > 0 && n % digit == 0; 
                           });
        cout << cnt << endl;
    }
    return 0;
}

