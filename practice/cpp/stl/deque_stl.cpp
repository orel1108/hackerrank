#include <deque>
#include <vector>
#include <cstdio>

using namespace std;

void solve(const vector< int > & i_v, int i_k)
{
	deque< int > dq;
	for (int i = 0; i < i_v.size(); ++i)
	{
		while (!dq.empty() && i_v[i] > dq.back())
            dq.pop_back(); 
		dq.push_back(i_v[i]);  
		if (i >= i_k && dq.front() == i_v[i - i_k])
            dq.pop_front();
		if (i >= i_k - 1)
            printf(i < i_v.size() - 1 ? "%d " : "%d\n", dq.front());
	}
}

int main()
{
	int t, n, k;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &k);
        vector< int > v(n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &v[i]);
        }
        solve(v, k);
    }
}

