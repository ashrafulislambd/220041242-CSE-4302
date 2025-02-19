// ichar.cpp

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream infile("TEST.txt");

    while(true) {
        char ch;
        infile.get(ch);
        if(!infile) break;
        cout << ch;
    }

    cout << endl;
    return 0;
}