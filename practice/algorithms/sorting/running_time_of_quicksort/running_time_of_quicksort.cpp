#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int SWAP_QUICK = 0;
int SWAP_INSERT = 0;

int partition(vector<int> & arr, int lo, int hi)
{
    const auto pivot = arr[hi];
    int pos = lo;
    
    for (int i = lo; i < hi; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[pos], arr[i]);
            pos++;
            SWAP_QUICK++;
        }
    }
    swap(arr[pos], arr[hi]);
    SWAP_QUICK++;
    return pos;
}

void quicksort_in_place(vector<int> & arr, int lo, int hi)
{
    if (lo < hi)
    {
        const auto p = partition(arr, lo, hi);
        quicksort_in_place(arr, lo, p - 1);
        quicksort_in_place(arr, p + 1, hi);
    }
}

void insertion_sort(vector<int> & arr)
{
    for (int pos = 1; pos < arr.size(); pos++)
    {
        const auto curr_val = arr[pos];
        auto position = pos;
        while (position > 0 && arr[position - 1] > curr_val)
        {
            arr[position] = arr[position - 1];
            position--;
            SWAP_INSERT++;
        }
        arr[position] = curr_val;
    }
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        
        a.push_back(val);
        b.push_back(val);
    }
    
    quicksort_in_place(a, 0, n - 1);
    insertion_sort(b);
    
    cout << (SWAP_INSERT - SWAP_QUICK) << endl;
    
    return 0;
}

