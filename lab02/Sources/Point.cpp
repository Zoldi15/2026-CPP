#include "Point.h"
#include <algorithm>
#include <iostream>
#include <cmath>

Point::Point(int x, int y) {
    if(x>=0 && x<=2000 && y>=0 && y<=2000) {
        this->x=x;
        this->y=y;
    }
    else {
        this->x=0;
        this->y=0;
    }
}
int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}
void Point::print() const {
    std::cout<<"X: "<<x<<", Y: "<<y<<std::endl;
}
double Point::distance(const Point& a, const Point& b) {
    double x=b.getX()-a.getX();
    double y=b.getY()-a.getY();
    return sqrt(x*x+y*y);
}
bool Point::isSquare(const Point& a, const Point& b, const Point& c, const Point& d) {
    double d1=distance(a,b), d2=distance(b,c), d3=distance(c,d), d4=distance(d,a), d5=distance(a,c), d6=distance(b,d);

    double array[7]={d1,d2,d3,d4,d5,d6};

    std::sort(array,array+6);

    return true;
}