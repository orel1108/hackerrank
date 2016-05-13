#include <iostream>
#include <algorithm>

using namespace std;

void median(const vector<char> & i_s, const vector<long long> & i_x)
{
    cout<< fixed;
    cout.precision(1);
    
    vector<long long> r;
    int n = i_s.size();
    
    for (int pos = 0; pos < n; ++pos)
    {
        if (i_s[pos] == 'a')
        {
            vector<long long>::iterator it = upper_bound(r.begin(), r.end(), i_x[pos]);
            r.insert(it, i_x[pos]);
            int l = r.size();
            if (l % 2 == 1)
            {
                cout << r[l / 2] << endl;
            }
            else
            {
                long long v = r[l / 2 - 1] + r[l / 2];
                if (v % 2 == 1 || v % 2 == -1)
                {
                    cout << (static_cast<double>(v) / 2.0) << endl;
                }
                else
                {
                    cout << (v / 2) << endl;   
                }
            }
        }
        else
        {
            vector<long long>::iterator it = find(r.begin(), r.end(), i_x[pos]);
            if (it == r.end())
            {
                cout << "Wrong!" << endl;
            }
            else
            {
                r.erase(it);
                int l = r.size();
                if (l % 2 == 1)
                {
                    cout << r[l / 2] << endl;
                }
                else if (l > 0)
                {
                    long long v = r[l / 2 - 1] + r[l / 2];
                    if (v % 2 == 1 || v % 2 == -1)
                    {
                        cout << (static_cast<double>(v) / 2.0) << endl;
                    }
                    else
                    {
                        cout << (v / 2) << endl;   
                    }
                }
                else
                {
                    cout << "Wrong!" << endl;
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
   
    vector<char> s(n);
    vector<long long> x(n);
    for(int pos = 0; pos < n; ++pos)
    {
        cin >> s[pos] >> x[pos];
    }
   
    median(s, x);
    return 0;
}

