#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    
    vector<int> a(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> a[pos];
    }
    
    for (int pos = 0; pos < n; ++pos)
    {
        cout << a[(pos + d) % n] << " ";
    }
    cout << endl;
    
    return 0;
}

