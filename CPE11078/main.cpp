#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int k = 0; k < T; k++) {
        int num;
        long long max_amount = -99999999;
        cin >> num;
        int *arr = (int *)malloc(sizeof(int) * num);
        for (int i = 0; i < num; i++) {
            cin >> arr[i];
            for (int j = 0; j < i && i != 0; j++) {
                if ((arr[j] - arr[i]) > max_amount)
                    max_amount = (arr[j] - arr[i]);
            }
        }
        cout << max_amount << endl;
    }
}
