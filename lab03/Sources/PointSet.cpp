#include "PointSet.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;

PointSet::PointSet(int n){
    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd()); // Mersenne Twister algorithm to generate random numbers
    uniform_int_distribution<int> dist(0, 1000); // return a number in the given range

    for(int i=0;i<n;i++){
        int x = dist(mt), y = dist(mt);
        Point Px=Point(x,y);
        this->points.push_back(Px);
    }
}

void PointSet::computeDistances(){
    for(int i=0;i<n;i++){
        Point point=this->points.at(i);
        this->distances.push_back(Point::distanceTo(point));
    }
}

double PointSet::maxDistance() const{
    double max=0;
    for(int i=0;i<n;i++) if(distances.at(i)>max) max=distances.at(i);
    return max;
}

double PointSet::minDistance() const{
    double min=0;
    for(int i=0;i<n;i++) if(distances.at(i)<min) min=distances.at(i);
    return min;
}

int PointSet::numDistances() const {
    return distances.size();
}

void PointSet::printPoints() const {
    for(Point p:points) p.print();
}

void PointSet::printDistances() const {
    for(double d:distances) cout<<d<<", ";
    cout<<endl;
}

int compareX(const Point& a,const Point& b) {
    return a.getX()-b.getX();
}

int compareY(const Point& a,const Point& b) {
    return a.getY()-b.getY();
}

void PointSet::sortPointsX() {
    sort(points.begin(),points.end(),compareX);
}

void PointSet::sortPointsY() {
    sort(points.begin(),points.end(),compareY);
}

void PointSet::sortDistances() {
    sort(distances.begin(),distances.end());
}
int PointSet::numDistinctDistances() {
    return distances.size();
}