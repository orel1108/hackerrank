#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<set<char>> rock_elems(n);
    
    for (int i = 0; i < n; i++)
    {
        string rock;
        cin >> rock;
        rock_elems[i] = set<char>(rock.begin(), rock.end());
    }
    
    set<char> gem = rock_elems[0];
    for (int i = 1; i < n; i++)
    {
        set<char> tmp;
        auto it = set_intersection(gem.begin(), gem.end(), rock_elems[i].begin(), rock_elems[i].end(), 
                                   inserter(tmp, tmp.begin()));
        gem = tmp;
    }
    
    cout << gem.size() << endl;
    
    return 0;
}
