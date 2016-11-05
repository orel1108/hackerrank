#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n, t;
    vector<bool> win_pos{false, false, true, true, true, true};
    for (int pos = 6; pos < 101; ++pos)
    {
        bool r = win_pos[pos - 5] && win_pos[pos - 3] && win_pos[pos - 2];
        win_pos.push_back(!r);
    }
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (win_pos[n])
        {
            cout << "First" << endl;
        }
        else
        {
            cout << "Second" << endl;
        }
    }
    return 0;
}

