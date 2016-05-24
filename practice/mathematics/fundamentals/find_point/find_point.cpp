#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    int px, py, qx, qy, rx, ry;
    while(t--)
    {
        cin >> px >> py >> qx >> qy;    
        rx = 2 * qx - px;
        ry = 2 * qy - py;
        cout << rx << " " << ry << endl;
    }
    return 0;
}

