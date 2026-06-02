#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    virtual void speak() {      
        cout << "Animal makes a sound" << endl;
    }

    void eat() {                
        cout << "Animal eats" << endl;
    }

    virtual ~Animal() {}        
};

class Dog : public Animal {
public:
    void speak() override {      
        cout << "Dog barks: Woof!" << endl;
    }

    void eat() {                 
        cout << "Dog eats kibble" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat meows: Meow!" << endl;
    }
};

int main() {
    Animal* animals[3];
    animals[0] = new Animal();
    animals[1] = new Dog();
    animals[2] = new Cat();

    

    cout << "=== Virtual functions (polymorphic) ===" << endl;

    for (int i = 0; i < 3; i++) {
        animals[i]->speak();   
    }

    cout << "\n=== Non-virtual functions (NOT polymorphic) ===" << endl;

    for (int i = 0; i < 3; i++) {
        animals[i]->eat();     
    }

    // Cleanup
    for (int i = 0; i < 3; i++) {
        delete animals[i];
    }

    return 0;
}