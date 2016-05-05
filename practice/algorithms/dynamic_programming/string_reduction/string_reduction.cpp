#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int stringReduction(string i_s)
{
    map<char, int> counter;
    counter['a'] = counter['b'] = counter['c'] = 0;
    
    const int n = i_s.size();
    
    for (int pos = 0; pos < n; ++pos)
    {
        counter[i_s[pos]]++;
    }
    
    if (counter['a'] == n || counter['b'] == n || counter['c'] == n)
    {
        return n;
    }
    
    if (counter['a'] % 2 == counter['b'] % 2 && counter['b'] % 2 == counter['c'] % 2)
    {
        return 2;
    }
    
    return 1;
}

int main()
{
    int t;
    cin >> t;
    
    string s;
    while (t--)
    {
        cin >> s;
        int res = stringReduction(s);
        cout << res << endl;
    }
  
    return 0;
}

