#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t, n, m;
    cin >> t;
    
    while (t--)
    {
        cin >> m >> n;
        
        vector<long long> y_values(m - 1);
        for (int pos = 0; pos < m - 1; ++pos)
        {
            cin >> y_values[pos];
        }
        sort(y_values.begin(), y_values.end(), greater<int>());
        y_values.push_back(0);
        
        vector<long long> x_values(n - 1);
        for (int pos = 0; pos < n - 1; ++pos)
        {
            cin >> x_values[pos];
        }
        sort(x_values.begin(), x_values.end(), greater<int>());
        x_values.push_back(0);
        
        long long y_segments = 1;
        long long x_segments = 1;
        long long cost = 0;
        
        int y_counter = 0;
        int x_counter = 0;
        for (int cnt = 0; cnt < m + n - 2; ++cnt)
        {
            if (y_values[y_counter] >= x_values[x_counter])
            {
                cost += y_values[y_counter] * x_segments;
                y_segments++;
                y_counter++;
            }
            else
            {
                cost += x_values[x_counter] * y_segments;
                x_segments++;
                x_counter++;
            }

            if (cost >= 1000000007)
            {
                cost %= 1000000007;
            } 
        }
        
        cout << cost << endl;
        
    }
    return 0;
}

