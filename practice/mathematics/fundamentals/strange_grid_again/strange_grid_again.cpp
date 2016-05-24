#include <iostream>

using namespace std;

int main()
{
    long long r, c;
    cin >> r >> c;
    
    r--, c--;
    long long t = 10 * (r / 2) + r % 2 + c * 2;
    cout << t << endl;
    
    return 0;
}

