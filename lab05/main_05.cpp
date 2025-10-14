#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    Matrix m1(3,4);
    m1.fillMatrix(1);

    //m1.printMatrix();
    cout<<m1<<endl;

    Matrix m2=m1;
    return 0;
}