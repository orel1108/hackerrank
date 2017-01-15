#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

double dist(pair<long, long> i_a, pair<long, long> i_b)
{
    return sqrt(static_cast<double>(pow(i_a.first - i_b.first, 2)) + static_cast<double>(pow(i_a.second - i_b.second, 2)));
}

int main()
{
    int n;
    long a, b;
    long min_x = 1000000001;
    long max_x = -1000000001;
    long min_y = 1000000001;
    long max_y = -1000000001;
    
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        if (a == 0)
        {
            min_y = min(b, min_y);
            max_y = max(b, max_y);
        }
        else
        {
            min_x = min(a, min_x);
            max_x = max(a, max_x);
        }
    }
    
    pair<long, long> cand[4] = {make_pair(min_x, 0), make_pair(max_x, 0), make_pair(0, min_y), make_pair(0, max_y)};
    double r = 0.0;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            double d = dist(cand[i], cand[j]);
            r = max(r, d);
        }

    cout << fixed << setprecision(12) << r << endl;
    
    return 0;
}

