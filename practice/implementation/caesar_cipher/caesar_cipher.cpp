#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;


int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    
    string cipher;
    transform(s.cbegin(), s.cend(), back_inserter(cipher), 
              [k](char m) -> char
             {
                 if (m >= 'a' && m <= 'z')
                 {
                    return (m - 'a' + k) % 26 + 'a';
                 }
                 else if (m >= 'A' && m <= 'Z')
                 {
                    return (m - 'A' + k) % 26 + 'A';
                 }
                 else
                 {
                    return m;    
                 }
             });
    cout << cipher << endl;
    
    return 0;
}

