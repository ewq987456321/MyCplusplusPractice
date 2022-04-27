#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

struct Account {
    char account[100] = "";
};

void print_all(Account *arr, int num) {
    bool check = false;
    for (int i = 0; i < num; i++) {
        if (strcmp(arr[i].account, "") != 0) {
            cout << arr[i].account << endl;
            check = true;
        }
    }
    if (!check)
        cout << "尚未輸入任何帳號" << endl;
}

void del_account(Account *arr, int num) {
    bool check = false;
    char temp[100];
    cout << "請輸入欲刪除帳號" << endl;
    cin >> temp;
    for (int i = 0; i < num; i++) {
        if (strcmp(arr[i].account, temp) == 0) {
            check = true;
            strcpy(arr[i].account, "");
            break;
        }
    }
    if (!check)
        cout << "查無此帳號\n";
}

void search_account(Account *arr, int num) {
    bool check = false;
    char temp[100];
    cout << "請輸入要查詢的帳號：";
    cin >> temp;
    for (int i = 0; i < num; i++) {
        if (strcmp(temp, arr[i].account) == 0) {
            check = true;
            cout << "帳號：" << temp << "index為" << i << endl;
            break;
        }
    }
    if (!check)
        cout << "查無此人帳號\n";
}

void insert_account_and_sort(Account *arr, int num) {
    char temp[100];
    int center = (int) floor(num / 2.0);
    bool check;
    do {
        check = false;
        cout << "請輸入要新增的帳號：";
        cin >> temp;
        for (int i = 0; i < num; i++) {
            if (strcmp(temp, arr[i].account) == 0) {
                break;
            }
        }
        check = true;
    } while (!check);
    if (strcmp(arr[(num - 1) / 2].account, "") == 0) {
        strcpy(arr[(num - 1) / 2].account, temp);
    } else {
        
        strcpy(arr[pos].account, temp);
    }
}

int main() {
    int num, func = 1;
    cout << "請輸入要存多少帳號：";
    cin >> num;
    Account *account = (Account *) malloc(sizeof(Account) * num);
    do {
        cout << "請輸入預選功能 1)顯示所有帳號 2)刪除帳號 3)查詢帳號 4)新增帳號 -1)結束： ";
        cin >> func;
        switch (func) {
            case 1:
                print_all(account, num);
                break;
            case 2:
                del_account(account, num);
                break;
            case 3:
                search_account(account, num);
                break;
            case 4:
                insert_account_and_sort(account, num);
        }
    } while (func != -1);
    free(account);
    return 0;
}
