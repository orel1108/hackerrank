class Person
{
protected:
    string name;
    int age;
public:
    virtual void getdata() {};
    virtual void putdata() {};
};

class Student : public Person
{
    int marks[6];
    int s = 0;
    int id;
    static int cur_id;
public:
    Student() { id = cur_id++;}
    void getdata()
    {
        cin >> name >> age;
        for (int i = 0; i < 6; i++)
        {
            cin >> marks[i];
            s += marks[i];
        }
    }
    
    void putdata()
    {
        cout << name << " " << age << " " << s << " " << id << endl;;    
    }
};

class Professor : public Person
{
    int publications;
    int id;
    static int cur_id;
public:
    Professor() {id = cur_id++;}
    void getdata()
    {
        cin >> this->name >> this->age >> this->publications;
    }
    
    void putdata()
    {
        cout << this->name << " " << this->age << " " << this->publications << " " << id << endl;;    
    }
    
    
};

int Student::cur_id = 1;
int Professor::cur_id = 1;
