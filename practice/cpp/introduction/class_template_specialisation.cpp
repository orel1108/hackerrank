template<>
struct Traits<Color>
{
    static string name(int i_idx)
    {
        if (i_idx == 0)
        {
            return "red";
        }
        if (i_idx == 1)
        {
            return "green";
        }
        if (i_idx == 2)
        {
            return "orange";   
        }
        
        return "unknown";
    }
};

template<>
struct Traits<Fruit>
{
    static string name(int i_idx)
    {
        if (i_idx == 0)
        {
            return "apple";
        }
        if (i_idx == 1)
        {
            return "orange";
        }
        if (i_idx == 2)
        {
            return "pear";   
        }
        
        return "unknown";
    }
};

