//
// Created by User on 07-Oct-25.
//

#include "Polynomial.h"

Polynomial::Polynomial(int degree, const double coefficients[]) {
    this->capacity=degree+1;
    this->coefficients=new double[degree+1];
    for(int i=0;i<degree+1;i++) {
        this->coefficients[i]=coefficients[i];
    }
}

Polynomial::Polynomial(const Polynomial &that) {
    this->capacity=that.capacity;
    this->coefficients=new double[this->capacity];
    for(int i=0;i<this->capacity;i++) {
        this->coefficients[i]=that.coefficients[i];
    }
}

Polynomial::~Polynomial() {
    if(this->coefficients!=nullptr) {
        delete[] this->coefficients;
    }
}

int Polynomial::degree() const {
    return this->capacity-1;
}

double Polynomial::evaluate(double x) const {
    double P=this->coefficients[capacity-1];
    for(int i=this->capacity-2;i>=0;i--) {
        P=P*x+this->coefficients[i];
    }
    return P;
}

Polynomial Polynomial::derivative() const {
    double* coeffP=new double[this->capacity-1];
    for(int i=0;i<this->capacity-1;i++) {
        coeffP[i]=this->coefficients[i];
    }
    Polynomial P(this->capacity-2,coeffP);
    return P;
}

double Polynomial::operator[](int index) const {
    return this->coefficients[index];
}

Polynomial operator-(const Polynomial &a) {
    double* coeffP=new double[a.capacity-1];
    for(int i=0;i<a.capacity;i++) {
        coeffP[i]=-a.coefficients[i];
    }
    Polynomial P(a.capacity-1,coeffP);
    return P;
}

Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    int capacityC;
    if(a.capacity>=b.capacity) capacityC=a.capacity;
    else capacityC=b.capacity;

    double* coeffC=new double[capacityC];

    //if(!coeffC) return Polynomial(0,nullptr);

    for(int i=0;i<capacityC;i++) {
        coeffC[i]=a.coefficients[i]+b.coefficients[i];
    }
    Polynomial P(capacityC-1,coeffC);
    return P;
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    int capacityC;
    if(a.capacity>=b.capacity) capacityC=a.capacity;
    else capacityC=b.capacity;

    double* coeffC=new double[capacityC];

    //if(!coeffC) return Polynomial(0,nullptr);

    for(int i=0;i<capacityC;i++) {
        coeffC[i]=a.coefficients[i]-b.coefficients[i];
    }
    Polynomial P(capacityC-1,coeffC);
    return P;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    int ossz=a.capacity+b.capacity-1;
    double* coeffC=new double[ossz];

    //if(!coeffC) return Polynomial(0,nullptr);

    for(int i=a.capacity-1;i>=0;i--) {
        for(int j=b.capacity-1;j>=0;j--) {
            coeffC[i+j]+=a.coefficients[i]*b.coefficients[j];
        }
    }

    Polynomial P(ossz,coeffC);
    return P;
}

ostream & operator<<(ostream &out, const Polynomial &what) {
    for(int i=0;i<what.capacity-1;i++) {
        out<<what.coefficients[i]<<"x^"<<(what.capacity-i-1)<<" + ";
    }
    out<<what.coefficients[what.capacity-1];
    return out;
}
