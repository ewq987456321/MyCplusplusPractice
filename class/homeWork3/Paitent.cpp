#include "header.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool find(vector<Patient> arr, string target) {
    cout << "333";
    for (auto &i : arr) {
        cout << "111";
        if (i.getID() == target) {
            return true;
        }
    }
    cout << "222";
    return false;
}

string Patient::getID() { return ID; }

int Patient::getStatus() { return status; }

int Patient::getType() { return type; }

void Patient::setID(string ID) { this->ID = ID; }

bool Patient::setType(int type) {
    if (type == 1 && MRI) {
        cout << "CT or MRI 一天只能做一項\n";
        return false;
    } else if (type == 2 && CT) {
        cout << "CT or MRI 一天只能做一項\n";
        return false;
    } else {
        this->type = type;
        if (type == 1 || type == 2) {
            MRI = true;
            CT = true;
        }
        return true;
    }
}

void Patient::setStatus(int status) { this->status = status; }

void Patient::setCT(bool CT) { this->CT = CT; }

void Patient::setMRI(bool MRI) { this->MRI = MRI; }

Patient::Patient(vector<Patient> arr, string temp_ID) {
    bool check = false;
    int temp_type = -1;
    setID(temp_ID);
    do {
        if (temp_type != -1 && temp_type < 1 || temp_type > 4) cout << "輸入錯誤請重新輸入\n";
        cout << "請選擇 1)CT 2)MRI 3)X-ray 4)超音波: ";
        cin >> temp_type;
    } while (temp_type < 1 || temp_type > 4);
    setType(temp_type);
}

void Patient::readPaper() { readFile(this->ID); }
