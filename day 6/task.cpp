#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    void display(string name) {
        cout << "Name: " << name << endl;
    }

    void display(string name, int attendance) {
        cout << "Name: " << name
             << ", Attendance: " << attendance << "%" << endl;
    }

    void display(string name, int attendance, double fee) {
        cout << "Name: " << name
             << ", Attendance: " << attendance << "%"
             << ", Fee: " << fee << endl;
    }

    void display(string name, int attendance, double fee, int marks) {
        cout << "Name: " << name
             << ", Attendance: " << attendance << "%"
             << ", Fee: " << fee
             << ", Marks: " << marks << endl;
    }
};

int main() {
    Student s;

    s.display("kumuda", 90);
    s.display("kavya", 85);
    s.display("kiran", 85, 25000.50);
    s.display("kiran", 85, 25000.50, 92);

    return 0;
}