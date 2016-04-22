#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>

using namespace std;

map<int, int> PARENT;
vector<int> RANK;

void init_set(int i_size)
{
    for (int vertex = 0; vertex < i_size; ++vertex)
    {
        PARENT[vertex] = vertex;
    }
    
    RANK = vector<int>(i_size, 0);
}

int Find(int i_vertex)
{
    if (PARENT[i_vertex] != i_vertex)
    {
        PARENT[i_vertex] = Find(PARENT[i_vertex]);
    }
    return PARENT[i_vertex];
}

void Union(int i_vertex1, int i_vertex2)
{
    int root1 = Find(i_vertex1);
    int root2 = Find(i_vertex2);
    
    if (root1 != root2)
    {
        if (RANK[root1] > RANK[root2])
        {
            PARENT[root2] = root1;
        }
        else
        {
            PARENT[root1] = root2;
            if (RANK[root1] == RANK[root2])
            {
                RANK[root2]++;
            }
        }
    }
}

vector<int> kruskal(const vector<pair<int, pair<int, int>>> & i_graph, int i_size)
{
    init_set(i_size);
    
    vector<int> res_mst;
    vector<pair<int, pair<int, int>>>::const_iterator cit = i_graph.begin();
    for (; cit != i_graph.end(); ++cit)
    {
        int v1 = cit->second.first;
        int v2 = cit->second.second;
        
        if (Find(v1) != Find(v2))
        {
            Union(v1, v2);
            res_mst.push_back(cit->first);
        }
    }
    
    return res_mst;
}

struct Compare
{
    bool operator()(const pair<int, pair<int, int>> & i_e1, const pair<int, pair<int, int>> & i_e2) const
    {
        if (i_e1.first != i_e2.first)
        {
            return i_e1.first < i_e2.first;
        }
        
        return i_e1.first + i_e1.second.first + i_e1.second.second < i_e2.first + i_e2.second.first + i_e2.second.second;
    }
};

int main()
{
    int n, m;
    int v1, v2, w;
    cin >> n >> m;
    
    vector<pair<int, pair<int, int>>> graph;
    while (m--)
    {
        cin >> v1 >> v2 >> w;
        v1--;
        v2--;
        if (v1 > v2)
        {
            swap(v1, v2);
        }
        
        pair<int, int> edge = make_pair(v1, v2);
        graph.push_back(make_pair(w, edge));
    }
    
    sort(graph.begin(), graph.end(), Compare());
    vector<int> mst = kruskal(graph, n);
    
    cout << accumulate(mst.begin(), mst.end(), 0) << endl;
    
    return 0;
}

