#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int countCh(vector<set<int>> & i_adjList, int i_par)
{
    int cnt = i_adjList[i_par].size();
    if(cnt)
    {
        set<int>::const_iterator it = i_adjList[i_par].begin();
        for(; it != i_adjList[i_par].end(); it++)
        {
            cnt += countCh(i_adjList, *it);
        }
    }
    
    return cnt;
}

int main()
{    
    int n, m;
    cin >> n >> m;
    
    vector<set<int>> adjList(n + 1);
    int v1, v2;
    for (int i = 0; i < m; ++i)
    {
        cin >> v1 >> v2;
        adjList[v2].insert(v1);
    }
    
    vector<int> numCh(n + 1, 0);
    for (int i = 1; i < adjList.size(); i++)
    {
        numCh[i] = countCh(adjList, i);
    }
    
    sort(numCh.begin(), numCh.end());
    int numEdge = 0;
    for (int i = 0; i < numCh.size() - 1; ++i)
    {
        if (numCh[i] % 2 == 1)
        {
            numEdge++;
        }
    }
    
    cout << numEdge << "\n";
    
    return 0;
}

