#include<iostream>
#include<string>
using namespace std;
class student {
    public:
        string name;
        int age;
        double Cgpa;
        student(string n, int a,double c) {
            name = n;
            age = a;
            Cgpa = c;
            cout << "Parameterized constructor called for: " << name << endl;
        }
        void display() {
            cout << name  << "| Age:"<< age << "| CGPA:" << Cgpa << endl;
        }
};

int main() {
    student s1("Alice", 20, 3.5);
    student s2("Bob", 22, 3.8);
    
    cout << "\nStudent Details:" << endl;
    s1.display();
    s2.display();
    
    return 0;
}