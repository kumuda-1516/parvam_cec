#include<iostream>
using namespace std;

class Student {
    private:
        string name;
        int age;
        double cgpa;

    public:
        string getName() const { return name;}
        int getAge() const { return age;}
        double getCgpa() const { return cgpa;}

        void setName (const string& n) { name = n; }
        void setAge (int a) {
            if (a>0 && a<150) {
                age = a;
            } else {
                cout << "Invalid age!" << endl;
            }
        }
        void setCgpa (double c) {
            if (c>=0.0 && c<=10.0) {
                cgpa = c;
            } else {
                cout << "Invalid CGPA! Must be between 0.0 and 10.0." << endl;
            }
        }
    };
        
    int main() {
        Student s;
        s.setName("Alice");
        s.setAge(20);
        s.setCgpa(3.5);
        
        cout << "Student Details:" << endl;
        cout << "Name: " << s.getName() << endl;
        cout << "Age: " << s.getAge() << endl;
        cout << "CGPA: " << s.getCgpa() << endl;
        
        return 0;
    }