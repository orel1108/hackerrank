template<typename T>
class AddElements
{
    public:
        AddElements(T i_element) : m_element(i_element){}
        T add(T i_element) {return i_element + m_element;}
    private:
        T m_element;
};

template<>
class AddElements<string>
{
    public:
        AddElements(string i_string) : m_string(i_string) {}
        string concatenate(string i_string) {return m_string + i_string;}
    private:
        string m_string;
};
