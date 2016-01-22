#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++)
    {
       cin >> arr[i];
    }
    
    long long sum = accumulate(arr.cbegin(), arr.cend(), 0L);
    cout << sum << endl;
    
    return 0;
}

