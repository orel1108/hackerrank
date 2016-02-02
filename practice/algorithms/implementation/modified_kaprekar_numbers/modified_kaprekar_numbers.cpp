#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isKaprekar(int value)
{
    int c = value;
    int cnt = 0;
    while (c > 0)
    {
        cnt++;
        c /= 10;
    }
    
    long long sqr = pow(value, 2);
    long long base = pow(10, cnt);
    
    long long right = sqr % base;
    long long left = sqr / base;
    
    return (left + right) == value;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int p, q;
    cin >> p >> q;
    bool hasKaprekar = false;
    for (int i = p; i < q + 1; i++)
    {
        if (isKaprekar(i))
        {
            hasKaprekar = true;
            cout << i << " ";
        }
    }
    if (!hasKaprekar)
    {
        cout << "INVALID RANGE";
    }
    return 0;
}

