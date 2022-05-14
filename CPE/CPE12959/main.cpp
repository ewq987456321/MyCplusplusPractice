#include <iostream>
using namespace std;

int main()
{
    int J, R;
    cin >> J >> R;
    do {
        int winer = 0;
        long long *point = new long long[J];
        for (int i = 0; i < J; i++) {
            point[i] = 0;
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < J; j++) {
                int temp;
                cin >> temp;
                point[j] += temp;
            }
        }
        for (int i = 0; i < J; i++) {
            if (point[winer] <= point[i]) winer = i;
        }
        cout << winer + 1 << endl;
        delete[] point;
        cin >> J >> R;
    } while (J != 0 && R != 0);
}
