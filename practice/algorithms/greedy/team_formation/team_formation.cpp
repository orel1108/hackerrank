#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    string line;
    getline(cin, line);
    
    while (t--)
    {
        getline(cin, line);
        istringstream iss(line);
        
        vector<int> numbers;
        int val;
        while (iss >> val)
        {
            numbers.push_back(val);
        }
        
        int n = numbers[0];
        if (n == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            numbers.erase(numbers.begin());
            sort(numbers.begin(), numbers.end());
            
            map<int, vector<int>> teams;
            teams[numbers[0]].push_back(1);
            
            set<int> keys;
            keys.insert(numbers[0]);
            
            for (int cnt = 1; cnt < numbers.size(); ++cnt)
            {
                if (keys.find(numbers[cnt] - 1) != keys.end())
                {
                    int m = teams[numbers[cnt] - 1][0];
                    teams[numbers[cnt]].push_back(m + 1);
                    teams[numbers[cnt] - 1].erase(teams[numbers[cnt] - 1].begin());
                    
                    if (teams[numbers[cnt] - 1].empty())
                    {
                        keys.erase(numbers[cnt] - 1);
                    }
                }
                else
                {
                    teams[numbers[cnt]].insert(teams[numbers[cnt]].begin(), 1);
                }
                keys.insert(numbers[cnt]);
            }
            
            int res = n;
            set<int>::const_iterator it = keys.begin();
            for (; it != keys.end(); ++it)
            {
                res = min(res, teams[*it][0]);
            }
            
            cout << res << endl;
        }
    }
    
    return 0;
}

