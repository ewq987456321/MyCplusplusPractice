#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int k = 0; k < T; k++) {
        int num;
        int max_num, min_num;
        long long max_amount = -99999999;
        cin >> num;
        int *arr = (int *)malloc(sizeof(int) * num);
        for (int i = 0; i < num; i++) {
            cin >> arr[i];
            if (i == 0)
                max_num = arr[i];
            if (i == 1) {
                min_num = arr[i];
                max_amount = max_num - min_num;
            }
            if ((max_num - arr[i]) > max_amount) {
                min_num = arr[i];
                max_amount = max_num - min_num;
            }
            if (arr[i] > max_num) {
                max_num = arr[i];
            }
        }
        cout << max_amount << endl;
        free(arr);
    }
}
