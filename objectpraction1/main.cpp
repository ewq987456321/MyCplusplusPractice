//
//  main.cpp
//  ObjectPracrice
//
//  Created by Jing on 2021/7/21.
//

#include <iostream>
#include "class.h"
using namespace std;
int main() {
    circle c1;
    retangle r1;
    double r,h,w;
    cout << "請依序輸入圓半徑、矩形長、寬（以空白隔開）" << endl << ":";
    cin >> r >> h >> w;
    r1.setHandW(h, w);
    c1.setradius(r);
    cout << "圓面積:" << c1.getArea() << "\n" << "圓周長："<< c1.getGirth();
    cout << "\n矩形面積：" << r1.getArea() << "\n矩形周長：" << r1.getGirth();
    return 0;
}
