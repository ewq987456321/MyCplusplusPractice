#include "header.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;
map<int, string> Township = {
    {1, "花連市"}, {2, "鳳林鎮"}, {3, "玉里鎮"},  {4, "新城鄉"},  {5, "吉安鄉"},  {6, "壽豐鄉"},  {7, "光復鄉"},
    {8, "豐濱鄉"}, {9, "瑞穗鄉"}, {10, "富里鄉"}, {11, "秀林鄉"}, {12, "萬榮鄉"}, {13, "卓溪鄉"},
};

map<int, string> Type = {
    {1, "風景"},
    {2, "美食"},
    {3, "體驗"},
    {4, "探索"},
};

int find(View_spot arr[], string name, int length) {
    int i = 0;
    while (i < length) {
        if (arr[i].name == name) {
            return i;
        }
        i += 1;
    }
    return -1;
}

int add(View_spot arr[], int length) {
    string temp;
    int check;
    cout << "請輸入要新增的景點名稱: ";
    cin >> temp;
    check = find(arr, temp, length);
    cout << check;
    if (check == -1) {
        arr[length].name = temp;
        do {
            if (arr[length].type != -1 && arr[length].type < 1 || arr[length].type > 4)
                cout << "輸入錯誤請重新輸入\n";
            cout << "請選擇類型 1)風景 2)美食 3)體驗 4)探索: ";
            cin >> arr[length].type;
        } while (arr[length].type < 1 || arr[length].type > 4);
        do {
            if (arr[length].township != -1 && arr[length].township < 1 || arr[length].township > 13)
                cout << "輸入錯誤請重新輸入\n";
            cout << "請選則 "
                    " 1)花蓮市 2)鳳林鎮 3)玉里鎮 4)新城鄉 "
                    "5)吉安鄉 6)壽豐鄉 7)光復鄉 8)豐濱鄉 "
                    "9)瑞穗鄉 10)富里鄉 11)秀林鄉 12)萬榮鄉 13)卓溪鄉: ";
            cin >> arr[length].township;
        } while (arr[length].township < 1 || arr[length].township > 13);
        do {
            if (arr[length].longitude < -180 || arr[length].longitude > 180) cout << "輸入錯誤請重新輸入\n";
            cout << "請輸入該景點的精度: ";
            cin >> arr[length].longitude;
        } while (arr[length].longitude < -180 || arr[length].longitude > 180);
        do {
            if (arr[length].latitude < -90 || arr[length].latitude > 90) cout << "輸入錯誤請重新輸入\n";
            cout << "請輸入該景點的緯度: ";
            cin >> arr[length].latitude;
        } while (arr[length].latitude < -90 || arr[length].latitude > 90);
        return length + 1;
    } else {
        cout << "該景點已存在\n";
        return length;
    }
}

int del(View_spot arr[], int length) {
    string temp;
    int check;
    char char_del;
    cout << "請輸入要刪除的景點名稱: ";
    cin >> temp;
    check = find(arr, temp, length);
    if (check != -1) {
        cout << "name: " << arr[check].name << endl;
        cout << "township: " << Township[arr[check].township] << endl;
        cout << "type: " << Type[arr[check].type] << endl;
        cout << "longitude: " << arr[check].longitude << endl;
        cout << "latitude: " << arr[check].latitude << endl;
        cout << "確定要刪除嗎？(y/n)";
        cin >> char_del;
        if (char_del == 'y') {
            View_spot space;
            arr[check] = space;
            return length - 1;
        } else if (char_del != 'z') {
            cout << "輸入錯誤請重新輸入\n";
        }
    } else {
        cout << "未找到該景點\n";
    }
    return length;
}

void print(View_spot arr[], int length) {
    int i = 0;
    while (i < length) {
        if (arr[i].type != -1) {
            cout << "name: " << arr[i].name << endl;
            cout << "township: " << Township[arr[i].township] << endl;
            cout << "type: " << Type[arr[i].type] << endl;
            cout << "longitude: " << arr[i].longitude << endl;
            cout << "latitude: " << arr[i].latitude << endl << endl;
        }
        i += 1;
    }
}
void print_township(View_spot arr[], int length) {
    int i = 0;
    int choose = -1;
    do {
        if (choose != -1 && choose < 1 || choose > 13) cout << "輸入錯誤請重新輸入\n";
        cout << "請選則 "
                " 1)花蓮市 2)鳳林鎮 3)玉里鎮 4)新城鄉 "
                "5)吉安鄉 6)壽豐鄉 7)光復鄉 8)豐濱鄉 "
                "9)瑞穗鄉 10)富里鄉 11)秀林鄉 12)萬榮鄉 13)卓溪鄉: ";
        cin >> choose;
    } while (choose < 1 || choose > 13);
    while (i < length) {
        if (arr[i].township == choose) {
            cout << "name: " << arr[i].name << endl;
            cout << "township: " << Township[arr[i].township] << endl;
            cout << "type: " << Type[arr[i].type] << endl;
            cout << "longitude: " << arr[i].longitude << endl;
            cout << "latitude: " << arr[i].latitude << endl << endl;
        }
        i += 1;
    }
}
void print_type(View_spot arr[], int length) {
    int i = 0;
    int choose = -1;
    do {
        if (choose != -1 && choose < 1 || choose > 4) cout << "輸入錯誤請重新輸入\n";
        cout << "請選擇類型 1)風景 2)美食 3)體驗 4)探索: ";
        cin >> choose;
    } while (choose < 1 || choose > 4);
    while (i < length) {
        if (arr[i].type == choose) {
            cout << "name: " << arr[i].name << endl;
            cout << "township: " << Township[arr[i].township] << endl;
            cout << "type: " << Type[arr[i].type] << endl;
            cout << "longitude: " << arr[i].longitude << endl;
            cout << "latitude: " << arr[i].latitude << endl << endl;
        }
        i += 1;
    }
}
void sort_long(View_spot arr[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            if (arr[j].longitude < arr[i].longitude) {
                View_spot temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    print(arr, length);
}
void sort_la(View_spot arr[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            if (arr[j].latitude > arr[i].latitude) {
                View_spot temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    print(arr, length);
}
