class Box 
{
public:
    Box() : l(0), b(0), h(0) { BoxesCreated++; };
    Box(int l, int b, int h) : l(l), b(b), h(h) { BoxesCreated++; };
    Box(const Box& box)
    {
        l = box.l;
        b = box.b;
        h = box.h;
        BoxesCreated++;
    }
    
    int getLength() {return l;};
    int getBreadth() {return b;};
    int getHeight() {return h;};
    long long CalculateVolume() {return static_cast<long long>(l) * static_cast<long long>(b) * static_cast<long long>(h);};
    
    bool operator<(Box & box)
    {
        if (l == box.l)
        {
            if (b == box.b)
                return h < box.h;
            else
                return b < box.b;
        }
        else
            return l < box.l;
    }
    
    friend ostream& operator<<(ostream& out, Box B)
    {
        out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
        return out;
    }
    
    ~Box() { BoxesDestroyed++; };
    
private:
    int l, b, h;
};

