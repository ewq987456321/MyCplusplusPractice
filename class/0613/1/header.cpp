#include "header.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void addArr(int arr[]) {
    int i = 0;
    while (cin >> arr[i]) {
        i += 1;
    }
    sort(arr, arr + i);
    for (int j = 0; j < i; j++) {
        cout << arr[j] << " ";
    }
}

void addArr(float arr[]) {
    int i = 0;
    while (cin >> arr[i]) {
        i += 1;
    }
    sort(arr, arr + i);
    for (int j = 0; j < i; j++) {
        cout << arr[j] << " ";
    }
}

void addArr(string arr[]) {
    int i = 0;
    while (cin >> arr[i]) {
        i += 1;
    }
    sort(arr, arr + i);
    for (int j = 0; j < i; j++) {
        cout << arr[j] << " ";
    }
}
