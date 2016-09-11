#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n, d, res = 0;
    cin >> n >> d;
    vector<int> arr(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> arr[pos];
    }
    
    for (int pos1 = 0; pos1 < n; ++pos1)
    {
        for (int pos2 = pos1 + 1; pos2 < n; ++pos2)
        {
            if (arr[pos2] > arr[pos1] + d)
            {
                break;
            }
            if (arr[pos2] == arr[pos1] + d)
            {
                for (int pos3 = pos2 + 1; pos3 < n; ++pos3)
                {
                    if (arr[pos3] > arr[pos2] + d)
                    {
                        break;
                    }
                    if (arr[pos3] == arr[pos2] + d)
                    {
                        res++;
                    }
                }
            }    
        }
    }
    
    cout << res << endl;
    
    return 0;
}

