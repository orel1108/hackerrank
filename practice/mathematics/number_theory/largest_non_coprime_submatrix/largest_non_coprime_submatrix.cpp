#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

unsigned gcd(unsigned i_a, unsigned i_b)
{
    if (i_a > i_b)
    {
        swap(i_a, i_b);
    }
    
    while (i_a > 0)
    {
        unsigned c = i_b % i_a;
        i_b = i_a;
        i_a = c;
    }
    
    return i_b;
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<unsigned>> a(n, vector<unsigned>(m));
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < m; ++col)
        {
            cin >> a[row][col];
        }
    }
    
    vector<vector<vector<unsigned>>> aux(n, vector<vector<unsigned>>(m));
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < m; ++col)
        {
            aux[row][col].push_back(a[row][col]);
            int rcnt = row + 1;
            unsigned d = a[row][col];
            while (rcnt < n)
            {
                d = gcd(d, a[rcnt][col]);
                if (d == 1)
                {
                    break;
                }
                aux[row][col].push_back(d);
                rcnt++;
            }
        }
    }
    
    unsigned r = 0;
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < m; ++col)
        {
            for (int cnt = aux[row][col].size() - 1; cnt >= 0; --cnt)
            {
                if ((cnt + 1) * (m - col) < r)
                {
                    break;    
                }
                
                int h = cnt + 1;
                int ccnt = col + 1;
                unsigned d = aux[row][col][cnt];
                if (d > 1)
                {
                    unsigned w = 1;
                    while (ccnt < m && cnt < aux[row][ccnt].size())
                    {
                        d = gcd(d, aux[row][ccnt][cnt]);
                        if (d == 1)
                        {
                            break;
                        }
                        w++;
                        ccnt++;
                    }
                    if (w * h > r)
                    {
                        r = w * h;
                    }
                }
            }
        }
    }
    
    cout << r << endl;
    
    return 0;
}

