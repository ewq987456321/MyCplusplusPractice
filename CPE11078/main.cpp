#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int k = 0; k < T; k++) {
        int num;
        long long max_amount = -99999999;
        int A, B, temp = -1;
        cin >> num;
        int *arr = (int *)malloc(sizeof(int) * num);
        for (int i = 0; i < num; i++) {
            cin >> arr[i];
            if (i == 0)
                A = arr[i];
            if (i == 1) {
                B = arr[i];
                max_amount = A - B;
            }
            if (temp != -1 && arr[i] < B) {
                A = temp;
                temp = -1;
            }
            if (arr[i] > A)
                temp = arr[i];
            if (arr[i] < B) {
                max_amount = A - arr[i];
                B = arr[i];
            }
            // cout << max_amount << " " << temp << endl;
        }
        cout << max_amount << endl;
        free(arr);
    }
}
