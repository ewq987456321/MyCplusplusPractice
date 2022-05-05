#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    cin >> a;
    int l = a.length();
    char b[l];
    int count = 0, countb = 0;
    for (int i = 0; i < l; i++) {
        if (a[i] == 'A' || a[i] == 'B' || a[i] == 'C') { b[i] = '2'; }
        else if (a[i] == 'D' || a[i] == 'E' || a[i] == 'F') { b[i] = '3'; }
        else if (a[i] == 'G' || a[i] == 'H' || a[i] == 'I') { b[i] = '4'; }
        else if (a[i] == 'J' || a[i] == 'K' || a[i] == 'L') { b[i] = '5'; }
        else if (a[i] == 'M' || a[i] == 'N' || a[i] == 'O') { b[i] = '6'; }
        else if (a[i] == 'P' || a[i] == 'Q' || a[i] == 'Q' || a[i] == 'S') { b[i] = '7'; }
        else if (a[i] == 'T' || a[i] == 'U' || a[i] == 'V') { b[i] = '8'; }
        else if (a[i] == 'W' || a[i] == 'X' || a[i] == 'Y' || a[i] == 'Z') { b[i] = '9'; }
        else if (a[i] == '-') {
            b[i] = '-';
            count += 1;
        } else {
            b[i] = a[i];
            countb += 1;
        }
    }
    for (int j = 0; j < l; j++) { cout << b[j]; }
    cout << ' ' << l - countb - count << " " << count;
}