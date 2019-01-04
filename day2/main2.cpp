//PART 2 OF DAY 2
//Compiling w/ C++11: g++ -std=c++11 main.cpp -o main

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

bool diffCharsIsOne(string str1, string str2) {
    /*
    map <char, int> map1;
    map <char, int> map2;

    for (char &c : str1) {
        if  (map1.find(c) != map1.end()) {
            map1.find(c)->second ++;
        }
        else {
            map1.insert(pair<char, int>(c, 1));
        }
    }
    for (char &c : str2) {
        if  (map2.find(c) != map2.end()) {
            map2.find(c)->second ++;
        }
        else {
            map2.insert(pair<char, int>(c, 1));
        }
    }
    
    map<char, int>::iterator itr1;
    map<char, int>::iterator itr2 = map2.begin();

    int diff = 0;

    for (itr1 = map1.begin(); itr1 != map1.end(); itr1++) {
        if (diff > 1) {
            return false;
        }
        else {
            if ((itr1->first != itr2->first) && (itr1->second != itr2->second)) {
                diff++;
            }
        }
    }
    

    if (diff == 0) {
        cout << "return false" << endl;
        return false;
    } else {
        int temp = 0;
        for (int i = 0; i < str1.length(); i++) {
            if (str1[i] != str2[i]) {
                temp++;
            }
        }
        if (temp > 1) {
            return false;
        }
    }
    return true;

    */
   if (str1 == str2) {
       return false;
   }
   int diff = 0; 

    for (int i = 0; i < str1.length(); i++) {
        if (diff > 1) {
            //cout << "false" << endl;
            return false;
        }
        if (str1[i] != str2[i]) {
            diff++;
        }
    }

    cout << str1 << " " << str2 << endl;
    return true;
    
}

string remainingStr(string str1, string str2) {
    string result;
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i]) {
            //cout << str1 << " " << str2 << endl;
            string temp = str1;
            string temp2 = str2;
            result = temp.erase(i, 1);
            if (result == temp2.erase(i, 1)) {
                return result;
            }
        }
    }
    return result;
}

string finalResult(vector <string> vect) {

    string result;

    for (int i = 0; i < vect.size(); i++) {
        for (int j = i; j < vect.size(); j++) {
            if ((diffCharsIsOne(vect[i], vect[j]) == true) && (i != j)) {
                cout << i << " " << vect[i] << " " << j << " "<< vect[j] << endl;
                result = remainingStr(vect[i], vect[j]);
                return result;
            }
        }
    }
    return result;
    
}

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

    //cout << diffCharsIsOne("asdfghjkl", "asdfghjkl") << endl;

    cout << finalResult(vect) << endl;

    file.close();
    return 0;
}