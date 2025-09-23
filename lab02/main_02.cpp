#include <iostream>

#include "Point.h"

using namespace std;

int main(int argc, char** argv) {
    Point p1(2,3);
    cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;

    Point p2(100, 200);
    cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;

    Point * pp1 = new Point(300, 400);
    Point * pp2 = new Point(500, 1000);
    cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;

    delete pp1;
    delete pp2;

    //p1 es p2 'Point' tipusu valtozok, pp1 es pp2 'Point'-ra mutato cimek
    //A 'delete' felszabaditja a lefoglalt cimeket
    //A 'delete' csak dinamikusan lefoglalt cimeket tud felszabaditani
    //A 'cout' fuggveny kiir a standard kimenetre

    p1.print();
    p2.print();
    cout<<"Distance: "<<Point::distance(p1,p2)<<endl;

    Point s1(2,4);
    Point s2(2,9);
    Point s3(8,9);
    Point s4(8,4);
    if(Point::isSquare(s1,s2,s3,s4)==true) cout<<"Is a square."<<endl;
    else cout<<"Is not a square."<<endl;
    return 0;
}
