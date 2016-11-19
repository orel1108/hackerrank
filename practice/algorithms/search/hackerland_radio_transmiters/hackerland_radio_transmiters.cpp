#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> x(n);
    for(int pos = 0; pos < n; ++pos)
    {
       cin >> x[pos];
    }
    
    sort(x.begin(), x.end());

    int cnt = 0;
    int curr_pos = 0, prev_pos = 0;
    while (curr_pos < n)
    {
        prev_pos = curr_pos;
        while (curr_pos < n && (x[curr_pos] - x[prev_pos]) <= k)
            curr_pos++;
        
        curr_pos--;
        cnt++;
        
        prev_pos = curr_pos;
        while (curr_pos < n && (x[curr_pos] - x[prev_pos]) <= k)
            curr_pos++;
    }
    
    cout << cnt << endl;

    return 0;
}

