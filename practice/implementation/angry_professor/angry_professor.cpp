#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() 
{
    int T, N, K;
    int cnt;
    vector<int> arrival_time(1000);
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> K;
        for (int j = 0; j < N; j++)
        {
            cin >> arrival_time[j];
        }
        cnt = count_if(arrival_time.cbegin(), arrival_time.cbegin() + N, 
                       [](int atime) 
                       { 
                           return atime < 1; 
                       });
        if (cnt < K)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

