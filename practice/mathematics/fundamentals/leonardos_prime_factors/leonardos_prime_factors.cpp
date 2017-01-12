#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ull_t;

int main()
{
    std::vector<ull_t> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    std::vector<ull_t> prods(1, 1);
    int pos = 0;
    while (prods.back() <= 1000000000000000000ULL)
    {
        prods.push_back(prods.back() * primes[pos++]);
    }
    
    int n;
    ull_t x;
    
    cin >> n;
    while (n--)
    {
        cin >> x;
        std::cout << (std::distance(prods.begin(), std::upper_bound(prods.begin(), prods.end(), x)) - 1) << std::endl;
    }
    return 0;
}

