#include "header.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printWaitPatient(int type, vector<Patient> arr) {
    for (auto &i : arr) {
        if (i.getType() == type && i.getStatus() == 2) {
            cout << i.getID() << endl;
        }
    }
}
