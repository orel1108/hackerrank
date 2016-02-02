#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int roundVal(double value)
{
    int res = (int)value;
    return (value - res) >= 0.5 ? (res + 1) : res;
}

int main()
{
    string message;
    cin >> message;
    
    size_t len = message.size();
    
    int a = sqrt(len);
    int b = ceil(sqrt(len));
    
    int width = fmax(a, b);
    int height = roundVal((double)len / width);
    if (width * height < len)
    {
        height++;
    }
    
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if ((i + j * width) < len)
            {
                cout << message[i + j * width];
            }
        }
        if(i < width - 1)
        {
            cout << " ";
        }
    }

    return 0;
}

