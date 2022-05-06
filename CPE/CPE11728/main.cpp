#include <iostream>
#include <string>
using namespace std;

int main() {
    string num;
    cin >> num;
    while (num != "0") {
        int t = 0;
        for (unsigned long i = 0; i < num.length(); i++) {
            t += num[i];
        }

        cin >> num;
    }
}
