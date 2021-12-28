#include <iostream>
#include "myclass.h"

using namespace std;

int main() {
    circle c1;
    rectangle r1;
    double r, h, w;
    cout << "請依序輸入圓半徑、矩形長、寬（以空白隔開）" << endl << ":";
    cin >> r >> h >> w;
    r1.set_HandW(h, w);
    c1.set_radius(r);
    cout << "圓面積:" << c1.getArea() << "\n" << "圓周長：" << c1.getGirth();
    cout << "\n矩形面積：" << r1.getArea() << "\n矩形周長：" << r1.getGirth();
    return 0;
}
