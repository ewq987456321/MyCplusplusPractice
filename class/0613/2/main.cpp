#include "header.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    int func = 0;
    int length = 0;
    View_spot view_spot[50];
    do {
        cout << "請選擇 1)新增 2)刪除 3)印出全部 4)根據鄉鎮 5)根據類型 6)依經度排序 7)依緯度排序 -1)退出: ";
        cin >> func;
        switch (func) {
        case 1:
            length = add(view_spot, length);
            break;
        case 2:
            length = del(view_spot, length);
            break;
        case 3:
            print(view_spot, length);
            break;
        case 4:
            print_township(view_spot, length);
            break;
        case 5:
            print_type(view_spot, length);
            break;
        case 6:
            sort_long(view_spot, length);
            break;
        case 7:
            sort_la(view_spot, length);
        case -1:
            break;
        default:
            cout << "輸入錯誤請重新輸入\n";
            break;
        }
    } while (func != -1);
    return 0;
}
