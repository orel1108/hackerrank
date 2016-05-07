#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int pos = 0; pos < n; ++pos)
    {
       cin >> arr[pos];
    }
    
    reverse(arr.begin(), arr.end());
    for (int pos = 0; pos < n; ++pos)
    {
       cout << arr[pos] << " ";
    }
    cout << endl;
    
    return 0;
}

