#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<int, string>> stable_sort(const vector<pair<int, string>> & i_arr)
{
    vector<int> count(100);
    
    vector<pair<int, string>>::const_iterator it = i_arr.begin();
    for (; it != i_arr.end(); ++it)
    {
        count[it->first]++;
    }
    
    int total = 0;
    for (int pos = 0; pos < 100; ++pos)
    {
        int c = count[pos];
        count[pos] = total;
        total += c;
    }
    
    vector<pair<int, string>> res(i_arr.size());
    
    it = i_arr.begin();
    for (; it != i_arr.end(); ++it)
    {
        res[count[it->first]] = *it;
        count[it->first]++;
    }
    
    return res;
}

int main()
{
    int n;
    cin >> n;
    
    vector<pair<int, string>> phrases(n);
    for (int pos = 0; pos < n; ++pos)
    {
        int x;
        string phrase;
        
        cin >> x >> phrase;
        
        if (pos < n / 2)
        {
            phrases[pos] = make_pair(x, "-");
        }
        else
        {
            phrases[pos] = make_pair(x, phrase);
        }
    }
    
    vector<pair<int, string>> sorted = stable_sort(phrases);
    
    vector<pair<int, string>>::const_iterator it = sorted.begin();
    for (; it != sorted.end(); ++it)
    {
        cout << it->second << " ";
    }
    
    return 0;
}

