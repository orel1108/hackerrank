#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_funny(const string & s)
{
    const size_t n = s.length();
    for (int i = 0; i < n - 1; i++)
    {
        if (abs(s[i + 1] - s[i]) != abs(s[n - 1 - i] - s[n - 2 - i]))
        {
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    string s;
    for (int i = 0; i < t; i++)
    {
        cin >> s;
        if (is_funny(s))
        {
            cout << "Funny" << endl;
        }
        else
        {
            cout << "Not Funny" << endl;
        }
    }
    return 0;
}
