//PART 1 OF DAY 2
//Compiling w/ C++11: g++ -std=c++11 main.cpp -o main

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main(int argv, char** argc) {
    ifstream file (argc[1]);
    string line;

    if (file.fail()) {
        cout << "Could not open file." << endl;
    }

    int threeCount = 0;
    int twoCount = 0;
    while (getline(file, line) && line.length() > 0) {
        unordered_map<char, int> table;
        for (int i = 0; i < line.length(); i++) {
            table[line[i]]++;
        }
        bool foundTwo = false;
        bool foundThree = false;
        for (auto i : table) {
            if ((i.second == 2) && (foundTwo == false)) {
                twoCount++;
                foundTwo = true;
            }
            if ((i.second == 3) && (foundThree == false)) {
                threeCount++;
                foundThree = true;
            }
        }
        
    }

    int checksum = threeCount * twoCount;
    cout << "Checksum: " << checksum << endl;

    file.close();
    return 0;
}