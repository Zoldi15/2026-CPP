//
// Created by User on 11-Nov-25.
//

#ifndef DIRECTORY_H
#define DIRECTORY_H
#include <vector>

#include "File.h"
#include "FileSystemItem.h"

class Directory : public FileSystemItem {
private:
    vector<const FileSystemItem*> children;
public:
    Directory(const string& name);
    //~Directory() override;

    FileSystemItem* find(const string& name);
    long getSize() const override;
    string getName() const;
    void display(int depth = 0) const override;
    FileSystemItem* clone() const override;

    void add(FileSystemItem* item);
    void remove(const string &name);

    void operator +=(const FileSystemItem* item) {
        children.push_back(item);
    }
    //friend void operator -=(const FileSystemItem* item);
};

#endif //DIRECTORY_H
