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
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    if (is_sorted(a.begin(), a.end()))
    {
        cout << "yes" << endl;
    }
    else
    {
        int begin, end;
        
        begin = 0;
        while (begin < n - 1 && a[begin] < a[begin + 1])
        {
            begin++;
        }
        
        end = n - 1;
        while (end > 0 && a[end] > a[end - 1])
        {
            end--;
        }
        
        swap(a[begin], a[end]);
        if (is_sorted(a.begin(), a.end()))
        {
            cout << "yes" << endl;
            cout << "swap " << (begin + 1) << " " << (end + 1) << endl;
        }
        else
        {
            swap(a[begin], a[end]);
            reverse(a.begin() + begin, a.begin() + end + 1);
            if (is_sorted(a.begin(), a.end()))
            {
                cout << "yes" << endl;
                cout << "reverse " << (begin + 1) << " " << (end + 1) << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
    }
    
    return 0;
}

