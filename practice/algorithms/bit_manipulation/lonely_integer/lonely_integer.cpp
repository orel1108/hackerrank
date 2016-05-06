#include <iostream>
#include <vector>

using namespace std;
int lonely_integer(const vector<int> & i_arr)
{
    int res = 0;
    for (int pos = 0; pos < i_arr.size(); ++pos)
    {
        res ^= i_arr[pos];
    }
    
    return res;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> arr[pos];
    }
    
    cout << lonely_integer(arr) << endl;
    
    return 0;
}

