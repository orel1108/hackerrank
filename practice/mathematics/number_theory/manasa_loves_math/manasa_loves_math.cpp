#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map<int, int> counter(const string & i_s)
{
    map<int, int> c;
    
    string::const_iterator it = i_s.begin();
    for (; it != i_s.end(); ++it)
    {
        c[*it]++;
    }
    
    return c;
}

map<int, int> counter(int i_n)
{
    string s = to_string(i_n);
    return counter(s);
}

bool contains(const map<int, int> & i_cnt1, const map<int, int> & i_cnt2)
{
    map<int, int>::const_iterator it = i_cnt1.begin();
    for (; it != i_cnt1.end(); ++it)
    {
        int key = it->first;
        if (i_cnt2.find(key) == i_cnt2.end())
        {
            return false;
        }
        else if (i_cnt2.at(key) < i_cnt1.at(key))
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    const vector<int> d8_1{0, 8};
    const vector<int> d8_2{16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 69, 27, 46, 65, 84, 23, 42, 61};
    
    vector<map<int, int>> div_8;
    for (int val = 13; val < 125; ++val)
    {
        div_8.push_back(counter(8 * val));
    }
    
    int t;
    string s;
    
    cin >> t;
    while (t--)
    {
        cin >> s;
        if (s.size() == 1)
        {
            int v = atoi(s.c_str());
            if (find(d8_1.begin(), d8_1.end(), v) != d8_1.end())
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else if (s.size() == 2)
        {
            int v = atoi(s.c_str());
            if (find(d8_2.begin(), d8_2.end(), v) != d8_2.end())
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            map<int, int> c = counter(s);
            bool ans = false;
            
            vector<map<int, int>>::iterator it = div_8.begin();
            for (; it != div_8.end(); ++it)
            {
                if (contains(*it, c))
                {
                    ans = true;
                    break;
                }
            }
            if (ans)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    
    return 0;
}

