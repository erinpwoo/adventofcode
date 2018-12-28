//PART 2 OF DAY 2
//Compiling w/ C++11: g++ -std=c++11 main.cpp -o main

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(int argv, char** argc) {
    ifstream file (argc[1]);
    string line;

    if (file.fail()) {
        cout << "Could not open file." << endl;
    }

    vector <string> vect;
    while (getline(file, line) && line.length() > 0) {
        vect.push_back(line);
    }

    string result;

    for (int i = 1; i < vect.size(); i++) {
        for (int j = 0; j < vect[i].length(); j++) {

            if (vect[i][j] != vect[i-1][j]) {
                
                string str1 = vect[i-1];
                string str2 = vect[i];
                str1.erase(j, 1);
                str2.erase(j, 1);

                if (str1 == str2) {
                    result = str1;
                    cout << str1 << " " << str2 << endl;
                }
            }
        }
    }
    
    cout << result << endl;

    file.close();
    return 0;
}