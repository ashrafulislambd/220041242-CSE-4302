#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 100;
int buff[MAX];

int main() {
    for(int i=0; i<MAX; i++)
        buff[i] = i;
    
    ofstream os("edata.dat", ios::binary);
    os.write(reinterpret_cast<char*>(buff), MAX*sizeof(int));
    os.close();

    ifstream is("edata.dat", ios::binary);
    is.read(reinterpret_cast<char*>(buff), MAX*sizeof(int));

    for(int i=0; i<MAX; i++) {
        if(buff[i] != i) {
            cout << "Data is incorrect!" << endl;
            return 1;
        }
    }

    cout << "Data is correct!" << endl;
    return 0;
}