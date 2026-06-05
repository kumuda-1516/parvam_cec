#include <iostream>
#include <stdexcept>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Subtraction
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Unary minus
    Complex operator-() const {
        return Complex(-real, -imag);
    }

    // Equality
    bool operator==(const Complex& other) const {
        return (real == other.real) && (imag == other.imag);
    }

    // Prefix ++
    Complex& operator++() {
        ++real;
        ++imag;
        return *this;
    }

    // Postfix ++
    Complex operator++(int) {
        Complex temp = *this;
        real++;
        imag++;
        return temp;
    }

    // Subscript operator
    double operator[](int index) const {
        if (index == 0)
            return real;
        if (index == 1)
            return imag;

        throw out_of_range("Index must be 0 or 1");
    }

    friend ostream& operator<<(ostream& os, const Complex& c);
    friend istream& operator>>(istream& is, Complex& c);
};

// Output operator
ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real;

    if (c.imag >= 0)
        os << " + " << c.imag << "i";
    else
        os << " - " << -c.imag << "i";

    return os;
}

// Input operator
istream& operator>>(istream& is, Complex& c) {
    cout << "Enter real part: ";
    is >> c.real;

    cout << "Enter imaginary part: ";
    is >> c.imag;

    return is;
}

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    cout << "c1 + c2 = " << (c1 + c2) << endl;
    cout << "c1 - c2 = " << (c1 - c2) << endl;
    cout << "-c1 = " << (-c1) << endl;

    cout << "c1 == c2: "
         << (c1 == c2 ? "true" : "false") << endl;

    cout << "c1++ = " << (c1++) << ", after: " << c1 << endl;
    cout << "++c1 = " << (++c1) << endl;

    cout << "c1[0] = " << c1[0]
         << ", c1[1] = " << c1[1] << endl;

    return 0;
}