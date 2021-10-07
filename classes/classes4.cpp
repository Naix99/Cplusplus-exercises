include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* This code deal with basic inheretence of classes. We have a base class "Person" and two classes, "Professor" and "Student" that
inherit some basic functionally from "Person" */
class Person {
    public:
        string name; 
        int age; 
        virtual void getdata(){
            cin >> name>>age;
        }
        virtual void putdata(){
            cout<< name <<" " << age << " ";
        }
};

class Professor : public Person{
    public:
        // Professor adds a number of publications and a curriculum id to person.
        int cur_id;
        int pn;
        static int id;
        Professor(){
            cur_id = id;
            id++;
        }
        void getdata(){
            Person::getdata();
            cin >> pn;
        }
        void putdata(){
            Person::putdata();
            cout<< pn << " " << cur_id << endl;
        }
};
// This defines and id variable ONLY in the enviroment of the class Professor. Really useful for assigning different id to different professors
int Professor::id=1;


class Student : public Person{
    public:
    // Students also have an id (different from Professors) and a marking
    int cur_id;
    int sumarks;
    static int id;
        Student(){
            cur_id = id;
            id++;
        }
        void getdata(){
            cin >> name;
            cin >> age;
            static int suma; static int anum;
            suma = 0;
            for (int i=0; i<6; i++){
                cin>>anum;
                suma += anum;
            }
            sumarks = suma;
        }
        void putdata(){
            cout<< this->name << " " << this->age << " " << this->sumarks << " " << this->cur_id << "\n";
        }
};
int Student::id=1;



int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
