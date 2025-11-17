//
// Created by User on 11-Nov-25.
//

#ifndef FILESYSTEMITEM_H
#define FILESYSTEMITEM_H

#include <string>
#include <iostream>

using namespace std;

class FileSystemItem{
protected:
    string name;
    long size=0;
public:
    FileSystemItem(const string& name, long size): name(name), size(size) {}
    virtual ~FileSystemItem() = default;

    string getName() const {return name;};
    virtual long getSize() const = 0;
    virtual void display(int depth = 0) const = 0;
    virtual FileSystemItem* clone() const = 0;

    friend ostream& operator <<(ostream& os, const FileSystemItem& fsi) {
        os << fsi.getName() << " (" << fsi.getSize() << "b)";
        return os;
    }
    friend bool operator <(const FileSystemItem& fsi1, const FileSystemItem& fsi2) {
        return fsi1.name.compare(fsi2.name) < 0;
    }
};

#endif //FILESYSTEMITEM_H
