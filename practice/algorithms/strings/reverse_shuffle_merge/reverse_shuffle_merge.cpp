#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    reverse(s.begin(), s.end());
    
    const size_t n = s.length();
    const size_t h = n / 2;
    
    map<char, int> sfreq, afreq;
    for (auto c : s)
    {
        auto p = sfreq.insert(make_pair(c, 1));
        if (!p.second)
        {
            sfreq[c]++;
        }
    }
    for (auto p : sfreq)
    {
        afreq.insert(make_pair(p.first, p.second / 2));
    }
    
    string a;
    int pos = 0;
    while (a.length() < h)
    {
        int min_char_at = -1;
        while (true)
        {
            char c = s[pos];
            if (afreq[c] > 0 && (min_char_at < 0 || c < s[min_char_at]))
            {
                min_char_at = pos;
            }
            sfreq[c]--;
            if (sfreq[c] < afreq[c])
            {
                break;
            }
            pos++;
        }
        for (int ipos = min_char_at + 1; ipos < pos + 1; ipos++)
        {
            sfreq[s[ipos]]++;
        }
        afreq[s[min_char_at]]--;
        a += s[min_char_at];
        pos = min_char_at + 1;
    }
    
    cout << a << endl;
    
    return 0;
}

