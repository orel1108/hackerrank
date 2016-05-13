#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

long long solve(const vector<long long> & i_p)
{
    stack<pair<long long, long long>> st;
    long long max_days_alive = 0;
    
    for (int pos = 0; pos < i_p.size(); ++pos)
    {
        long long days_alive = 0;
        while (!st.empty() && (i_p[pos] <= st.top().first))
        {
            days_alive = max(days_alive, st.top().second);
            st.pop();
        }
        days_alive = st.empty() ? 0 : days_alive + 1;
        max_days_alive = max(max_days_alive, days_alive);
        st.push(make_pair(i_p[pos], days_alive));
    }
    
    return max_days_alive;
}

int main()
{
    int n;
    cin >> n;
    
    vector<long long> p(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> p[pos];
    }
    
    cout << solve(p) << endl;
    
    return 0;
}

