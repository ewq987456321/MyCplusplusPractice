#include "header.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

CheckRoom::CheckRoom(int type) { this->type = type; }

void CheckRoom::setStatus(bool status) { this->status = status; }

void CheckRoom::setPatientID(string ID) { this->patient_ID = ID; }

bool CheckRoom::getStatus() { return status; }

string CheckRoom::getPatientID() { return patient_ID; }

void CheckRoom::writePaper(vector<Patient> &arr) {
    writeFile(patient_ID);
    for (auto &i : arr) {
        if (i.getID() == patient_ID) {
            i.setStatus(false);
            break;
        }
    }
    status = false;
}

