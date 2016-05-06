#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;

string decrypt(const string & i_enc, int i_n, int i_k)
{
    vector<int> bits;
    transform(i_enc.begin(), i_enc.end(), back_inserter(bits), 
              [](char i_c)
              { 
                  return static_cast<int>(i_c - '0');
              });
    
    vector<int> d(1, bits[0]);
    for (int k = 1; k < min(i_k, i_n); ++k)
    {
        d.push_back(bits[k - 1] ^ bits[k]);
    }
    for (int k = i_k; k < i_n; ++k)
    {
        d.push_back(bits[k - 1] ^ bits[k] ^ d[k - i_k]);
    }
    
    string dec;
    transform(d.begin(), d.end(), back_inserter(dec), 
             [](int c)
             {
                return static_cast<char>(c + '0'); 
             });
    
    return dec;
}

int main()
{
    int n, k;
    cin >> n >> k;
    
    string enc;
    cin >> enc;
    
    cout << decrypt(enc, n, k) << endl;
    
    return 0;
}

