#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int n, k, q;
    string s, a;
    
    cin >> n;
    stack<string> states;
    while (n--)
    {
        cin >> q;
        if (q == 1)
        {
            cin >> a;
            states.push(s);
            s += a;
        }
        else if (q == 2)
        {
            states.push(s);
            cin >> k;
            size_t l = s.length();
            s.erase(s.begin() + l - k, s.end());
        }
        else if (q == 3)
        {
            cin >> k;
            cout << s[k - 1] << endl;
        }
        else
        {
            s = states.top();
            states.pop();
        }
    }
    
    return 0;
}

