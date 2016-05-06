#include <iostream>

using namespace std;

int main()
{
    int t;
    unsigned n;
    cin >> t;
    
    while (t--)
    {
        cin >> n;
        cout << (n ^ 0xFFFFFFFF) << endl;
    }
    return 0;
}

