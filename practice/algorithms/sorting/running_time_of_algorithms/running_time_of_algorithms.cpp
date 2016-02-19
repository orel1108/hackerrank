#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int rtInsertionSort(vector<int> ar, int n)
{
    int rt = 0;
    for (int pos = 1; pos < n; pos++)
    {
        int j = pos;
        int v = ar[pos];
        while (j > 0 && ar[j - 1] > v)
        {
            j--;
            rt++;
        }
        for (int k = pos; k > j; k--)
        {
            ar[k] = ar[k - 1];
        }
        ar[j] = v;
    }
    
    return rt;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> ar(n);
    for (int pos = 0; pos < n; pos++)
    {
        cin >> ar[pos];
    }
    
    int cnt = rtInsertionSort(ar, n);
    cout << cnt << endl;
    
    return 0;
}

