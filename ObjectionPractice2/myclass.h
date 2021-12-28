//
// Created by Jing on 2021/10/5.
//

#ifndef OBJECTIONPRACTICE2_MYCLASS_H
#define OBJECTIONPRACTICE2_MYCLASS_H

#endif //OBJECTIONPRACTICE2_MYCLASS_H

class shape {
protected:
    double area = 0;
    double girth = 0;
public:
    double getArea() const { return area; }

    double getGirth() const { return girth; }
};

class circle : public shape {
private:
    double radius = 0;
public:
    void set_radius(double r); //宣告set_radius方法的原型
};

void circle::set_radius(double r) { //set_radius 實作方法
    if (r > 0) {
        radius = r;
        area = radius * radius * 3.14159;
        girth = 2 * radius * 3.14159;
    } else {
        std::cout << "You input a wrong radius, Please input a correct number\n";
    }
}

class rectangle : public shape {
    double height = 0;
    double width = 0;
public:
    void set_HandW(double h, double w); //宣告原形
};

void rectangle::set_HandW(double h, double w) { //第41行先告原型，以下為實作方法
    if (h > 0 && w > 0) {
        height = h;
        width = w;
        area = height * width;
        girth = (height + width) * 2;
    } else {
        std::cout << "You input a wrong height or width, Please input a correct number\a\n";
    }

}

