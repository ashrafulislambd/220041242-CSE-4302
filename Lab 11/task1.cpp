//ochar.cpp

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string str = "IUT is a great institute. "
                 "but unfortunately, here CGPA matters.";
    ofstream outfile("TEST.txt");
    for(char c : str) {
        outfile.put(c);
    }
    cout << "File Written" << endl;
    return 0;
}