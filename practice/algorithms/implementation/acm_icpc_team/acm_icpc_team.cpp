#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int numTopics(string team1, string team2)
{
    int cnt = 0;
    for (int i = 0; i < team1.size(); i++)
    {
        if (team1[i] == '1' || team2[i] == '1')
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> topic(n);
    for(int i = 0; i < n; i++)
    {
       cin >> topic[i];
    }
    
    int res = 0;
    int cnt = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int t = numTopics(topic[i], topic[j]);
            if (t > res)
            {
                res = t;
                cnt = 1;
            }
            else if (t == res)
            {
                cnt++;
            }
        }
    }
    
    cout << res << endl;
    cout << cnt << endl;
    return 0;
}

