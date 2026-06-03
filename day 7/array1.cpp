#include<iostream>
#include<string>
using namespace std;

template<typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}
int main() {
    cout<< "Max of 3 and 7: " << getMax(3, 7) << endl;
    cout << "Max of 3.5 and 2.1: " << getMax(3.5, 2.1) << endl;
    cout << "Max of 'a' and 'z': " << getMax('a', 'z') << endl;

    cout<<"Max (explicit) of 3 and 7: " << getMax<double>(3, 7) << endl;

    cout << "Add int + double: " << add(5, 2.5) << endl;
    cout << "Add string + string: " << add(to_string(42), to_string(100)) << endl;

    return 0;


}