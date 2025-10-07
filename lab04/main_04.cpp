#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
    double x[]{1,2,1};
    Polynomial p1(2,x);
    cout<<p1<<endl;

    //-------Masolas
    //Polynomial p2(p1);
    //Polynomial p3=p1;

    cout<<"Gyokok:  0:"<<p1.evaluate(0)<<" 1:"<<p1.evaluate(1)<<" 2:"<<p1.evaluate(2)<<endl;

    cout<<"Derivalt: "<<p1.derivative()<<endl;
    cout<<"Egyutthatok: "<<p1[0]<<p1[1]<<p1[2]<<endl;
    cout<<"Rang: "<<p1.degree()<<endl;
    cout<<"Negativ: "<<-p1<<endl;
    cout<<"Osszead: "<<p1+p1<<endl;
    cout<<"Kivon: "<<p1-p1<<endl;
    cout<<"Szorzas: "<<p1*p1<<endl;

    return 0;
}