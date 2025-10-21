//
// Created by User on 21-Oct-25.
//

#include "Quiz.h"

#include <ostream>

int Quiz::nextId=10;

Quiz::Quiz(string name, vector<QuizItem> items) {
    this->name=move(name);
    this->items=move(items);
    id=nextId++;
}

Quiz::Quiz(string name) {
    this->name=move(name);
    id=nextId++;
}

void Quiz::addItem(QuizItem item) {
    this->items.push_back(item);
}

void Quiz::finalize() {
    this->isReady=true;
}

bool Quiz::operator<(const Quiz& a) const {
    return this->id < a.id;
}

ostream Quiz::operator<<(ostream s, const Quiz &a) const {
    return s;
}
