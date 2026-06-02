#include <iostream>
#include <string>
using namespace std;


class Shape {
    protected:
        string color;
    
    public:
        Shape(string c) : color(c) {}
        
        
        virtual double area() const = 0;
        virtual void draw() const = 0;
        
        // Concrete method
        string getColor() const { return color; }
        
        
        virtual ~Shape() {}
};

class Circle : public Shape {
    private:
        double radius;
    
    public:
        Circle(string c, double r) : Shape(c), radius(r) {}
        
        double area() const override {
            return 3.14159 * radius * radius;
        }
        
        void draw() const override {
            cout << "○ Drawing a " << color << " circle (r=" << radius 
                 << ", area=" << area() << ")" << endl;
        }
};

class Square : public Shape {
    private:
        double side;
    
    public:
        Square(string c, double s) : Shape(c), side(s) {}
        
        double area() const override {
            return side * side;
        }
        
        void draw() const override {
            cout << "□ Drawing a " << color << " square (side=" << side 
                 << ", area=" << area() << ")" << endl;
        }
};

int main() {
    
    
    Shape* shapes[2];
    shapes[0] = new Circle("Red", 5);
    shapes[1] = new Square("Blue", 4);
    
    for (int i = 0; i < 2; i++) {
        shapes[i]->draw();
    }
    
    for (int i = 0; i < 2; i++) {
        delete shapes[i];
    }
    
    return 0;
}