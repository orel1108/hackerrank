#include <cmath>
#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{
    long long q, qi;
    double L, s1, s2;
    
    cin >> L >> s1 >> s2;
    double s = sqrt(2.0) * L;
    double t = s1 - s2;
    
    cin >> q;
    
    while (q--)
    {
        cin >> qi;
        double r = sqrt(2.0 * qi);
        double ans = abs(r - s) / abs(t);
        cout << setprecision(6) << fixed << ans << endl;
    }
        
    return 0;
}

