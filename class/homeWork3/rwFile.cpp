#include "header.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
void writeFile(string FILE_name) {
    fstream file(FILE_name, ios::in | ios::app);
    string temp;
    if (file.is_open()) {
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        getline(cin, temp);
        file << temp << endl;
    } else {
        cout << "file open error.\n";
    }
    file.close();
}

void readFile(string FILE_name) {
    fstream file(FILE_name, ios::in);
    string temp;
    if (file.is_open()) {
        while (getline(file, temp)) {
            cout << temp << endl;
        }
    } else {
        cout << "file open error.\n";
    }
    file.close();
}
