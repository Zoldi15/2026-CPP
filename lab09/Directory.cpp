//
// Created by User on 11-Nov-25.
//

#include "Directory.h"
#include <algorithm>

Directory::Directory(const string& name): FileSystemItem(name,0) {
    this->name = name;
    long size = 0;
    for (FileSystemItem *child: children) size += child->getSize();
    this->size = size;
}

string Directory::getName() const {
    return this->name;
}

FileSystemItem * Directory::find(const string &name) {
    for (FileSystemItem* child : children) {
        //if (child->getName()==name) return child;
    }
    return nullptr;
}

long Directory::getSize() const {
    return this->size;
}

void Directory::display(int depth) const {
    cout<<setw(depth)<<this->name<<endl;
    for(int i=0;i<children.size();i++) {
        children[i]->display(depth+4);
    }
}

FileSystemItem * Directory::clone() const {
    return new Directory(this->name);
}

void Directory::add(FileSystemItem *item) {
    children.push_back(item);
}

void Directory::remove(const string &name) {
    //auto child=find_if(children.begin(), children.end(), [&](FileSystemItem *item) {return item->getName()==name;});
}
