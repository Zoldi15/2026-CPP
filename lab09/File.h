//
// Created by User on 11-Nov-25.
//

#ifndef FILE_H
#define FILE_H

#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>

#include "FileSystemItem.h"

using namespace std;

class File : public FileSystemItem{
public:
    File(const string& name, long size): FileSystemItem(name, size){};

    long getSize() const override {return this->size;}
    void display(int depth = 0) const override {
        cout<<setw(depth)<<this->name<<" ("<<this->size<<"b)"<<endl;
    }

    File* clone() const override {
        return new File(this->name,this->size);
    }
};

#endif //FILE_H
