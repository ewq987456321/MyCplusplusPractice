#include "header.h"
#include <iostream>
#include <string>

using namespace std;
int main() {
    int func1 = 1, func2 = 1;
    work *Whead = NULL;
    work_type *Thead = NULL;
    group *Ghead = NULL;
    do {
        cout << endl << "--------------------------------------------------------" << endl;
        cout << "請選擇 1)管理小組 2)管理類型 3)管理任務 -1)離開: ";
        cin >> func1;
        switch (func1) {
        case 1:
            do {
                cout << "請選擇 1)新增小組 2)修改小組 -1)結束: ";
                cin >> func2;
                switch (func2) {
                case 1:
                    add_group(&Ghead);
                    break;
                case 2:
                    modify_group(Ghead);
                    break;
                case -1:
                    break;
                default:
                    cout << "輸入錯誤請重新輸入\n";
                    break;
                }
            } while (func2 != 1 && func2 != 2 && func2 != -1);
            break;
        case 2:
            do {
                cout << "請選擇 1)新增類別 2)修改類別名稱 -1)結束: ";
                cin >> func2;
                switch (func2) {
                case 1:
                    add_workType(&Thead);
                    break;
                case 2:
                    modify_workType(Thead);
                    break;
                case -1:
                    break;
                default:
                    cout << "輸入錯誤請重新輸入\n";
                    break;
                }
            } while (func2 != 1 && func2 != 2 && func2 != -1);
            break;
        case 3:
            do {
                cout << "請選擇 1)新增任務 2)修改任務 3)印出所有任務 -1)結束: ";
                cin >> func2;
                switch (func2) {
                case 1:
                    add_work(&Whead, &Ghead, &Thead);
                    break;
                case 2:
                    modify_work(Whead, Thead, Ghead);
                    break;
                case 3:
                    print_works(Whead);
                    break;
                case -1:
                    break;
                default:
                    cout << "輸入錯誤請重新輸入\n";
                    break;
                }
            } while (func2 != 1 && func2 != 2 && func2 != 3 && func2 != -1);
            break;
        case -1:
            free_LK(Whead, Ghead, Thead);
            break;
        default:
            cout << "輸入錯誤請重新輸入\n";
            break;
        }
    } while (func1 != -1);
}
