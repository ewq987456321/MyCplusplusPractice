#include "3header.h"
#include <cmath>

float dis(int x1, int x2, int y1, int y2) { return sqrt(pow((x1 - y1), 2) + pow((x2 - y2), 2)); }

float area(int x1, int x2, int y1, int y2) { return abs(y1 - x1) * abs(y2 - x2); }

float *mid(int x1, int x2, int y1, int y2) {
    float m[2] = {0};
    m[0] = (x1 + y1) / 2.0;
    m[1] = (x2 + y2) / 2.0;
    return m;
}

float cir(int x, int y, int r) { return M_PI * pow(r, 2); }

float *bary(int x1, int x2, int x3, int y1, int y2, int y3) {
    float b[2] = {0};
    b[0] = abs(x1 + x2 + x3) / 3.0;
    b[1] = abs(y1 + y2 + y3) / 3.0;
    return b;
}

