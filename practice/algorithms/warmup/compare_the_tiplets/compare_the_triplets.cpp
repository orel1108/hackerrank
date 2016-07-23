#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    vector<int> a(3), b(3);
    vector<pair<int, int>> c(3);
    
    for (int pos = 0; pos < 3; ++pos)
    {
        cin >> a[pos];
    }
    for (int pos = 0; pos < 3; ++pos)
    {
        cin >> b[pos];
    }
    
    transform(a.begin(), a.end(), b.begin(), c.begin(), 
              [](int i_a, int i_b)
              {
                  if (i_a > i_b)
                  {
                      return make_pair(1, 0);
                  }
                  if (i_a < i_b)
                  {
                      return make_pair(0, 1);
                  }
                  
                  return make_pair(0, 0); 
              });
    
    pair<int, int> score = accumulate(c.begin(), c.end(), make_pair(0, 0), 
               [](pair<int, int> i_res, pair<int, int> i_p)
              {
                  return make_pair(i_res.first + i_p.first, i_res.second + i_p.second);
              });
    
    cout << score.first << " " << score.second << endl;
    return 0;
}

