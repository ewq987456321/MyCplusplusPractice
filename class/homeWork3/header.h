#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <vector>
using namespace std;

class Patient {
    string ID = "";
    int status = false;
    int type = -1;
    bool CT = false;
    bool MRI = false;

public:
    Patient(vector<Patient> arr, string temp_ID); // PERF:
    void setID(string ID);                        // PERF:
    bool setType(int type);                       // PERF:
    void setStatus(int status);                   // PERF:
    void setCT(bool CT);                          // PERF:
    void setMRI(bool MRI);                        // PERF:
    string getID();                               // PERF:
    int getType();                                // PERF:
    int getStatus();                              // PERF:
    void readPaper();                             // PERF:
};

class CheckRoom {
    int type = -1;
    bool status = false;
    string patient_ID = "";

public:
    CheckRoom(int type);          // PERF:
    void setStatus(bool status);  // PERF:
    void setPatientID(string ID); // PERF:
    bool getStatus();             // PERF:
    string getPatientID();
    void writePaper(vector<Patient> &arr); // PERF:
};

void writeFile(string FILE_name); // PERF:
void readFile(string FILE_name);  // PERF:
void printWaitPatient(int type, vector<Patient> arr);
int check_in(vector<CheckRoom> &arr, string ID); // PERF:
bool cancel(vector<Patient> &arr);               // PERF:
#endif
