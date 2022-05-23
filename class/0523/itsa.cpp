#include <iostream>

using namespace std;

int main() {
    int N, a1, a2, a3;
    int b1 = 0, b2 = 0, b3 = 0;
    char a;
    cin >> N >> a >> a1 >> a >> a2 >> a >> a3;
    int total = 15 * a1 + 20 * a2 + 30 * a3;
    if (N < total)
        cout << "0" << endl;
    else {
        total = N - total;
        b3 = total / 50;
        total -= 50 * b3;
        b2 = total / 5;
        total -= 5 * b2;
        b1 = total;
        cout << b1 << "," << b2 << "," << b3 << endl;
    }
}
