#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    string s;
    for (int i = 0; i < t; i++)
    {
        cin >> s;
        auto a = next_permutation(s.begin(), s.end());
        if (a)
        {
            cout << s << endl;
        }
        else
        {
            cout << "no answer" << endl;
        }
    }
    return 0;
}

