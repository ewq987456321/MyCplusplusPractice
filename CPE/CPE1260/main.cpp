#include <iostream>

using namespace std;

int main() {
    int T = 0;
    scanf("%d", &T);
    for (int l = 0; l < T; l++) {
        int num;
        long long sum = 0;
        scanf("%d", &num);
        int *arr = (int *)malloc(sizeof(int) * num);
        for (int i = 0; i < num; i++) {
            scanf("%d", &arr[i]);
            if (i != 0) {
                for (int j = i - 1; j >= 0; j--) {
                    if (arr[i] >= arr[j])
                        sum += 1;
                }
            }
        }
        free(arr);
        cout << sum << endl;
    }
}
