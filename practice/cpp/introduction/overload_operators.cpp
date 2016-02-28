Complex operator+ (const Complex & i_left, const Complex & i_right)
{
    Complex c;
    c.a = i_left.a + i_right.a;
    c.b = i_left.b + i_right.b;
    
    return c;
}

ostream& operator<<(ostream & os, const Complex & i_value)
{
    os << i_value.a << "+i" << i_value.b << endl;
    return os;
}

