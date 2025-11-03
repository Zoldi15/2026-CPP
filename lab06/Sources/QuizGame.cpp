//
// Created by User on 21-Oct-25.
//

#include "QuizGame.h"

#include <iostream>
#include <ostream>

using namespace std;

void QuizGame::runQuiz() {
    if(this->quiz.isReady==false) {
        cout<<"Quiz not ready"<<endl;
        return;
    }
    for(QuizItem q:this->quiz.items) {
        q.printQuizItem();
        cout<<endl;
        while(true) {
            char x; cout<<"Valasz: "; cin>>x;
            if(x=='A' || x=='B' || x=='C' || x=='D') break;
        }
    }
}
