#include <fstream>
using namespace std;

// Open modes (can be combined with | operator)

ios::in      // Open for reading (default for ifstream)
ios::out     // Open for writing (default for ofstream) - truncates existing file
ios::app     // Append mode - writes at end of file
ios::ate     // Seek to end of file on open
ios::trunc   // Truncate (delete contents) on open
ios::binary  // Open in binary mode

// Examples

ifstream file1("data.txt");                           // Default: ios::in
ofstream file2("data.txt");                           // Default: ios::out | ios::trunc
ofstream file3("data.txt", ios::app);                 // Append mode
fstream  file4("data.txt", ios::in | ios::out);       // Read and write
ofstream file5("data.bin", ios::out | ios::binary);   // Binary output