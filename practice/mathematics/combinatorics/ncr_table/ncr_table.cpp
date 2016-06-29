#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<vector<unsigned>> pascal;
    pascal.push_back(vector<unsigned>(1, 1));
    pascal.push_back(vector<unsigned>(2, 1));
    
    for (int cnt = 0; cnt < 1000; ++cnt)
    {
        vector<unsigned> last = pascal.back();
        vector<unsigned> new_row(1, 1);
        for (int pos = 0; pos < last.size() - 1; ++pos)
        {
            new_row.push_back((last[pos] + last[pos + 1]) % 1000000000);
        }
        new_row.push_back(1);
        pascal.push_back(new_row);
    }
    
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int pos = 0; pos < pascal[n].size(); ++pos)
        {
            cout << pascal[n][pos] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

