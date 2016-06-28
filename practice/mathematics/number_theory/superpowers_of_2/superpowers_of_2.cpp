#include <iostream>

using namespace std;

int main()
{
    unsigned long long a, b, c = 2;
    cin >> a >> b;
    
    while (a--)
    {
        c = c * c % b;
    }
    
    cout << c << endl;
    
    return 0;
}

