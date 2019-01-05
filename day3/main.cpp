#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(int argv, char** argc) {
    ifstream file (argc[1]);
    string line;

    if (file.fail()) {
        cout << "Could not open file." << endl;
    }

    while (getline(file, line)) {

    }

    return 0;
}