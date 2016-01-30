#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{    
    int t, i = 0;
    int money, price, exch;
    cin >> t;
    while(i < t)
    {
        cin >> money >> price >> exch;
        int amount = money / price;
        int cnt = amount;
        while(amount >= exch)
        {
            cnt++;
            amount -= exch;
            amount++;
        }
        
        cout << cnt << endl;;
        i++;
    }
    
    return 0;
}

