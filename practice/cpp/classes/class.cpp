#include <iostream>
#include <sstream>

using namespace std;

class Student
{
    public:
        void set_age(int i_age) {age = i_age;}
        int get_age() const {return age;}
        
        string get_first_name() const {return first_name;}
        void set_first_name(string i_f_name) {first_name = i_f_name;}
        
        string get_last_name() const {return last_name;}
        void set_last_name(string i_l_name) {last_name = i_l_name;}
        
        int get_standard() const {return standard;}
        void set_standard(int i_standard) {standard = i_standard;}
        
        string to_string() const
        {
            stringstream s;
            s << age << "," << first_name << "," << last_name << "," << standard;
            return s.str();
        }
    
    private:
        int age;
        string first_name, last_name;
        int standard;
};

int main()
{
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}

