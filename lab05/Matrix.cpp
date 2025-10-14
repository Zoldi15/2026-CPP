//
// Created by User on 14-Oct-25.
//

#include "Matrix.h"
#include <algorithm>
#include <iomanip>

using namespace std;

Matrix::Matrix(int rows, int cols):mRows(rows),mCols(cols) {
    mElements.reserve(rows*cols);
    mElements.resize(rows*cols,0);
}

Matrix::Matrix(const Matrix &other):mRows(other.mRows),mCols(other.mCols),mElements(other.mElements) {}

Matrix::Matrix(Matrix &&other) noexcept:mRows(other.mRows),mCols(other.mCols),mElements(std::move(other.mElements)) {
    other.mRows=0; other.mCols=0;
}

Matrix::~Matrix() {
    this->mElements.clear();
    this->mElements.resize(0);
}

void Matrix::fillMatrix(double value) {
    fill(this->mElements.begin(), this->mElements.end(), value);
}

void Matrix::randomMatrix(int a, int b) {
    this->fillMatrix(rand() % (b-a+1));
}

void Matrix::printMatrix(std::ostream &os) const {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            os <<setw(6)<< mElements[i*mCols + j] << " ";
        }
        os << endl;
    }
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if(x.mRows != y.mRows || x.mCols != y.mCols) {
        cout<<"Matrix dimensions do not match/addition skipped."<<endl;
        return x;
    }
    Matrix z(x);
    for (int i = 0; i < z.mRows; ++i) {
        for (int j = 0; j < z.mCols; ++j) {
            z.mElements[i*z.mCols + j]+=y.mElements[i*z.mCols + j];
        }
    }
    return z;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if(x.mCols != y.mRows) {
        cout<<"Matrix dimensions do not match/multiplication skipped."<<endl;
        return x;
    }
    Matrix z(x.mRows,y.mCols);
    for (int i = 0; i < z.mRows; ++i) {
        for (int j = 0; j < z.mCols; ++j) {
            double sum=0;
            for(int k = 0; k < x.mCols; ++k) {
                sum=sum+x.mElements[i*x.mCols + k]*y.mElements[k*x.mCols + j];
            }
            z.mElements[i*z.mCols + j]=sum;
        }
    }
    return z;
}

std::istream & operator>>(std::istream &is, Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            is >> mat.mElements[i*mat.mCols + j];
        }
    }
    return is;
}

std::ostream & operator<<(std::ostream &os, const Matrix &mat) {
    mat.printMatrix(os);
    return os;
}

double * Matrix::operator[](int row) {
    return &mElements[row*mCols];
}

const double * Matrix::operator[](int row) const {
    return &mElements[row*mCols];
}

double & Matrix::operator()(int row, int col) {
    return mElements[row*mCols + col];
}

const double & Matrix::operator()(int row, int col) const {
    return mElements[row*mCols + col];
}
