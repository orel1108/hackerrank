#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

vector<int> parseInts(string str)
{
    stringstream s(str);
    char c;
    int d;
    vector<int> res;
    while (!s.eof())
    {
        s >> d;
        s >> c;
        res.push_back(d);
    }
    return res;
}

int main()
{
    string str;
    cin >> str;

    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << "\n";
    }
    
    return 0;
}

