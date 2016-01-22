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
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
       cin >> arr[i];
    }
    
    int sum = accumulate(arr.cbegin(), arr.cend(), 0);
    cout << sum << endl;
    
    return 0;
}

