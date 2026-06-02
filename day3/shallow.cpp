#include<iostream>
#include<string>
using namespace std;

class Rectangle {
    private:
        double length;
        double width;
    public:
        Rectangle() {
            length = 0;
            width = 0;
            cout << "Default constructor" << endl;
        }

        Rectangle(double side) {
            length = side;
            width = side;
            cout << "Square constructor" << endl;
        }
        Rectangle(double l, double w) {
            length = l;
            width = w;
            cout << "Two-parameter constructor" << endl;
        }

        Rectangle(const Rectangle& r) {
            length = r.length;
            width = r.width;
            cout << "Copy constructor" << endl;
        }

        double area() {
            return length * width;
        }
    };
    int main() {
        Rectangle r1;
        Rectangle r2(5);
        Rectangle r3(4,6);
        Rectangle r4 = r3;

        cout << "\nAreas:" << r1.area() << ", " << r2.area() << ", " << r3.area() << ", " << r4.area() <<  endl;
   

    return 0;
}

        
    