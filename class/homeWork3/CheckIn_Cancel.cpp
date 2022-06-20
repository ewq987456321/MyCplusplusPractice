#include "header.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int check_in(vector<CheckRoom> &arr, string ID) {
    for (auto &i : arr) {
        if (!(i.getStatus())) {
            cout << "請進入檢查室\n";
            i.setPatientID(ID);
            cout << i.getPatientID();
            i.setStatus(true);
            return true;
        }
    }
    cout << "請稍候\n";
    return 2;
}

bool cancel(vector<Patient> &arr) {
    string ID;
    cout << "請輸入要取消的ID: ";
    cin >> ID;
    for (auto &i : arr) {
        if (i.getID() == ID && i.getStatus() == 2) {
            i.setStatus(false);
            if (i.getType() == 1 || i.getType() == 2) {
                i.setCT(false);
                i.setMRI(false);
            }
            cout << "取消成功\n";
            return true;
        }
    }
    cout << "未找到\n";
    return false;
}
