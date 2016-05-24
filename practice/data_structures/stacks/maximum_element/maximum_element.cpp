#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    stack<int> sm;
    int n, a, b;
    cin >> n;
    
    while (n--)
    {
        cin >> a;
        if (a == 1)
        {
            cin >> b;
            if (sm.empty())
            {
                sm.push(b);
            }
            else
            {
                sm.push(max(b, sm.top()));
            }
        }
        else if (a == 2)
        {
            sm.pop();
        }
        else
        {
            cout << sm.top() << endl;
        }
    }
    return 0;
}

