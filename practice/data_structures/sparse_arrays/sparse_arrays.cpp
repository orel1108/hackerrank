#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n, q;
    string s;
    
    cin >> n;
    
    vector<string> a(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> a[pos];
    }
    
    cin >> q;
    while (q--)
    {
        cin >> s;
        cout << count(a.begin(), a.end(), s) << endl;
    }
    
    return 0;
}

