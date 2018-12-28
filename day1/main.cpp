#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cstring>
#include <unordered_set>

using namespace std;

int main(int argv, char** argc) {

    //reading data from input.txt
    ifstream file (argc[1]);
    string line;

    if (file.fail()){
        cout << "Could not open file.\n";
    }

    int sum = 0;
    unordered_set<int> sums; //unordered_set has O(1) lookup
    sums.insert(0);
    bool found = false;
    while (getline (file, line) && (line.length() > 0) && (found == false)) {
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

        if (sums.find(sum) == sums.end()) {
            sums.insert(sum);
        }
        else {
            found = true;
        }
    }
    file.close();
    cout << sum << endl;
    return 0;
}