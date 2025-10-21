//
// Created by User on 21-Oct-25.
//

#ifndef QUIZITEM_H
#define QUIZITEM_H

#include <string>
#include <vector>

using namespace std;

class QuizItem {
    static int nextId;
    int id;
    string question;
    vector<string> answers;
    int correct;
public:
    QuizItem(string question, vector<string> answers, int correct);
    void printQuizItem();
};

#endif //QUIZITEM_H
