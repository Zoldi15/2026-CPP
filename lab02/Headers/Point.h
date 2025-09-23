//
// Created by User on 23-Sep-25.
//

#ifndef POINT_H
#define POINT_H

class Point {
private:
    int x,y;
public:
    Point(int x, int y);
    int getX() const;
    int getY() const;
    void print() const;
    static double distance(const Point& a, const Point& b);
    static bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
};

#endif //POINT_H
