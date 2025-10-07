#include "Point.h"
#include <algorithm>
#include <iostream>
#include <cmath>

Point::Point(int x, int y) {
    if(x>=0 && x<=M && y>=0 && y<=M) {
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

double Point::distanceTo(const Point& point) {
    return sqrt(point.x*point.x+point.y*point.y);
}