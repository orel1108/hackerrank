class Rectangle
{
public:
    void Display() { cout << width << " " << height << endl; }
protected:
    int width, height;
};

class RectangleArea : public Rectangle
{
public:
    void Input() { cin >> width >> height; }
    void Display() { cout << width * height << endl; }
};
