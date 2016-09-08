#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k, res = 0, curr_page = 1;
    cin >> n >> k;
    
    vector<int> t(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> t[pos];
    }
    
    for(int chapter = 1; chapter <= n; ++chapter)
    {
        for(int pos = 1; pos <= t[chapter - 1]; ++pos)
        {
            if(pos == curr_page)
            {
                res++;
            }
            if(pos == t[chapter - 1] || pos % k == 0)
            {
                curr_page++;
            }
        }
    }
    
    cout << res << endl;;
    return 0;
}

