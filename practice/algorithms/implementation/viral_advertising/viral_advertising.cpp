#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(1, 2);
    while (n-- > 1)
    {
        arr.push_back((3 * arr.back()) / 2);
    }
    
    cout << accumulate(arr.begin(), arr.end(), 0) << endl;
    
    return 0;
}

