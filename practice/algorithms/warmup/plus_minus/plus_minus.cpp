#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solve_1(vector<int> arr)
{
    vector<int> res(3, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            res[0]++;
        }
        else if (arr[i] < 0)
        {
            res[1]++;
        }
        else
        {
            res[2]++;    
        }
    }
    return res;
}

vector<int> solve_2(vector<int> arr)
{
    vector<int> res(3, 0);
    
    res[0] = count_if(arr.cbegin(), arr.cend(), [](int val) { return val > 0; });
    res[1] = count_if(arr.cbegin(), arr.cend(), [](int val) { return val < 0; });
    res[2] = count_if(arr.cbegin(), arr.cend(), [](int val) { return val == 0; });
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
       cin >> arr[i];
    }
    
    vector<int> ans = solve_2(arr);
    for (int i = 0; i < 3; i++)
    {
        cout << (static_cast<double>(ans[i]) / n) << endl;
    }
    
    return 0;
}

