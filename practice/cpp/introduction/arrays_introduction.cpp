#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{    
    int N;
    int arr[1001];
    cin >> N;
    
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    
    for (int i = N - 1; i > -1; --i)
        cout << arr[i] << " ";
    
    return 0;
}

