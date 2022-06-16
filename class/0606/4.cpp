#include <ctime>
#include <iostream>

using namespace std;

int f(int n) {
    if (n == 1 or n == 2) return 1;
    if (n >= 3) return f(n - 1) + f(n - 2);
}

int main() {
    int n;
    cin >> n;
    int start = clock();
    cout << f(n) << endl;
    int end = clock();
    cout << "遞迴：" << (double)(end - start) / CLK_TCK << endl;

    long long fib[75];
    int i;
    fib[1] = 1;
    fib[2] = 1;
    for (i = 3; i <= 70; i = i + 1)
        fib[i] = fib[i - 1] + fib[i - 2];

    cin >> n;
    start = clock();
    cout << fib[n] << endl;
    end = clock();
    cout << "迴圈+陣列" << (double)(end - start) / CLK_TCK << endl;

    cin >> n;
    start = clock();
    int fib1, n_2 = 0, n_1 = 1;
    if (n == 0)
        fib1 = n_2;

    else if (n == 1)
        fib1 = n_1;

    else {

        for (i = 2; i <= n; i++) {
            fib1 = n_2 + n_1;
            n_2 = n_1;
            n_1 = fib1;
        }
    }
    cout << fib1 << endl;
    end = clock();
    cout << "迴圈" << (double)(end - start) / CLK_TCK << endl;
    return 0;
}
