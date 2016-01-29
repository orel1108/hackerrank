#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getHeight(int ncycles)
{
    if (ncycles == 0)
    {
        return 1;
    }
    return ncycles % 2 == 1 ? 2 * getHeight(ncycles - 1) : 1 + getHeight(ncycles - 1);
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << getHeight(n) << endl;
    }
    return 0;
}
