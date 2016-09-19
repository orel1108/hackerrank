class BadLengthException : public exception
{
public:
    BadLengthException(int n)
        : m_n(n)
    {}
    
    virtual char const * what() const noexcept
    { 
        return to_string(m_n).c_str(); 
    }
    
private:
    int m_n;    
};
