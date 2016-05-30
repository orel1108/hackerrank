#include <iostream>
#include <set>

using namespace std;

set<int> fib_seq()
{
    unsigned long long a, b, c;
    set<int> f;
    f.insert(0);
    f.insert(1);
    
    a = 0, b = 1;
    c = 0;
    while (c < 10000000000LL)
    {
        c = a + b;
        a = b;
        b = c;
        f.insert(c);
    }
    
    return f;
}

int main()
{
    int t;
    unsigned long long n;
    
    set<int> f = fib_seq();
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (f.find(n) != f.end())
        {
            cout << "IsFibo" << endl;
        }
        else
        {
            cout << "IsNotFibo" << endl;
        }
    }
    
    return 0;
}

