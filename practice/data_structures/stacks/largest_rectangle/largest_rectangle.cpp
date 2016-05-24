#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

long long max_area(const vector<long long> & i_heights)
{
    stack<long long> st;
    long long res = 0;
    
    int pos = 0;
    while (pos < i_heights.size())
    {
        if (st.empty() || (i_heights[st.top()] <= i_heights[pos]))
        {
            st.push(pos);
            pos++;
        }
        else
        {
            long long top = st.top();
            st.pop();
            long long w;
            if (st.empty())
            {
                w = pos;
            }
            else
            {
                w = pos - st.top() - 1;
            }
            res = max(res, i_heights[top] * w);
        }
    }
    
    while (!st.empty())
    {
        long long top = st.top();
        st.pop();
        long long w;
        if (st.empty())
        {
            w = pos;
        }
        else
        {
            w = pos - st.top() - 1;
        }
        res = max(res, i_heights[top] * w);
    }
    
    return res;
}

int main()
{
    int n;
    cin >> n;
    
    vector<long long> heights(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> heights[pos];
    }
    
    cout << max_area(heights) << endl;
    return 0;
}

