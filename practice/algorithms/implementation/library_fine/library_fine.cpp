#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int get_fine(int d1, int m1, int y1, int d2, int m2, int y2)
{
    if (y1 > y2)
    {
        return 10000;
    }
    else if (y1 < y2)
    {
        return 0;    
    }
    else
    {
        if (m1 > m2)
        {
            return (m1 - m2) * 500;
        }
        else if (m1 < m2)
        {
            return 0;    
        }
        else
        {
            if (d1 > d2)
            {
                return (d1 - d2) * 15;
            }
        }
    }
    return 0;
}

int main()
{
    int d1;
    int m1;
    int y1;
    cin >> d1 >> m1 >> y1;
    int d2;
    int m2;
    int y2;
    cin >> d2 >> m2 >> y2;
    
    int fine = get_fine(d1, m1, y1, d2, m2, y2);
    cout << fine << endl;
    
    return 0;
}

