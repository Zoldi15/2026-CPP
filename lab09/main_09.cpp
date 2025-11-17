#include <iostream>

#include "Directory.h"
#include "FileSystemItem.h"

int main() {
    Directory filemanager=Directory("filemanager");
    Directory d1("1D"); Directory d2("2D"); Directory d3("3D");
    File f1("A",2); File f2("B",10); File f3("C",20);

    filemanager.add(&f1); filemanager.add(&f2);
    filemanager.add(&d1); filemanager.add(&d2);
    d1.add(&d3);
    d1.add(&f1);
    d2.add(&f1); d2.add(&f2);
    d3.add(&f2); d3.add(&f3);
    filemanager.display();
    return 0;
}