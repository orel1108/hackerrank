#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(vector<int> ar)
{
    const size_t n = ar.size();
    const int v = ar[n - 1];
    
    int j = n - 1;
    while (j > 0 && ar[j - 1] > v)
    {
        ar[j] = ar[j - 1];
        j--;
        for (size_t pos = 0; pos < n; pos++)
        {
            cout << ar[pos] << " ";
        }
        cout << endl;
    }
    
    ar[j] = v;
    for (size_t pos = 0; pos < n; pos++)
    {
        cout << ar[pos] << " ";
    }
    cout << endl;
}

int main(void)
{
    int n;
    cin >> n;
    
    vector<int> ar(n);
    for (int pos = 0; pos < n; pos++)
    {
        cin >> ar[pos]; 
    }

    insertionSort(ar);
    return 0;
}

