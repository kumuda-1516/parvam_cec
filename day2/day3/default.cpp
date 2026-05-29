#include<iostream>
using namespace std;

class student {
    public:
        string name;
        int age;
        student() {
            name = "unknown";
            age = 0;
            cout << "Default constructor called for: " << name << endl;
        }
        void display() {
            cout << "Name: " << name << ", Age: " << age << endl;
        }
};
int main() {
    student s1; 
    s1.display();
    student s2; 
    return 0;
}