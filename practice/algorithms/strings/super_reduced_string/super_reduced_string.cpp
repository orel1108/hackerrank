#include <string>
#include <iostream>

using namespace std;

int main()
{
    string s, r;
    
    cin >> s;
    for (int pos = 0; pos < s.size(); ++pos)
    {
        if (r.size() > 0 && (r.back() == s[pos]))
        {
            r.pop_back();
        }
        else
        {
            r += s[pos];
        }
    }
    
    if (r.size() > 0)
    {
        cout << r << endl;
    }
    else
    {
        cout << "Empty String" << endl;
    }
    
    return 0;
}

