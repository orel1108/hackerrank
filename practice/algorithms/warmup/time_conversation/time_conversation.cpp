#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main(){
    string time;
    cin >> time;
    
    int h, m, s;
    h = 10 * static_cast<int>(time[0] - '0') + static_cast<int>(time[1] - '0');
    m = 10 * static_cast<int>(time[3] - '0') + static_cast<int>(time[4] - '0');
    s = 10 * static_cast<int>(time[6] - '0') + static_cast<int>(time[7] - '0');

    if (h < 12 && time[8] == 'P')
    {
        h += 12;
    }
    if (h == 12 && time[8] == 'A')
    {
        h = 0;    
    }

    stringstream ss;
    
    if (h < 10)
    {
        ss << "0";    
    }
    ss << h << ":";
    
    if (m < 10)
    {
        ss << "0";    
    }
    ss << m << ":";
    
    if (s < 10)
    {
        ss << "0";    
    }
    ss << s;
    
    cout << ss.str();
    
    return 0;
}

