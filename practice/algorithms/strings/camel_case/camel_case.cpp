#include <string>
#include <iostream>
#include <numeric>
#include <cctype>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    int res = accumulate(s.begin(), s.end(), 1, 
                         [](int i_acc, char i_chr)
                         {
                            return i_acc + (isupper(i_chr) ? 1 : 0);    
                         });
    
    cout << res << endl;
    
    return 0;
}

