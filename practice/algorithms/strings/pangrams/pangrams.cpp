#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main()
{
    string s, w;
    while (cin.good())
    {
        cin >> w;
        s += w;
    }
    
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    
    set<char> letters(s.begin(), s.end());
    if (letters.size() == 26)
    {
        cout << "pangram" << endl;
    }
    else
    {
        cout << "not pangram" << endl;
    }
    
    return 0;
}

