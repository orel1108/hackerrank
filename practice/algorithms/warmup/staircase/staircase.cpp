#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void print_staircase(int n)
{
    string s = "";
    for (int pos = 0; pos < n; pos++)
    {
        for (int ipos = 0; ipos < n - pos - 1; ipos++)
        {
            s += " ";    
        }
        for (int ipos = 0; ipos < pos + 1; ipos++)
        {
            s += "#";    
        }
        s += "\n";
    }
    
    cout << s;
}

int main(){
    int n;
    cin >> n;
    
    print_staircase(n);
    
    return 0;
}

