#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    long long A, B;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        double SA = sqrt(static_cast<double>(A));
        double SB = sqrt(static_cast<double>(B));
        
        int IA = (int)sqrt(static_cast<double>(A));
        int IB = (int)sqrt(static_cast<double>(B));
        
        if (IA < SA)
        {
            IA++;
        }
        cout << (IB - IA + 1) << "\n";
        
    }
    return 0;
}
