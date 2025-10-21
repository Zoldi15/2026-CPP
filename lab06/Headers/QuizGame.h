//
// Created by User on 21-Oct-25.
//

#ifndef QUIZGAME_H
#define QUIZGAME_H

#include "User.h"

class QuizGame {
    Quiz& quiz;
    User& user;
public:
    QuizGame(Quiz& q, User& u):quiz(q),user(u){}
    void runQuiz();
};


#endif //QUIZGAME_H
