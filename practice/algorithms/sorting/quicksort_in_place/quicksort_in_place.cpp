#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int partition(vector<int> & i_arr, int i_low, int i_high)
{
    const int pivot = i_arr[i_high];
    int pos = i_low;

    for (int ipos = i_low; ipos < i_high; ++ipos)
    {
        if (i_arr[ipos] <= pivot)
        {
            swap(i_arr[pos], i_arr[ipos]);
            pos++;
        }
    }
            
    swap(i_arr[pos], i_arr[i_high]);
    for (int ipos = 0; ipos < i_arr.size(); ++ipos)
    {
        cout << i_arr[ipos] << " ";
    }
    cout << endl;
            
    return pos;
}

void quicksort(vector<int> & i_arr, int i_low, int i_high)
{
    if (i_low < i_high)
    {
        int p = partition(i_arr, i_low, i_high);
        quicksort(i_arr, i_low, p - 1);
        quicksort(i_arr, p + 1, i_high);   
    }   
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int pos = 0; pos < n; pos++)
    {
        cin >> arr[pos];
    }
    
    quicksort(arr, 0, n - 1);
    
    return 0;
}

