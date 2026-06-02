#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int empId;

public:
    Employee(string n, int id) : name(n), empId(id) {}

    void display() {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << empId << endl;
    }
};

// Single Inheritance
class Manager : public Employee {
protected:
    string department;

public:
    Manager(string n, int id, string d)
        : Employee(n, id), department(d) {}

    void display() {
        Employee::display();
        cout << "Department: " << department << endl;
    }
};

// Multilevel Inheritance
class TeamLead : public Manager {
private:
    int teamSize;

public:
    TeamLead(string n, int id, string d, int t)
        : Manager(n, id, d), teamSize(t) {}

    void display() {
        Manager::display();
        cout << "Team Size: " << teamSize << endl;
    }
};

// Hierarchical Inheritance
class HR : public Employee {
private:
    int recruitsHandled;

public:
    HR(string n, int id, int r)
        : Employee(n, id), recruitsHandled(r) {}

    void display() {
        Employee::display();
        cout << "Recruits Handled: " << recruitsHandled << endl;
    }
};

int main() {

    cout << "=== Single Inheritance ===" << endl;
    Manager m("kavya", 101, "Sales");
    m.display();

    cout << "\n=== Multilevel Inheritance ===" << endl;
    TeamLead tl("keerthana", 102, "IT", 8);
    tl.display();

    cout << "\n=== Hierarchical Inheritance ===" << endl;
    HR h("Priya", 103, 25);
    h.display();

    return 0;
}