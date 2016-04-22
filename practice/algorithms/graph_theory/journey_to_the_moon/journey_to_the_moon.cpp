#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

vector<int> graph;

void init_graph(int i_n)
{
    graph = vector<int>(i_n);
    for (size_t pos = 0; pos < i_n; ++pos)
    {
        graph[pos] = pos;
    }
}

int Find(int i_vertex)
{
    if (graph[i_vertex] == i_vertex)
    {
        return i_vertex;
    }
    return Find(graph[i_vertex]);
}

void Union(int i_v1, int i_v2)
{
    int v1 = Find(i_v1);
    int v2 = Find(i_v2);
    if (v1 != v2)
    {
        graph[v1] = v2;
    }
}

int main()
{ 
    int n, i;
    cin >> n >> i;
    
    init_graph(n);
    
    for (int cnt = 0; cnt < i; ++cnt)
    {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
    
    map<int, int> d;
    for (int v = 0; v < n; ++v)
    {
        int s = Find(v);
        if (d.find(s) == d.end())
        {
            d[s] = 0;
        }
        d[s]++;
    }
    
    long long int res = 0;
    map<int, int>::const_iterator it = d.begin();
    for (; it != d.end(); ++it)
    {
        n -= it->second;
        res += it->second * n;
    }
    
    cout << res << endl;
    
    return 0;
}

