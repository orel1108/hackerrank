#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>

using namespace std;

void insertionSort(int ar_size, int *  ar)
{
    for (int i = 1; i < ar_size; i++)
    {
        int j = i;
        while (j > 0 && ar[i] < ar[j - 1])
        {
            j--;
        }
        
        int v = ar[i];
        for (int k = i; k > j; k--)
        {
            ar[k] = ar[k - 1];
        }
        ar[j] = v;
        
        for (int j = 0; j < ar_size; j++)
        {
            cout << ar[j] << " ";
        }
        cout << endl;
    }

}
int main(void) {
   
    int _ar_size;
    cin >> _ar_size;
    
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        cin >> _ar[_ar_i];
    }

   insertionSort(_ar_size, _ar);
   
   return 0;
}

