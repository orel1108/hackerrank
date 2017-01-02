#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    unsigned long long s = 0, min_v = 1000000001, max_v = 0, curr;
    for (int cnt = 0; cnt < 5; ++cnt)
    {
        cin >> curr;
        min_v = min(min_v, curr);
        max_v = max(max_v, curr);
        s += curr;
    }
    
    cout << (s - max_v) << " " << (s - min_v) << endl;
    
    return 0;
}

