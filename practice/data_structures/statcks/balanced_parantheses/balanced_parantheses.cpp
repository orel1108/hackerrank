#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <map>

using namespace std;

const map<char, char> PAIRS{
    {'}', '{'}, 
    {')', '('}, 
    {']', '['}};

const vector<char> CLOSE{'}', ')', ']'};

const vector<char> OPEN{'{', '(', '['};

bool balanced(const string & i_s)
{
    stack<char> st;
    for (int pos = 0; pos < i_s.size(); ++pos)
    {
        if (!st.empty())
        {
            if (find(CLOSE.begin(), CLOSE.end(), i_s[pos]) != CLOSE.end())
            {
                if (st.top() == PAIRS.at(i_s[pos]))
                {
                    st.pop();
                }
            }
            else
            {
                st.push(i_s[pos]);
            }
        }
        else
        {
            if (find(OPEN.begin(), OPEN.end(), i_s[pos]) != OPEN.end())
            {
                st.push(i_s[pos]);
            }
            else
            {
                return false;
            }
        }
    }
    
    return st.empty();
}

int main()
{
    int n;
    cin >> n;
    
    string s;
    while (n--)
    {
        cin >> s;
        if (balanced(s))
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

