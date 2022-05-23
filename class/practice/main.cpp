#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        unsigned long long ans = 0;
        string a = "";
        int temp = 0;
        int count = 0;
        cin >> m;
        do {
            for (int j = 0; j < 9; j++) {
                if ((m * j + temp) % 10 == 1) {
                    // ans = ans * 10 + j;
                    temp = (m * j + temp) / 10;
                    a.insert(0, to_string(j));
                }
            }
            count += 1;
        } while (temp != 1);
        ans = stoi(a);
        ans *= m;
        cout << to_string(ans).size() << endl;
        // cout << " " << stoi(a) << "|" << endl;
        //   cout << m * num << endl;
        // cout << ans << endl;
    }
}
