#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream outfiles("example.txt");
    if (outfiles.is_open()) {
        outfiles << "Hello, file!" << endl;
        outfiles << "This is line 2." << endl;
        outfiles << "C++ file handling is easy!" << endl;
        outfiles.close();
        cout << "File written successfully!" << endl;

    } else {
        cout << "Error: Could not open file for writing!" << endl;
    }
    
    fstream inFile("example.txt");    // Open file for reading

if (inFile.is_open()) {
    string line;
    cout << "\nFile contents:" << endl;

    while (getline(inFile, line)) {    // Read line by line
        cout << line << endl;
    }

    inFile.close();    // Always close the file
}
else {
    cout << "Error: Could not open file for reading!" << endl;
}

return 0;
}