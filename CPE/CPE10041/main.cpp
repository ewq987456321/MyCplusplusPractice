#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;
    for (int l = 0; l < num; l++) {
        int r, sum = 0;
        int temp;
        vector<int> arr;
        cin >> r;
        for (int i = 0; i < r; i++) {
            cin >> temp;
            arr.push_back(temp);
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
            if (arr[i + 1] != arr[i] && i != arr.size() - 1)
                sum += (arr[i + 1] - arr[i]);
        }
        cout << sum << endl;
    }
}
