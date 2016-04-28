#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <queue>

using namespace std;

const long long INF = numeric_limits<long long>::max();
vector<pair<long long, long long>> edges[100009];

vector<long long> dijkstra(int i_n, int i_s)
{
    vector<long long> dist(i_n, INF);
    vector<long long> parent(i_n, -1);
    
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
    q.push (make_pair (0ll, (long long)i_s));
    dist[i_s] = 0;
    
    while (!q.empty())
    {
        pair<long long, long long> p = q.top();
        q.pop();
        long long vertex = p.second;
        vector<pair<long long, long long>>::const_iterator it = edges[vertex].begin();
        for (; it != edges[vertex].end(); ++it)
        {
            if (dist[vertex] + it->first < dist[it->second])
            {
                dist[it->second] = dist[vertex] + it->first;
                parent[it->second] = vertex;
                q.push (make_pair(dist[it->second], it->second));
            }
        }
    }
    
    return dist;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        long long s1, s2, l;
        
        long long n, m, k;
        cin >> n >> m >> k;
        
        for (int pos = 0; pos < 100009; ++pos)
        {
            edges[pos].clear();
        }
            
        for (int cnt = 0; cnt < m; ++cnt)
        {
            long long v1, v2, w;
            cin >> v1 >> v2 >> w;
            edges[v1 - 1].push_back(make_pair(w, v2 - 1));
            edges[v2 - 1].push_back(make_pair(w, v1 - 1));
            if (cnt == k - 1)
            {
                s1 = v1 - 1;
                s2 = v2 - 1;
                l = w;
            }
        }
        
        vector<long long> dist1 = dijkstra(n, s1);
        vector<long long> dist2 = dijkstra(n, s2);

        vector<pair<long long, long long>> fin;
        for (int pos = 0; pos < n; ++pos)
        {
            fin.push_back(make_pair(dist1[pos], dist2[pos]));
        }
        sort(fin.begin(),fin.end());
        
        long long prevx = -1, prevy = -1;
        vector<pair<long long, long long>> w;
        for (int pos = n - 1; pos >= 0; --pos)
        {
            if (fin[pos].first <= prevx && fin[pos].second <= prevy)
            {
                continue;    
            }
            
            prevx = fin[pos].first;
            prevy = fin[pos].second;
            w.push_back(fin[pos]);
        }
        
        int p = w.size();
        double ans = min(w[0].first, w[p - 1].second);
        double finans;
        
        if (w[0].first <= w[p - 1].second)
        {
            finans = 0;   
        }
        else
        {
            finans = l;   
        }
        
        for(int pos = 0; pos < p - 1; ++pos)
        {
            double tmp = (w[pos].second - w[pos + 1].first + l) / 2.0;
            double val= w[pos + 1].first + tmp;
            if (val < ans)
            {
                ans = val;
                finans = tmp;
            }
            else if (val == ans)
            {
                finans = min(finans, tmp);   
            }
        }
        cout.precision(5);
        cout.setf(ios::fixed, ios::floatfield);
        cout << finans << " " << ans << endl;
    }
    
    return 0;
}

