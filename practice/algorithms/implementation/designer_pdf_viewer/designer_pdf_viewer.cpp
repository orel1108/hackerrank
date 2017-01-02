#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> h(26);
    for (int h_i = 0; h_i < 26; ++h_i)
    {
       cin >> h[h_i];
    }
    
    string word;
    cin >> word;
    
    int max_h = 0;
    for (int pos = 0; pos < word.size(); ++pos)
    {
        int curr_pos = word[pos] - 'a';
        max_h = max(max_h, h[curr_pos]);
    }
    
    cout << max_h * word.size() << endl;
    
    return 0;
}

