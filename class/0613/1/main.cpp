#include "header.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    int func = 0;
    int arr_i[50] = {0};
    string arr_str[50];
    float arr_f[50] = {0};
    cout << "請選擇 1)整數 2)浮點數 3)字串 -1)結束: ";
    cin >> func;
    switch (func) {
    case 1:
        addArr(arr_i);
        break;
    case 2:
        addArr(arr_f);
        break;
    case 3:
        addArr(arr_str);
        break;
    case -1:
        break;
    default:
        cout << "輸入錯誤請重新輸入\n";
        break;
    }
}
