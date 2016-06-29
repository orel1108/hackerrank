#include <vector>
#include <iostream>
#include <map>

using namespace std;

int coins[4] = {1, 2, 5, 10};

int count(map<pair<int, int>, int> & io_mem, const vector<int> & i_limits, int i_n, int i_k)
{
    if (i_n == 0)
    {
        return 1;
    }
    
    if (i_n < 0 || i_k < 1)
    {
        return 0;
    }
    
    auto it = io_mem.find(make_pair(i_n, i_k));
    if (it != io_mem.end())
    {
        return it->second;
    }
    
    int s = 0;
    for (int i = 0; i <= i_limits[i_k]; i++)
    {
        s += count(io_mem, i_limits, i_n - i * coins[i_k], i_k - 1);
    }
    
    io_mem[make_pair(i_n, i_k)] = s;
    return s;
}

int main()
{
    int t, n;
    vector<int> limits(4);
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < 4; i++)
        {
            cin >> limits[i];
        }
        
        map<pair<int, int>, int> mem;
        
        int s = 0;
        for (int i = 0; i <= limits[0]; i++)
        {
            s += count(mem, limits, n - i, 3);    
        }
        cout << s << endl;
    }
    return 0;
}

