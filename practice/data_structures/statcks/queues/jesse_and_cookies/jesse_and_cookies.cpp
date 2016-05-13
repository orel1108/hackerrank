#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solve(const vector<int> & i_s, int i_k)
{
    if (i_s.size() == 1)
    {
        if (i_s[0] >= i_k)
        {
            return 0;
        }
        return -1;
    }
    
    priority_queue<int, vector<int>, greater<int>> q;
    for (int pos = 0; pos < i_s.size(); ++pos)
    {
        q.push(i_s[pos]);
    }
    
    int cnt = 0;
    while (true)
    {
        if (q.size() == 1)
        {
            if (q.top() >= i_k)
            {
                return cnt;
            }
            return -1;
        }
        
        int a = q.top();
        if (a >= i_k)
        {
            return cnt;
        }
        q.pop();
        
        int b = q.top();
        q.pop();
        
        q.push(a + 2 * b);
        cnt++;
    }
    
    return 0;
}

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> s(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> s[pos];
    }
    
    cout << solve(s, k) << endl;
    
    return 0;
}

