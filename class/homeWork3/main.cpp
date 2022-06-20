#include "header.h"
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    vector<Patient> patientArr;
    vector<CheckRoom> CT;
    vector<CheckRoom> MRI;
    vector<CheckRoom> X_RAY;
    vector<CheckRoom> UI;

    CT.push_back(CheckRoom(1));
    MRI.push_back(CheckRoom(2));
    X_RAY.push_back(CheckRoom(3));
    X_RAY.push_back(CheckRoom(3));
    X_RAY.push_back(CheckRoom(3));
    UI.push_back(CheckRoom(4));
    UI.push_back(CheckRoom(4));

    string ID;
    bool check = false;
    int func = 1;
    int type;
    do {
        cout << "請選擇 1)報到 2)取消報到 3)寫檢查報告 4)查詢報告 5)印出等待 -1)結束: ";
        cin >> func;
        switch (func) {
        case 1:
            check = false;
            cout << "請輸入ID: ";
            cin >> ID;
            for (auto &i : patientArr) {
                if (i.getID() == ID) {
                    if (i.getStatus() != 0) {
                        check = true;
                        cout << "重複報到\n";
                    } else {
                        check = true;
                        cout << "請選擇要報到的類型 1)CT 2)MRI 3)x-ray 4)超音波: ";
                        cin >> type;
                        switch (type) {
                        case 1:
                            if (i.setType(1)) i.setStatus(check_in(CT, ID));
                            break;
                        case 2:
                            if (i.setType(2)) i.setStatus(check_in(MRI, ID));
                            break;
                        case 3:
                            i.setType(3);
                            i.setStatus(check_in(X_RAY, ID));
                            break;
                        case 4:
                            i.setType(4);
                            i.setStatus(check_in(UI, ID));
                            break;
                        default:
                            cout << "input error, check_in fail\n";
                            break;
                        }
                    }
                    break;
                }
            }
            if (check == false) {
                patientArr.push_back(Patient(patientArr, ID));
                switch (patientArr[patientArr.size() - 1].getType()) {
                case 1:
                    patientArr[patientArr.size() - 1].setStatus(check_in(CT, ID));
                    break;
                case 2:
                    patientArr[patientArr.size() - 1].setStatus(check_in(MRI, ID));
                    break;
                case 3:
                    patientArr[patientArr.size() - 1].setStatus(check_in(X_RAY, ID));
                    break;
                case 4:
                    patientArr[patientArr.size() - 1].setStatus(check_in(UI, ID));
                    break;
                default:
                    cout << "input error, check_in fail\n";
                    break;
                }
            }
            break;
        case 2:
            cancel(patientArr);
            break;
        case 3:
            cout << "請選擇要報告的類型 1)CT 2)MRI 3)x-ray 4)超音波: ";
            cin >> type;
            cout << "input ID: ";
            cin >> ID;
            switch (type) {
            case 1:
                for (auto &i : CT) {
                    // cout << i.getPatientID() << i.getStatus();
                    if (i.getStatus() && i.getPatientID() == ID) {
                        cout << "請輸入病人ID: " << i.getPatientID() << " 的檢查報告:\n";
                        i.writePaper(patientArr);

                        for (auto &j : patientArr) {
                            if (j.getStatus() == 2 && j.getType() == 1) {
                                i.setStatus(true);
                                i.setPatientID(j.getID());
                                j.setStatus(true);
                                cout << j.getID() << "請至檢查室檢查\n";
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            case 2:
                for (auto &i : MRI) {
                    if (i.getStatus() && i.getPatientID() == ID) {
                        cout << "請輸入病人ID: " << i.getPatientID() << " 的檢查報告:\n";
                        i.writePaper(patientArr);

                        for (auto &j : patientArr) {
                            if (j.getStatus() == 2 && j.getType() == 2) {
                                i.setStatus(true);
                                i.setPatientID(j.getID());
                                j.setStatus(true);
                                cout << j.getID() << "請至檢查室檢查\n";
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            case 3:
                for (auto &i : X_RAY) {
                    if (i.getStatus() && i.getPatientID() == ID) {
                        cout << "請輸入病人ID: " << i.getPatientID() << " 的檢查報告:\n";
                        i.writePaper(patientArr);

                        for (auto &j : patientArr) {
                            if (j.getStatus() == 2 && j.getType() == 3) {
                                i.setStatus(true);
                                i.setPatientID(j.getID());
                                j.setStatus(true);
                                cout << j.getID() << "請至檢查室檢查\n";
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            case 4:
                for (auto &i : UI) {
                    if (i.getStatus() && i.getPatientID() == ID) {
                        cout << "請輸入病人ID: " << i.getPatientID() << " 的檢查報告:\n";
                        i.writePaper(patientArr);

                        for (auto &j : patientArr) {
                            if (j.getStatus() == 2 && j.getType() == 4) {
                                i.setStatus(true);
                                i.setPatientID(j.getID());
                                j.setStatus(true);
                                cout << j.getID() << "請至檢查室檢查\n";
                                break;
                            }
                        }
                        break;
                        break;
                    }
                }
                break;
            default:
                cout << " input error\n";
                break;
            }
            break;
        case 4:
            cout << "請輸入要查詢的病人ID: ";
            cin >> ID;
            for (auto &i : patientArr) {
                if (i.getID() == ID) i.readPaper();
            }
            break;
        case 5:
            cout << "請輸入要查詢的類型 1)CT 2)MRI 3)x-ray 4)超音波: ";
            cin >> type;
            switch (type) {
            case 1:
                printWaitPatient(1, patientArr);
                break;
            case 2:
                printWaitPatient(2, patientArr);
                break;
            case 3:
                printWaitPatient(3, patientArr);
                break;
            case 4:
                printWaitPatient(4, patientArr);
                break;
            default:
                cout << "innput error\n";
                break;
            }
            break;
        case -1:
            break;
        default:
            cout << "input error!\n";
            break;
        }
    } while (func != -1);

    return 0;
}
