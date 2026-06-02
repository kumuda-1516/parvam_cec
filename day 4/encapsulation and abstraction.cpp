#include <iostream>
#include <string>
using namespace std;

class Temperature {
private:
    double celsius;

    // Helper (private) - not exposed to users
    double toFahrenheit() const {
        return (celsius * 9.0 / 5.0) + 32;
    }

    double toKelvin() const {
        return celsius + 273.15;
    }

public:
    Temperature() : celsius(0) {}

    void setCelsius(double temp) {
        celsius = temp;
    }

    void displayTemperature() const {
        cout << "Celsius: " << celsius << "°C" << endl;
        cout << "Fahrenheit: " << toFahrenheit() << "°F" << endl;
        cout << "Kelvin: " << toKelvin() << "K" << endl;
    }
};

int main() {
    Temperature temp;

    temp.setCelsius(25);
    temp.displayTemperature();

    return 0;
}