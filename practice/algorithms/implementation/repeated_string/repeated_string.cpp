#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    long n, q, r;
    cin >> n;
    
    q = n / s.size();
    r = n % s.size();
    
    long res = q * count(s.begin(), s.end(), 'a') + count(s.begin(), s.begin() + r, 'a');
    cout << res << endl;
    
    return 0;
}

