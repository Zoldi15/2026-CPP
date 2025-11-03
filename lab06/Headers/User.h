//
// Created by User on 21-Oct-25.
//

#ifndef USER_H
#define USER_H


#include <iostream>

#include "Quiz.h"
#include <map>

class User {
    static int nextId;
    int id;
    string name;
    map<Quiz, double> results;
public:
    User(string name);
    void addResult(Quiz& quiz, double result);
    void printResults(std::ostream& os = std::cout) const;

    std::ostream& operator<<(ostream& os) const;
};

#endif //USER_H
