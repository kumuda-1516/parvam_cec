#include <iostream>
using namespace std;

int main() {

    int *p = new int;
    *p = 42;
    cout << "Value :" << *p << endl;
    delete p;
    p =  nullptr;
    int* q = new int(100);
    cout << "Value :" << *q << endl;
    delete q;

    return 0;
}