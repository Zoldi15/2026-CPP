//
// Created by User on 21-Oct-25.
//

#ifndef QUIZ_H
#define QUIZ_H

#include "QuizItem.h"

class Quiz {
public:
    static int nextId;
    int id;
    string name;
    bool isReady=false;
    vector<QuizItem> items;

    Quiz(string name, vector<QuizItem> items);
    Quiz(string name);

    void addItem(QuizItem item);
    void finalize();

    bool operator<(const Quiz& a) const;

    friend std::ostream & operator<<(std::ostream &os, const Quiz &q);
};



#endif //QUIZ_H
