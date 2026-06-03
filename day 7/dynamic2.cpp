#include<iostream>
#include<string>
using namespace std;

class Student {
public:
    string name;
    int age;

    Student(string n, int a) : name(n), age(a) {}

    void display() {
        cout << name <<" ( " << age << " years old)" << endl;
    }
};
 int main() {
    Student* s1 = new Student("kumuu", 20);

    cout << "Name:"<<s1->name << endl;
    cout << "Age:" << s1->age << endl;
    s1->display();

    (*s1).display();

    delete s1;
    return 0;
}