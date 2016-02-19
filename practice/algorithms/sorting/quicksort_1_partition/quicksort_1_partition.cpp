#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void partition(vector <int>  ar)
{
    vector<int> smaller, equal, greater;
    equal.push_back(ar[0]);
    for (int i = 1; i < ar.size(); i++)
    {
        if (ar[i] < ar[0])
        {
            smaller.push_back(ar[i]);
        }
        else if (ar[i] == ar[0])
        {
            equal.push_back(ar[i]);
        }
        else
        {
            greater.push_back(ar[i]);
        }
    }
    for (auto v : smaller)
    {
        cout << v << " ";
    }
    for (auto v : equal)
    {
        cout << v << " ";
    }
    for (auto v : greater)
    {
        cout << v << " ";
    }
}
int main(void) {
   vector <int>  _ar;
   int _ar_size;
   cin >> _ar_size;
    
     for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp); 
    }

   partition(_ar);
   
   return 0;
}

