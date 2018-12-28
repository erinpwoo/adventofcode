#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argv, char** argc) {

    //reading data from input.txt
    ifstream file (argc[1]);
    string line;

    if (file.fail()){
        cout << "Could not open file.\n";
    }

    int sum = 0;

    while (getline (file, line) && (line.length() > 0)) {
        char l = line[0];
        string temp = line.substr(1);
        char cstr[temp.size() + 1];
        strcpy(cstr, temp.c_str());

        int num = atoi(cstr);

        if (l == '+') {
            sum += num;
        }
        if (l == '-') {
            sum -= num;
        }
    }

    cout << "The resulting frequency is: " << sum << endl;

    file.close();
    return 0;
}