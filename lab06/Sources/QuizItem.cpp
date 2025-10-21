//
// Created by User on 21-Oct-25.
//

#include "QuizItem.h"

#include <iomanip>
#include <iostream>
#include <string>
#include <utility>

int QuizItem::nextId=0;

QuizItem::QuizItem(string question, vector<string> answers, int correct) {
    this->question=move(question);
    this->answers=move(answers);
    this->correct=correct;
    id=nextId++;
}

void QuizItem::printQuizItem() {
    cout<<id<<": "<<question<<endl;
    for(int i=0;i<answers.size();i++) {
        cout<<setw(2)<<answers[i]<<endl;
    }
}
