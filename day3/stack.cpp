#include<iostream>
using namespace std;

class Demo {
    public:
        int id;
        Demo(int i) {
            id = i;
            cout << "Construction called for object" << id << endl;
        }
        Demo() {
            cout << "Destructor called for object" << id << endl;
        }
};

int main() {
    cout << "---Stack object---" << endl;
    Demo stackObj(1);
    
    cout<< "\n---Heap object---" << endl;
    Demo* heapObj = new Demo(2);
    
    cout<< "\nStack object goes out of scope automatically..." << endl;
    
    cout<< "Heap object must be explicitly deleted..."<< endl;
    delete heapObj;
    
    cout<< "\nEnd of main()" << endl;
    return 0;
}