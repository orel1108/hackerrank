#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
long long answer = 0;

void merge(vector<int> & i_arr, int i_left, int i_right)
{
    int mid = i_left + (i_right - i_left) / 2;
    
    int end_left = mid + 1;
    int end_right = i_right + 1;
    
    int s = i_left;
    vector<int> arr(i_right - i_left + 1);
    
    i_right = end_left;
    int k = 0;
    while (i_left < end_left && i_right < end_right)
    {
        if (i_arr[i_left] <= i_arr[i_right])
        {
            arr[k] = i_arr[i_left];
            i_left++;
        }
        else
        {
            arr[k] = i_arr[i_right];
            answer += (end_left - i_left);
            i_right++;
        }
        k++;
    }
    
    for (; i_left < end_left; ++i_left, ++k)
    {
        arr[k] = i_arr[i_left];
    }
    for (; i_right < end_right; ++i_right, ++k)
    {
        arr[k] = i_arr[i_right];
    }

    for (k = 0; s < i_right; s++, k++)
    {
        i_arr[s] = arr[k];
    }
}

void adv_sort(vector<int> & i_arr, int i_left, int i_right)
{
    if (i_left < i_right)
    {
        int mid = i_left + (i_right - i_left) / 2;
        adv_sort(i_arr, i_left, mid);
        adv_sort(i_arr, mid + 1, i_right);
        merge(i_arr, i_left, i_right);
    }
}

int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for (int pos = 0; pos < n; ++pos)
        {
            cin >> arr[pos];
        }
        
        answer = 0;
        
        adv_sort(arr, 0, n - 1);
        
        cout << answer << endl;
    }
    return 0;
}

