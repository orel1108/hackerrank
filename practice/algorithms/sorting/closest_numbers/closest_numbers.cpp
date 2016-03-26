#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

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
    
    // sort array
    sort(arr.begin(), arr.end());
    
    int curr_min = abs(arr[0] - arr[1]);
    
    for (int pos = 1; pos < n - 1; ++pos)
    {
        int diff = abs(arr[pos] - arr[pos + 1]);
        if (diff < curr_min)
        {
            curr_min = diff;    
        }
    }
    
    set<pair<int, int>> pairs;
    for (int pos = 0; pos < n - 1; ++pos)
    {
        int diff = abs(arr[pos] - arr[pos + 1]);
        if (diff == curr_min)
        {
            if (arr[pos] > arr[pos + 1])
            {
                pairs.insert(make_pair(arr[pos + 1], arr[pos]));    
            }
            else
            {
                pairs.insert(make_pair(arr[pos], arr[pos + 1]));
            }
        }
    }
    
    set<pair<int, int>>::iterator it = pairs.begin();
    for (; it != pairs.end(); ++it)
    {
        cout << it->first << " " << it->second << " ";    
    }
    
    return 0;
}

