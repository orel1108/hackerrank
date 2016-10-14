#include <set>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

string copy_substring(const string & i_s, char i_c1, char i_c2)
{
    string res = "";
    for (int pos = 0; pos < i_s.size(); ++pos)
    {
        if (i_s[pos] == i_c1 || i_s[pos] == i_c2)
        {
            res += i_s[pos];
        }
    }
    
    return res;
}

bool is_valid(const string & i_s)
{
    stack<char> s;
    for (int pos = 0; pos < i_s.size(); ++pos)
    {
        if (s.empty() || s.top() != i_s[pos])
        {
            s.push(i_s[pos]);
        }
        else
        {
            s.pop();
        }
    }
    
    return s.size() == i_s.size();
}

int main()
{
    int len;
    cin >> len;
    string s;
    cin >> s;
    
    set<char> c(s.begin(), s.end());
    if (c.size() == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        int res = 0;
        for (set<char>::iterator it1 = c.begin(); it1 != c.end(); ++it1)
        {
            for (set<char>::iterator it2 = c.begin(); it2 != c.end(); ++it2)
            {
                string t = copy_substring(s, *it1, *it2);
                if (is_valid(t) && res < t.size())
                {
                    res = t.size();
                }
            }
        }
        
        cout << res << endl;
    }
    
    return 0;
}

