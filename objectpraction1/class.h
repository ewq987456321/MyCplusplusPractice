class shape{
protected:
    double area = 0;
    double girth = 0;
public:
    double getArea() const{return area;}
    double getGirth() const{return girth;}
};

class circle : public shape{
private:
    double radius = 0;
public:
    void setradius(double r);
};
void circle::setradius(double r){
    if (r > 0) {
        radius = r;
        area = radius * radius * 3.14159;
        girth = 2 * radius * 3.14159;
    }
    else {
        std::cout << "You input a wrong radius, Please input a correct number\n";
    }
}

class retangle : public shape{
    double height = 0;
    double width = 0;
public:
    void setHandW(double h,double w);
};
void retangle::setHandW(double h, double w){
    if(h > 0 && w > 0){
        height = h;
        width = w;
        area = height * width;
        girth = (height + width) * 2;
    }
    else{
        std::cout << "You input a wrong height or width, Please input a correct number\a\n" ;
    }

}
