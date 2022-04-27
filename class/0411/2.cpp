#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int num_10;
    int num_2[9] = {0};
    cin >> num_10;
    if (num_10 >= 0) {
        for (int i = 0; (num_10) != 0; i++) {
            num_2[i] = num_10 % 2;
            num_10 /= 2;
        }
    } else {
        num_10 = abs(num_10);
        for (int i = 0; (num_10) != 0; i++) {
            num_2[i] = num_10 % 2;
            num_10 /= 2;
        }
        for (int i = 0; i < 8; i++) {
            if (num_2[i] == 1)
                num_2[i] = 0;
            else
                num_2[i] = 1;
        }
        int temp = 0;
        num_2[0] += 1;
        for (int i = 0; i < 8; i++) {
            if (num_2[i] == 2) {
                num_2[i] = 0;
                temp += 1;
            }
            if (temp == 1)
                num_2[i + 1] += (temp--);
        }
    }
    for (int i = 7; i >= 0; i--)
        cout << num_2[i];
    cout << endl;
    return 0;
}