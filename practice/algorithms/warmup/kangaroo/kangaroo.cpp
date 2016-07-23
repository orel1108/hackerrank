#include <iostream>

using namespace std;

int main(){
    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;
    
    if (v1 != v2)
    {
        int d = x1 - x2;
        int v = v2 - v1;
        if (d * v >= 0 && d % v == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else if (x1 == x2)
    {
            cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
    return 0;
}

