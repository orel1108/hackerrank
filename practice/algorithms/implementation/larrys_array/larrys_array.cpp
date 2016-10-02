#include <vector>
#include <iostream>

using namespace std;

void rotate_triple(vector<int> & i_a, int i_pos)
{
    int tmp = i_a[i_pos];
    i_a[i_pos] = i_a[i_pos + 1];
    i_a[i_pos + 1] = i_a[i_pos + 2];
    i_a[i_pos + 2] = tmp;
}

void set_min_correct(vector<int> & i_a, int i_pos)
{
    int m = 1000000;
    int p = i_pos;
    for (int pos = i_pos; pos < i_a.size(); ++pos)
    {
        if (i_a[pos] < m)
        {
            m = i_a[pos];
            p = pos;
        }
    }
    
    while (p > i_pos)
    {
        if (p == (i_pos + 1))
        {
            rotate_triple(i_a, p - 1);
            p--;
        }
        else
        {
            rotate_triple(i_a, p - 2);
            rotate_triple(i_a, p - 2);
            p -= 2;
        }
    }
}

int main()
{
    int t, n;
    vector<int> a;
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        a = vector<int>(n);
        for (int pos = 0; pos < n; ++pos)
        {
            cin >> a[pos];
        }
        
        for (int pos = 0; pos < n - 2; ++pos)
        {
            set_min_correct(a, pos);
        }
        
        if (a[n - 3] <= a[n - 2] && a[n - 2] <= a[n - 1])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}

