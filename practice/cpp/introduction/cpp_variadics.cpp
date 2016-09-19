template<bool...digits>
int reversed_binary_value()
{
    const int size = sizeof...(digits);
    int d[size] = {digits...};
    
    int res = 0;
    for (int pos = size - 1; pos >= 0; --pos)
    {
        res = 2 * res + static_cast<int>(d[pos]);
    }
    return res;
}
