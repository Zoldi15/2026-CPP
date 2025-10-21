//
// Created by User on 21-Oct-25.
//

#ifndef USER_H
#define USER_H


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
    void printResults();
};

#endif //USER_H
