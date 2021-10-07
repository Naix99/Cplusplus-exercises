#include <iostream>
#include <sstream>
using namespace std;

/*
A code with a class that saves the basic information (age, first and last name and standard grade) of a student.
*/
class Student {
    private:
        int age;
        int standard;
        string first_name;
        string last_name;
    public:
        void set_age(int a) {
            age = a;
        }
        void set_standard(int a) {
            standard = a;
        }
        void set_first_name(string a) {
            first_name = a;
        }
        void set_last_name(string a) {
            last_name = a;
        }
        
        int get_age() {
            return age;
        }
        int get_standard(){
            return standard;
        }
        string get_first_name(){
            return first_name;
        }
        string get_last_name(){
            return last_name;
        }
         string to_string(){
            string info;
            info = std::to_string(age);
            info = info + "," + first_name + "," + last_name + ",";
            info = info + std::to_string(standard);
            return info;
        }
};


int main() {
    int age, standard;
    string first_name, last_name;
    // This part reads input for the information.
    cin >> age >> first_name >> last_name >> standard;
    
    // This part creates the student object and set the corresponding values to the inputs given.
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    // This part print the student information. Note: It could be done better by overriding the operator "<<" for the student class.
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}