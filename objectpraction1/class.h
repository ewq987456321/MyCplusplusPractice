class shape{
protected:
    double area = 0;
    double girth = 0;
public:
    double getArea(){return area;}
    double getGirth(){return girth;}
};

class circle : public shape{
private:
    int radius = 0;
public:
    void setradius(int r);
};
void circle::setradius(int r){
    area = r * r * 3.14159;
    girth = 2 * r * 3.14159;
}

class retangle : public shape{
    int height = 0;
    int width = 0;
public:
    void setHandW(int h,int w);
};
void retangle::setHandW(int h, int w){
    area = h * w;
    girth = (h + w) * 2;
}
